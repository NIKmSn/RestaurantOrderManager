#pragma once
#include "Person.h"
ref class Customer :
	public Person
{
private:
	int id;
	String^ email;
	Decimal discount;
protected:
	//Методы заполнения полей класса
	void SetEmail(String^ value)
	{
		email = value;
	}

	void SetDiscount(Decimal value)
	{
		discount = value;
	}

public: 
	//Методы чтения полей класса
	int GetId()
	{
		return id;
	}
	String^ GetEmail()
	{
		return email;
	}
	Decimal GetDiscount()
	{
		return discount;
	}

	//Конструкторы
	Customer() :Person()
	{
		SetEmail("");
		SetDiscount(0);
	}
	Customer(String^ name, String^ phoneNumber, String^ email, Decimal discount) : Person(name, phoneNumber)
	{
		SetEmail(email);
		SetDiscount(discount);
	}
};

