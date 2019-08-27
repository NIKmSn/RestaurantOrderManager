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
	//Методы заполнения и чтения полей класса
	int GetId()
	{
		return id;
	}

	String^ GetEmail()
	{
		return email;
	}
	void SetEmail(String^ value)
	{
		email = value;
	}

	Decimal GetDiscount()
	{
		return discount;
	}
	void SetDiscount(Decimal value)
	{
		discount = value;
	}

public: 
	//Конструкторы
	Customer() :Person()
	{
		SetEmail("");
		SetDiscount(0);
	}
	Customer(String^ email, Decimal discount)
	{
		SetEmail(email);
		SetDiscount(discount);
	}
};

