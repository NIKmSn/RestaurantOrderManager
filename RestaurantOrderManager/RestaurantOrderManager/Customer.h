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

public: static Customer^ GetCustomer(int id)
{
	if (customerCache.ContainsKey(id))
	{
		return customerCache[id];
	}

	SqlConnection^ conn = Database::CreateOpenConnection();
	SqlCommand^ sqlCommand = Database::CreateStoredProcedureCommand("SELECT * FROM Customer WHERE Id = @id", conn);
	sqlCommand->Parameters->Add("@id", SqlDbType::Int)->Value = 1;
	SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();
	conn->Close();
	if (sqlReader->Read())
	{
		Customer^ customer = gcnew Customer();
		customer->SetId(id);
		customer->SetDiscount(Convert::ToDecimal(sqlReader["Discount"]));
		customer->SetName(sqlReader["Name"]->ToString());
		customer->SetPhoneNumber(sqlReader["PhoneNumber"]->ToString());
		customer->SetEmail(sqlReader["Email"]->ToString());
		customerCache.Add(id, customer);
		return customer;
	}
	return nullptr;
}
};

