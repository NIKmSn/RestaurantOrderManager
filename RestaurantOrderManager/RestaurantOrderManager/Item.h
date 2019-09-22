#pragma once
#include "Product.h"
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

ref class Item
{
private:
	//Поля
	int id;
	//String^ item;
	int invoiceId;
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
		id = (int)sqlCommand->ExecuteScalar();
		conn->Close();
	}

	void SetInvoiceId(int value)
	{
		invoiceId = value;
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

	int GetInvoiceId()
	{
		return invoiceId;
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
		SetId(0);
		//SetItem("");
		SetInvoiceId(0);
		SetProduct(nullptr);
		SetQuantity(0);
		SetCost(0);
	}
	Item(int id, int invoiceId, Product^ product, int quantity, Decimal cost)
	{
		//SetItem(item);
		SetId(id);
		SetInvoiceId(invoiceId);
		SetProduct(product);
		SetQuantity(quantity);
		SetCost(cost);
	}
	static Item^ GetItem(SqlDataReader^ sqlReader)
	{
		if (sqlReader->Read())
		{
			//TODO: Исправить InvoiceId
			Item^ item = gcnew Item();
			item->SetId(Convert::ToInt32(sqlReader["Id"]));
			item->SetInvoiceId(0);
			Product^ product = Product::GetProduct(Convert::ToInt32(sqlReader["Id"]));
			item->SetProduct(product);
			item->SetQuantity(Convert::ToInt32(sqlReader["Quantity"]));
			item->SetCost(item->GetQuantity() * product->GetPrice());
			return item;
		}
		return nullptr;
	}
	static List<Item^>^ GetItems(int invoiceId)
	{
		List<Item^>^ items = gcnew List<Item^>();
		SqlConnection^ conn = Database::CreateOpenConnection();
		SqlCommand^ sqlCommand = Database::CreateStoredProcedureCommand("SELECT * FROM Item WHERE InvoiceId = @invoiceId", conn);
		sqlCommand->Parameters->Add("@invoiceId", SqlDbType::Int)->Value = 1;
		SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();
		conn->Close();

		while (sqlReader->Read())
		{
			items->Add(GetItem(sqlReader));
		}
		return items;
	}
};

