#pragma once

#include <map>
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
using namespace System::Collections::Generic;

ref class Product
{
private:
	//����
	int id;
	String^ dishType;
	String^ name;
	String^ description;
	Decimal price;
	String^ photo;
	


protected:
	//������ ���������� ����� ������
	void SetName(String^ value)
	{
		name = value;
	}
	void SetDescription(String^ value)
	{
		description = value;
	}
	void SetPrice(Decimal value)
	{
		price = value;
	}
	void SetPhoto(String^ value)
	{
		photo = value;
	}
	void SetDishType(int key)
	{
		if (dishDictionary->ContainsKey(key))
		{
			dishType = dishDictionary[key];
		}
		else 
		{
			dishType = dishDictionary[0];
		}
	}
public:	
	enum class DishType
	{
		NotStated = 0,
		Starters = 1,
		Salads = 2,
		Soups = 3,
		Main = 4,
		Baking = 5,
		Desserts = 6,
		SoftDrinks = 7,
		HotDrinks = 8,
		Alcoholic = 9,
		Other = 10,
	};
	static Dictionary<int, String^>^ dishDictionary = gcnew Dictionary<int, String^>();
	static void InitDishDictionary()
	{
		String^ parseString;
		if (!dishDictionary->TryGetValue((int)DishType::NotStated, parseString))
		{
			dishDictionary->Add((int)DishType::NotStated, "�� �������");
		}
		if (!dishDictionary->TryGetValue((int)DishType::Starters, parseString))
		{
			dishDictionary->Add((int)DishType::Starters, "�������");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::Salads, parseString))
		{
			dishDictionary->Add((int)DishType::Salads, "������");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::Soups, parseString))
		{
			dishDictionary->Add((int)DishType::Soups, "����");
		}
		if (!dishDictionary->TryGetValue((int)DishType::Main, parseString))
		{
			dishDictionary->Add((int)DishType::Main, "������� �����");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::Baking, parseString))
		{
			dishDictionary->Add((int)DishType::Baking, "�������");
		}
		if (!dishDictionary->TryGetValue((int)DishType::Desserts, parseString))
		{
			dishDictionary->Add((int)DishType::Desserts, "�������");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::SoftDrinks, parseString))
		{
			dishDictionary->Add((int)DishType::SoftDrinks, "�������������� �������");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::HotDrinks, parseString))
		{
			dishDictionary->Add((int)DishType::HotDrinks, "������� �������");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::Alcoholic, parseString))
		{
			dishDictionary->Add((int)DishType::Alcoholic, "����������� �������");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::Other, parseString))
		{
			dishDictionary->Add((int)DishType::Other, "������");
		}
	}


	//������ ������ ����� ������
	int GetId()
	{
		return id;
	}
	String^ GetDishType()
	{
		return dishType;
	}
	String^ GetName()
	{
		return name;
	}
	String^ GetDescription()
	{
		return description;
	}
	Decimal GetPrice()
	{
		return price;
	}
	String^ GetPhoto()
	{
		return photo;
	}

	//������������
	Product() 
	{
		SetDishType(0);
		SetName("");
		SetDescription("");
		SetPrice(0);
		SetPhoto("");
	}
	Product(int dishType, String^ name, String^ description, Decimal price, String^ photo)
	{
		SetDishType(dishType);
		SetName(name);
		SetDescription(description);
		SetPrice(price);
		SetPhoto(photo);
	}
};

