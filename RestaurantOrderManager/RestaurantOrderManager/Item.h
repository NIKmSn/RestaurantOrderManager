#pragma once
#include "Product.h"
#include "Database.h"
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
ref class Invoice;
ref class Item
{
private:
	//Поля
	int id;
	//String^ item;
	//int invoiceId;
	Invoice^ invoice;
	Product^ product;
	int quantity;
	Decimal cost;
private: void SetId(int value)
{
	id = value;
}
protected:
	//Методы заполнения полей
	/*void SetItem(String^ value)
	{
		item = value;
	}*/

	void SetId()
	{
		SqlConnection^ conn = Database::CreateConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT MAX(Id) FROM Item", conn);
		conn->Open();
		id = Convert::ToInt32(sqlCommand->ExecuteScalar()) + 1;
		conn->Close();
	}

	void SetProduct(Product^ value)
	{
		product = value;
	}

	void SetQuantity(int value)
	{
		quantity = value;
	}

	void SetCost(Decimal value)
	{
		cost = value;
	}
public:void SetInvoice(Invoice^ value)
	{
		invoice = value;
	}
public:
	//Методы чтения полей
	int GetId()
	{
		return id;
	}

	/*String^ GetItem()
	{
		return item;
	}*/

	Invoice^ GetInvoice()
	{
		return invoice;
	}

	Product^ GetProduct()
	{
		return product;
	}

	int GetQuantity()
	{
		return quantity;
	}

	Decimal GetCost()
	{
		return cost;
	}
	//Конструкторы
	Item()
	{
		SetId();
		//SetItem("");
		SetInvoice(nullptr);
		SetProduct(nullptr);
		SetQuantity(0);
		SetCost(0);
	}
	Item(int id, Invoice^ invoice, Product^ product, int quantity, Decimal cost)
	{
		//SetItem(item);
		SetId(id);
		SetInvoice(invoice);
		SetProduct(product);
		SetQuantity(quantity);
		SetCost(cost);
	}
	Item(Product^ product, int quantity)
	{
		SetId();
		SetProduct(product);
		SetQuantity(quantity);
		SetCost(GetQuantity() * product->GetPrice());
	}
public: static Item^ GetItem(SqlDataReader^ sqlReader)
{
		if (sqlReader->Read())
		{
			Item^ item = gcnew Item();
			item->SetId(Convert::ToInt32(sqlReader["Id"]));
			item->SetInvoice(Invoice::GetInvoice(Convert::ToInt32(sqlReader["InvoiceId"])));
			Product^ product = Product::GetProduct(Convert::ToInt32(sqlReader["Id"]));
			item->SetProduct(product);
			item->SetQuantity(Convert::ToInt32(sqlReader["Quantity"]));
			item->SetCost(item->GetQuantity() * product->GetPrice());
			return item;
		}
		return nullptr;
}
public: static List<Item^>^ GetItemsOfInvoice(int invoiceId)
{
	List<Item^>^ items = gcnew List<Item^>();
	SqlConnection^ conn = Database::CreateOpenConnection();
	SqlCommand^ sqlCommand = Database::CreateCommand("SELECT * FROM Item WHERE InvoiceId = @invoiceId", conn);
	sqlCommand->Parameters->Add("@invoiceId", SqlDbType::Int)->Value = 1;
	SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();

	while (sqlReader->Read())
	{
		items->Add(GetItem(sqlReader));
	}
	conn->Close();
	return items;
}
};

