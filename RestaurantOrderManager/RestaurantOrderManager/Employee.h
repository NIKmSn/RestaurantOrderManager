#pragma once
#include "Person.h"
#include "Database.h"
ref class Employee :
	public Person
{
	private:
		//Поля
		int id;
		String^ title;
		Decimal salary;
		String^ photo;
private: void SetId(int value)
{
	id = value;
}
	protected:
		//Методы заполнения полей класса
		void SetId()
		{
			SqlConnection^ conn = Database::CreateConnection();
			SqlCommand^ sqlCommand = Database::CreateCommand("SELECT MAX(Id) FROM Employee", conn);
			conn->Open();
			id = (int)sqlCommand->ExecuteScalar();
			conn->Close();
		}
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
public: static Employee^ GetEmployee(int id)
{
	SqlConnection^ conn = Database::CreateOpenConnection();
	SqlCommand^ sqlCommand = Database::CreateStoredProcedureCommand("SELECT * FROM Employee WHERE Id = @id", conn);
	sqlCommand->Parameters->Add("@id", SqlDbType::Int)->Value = 1;
	SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();
	conn->Close();

	if (sqlReader->Read())
	{
		Employee^ employee = gcnew Employee();
		employee->SetId(id);
		employee->SetName(sqlReader["Name"]->ToString());
		employee->SetPhoneNumber(sqlReader["PhoneNumber"]->ToString());
		employee->SetTitle(sqlReader["Title"]->ToString());
		employee->SetSalary(Convert::ToDecimal(sqlReader["Salary"]));
		employee->SetPhoto(sqlReader["Photo"]->ToString());
		return employee;
	}
	return nullptr;
}
};

