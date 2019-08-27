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
ref class Person
{
private:
	//Поля
	String^ name;
	String^ phoneNumber;
protected:
	//Методы заполнения полей класса
	void SetName(String^ value)
	{
		name = value;
	}

	void SetPhoneNumber(String^ value)
	{
		phoneNumber = value;
	}
public: 
	//Методы чтения полей класса
	String^ GetName()
	{
		return name;
	}
	String^ GetPhoneNumber()
	{
		return phoneNumber;
	}

	//Конструкторы 
	Person()
	{
		SetName("");
		SetPhoneNumber("");
	}
	Person(String^ name):Person()
	{
		SetName(name);
	}
	Person(String^ name, String^ phoneNumber) : Person(name)
	{
		SetName(name);
		SetPhoneNumber(phoneNumber);
	}
};

