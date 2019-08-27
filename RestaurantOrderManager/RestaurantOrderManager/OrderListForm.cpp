#include "OrderListForm.h"

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


namespace RestaurantOrderManager
{
	void OrderListForm::ReadOrderData()
	{
		String^ connStr = L"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Programs\\repos\\RestaurantOrderManager\\RestaurantOrderManager\\RestaurantDatabase\\Restaurant.mdf;Integrated Security=True;Connect Timeout=30";
		SqlConnection^ myConnection = gcnew SqlConnection(connStr);
		SqlCommand^ sqlCommand = gcnew SqlCommand();
		sqlCommand->Connection = myConnection;
		sqlCommand->CommandText = "SELECT Id AS 'Номер заказа', CustomerId AS 'ID Клиента', TableId AS 'Столик', InvoiceId AS 'Номер чека', Date AS 'Дата' FROM Orders";
		try
		{
			myConnection->Open();
			SqlDataAdapter^ sda = gcnew SqlDataAdapter();
			sda->SelectCommand = sqlCommand;
			DataTable^ dbDataSet = gcnew DataTable();
			sda->Fill(dbDataSet);
			BindingSource^ bindSource = gcnew BindingSource();
			bindSource->DataSource = dbDataSet;
			dgvOrderList->DataSource = bindSource;
			sda->Update(dbDataSet);
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally
		{
			myConnection->Close();
		}
	}
}