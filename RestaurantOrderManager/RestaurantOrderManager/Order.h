#pragma once
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
	int customerId;
	int tableId;
	DateTime^ date;
protected:
	//Методы заполнения полей
	void SetCustomerId(int value)
	{
		customerId = value;
	}

	void SetTableId(int value)
	{
		tableId = value;
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

	int GetCustomerId()
	{
		return customerId;
	}

	int GetTableId()
	{
		return tableId;
	}

	DateTime^ GetDate()
	{
		return date;
	}

	//Конструкторы
	Order()
	{
		SetCustomerId(-1);
		SetTableId(-1);
		SetDate(gcnew DateTime);
	}
	Order(int customerId, int tableId, DateTime^ date)
	{
		SetCustomerId(customerId);
		SetTableId(tableId);
		SetDate(date);
	}

};

