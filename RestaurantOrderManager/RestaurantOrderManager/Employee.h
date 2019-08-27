#pragma once
#include "Person.h"
ref class Employee :
	public Person
{
	private:
		//Поля
		int id;
		String^ title;
		Decimal salary;
		String^ photo;
	protected:
		//Методы заполнения полей класса
		void SetTitle(String^ value)
		{
			title = value;
		}
		void SetSalary(Decimal value)
		{
			salary = value;
		}
		void SetPhoto(String^ value)
		{
			photo = value;
		}

	public:
		//Методы чтения полей класса
		int GetId()
		{
			return id;
		}
		String^ GetTitle()
		{
			return title;
		}
		Decimal GetSalary()
		{
			return salary;
		}
		String^ GetPhoto()
		{
			return photo;
		}

		//Конструкторы
		Employee() :Person()
		{
			SetTitle("");
			SetSalary(0);
			SetPhoto("");
		}
		Employee(String^ name, String^ phoneNumber, String^ title, Decimal salary, String^ photo): Person(name, phoneNumber)
		{
			SetTitle(title);
			SetSalary(salary);
			SetPhoto(photo);
		}

};

