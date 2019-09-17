#pragma once
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::Sql;
using namespace System::Data::SqlClient;
using namespace System::Data::SqlTypes;
using namespace Microsoft::SqlServer::Server;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;
ref class Database
{

private: String^ connStr = L"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Programs\\repos\\RestaurantOrderManager\\RestaurantOrderManager\\RestaurantDatabase\\Restaurant.mdf;Integrated Security=True;Connect Timeout=30";
	SqlConnection^ myConnection;
	SqlCommand^ sqlCommand = gcnew SqlCommand();
	SqlDataAdapter^ sda = gcnew SqlDataAdapter();
	SqlDataReader^ sqlReader;
	
public: SqlConnection^ GetConnection(SqlCommand^& sqlCommand)
	{
		try
		{
			myConnection = gcnew SqlConnection(connStr);
			sqlCommand->Connection = myConnection;
		}
		catch (Exception^ ex)
		{
			int id;
			MessageBox::Show(ex->Message, "Îøèáêà", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	myConnection = gcnew SqlConnection(connStr);
	sqlCommand->Connection = myConnection;
	sqlCommand->Parameters->AddWithValue("@product_type", "");
	sqlCommand->Parameters->AddWithValue("@product_name", "");
	sqlCommand->Parameters->AddWithValue("@item_invoiceId", "");
	sqlCommand->Parameters->AddWithValue("@item_productId", "");
	sqlCommand->Parameters->AddWithValue("@item_quantity", "");
};

