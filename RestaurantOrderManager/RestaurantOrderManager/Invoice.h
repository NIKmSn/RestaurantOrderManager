#pragma once
#include "Database.h"
#include "Product.h"
#include "Customer.h"
#include "Employee.h"
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Data::Sql;
using namespace System::Data::SqlClient;
using namespace System::Data::SqlTypes;
using namespace Microsoft::SqlServer::Server;
using namespace System::Runtime::InteropServices;

ref class Item;
ref class Invoice
{
private:
	int id;
	Customer^ customer;
	double totalPrice;
	List<Item^>^ items = gcnew List<Item^>();;
	String^ paymentMethod;
	Employee^ employee;
	DateTime^ date;
private: void SetId(int value);
protected:
	//Методы заполнения полей класса
	void SetId();
		
	void SetCustomer(Customer^ value);

	void SetPaymentMethod(String^ value);

	void SetTotal(double value);
		
	void SetItems(List<Item^>^ value);
		
	void SetEmployee(Employee^ value);
		
	void SetDate(DateTime^ value);
		
public:
	static Invoice^ invoiceInstance = gcnew Invoice();
	//Методы чтения полей класса
	int GetId();
		
	String^ GetPaymentMethod();
		
	Customer^ GetCustomer();
		
	double GetTotalPrice();
		
	List<Item^>^ GetItems();

	Employee^ GetEmployee();
		
	DateTime^ GetDate();
		

	//Конструкторы
	Invoice()
	{
		SetId();
		SetCustomer(gcnew Customer());
		SetPaymentMethod("");
		SetEmployee(gcnew Employee());
		SetDate(gcnew DateTime);
		//SetItems(items);
		SetTotal(0);
	}
	Invoice(Customer^ customer, List<Item^>^ items, Employee^ employee, double totalPrice, DateTime^ date)
	{
		SetId();
		SetCustomer(customer);
		SetItems(items);
		SetTotal(totalPrice);
		SetEmployee(employee);
		SetDate(date);
	}

	Invoice(int id, Customer^ customer, List<Item^>^ items, String^ paymentMethod, Employee^ employee, double totalPrice, DateTime^ date)
	{
		SetId(id);
		SetCustomer(customer);
		SetItems(items);
		SetPaymentMethod(paymentMethod);
		SetTotal(totalPrice);
		SetEmployee(employee);
		SetDate(date);
	}
public: static Invoice^ GetInvoice(SqlDataReader^ sqlReader);
	
public: static Invoice^ GetInvoice(int id);
	
public: static List<Invoice^>^ GetInvoices();
};
