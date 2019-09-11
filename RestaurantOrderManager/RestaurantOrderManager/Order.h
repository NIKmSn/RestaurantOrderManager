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
	DateTime date;
protected:
	//Методы заполнения полей
	void SetCustomerId(int value)
	{
		customerId = value;
	}
public:
	//Методы чтения полей
};

