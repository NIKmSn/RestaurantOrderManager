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
	//������ ���������� ����� ������
	void SetEmail(String^ value)
	{
		email = value;
	}

	void SetDiscount(Decimal value)
	{
		discount = value;
	}

public: 
	//������ ������ ����� ������
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

	//������������
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

