#pragma once
#include "Database.h"
#include <map>
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


ref class Product
{
private: static Dictionary<int, Product^> productCache;
private:
	//Поля
	int id;
	String^ dishType;
	String^ name;
	String^ description;
	Decimal price;
	String^ photo;
	
	//Принудительно присвоить значение полю ID (для создания экземпляра при чтении из БД)
	private: void SetId(int value)
	{
		id = value;
	}


protected:
	//Методы заполнения полей класса
	void SetId()
	{
		SqlConnection^ conn = Database::CreateConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT MAX(Id) FROM Product", conn);
		conn->Open();
		id = (int)sqlCommand->ExecuteScalar();
		conn->Close();
	}
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
	void SetDishType(String^ type)
	{
		if (dishDictionary->ContainsValue(type))
		{
			dishType = type;
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
			dishDictionary->Add((int)DishType::NotStated, "Не выбрано");
		}
		if (!dishDictionary->TryGetValue((int)DishType::Starters, parseString))
		{
			dishDictionary->Add((int)DishType::Starters, "Закуски");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::Salads, parseString))
		{
			dishDictionary->Add((int)DishType::Salads, "Салаты");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::Soups, parseString))
		{
			dishDictionary->Add((int)DishType::Soups, "Супы");
		}
		if (!dishDictionary->TryGetValue((int)DishType::Main, parseString))
		{
			dishDictionary->Add((int)DishType::Main, "Горячие блюда");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::Baking, parseString))
		{
			dishDictionary->Add((int)DishType::Baking, "Выпечка");
		}
		if (!dishDictionary->TryGetValue((int)DishType::Desserts, parseString))
		{
			dishDictionary->Add((int)DishType::Desserts, "Десерты");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::SoftDrinks, parseString))
		{
			dishDictionary->Add((int)DishType::SoftDrinks, "Безалкогольные напитки");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::HotDrinks, parseString))
		{
			dishDictionary->Add((int)DishType::HotDrinks, "Горячие напитки");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::Alcoholic, parseString))
		{
			dishDictionary->Add((int)DishType::Alcoholic, "Алкогольные напитки");
		}		
		if (!dishDictionary->TryGetValue((int)DishType::Other, parseString))
		{
			dishDictionary->Add((int)DishType::Other, "Другое");
		}
	}
	static Product^ GetProduct(String^ name)
	{
		SqlConnection^ conn = Database::CreateOpenConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT * FROM Product WHERE Name = @name", conn);
		sqlCommand->Parameters->Add("@name", SqlDbType::NVarChar)->Value = name;
		SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();
		
		if (sqlReader->Read())
		{
			Product^ product = gcnew Product(Convert::ToInt32(sqlReader["Id"]), sqlReader["Type"]->ToString(), name, sqlReader["Description"]->ToString(), Convert::ToDecimal(sqlReader["Price"]), sqlReader["Picture"]->ToString());
			return product;
		}
		conn->Close();
		return nullptr;

	}
	static Product^ GetProduct(int id)
	{
		if (productCache.ContainsKey(id))
		{
			return productCache[id];
		}
		SqlConnection^ conn = Database::CreateOpenConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand("SELECT * FROM Product WHERE Id = @id", conn);
		sqlCommand->Parameters->Add("@id", SqlDbType::Int)->Value = 1;
		SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();

		if (sqlReader->Read())
		{
			Product^ product = gcnew Product(id, Convert::ToInt32(sqlReader["Type"]), sqlReader["Name"]->ToString(), sqlReader["Description"]->ToString(), Convert::ToDecimal(sqlReader["Price"]), sqlReader["Picture"]->ToString());
			productCache.Add(id, product);
			return product;
		}
		conn->Close();
		return nullptr;

	}

	//Методы чтения полей класса
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

	//Конструкторы
	Product() 
	{
		SetId(0);
		SetDishType(0);
		SetName("");
		SetDescription("");
		SetPrice(0);
		SetPhoto("");
	}
	Product(int dishType, String^ name, String^ description, Decimal price, String^ photo)
	{
		SetId();
		SetDishType(dishType);
		SetName(name);
		SetDescription(description);
		SetPrice(price);
		SetPhoto(photo);
	}
	Product(int id, int dishType, String^ name, String^ description, Decimal price, String^ photo)
	{
		SetId(id);
		SetDishType(dishType);
		SetName(name);
		SetDescription(description);
		SetPrice(price);
		SetPhoto(photo);
	}

	Product(int id, String^ dishType, String^ name, String^ description, Decimal price, String^ photo)
	{
		SetId(id);
		SetDishType(dishType);
		SetName(name);
		SetDescription(description);
		SetPrice(price);
		SetPhoto(photo);
	}

};

