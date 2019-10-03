#include "Invoice.h"
#include "Item.h"
void Invoice::SetId(int value)
{
	id = value;
}

void Invoice::SetId()
{
	SqlConnection^ conn = Database::CreateConnection();
	SqlCommand^ sqlCommand = Database::CreateCommand("SELECT MAX(Id) FROM Invoice", conn);
	conn->Open();
	id = (int)sqlCommand->ExecuteScalar() + 1;
	conn->Close();
}

void Invoice::SetCustomer(Customer^ value)
{
	customer = value;
}

void Invoice::SetPaymentMethod(String^ value)
{
	paymentMethod = value;
}

void Invoice::SetTotal(double value)
{
	totalPrice = value;
}

void Invoice::SetItems(List<Item^>^ value)
{
	if (value == nullptr)
	{
		throw gcnew Exception("There is no items");
	}
	else
	{
		for each (Item ^ item in value)
		{
			items->Add(item);
		}
	}
}

void Invoice::SetEmployee(Employee^ value)
{
	employee = value;
}

void Invoice::SetDate(DateTime^ value)
{
	date = value;
}

int Invoice::GetId()
{
	return id;
}

String^ Invoice::GetPaymentMethod()
{
	return paymentMethod;
}

Customer^ Invoice::GetCustomer()
{
	return customer;
}

double Invoice::GetTotalPrice()
{
	return totalPrice;
}

List<Item^>^ Invoice::GetItems()
{
	List<Item^>^ result;
	for each (Item ^ item in items)
	{
		result->Add(item);
	}
	return result;
}

Employee^ Invoice::GetEmployee()
{
	return employee;
}

DateTime^ Invoice::GetDate()
{
	return date;
}

Invoice^ Invoice::GetInvoice(SqlDataReader^ sqlReader)
{
	if (sqlReader->Read())
	{
		Invoice^ invoice = gcnew Invoice();
		invoice->SetId(Convert::ToInt32(sqlReader["Id"]));
		invoice->SetCustomer(Customer::GetCustomer(Convert::ToInt32(sqlReader["CustomerId"])));
		List<Item^>^ items = Item::GetItemsOfInvoice(Convert::ToInt32(sqlReader["Id"]));
		invoice->SetItems(items);
		double total = 0;
		for each (Item ^ item in items)
		{
			total += Convert::ToDouble(item->GetProduct()->GetPrice() * (1 - invoice->GetCustomer()->GetDiscount()));
		}
		invoice->SetTotal(total);
		invoice->SetEmployee(Employee::GetEmployee(Convert::ToInt32(sqlReader["EmployeeId"])));
		invoice->SetDate(Convert::ToDateTime(sqlReader["Date"]));
		return invoice;
	}
	return nullptr;
}

Invoice^ Invoice::GetInvoice(int id)
{
	SqlConnection^ conn = Database::CreateOpenConnection();
	SqlCommand^ sqlCommand = Database::CreateCommand("SELECT * FROM Invoice WHERE Id = @id", conn);
	sqlCommand->Parameters->Add("@id", SqlDbType::Int)->Value = 1;
	SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();
	if (sqlReader->Read())
	{
		return GetInvoice(sqlReader);
	}
	conn->Close();
	return nullptr;
}

List<Invoice^>^ Invoice::GetInvoices()
{
	List<Invoice^>^ invoices;
	SqlConnection^ conn = Database::CreateOpenConnection();
	SqlCommand^ sqlCommand = Database::CreateCommand("SELECT * FROM Invoice", conn);
	SqlDataReader^ sqlReader = sqlCommand->ExecuteReader();
	while (sqlReader->Read())
	{
		invoices->Add(GetInvoice(sqlReader));
	}
	conn->Close();
	return invoices;
}