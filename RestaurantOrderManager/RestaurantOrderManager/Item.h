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

ref class Item
{
private:
	//����
	int id;
	//String^ item;
	int customerId;
	int tableId;
	DateTime^ date;
protected:
	//������ ���������� �����
	/*void SetItem(String^ value)
	{
		item = value;
	}*/

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
	//������ ������ �����
	int GetId()
	{
		return id;
	}

	/*String^ GetItem()
	{
		return item;
	}*/

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

	//������������
	Item()
	{
		//SetItem("");
		SetCustomerId(-1);
		//SetTableId(-1);
		SetDate(gcnew DateTime);
	}
	Item(String^ item, int customerId, int tableId, DateTime^ date)
	{
		//SetItem(item);
		SetCustomerId(customerId);
		//SetTableId(tableId);
		SetDate(date);
	}
};

