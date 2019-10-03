#pragma once
#include "Invoice.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace System::Data::Sql;
using namespace System::Data::SqlClient;
using namespace System::Data::SqlTypes;
using namespace Microsoft::SqlServer::Server;
using namespace System::Runtime::InteropServices;
ref class Order
{
private:
	//Поля
	int id;
	Customer^ customer;
	int tableId;
	Invoice^ invoice;
	DateTime^ date;
private: void SetId(int value)
{
	id = value;
}
protected:
	//Методы заполнения полей
	void SetId()
	{
		SqlConnection^ conn = Database::CreateConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT MAX(Id) FROM Orders", conn);
		conn->Open();
		id = (int)sqlCommand->ExecuteScalar();
		conn->Close();
	}
	void SetCustomer(Customer^ value)
	{
		customer = value;
	}

	void SetTableId(int value)
	{
		tableId = value;
	}

	void SetInvoice(Invoice^ value)
	{
		invoice = value;
	}

	void SetDate(DateTime^ value)
	{
		date = value;
	}
public:
	//Методы чтения полей
	int GetId()
	{
		return id;
	}

	Customer^ GetCustomer()
	{
		return customer;
	}

	int GetTableId()
	{
		return tableId;
	}

	Invoice^ GetInvoice()
	{
		return invoice;
	}

	DateTime^ GetDate()
	{
		return date;
	}

	//Конструкторы
	Order()
	{
		SetCustomer(nullptr);
		SetTableId(-1);
		SetDate(gcnew DateTime);
	}
	Order(Customer^ customer, int tableId, DateTime^ date)
	{
		SetCustomer(customer);
		SetTableId(tableId);
		SetDate(date);
	}
	Order(Customer^ customer, int tableId, Invoice^ invoice, DateTime^ date)
	{
		SetCustomer(customer);
		SetTableId(tableId);
		SetInvoice(invoice);
		SetDate(date);
	}
public: Order^ GetOrder(int id)
{
	SqlConnection^ conn = Database::CreateOpenConnection();
	SqlCommand^ sqlCommand = Database::CreateCommand("SELECT * FROM Orders WHERE Id = @id", conn);
	sqlCommand->Parameters->Add("@id", SqlDbType::Int)->Value = 1;
	SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();

	if (sqlReader->Read())
	{
		Order^ order = gcnew Order();
		order->SetId(id);
		order->SetCustomer(Customer::GetCustomer(Convert::ToInt32(sqlReader["CustomerId"])));
		order->SetTableId(Convert::ToInt32(sqlReader["TableId"]));
		order->SetInvoice(Invoice::GetInvoice(Convert::ToInt32(sqlReader["InvoiceId"])));
		order->SetDate(Convert::ToDateTime(sqlReader["Date"]));
		return order;
	}
	conn->Close();
	return nullptr;
}
};

