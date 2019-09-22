#pragma once
#include "Database.h"
#include "Product.h"
#include "Customer.h"
#include "Item.h"
#include "Employee.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Data::Sql;
using namespace System::Data::SqlClient;
using namespace System::Data::SqlTypes;
using namespace Microsoft::SqlServer::Server;
using namespace System::Runtime::InteropServices;
ref class Invoice
{
private:
	int id;
	Customer^ customer;
	double totalPrice;
	List<Item^>^ items;
	String^ paymentMethod;
	Employee^ employee;
	DateTime^ date;
private: void SetId(int value)
{
	id = value;
}
protected:
	//Методы заполнения полей класса
	void SetId()
	{
		SqlConnection^ conn = Database::CreateConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT MAX(Id) FROM Invoice", conn);
		conn->Open();
		id = (int)sqlCommand->ExecuteScalar();
		conn->Close();
	}
	void SetCustomer(Customer^ value)
	{
		customer = value;
	}

	void SetPaymentMethod(String^ value)
	{
		paymentMethod = value;
	}

	void SetTotal(double value)
	{
		totalPrice = value;
	}

	void SetItems(List<Item^>^ value)
	{
		for each (Item^ item in value)
		{
			items->Add(item);
		}
	}

	void SetEmployee(Employee^ value)
	{
		employee = value;
	}

	void SetDate(DateTime^ value)
	{
		date = value;
	}

public:
	//Методы чтения полей класса
	int GetId()
	{
		return id;
	}

	String^ GetPaymentMethod()
	{
		return paymentMethod;
	}

	Customer^ GetCustomer()
	{
		return customer;
	}

	double GetTotalPrice()
	{
		return totalPrice;
	}

	List<Item^>^ GetItems()
	{
		List<Item^>^ result;
		for each (Item^ item in items)
		{
			result->Add(item);
		}
		return result;	
	}


	Employee^ GetEmployee()
	{
		return employee;
	}

	DateTime^ GetDate()
	{
		return date;
	}

	//Конструкторы
	Invoice()
	{
		SetId(0);
		SetCustomer(gcnew Customer());
		SetPaymentMethod("");
		SetEmployee(nullptr);
		SetDate(gcnew DateTime);
		SetItems(nullptr);
		SetTotal(0);
	}
	Invoice(int id, Customer^ customer, List<Item^>^ items, String^ paymentMethod, Employee^ employee, double totalPrice, DateTime^ date)
	{
		SetId(id);
		SetCustomer(customer);
		SetItems(items);
		SetPaymentMethod(paymentMethod);
		SetTotal(totalPrice);
		SetEmployee(employee);
		SetDate(date);
	}
	public: static Invoice^ GetInvoice(SqlDataReader^ sqlReader)
	{
		if (sqlReader->Read())
		{
			Invoice^ invoice = gcnew Invoice();
			invoice->SetId(Convert::ToInt32(sqlReader["Id"]));
			invoice->SetCustomer(Customer::GetCustomer(Convert::ToInt32(sqlReader["CustomerId"])));
			List<Item^>^ items = Item::GetItems(Convert::ToInt32(sqlReader["Id"]));
			invoice->SetItems(items);
			double total = 0;
			for each (Item ^ item in items)
			{
				total += Convert::ToDouble(item->GetProduct()->GetPrice() * (1 - invoice->GetCustomer()->GetDiscount()));
			}
			invoice->SetTotal(total);
			invoice->SetEmployee(Employee::GetEmployee(Convert::ToInt32(sqlReader["EmployeeId"])));
			invoice->SetDate(Convert::ToDateTime(sqlReader["Date"]));
			return invoice;
		}
		return nullptr;
	}
	public: static Invoice^ GetInvoice(int id)
	{
		SqlConnection^ conn = Database::CreateOpenConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT * FROM Invoice WHERE Id = @id", conn);
		sqlCommand->Parameters->Add("@id", SqlDbType::Int)->Value = 1;
		SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();

		if (sqlReader->Read())
		{
			Invoice^ invoice = gcnew Invoice();
			invoice->SetId(id);
			invoice->SetCustomer(Customer::GetCustomer(Convert::ToInt32(sqlReader["CustomerId"])));
			List<Item^>^ items = Item::GetItems(Convert::ToInt32(sqlReader["Id"]));
			invoice->SetItems(items);
			double total = 0;
			for each (Item ^ item in items)
			{
				total += Convert::ToDouble(item->GetProduct()->GetPrice() * (1 - invoice->GetCustomer()->GetDiscount()));
			}
			invoice->SetTotal(total);
			invoice->SetEmployee(Employee::GetEmployee(Convert::ToInt32(sqlReader["EmployeeId"])));
			invoice->SetDate(Convert::ToDateTime(sqlReader["Date"]));
			return invoice;
		}
		return nullptr;
	}
	public: static List<Invoice^>^ GetInvoices()
	{
		List<Invoice^>^ invoices;
		SqlConnection^ conn = Database::CreateOpenConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT * FROM Invoice", conn);
		SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();
		while (sqlReader->Read())
		{
			invoices->Add(GetInvoice(sqlReader));
		}
		conn->Close();
		return invoices;
	}
};

