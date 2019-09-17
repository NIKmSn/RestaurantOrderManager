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

private: static String^ connStr = L"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Programs\\repos\\RestaurantOrderManager\\RestaurantOrderManager\\RestaurantDatabase\\Restaurant.mdf;Integrated Security=True;Connect Timeout=30";
public: static SqlConnection^ CreateConnection()
{
	try
	{
		SqlConnection^ myConnection = gcnew SqlConnection(connStr);
		return myConnection;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Îøèáêà", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
public: static SqlCommand^ CreateCommand()
{
	return gcnew SqlCommand();
}
public: static SqlConnection^ CreateOpenConnection()
{
	try
	{
		SqlConnection^ connection = CreateConnection();
		connection->Open();
		return connection;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Îøèáêà", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
public: static SqlCommand^ CreateCommand(String^ commandText, SqlConnection^ connection)
{
	SqlCommand^ command = CreateCommand();
	command->CommandText = commandText;
	command->Connection = connection;
	command->CommandType = CommandType::Text;
	return command;
}
public: static SqlCommand^ CreateStoredProcedureCommand(String^ procName, SqlConnection^ connection)
{
	SqlCommand^ command = CreateCommand();
	command->CommandText = procName;
	command->Connection = connection;
	command->CommandType = CommandType::StoredProcedure;
	return command;
}
public: static SqlDataAdapter^ CreateDataAdapter()
{
	return gcnew SqlDataAdapter();
}
public: static SqlDataReader^ CreateSqlReader()
{
	return gcnew SqlDataReader();
}
public: static SqlParameter^ CreateParameter(String^ parameterName, Object^ parameterValue)
{
	return gcnew SqlParameter(parameterName, parameterValue);
}

public: static Database database;
public: static SqlDataReader^ sqlReader = CreateSqlReader();
//public: SqlCommand^ GetProduct()
//{
//	SqlCommand^ sqlCommand = gcnew SqlCommand();
//	sqlCommand->Connection = myConnection;
//	sqlCommand.
//}
	//myConnection = GetConnection();
	//sqlCommand->Connection = myConnection;
	//sqlCommand->Parameters->AddWithValue("@product_type", "");
	//sqlCommand->Parameters->AddWithValue("@product_name", "");
	//sqlCommand->Parameters->AddWithValue("@item_invoiceId", "");
	//sqlCommand->Parameters->AddWithValue("@item_productId", "");
	//sqlCommand->Parameters->AddWithValue("@item_quantity", "");
};

