#pragma once
#include "Person.h"
#include "Database.h"
ref class Customer :
	public Person
{
private: static Dictionary<int, Customer^> customerCache;

private:
	int id;
	String^ email;
	Decimal discount;
private: void SetId(int value)
{
	id = value;
}
protected:
	//Методы заполнения полей класса
	void SetId()
	{
		SqlConnection^ conn = Database::CreateConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT MAX(Id) FROM Customer", conn);
		conn->Open();
		id = (int)sqlCommand->ExecuteScalar();
		conn->Close();
	}
	void SetEmail(String^ value)
	{
		email = value;
	}

	void SetDiscount(Decimal value)
	{
		discount = value;
	}

public: 
	//Методы чтения полей класса
	int GetId()
	{
		return id;
	}
	String^ GetEmail()
	{
		return email;
	}
	Decimal GetDiscount()
	{
		return discount;
	}

	//Конструкторы
	Customer() :Person()
	{
		SetEmail("");
		SetDiscount(0);
	}
	Customer(String^ name, String^ phoneNumber, String^ email, Decimal discount) : Person(name, phoneNumber)
	{
		SetEmail(email);
		SetDiscount(discount);
	}

public: double CalcDiscount(double price)
{
	return price * Convert::ToDouble(1 - GetDiscount());
}
public: static Customer^ GetCustomer(int id)
{
	SqlConnection^ conn = Database::CreateOpenConnection();
	try
	{
		/*if (customerCache.ContainsKey(id))
		{
			return customerCache[id];
		}*/
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT * FROM Customer WHERE Id = @id", conn);
		sqlCommand->Parameters->Add("@id", SqlDbType::Int)->Value = id;
		SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();

		if (sqlReader->Read())
		{
			Customer^ customer = gcnew Customer();
			customer->SetId(Convert::ToInt32(sqlReader["Id"]));
			customer->SetDiscount(Convert::ToDecimal(sqlReader["Discount"]));
			customer->SetName(sqlReader["Name"]->ToString());
			customer->SetPhoneNumber(sqlReader["PhoneNumber"]->ToString());
			customer->SetEmail(sqlReader["Email"]->ToString());
			//customerCache.Add(id, customer);
			return customer;
		}

	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Ошибка доступа к базе данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	finally
	{
		conn->Close();
	}
}
public: static Customer^ GetCustomerByName(String^ name)
{
	SqlConnection^ conn = Database::CreateOpenConnection();
	try
	{
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT * FROM Customer WHERE Name = @name", conn);
		sqlCommand->Parameters->Add("@name", SqlDbType::NVarChar)->Value = name;
		SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();
		if (sqlReader->Read())
		{
			return GetCustomer(Convert::ToInt32(sqlReader["Id"]));
		}
		
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Ошибка доступа к базе данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	finally
	{
		conn->Close();
	}
}
};

