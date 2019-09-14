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
ref class Invoice
{
private:
	int id;
	int customerId;
	String^ paymentMethod;
	int employeeId;
	DateTime^ date;

protected:
	//Методы заполнения полей класса
	void SetCustomerId(int value)
	{
		customerId = value;
	}

	void SetPaymentMethod(String^ value)
	{
		paymentMethod = value;
	}

	void SetEmployeeId(int value)
	{
		employeeId = value;
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

	int GetEmployeeId()
	{
		return employeeId;
	}

	DateTime^ GetDate()
	{
		return date;
	}

	//Конструкторы
	Invoice()
	{
		SetPaymentMethod("");
		SetEmployeeId(-1);
		SetDate(gcnew DateTime);
	}
	Invoice(String^ paymentMethod, int employeeId, DateTime^ date)
	{
		SetPaymentMethod(paymentMethod);
		SetEmployeeId(employeeId);
		SetDate(date);
	}
};

