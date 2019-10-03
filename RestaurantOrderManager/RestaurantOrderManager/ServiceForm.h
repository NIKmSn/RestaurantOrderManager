#pragma once
#include "Product.h"
#include "AddNewClientForm.h"
#include "Item.h"
#include "Order.h"
#include "Invoice.h"
#include "Item.h"
#include "Database.h"
namespace RestaurantOrderManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;	
	using namespace System::Globalization;
	
	/// <summary>
	/// Summary for Service
	/// </summary>
	public ref class Service : public System::Windows::Forms::Form
	{
		List<Item^>^ items = gcnew List<Item^>();
		double totalPrice;
		SqlConnection^ myConnection = Database::CreateConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand();
		SqlDataAdapter^ sda = Database::CreateDataAdapter();
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::Label^ lblTotalCost;
	private: System::Windows::Forms::Button^ btnCheck;

			 SqlDataReader^ sqlReader;
	public:
		Service(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Service()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgvItems;
	protected:

	protected:
	private: System::Windows::Forms::Button^ btnNewItem;
	private: System::Windows::Forms::NumericUpDown^ numQuantity;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ cbName;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cbDishType;
	private: System::Windows::Forms::Label^ lblType;
	private: System::Windows::Forms::ComboBox^ cbCustomers;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::GroupBox^ groupCustomer;
	private: System::Windows::Forms::Button^ btnNewClient;
	private: System::Windows::Forms::NumericUpDown^ numTable;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupEmployee;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ cbEmployee;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


	private: void FillCustomerCombo()
	{
		try
		{
			cbCustomers->Items->Clear();
			sqlCommand->CommandText = "SELECT * FROM Customer ORDER BY Name";
			myConnection->Open();
			sqlReader = sqlCommand->ExecuteReader();
			while (sqlReader->Read())
			{
				cbCustomers->Items->Add(sqlReader["Name"]->ToString());
			}
			if (cbCustomers->Items->Count != 0)
				cbCustomers->SelectedIndex = 0;
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Ошибка доступа к базе", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally
		{
			myConnection->Close();
		}
	}
	private: void FillDishTypeCombo()
	{
		cbName->Items->Clear();
		Product::InitDishDictionary();
		BindingSource^ bindSource = gcnew BindingSource(Product::dishDictionary, nullptr);
		cbDishType->DataSource = bindSource;
		cbDishType->DisplayMember = "Value";
		cbDishType->ValueMember = "Key";
	}
	private: void FillStaffCombo()
	{
		try
		{
			cbName->Items->Clear();
			sqlCommand->CommandText = "SELECT * FROM Employee ORDER BY Name";
			myConnection->Open();
			sqlReader = sqlCommand->ExecuteReader();
			while (sqlReader->Read())
			{
				cbEmployee->Items->Add(sqlReader["Name"]->ToString());
			}
			if (cbEmployee->Items->Count != 0)
				cbEmployee->SelectedIndex = 0;
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Ошибка доступа к базе", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally
		{
			myConnection->Close();
		}
	}
	private: void FillDishName()
	{
		try
		{
			cbName->Items->Clear();
			cbName->Text = "";
			sqlCommand->Parameters["@product_type"]->Value = cbDishType->GetItemText(cbDishType->SelectedItem);
			sqlCommand->CommandText = "SELECT * FROM Product WHERE (Type = @product_type) ORDER BY Name";
			myConnection->Open();
			sqlReader = sqlCommand->ExecuteReader();
			while (sqlReader->Read())
			{
				cbName->Items->Add(sqlReader["Name"]->ToString());
			}
			if (cbName->Items->Count != 0)
				cbName->SelectedIndex = 0;
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Ошибка доступа к базе", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally
		{
			myConnection->Close();
		}
	}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgvItems = (gcnew System::Windows::Forms::DataGridView());
			this->btnNewItem = (gcnew System::Windows::Forms::Button());
			this->numQuantity = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cbName = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbDishType = (gcnew System::Windows::Forms::ComboBox());
			this->lblType = (gcnew System::Windows::Forms::Label());
			this->cbCustomers = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupCustomer = (gcnew System::Windows::Forms::GroupBox());
			this->numTable = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnNewClient = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupEmployee = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->cbEmployee = (gcnew System::Windows::Forms::ComboBox());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->lblTotalCost = (gcnew System::Windows::Forms::Label());
			this->btnCheck = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvItems))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuantity))->BeginInit();
			this->groupCustomer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTable))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupEmployee->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgvItems
			// 
			this->dgvItems->AllowUserToAddRows = false;
			this->dgvItems->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvItems->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dgvItems->Location = System::Drawing::Point(12, 96);
			this->dgvItems->Name = L"dgvItems";
			this->dgvItems->ReadOnly = true;
			this->dgvItems->RowHeadersWidth = 51;
			this->dgvItems->RowTemplate->Height = 24;
			this->dgvItems->Size = System::Drawing::Size(484, 491);
			this->dgvItems->TabIndex = 0;
			this->dgvItems->UserDeletedRow += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &Service::DgvItems_UserDeletedRow);
			this->dgvItems->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &Service::DgvItems_UserDeletingRow);
			// 
			// btnNewItem
			// 
			this->btnNewItem->Location = System::Drawing::Point(16, 280);
			this->btnNewItem->Name = L"btnNewItem";
			this->btnNewItem->Size = System::Drawing::Size(113, 36);
			this->btnNewItem->TabIndex = 1;
			this->btnNewItem->Text = L"Добавить";
			this->btnNewItem->UseVisualStyleBackColor = true;
			this->btnNewItem->Click += gcnew System::EventHandler(this, &Service::BtnNewItem_Click);
			// 
			// numQuantity
			// 
			this->numQuantity->Location = System::Drawing::Point(111, 197);
			this->numQuantity->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->numQuantity->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numQuantity->Name = L"numQuantity";
			this->numQuantity->Size = System::Drawing::Size(69, 22);
			this->numQuantity->TabIndex = 39;
			this->numQuantity->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 197);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 17);
			this->label2->TabIndex = 38;
			this->label2->Text = L"Количество";
			// 
			// cbName
			// 
			this->cbName->FormattingEnabled = true;
			this->cbName->Location = System::Drawing::Point(95, 112);
			this->cbName->Margin = System::Windows::Forms::Padding(4);
			this->cbName->Name = L"cbName";
			this->cbName->Size = System::Drawing::Size(195, 24);
			this->cbName->TabIndex = 37;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 112);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 17);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Название";
			// 
			// cbDishType
			// 
			this->cbDishType->FormattingEnabled = true;
			this->cbDishType->Location = System::Drawing::Point(95, 37);
			this->cbDishType->Margin = System::Windows::Forms::Padding(4);
			this->cbDishType->Name = L"cbDishType";
			this->cbDishType->Size = System::Drawing::Size(195, 24);
			this->cbDishType->TabIndex = 35;
			this->cbDishType->SelectedValueChanged += gcnew System::EventHandler(this, &Service::CbDishType_SelectedValueChanged);
			// 
			// lblType
			// 
			this->lblType->AutoSize = true;
			this->lblType->Location = System::Drawing::Point(13, 37);
			this->lblType->Name = L"lblType";
			this->lblType->Size = System::Drawing::Size(33, 17);
			this->lblType->TabIndex = 34;
			this->lblType->Text = L"Тип";
			// 
			// cbCustomers
			// 
			this->cbCustomers->FormattingEnabled = true;
			this->cbCustomers->Location = System::Drawing::Point(95, 34);
			this->cbCustomers->Margin = System::Windows::Forms::Padding(4);
			this->cbCustomers->Name = L"cbCustomers";
			this->cbCustomers->Size = System::Drawing::Size(195, 24);
			this->cbCustomers->TabIndex = 41;
			this->cbCustomers->DropDown += gcnew System::EventHandler(this, &Service::CbCustomers_DropDown);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 41);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 17);
			this->label3->TabIndex = 40;
			this->label3->Text = L"Выбрать";
			// 
			// groupCustomer
			// 
			this->groupCustomer->Controls->Add(this->numTable);
			this->groupCustomer->Controls->Add(this->label4);
			this->groupCustomer->Controls->Add(this->btnNewClient);
			this->groupCustomer->Controls->Add(this->label3);
			this->groupCustomer->Controls->Add(this->cbCustomers);
			this->groupCustomer->Location = System::Drawing::Point(514, 13);
			this->groupCustomer->Name = L"groupCustomer";
			this->groupCustomer->Size = System::Drawing::Size(365, 220);
			this->groupCustomer->TabIndex = 42;
			this->groupCustomer->TabStop = false;
			this->groupCustomer->Text = L"Клиент";
			// 
			// numTable
			// 
			this->numTable->Location = System::Drawing::Point(95, 126);
			this->numTable->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numTable->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numTable->Name = L"numTable";
			this->numTable->Size = System::Drawing::Size(69, 22);
			this->numTable->TabIndex = 40;
			this->numTable->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 126);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 17);
			this->label4->TabIndex = 44;
			this->label4->Text = L"№ столика";
			// 
			// btnNewClient
			// 
			this->btnNewClient->Location = System::Drawing::Point(95, 65);
			this->btnNewClient->Name = L"btnNewClient";
			this->btnNewClient->Size = System::Drawing::Size(113, 36);
			this->btnNewClient->TabIndex = 43;
			this->btnNewClient->Text = L"Новый...";
			this->btnNewClient->UseVisualStyleBackColor = true;
			this->btnNewClient->Click += gcnew System::EventHandler(this, &Service::BtnNewClient_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lblType);
			this->groupBox1->Controls->Add(this->btnNewItem);
			this->groupBox1->Controls->Add(this->numQuantity);
			this->groupBox1->Controls->Add(this->cbDishType);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->cbName);
			this->groupBox1->Location = System::Drawing::Point(514, 239);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(365, 348);
			this->groupBox1->TabIndex = 44;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Новая позиция";
			// 
			// groupEmployee
			// 
			this->groupEmployee->Controls->Add(this->label5);
			this->groupEmployee->Controls->Add(this->cbEmployee);
			this->groupEmployee->Location = System::Drawing::Point(12, 14);
			this->groupEmployee->Name = L"groupEmployee";
			this->groupEmployee->Size = System::Drawing::Size(484, 76);
			this->groupEmployee->TabIndex = 45;
			this->groupEmployee->TabStop = false;
			this->groupEmployee->Text = L"Обслуживающий";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 40);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 17);
			this->label5->TabIndex = 45;
			this->label5->Text = L"Выбрать";
			// 
			// cbEmployee
			// 
			this->cbEmployee->FormattingEnabled = true;
			this->cbEmployee->Location = System::Drawing::Point(89, 33);
			this->cbEmployee->Margin = System::Windows::Forms::Padding(4);
			this->cbEmployee->Name = L"cbEmployee";
			this->cbEmployee->Size = System::Drawing::Size(282, 24);
			this->cbEmployee->TabIndex = 46;
			// 
			// lblTotal
			// 
			this->lblTotal->AutoSize = true;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Calibri", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblTotal->Location = System::Drawing::Point(5, 628);
			this->lblTotal->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(500, 41);
			this->lblTotal->TabIndex = 47;
			this->lblTotal->Text = L"Общая сумма заказа без скидки: ";
			// 
			// lblTotalCost
			// 
			this->lblTotalCost->AutoSize = true;
			this->lblTotalCost->Font = (gcnew System::Drawing::Font(L"Calibri", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblTotalCost->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lblTotalCost->Location = System::Drawing::Point(527, 628);
			this->lblTotalCost->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTotalCost->Name = L"lblTotalCost";
			this->lblTotalCost->Size = System::Drawing::Size(116, 46);
			this->lblTotalCost->TabIndex = 48;
			this->lblTotalCost->Text = L"0 руб.";
			// 
			// btnCheck
			// 
			this->btnCheck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnCheck->Location = System::Drawing::Point(238, 706);
			this->btnCheck->Name = L"btnCheck";
			this->btnCheck->Size = System::Drawing::Size(484, 82);
			this->btnCheck->TabIndex = 49;
			this->btnCheck->Text = L"Завершить заказ";
			this->btnCheck->UseVisualStyleBackColor = true;
			this->btnCheck->Click += gcnew System::EventHandler(this, &Service::BtnCheck_Click);
			// 
			// Service
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(898, 822);
			this->Controls->Add(this->btnCheck);
			this->Controls->Add(this->lblTotalCost);
			this->Controls->Add(this->lblTotal);
			this->Controls->Add(this->groupEmployee);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupCustomer);
			this->Controls->Add(this->dgvItems);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Service";
			this->Text = L"Service";
			this->Load += gcnew System::EventHandler(this, &Service::Service_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvItems))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuantity))->EndInit();
			this->groupCustomer->ResumeLayout(false);
			this->groupCustomer->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTable))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupEmployee->ResumeLayout(false);
			this->groupEmployee->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Service_Load(System::Object^ sender, System::EventArgs^ e)
	{
		numQuantity->Maximum = 999;
		numQuantity->Minimum = 1;
		numTable->Maximum = 50;
		numTable->Minimum = 1;
		try
		{
			sqlCommand->Connection = myConnection;
			sqlCommand->Parameters->AddWithValue("@product_type", "");
			sqlCommand->Parameters->AddWithValue("@product_name", "");
			sqlCommand->Parameters->AddWithValue("@item_invoiceId", "");
			sqlCommand->Parameters->AddWithValue("@item_productId", "");
			sqlCommand->Parameters->AddWithValue("@item_quantity", "");
			FillDishTypeCombo();
			FillDishName();
			FillCustomerCombo();
			FillStaffCombo();
			items->Clear();
			dgvItems->Columns->Add("name", "Название");
			dgvItems->Columns->Add("quantity", "Количество");
			dgvItems->Columns->Add("price", "Цена");

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}			
private: System::Void CbDishType_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) 
{
	FillDishName();
}
private: System::Void BtnNewItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	try
	{
		Item^ newItem = gcnew Item(Product::GetProduct(cbName->GetItemText(cbName->SelectedItem)), Convert::ToInt32(numQuantity->Value));
		items->Add(newItem);
		dgvItems->Rows->Add(newItem->GetProduct()->GetName()->ToString(), newItem->GetQuantity().ToString(), newItem->GetCost().ToString("F2", CultureInfo::GetCultureInfo("ru-RU")));
		totalPrice += Convert::ToDouble(newItem->GetCost());
		lblTotalCost->Text = totalPrice.ToString("G", CultureInfo::GetCultureInfo("ru-RU")) + " руб.";
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Ошибка доступа к базе", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally
	{
		myConnection->Close();
	}
}
private: System::Void BtnNewClient_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Form^ addingForm = Application::OpenForms["AddNewClientForm"];
	if (addingForm != nullptr)
		addingForm->BringToFront();
	else
	{
		AddNewClientForm^ addingForm = gcnew AddNewClientForm();
		addingForm->Show();
	}
}
private: System::Void CbCustomers_DropDown(System::Object^ sender, System::EventArgs^ e) 
{
	FillCustomerCombo();
}
private: System::Void BtnCheck_Click(System::Object^ sender, System::EventArgs^ e) 
{
	try
	{
		SqlCommand^ sqlCommand = Database::CreateCommand();
		sqlCommand->Connection = myConnection;
		Customer^ customer = Customer::GetCustomerByName(cbCustomers->GetItemText(cbCustomers->SelectedItem));
		Employee^ employee = Employee::GetEmployeeByName(cbEmployee->GetItemText(cbEmployee->SelectedItem));
		Invoice^ invoice = gcnew Invoice(customer, items, employee, totalPrice, DateTime::Now);
		for each (Item ^ item in items)
		{
			item->SetInvoice(invoice);
		}
		Order^ order = gcnew Order(customer, Convert::ToInt32(numTable->Value), invoice, DateTime::Now);
		totalPrice = invoice->GetCustomer()->CalcDiscount(totalPrice);
		myConnection->Open();

		sqlCommand->Parameters->Add("@customerId", System::Data::DbType::Int32)->Value = invoice->GetCustomer()->GetId();
		sqlCommand->Parameters->Add("@employeeId", System::Data::DbType::Int32)->Value = invoice->GetEmployee()->GetId();
		sqlCommand->Parameters->Add("@invoiceDate", System::Data::DbType::DateTime)->Value = invoice->GetDate();
		sqlCommand->CommandText = "INSERT INTO Invoice (CustomerId, EmployeeId, Date) VALUES (@customerId, @employeeId, @invoiceDate)";
		sqlCommand->ExecuteNonQuery();

		for each (Item^ item in items)
		{
			SqlCommand^ sqlCommand = Database::CreateCommand("INSERT INTO Item (InvoiceId, ProductId, Quantity) VALUES (@invoiceId, @productId, @quantity)", myConnection);
			sqlCommand->Parameters->Add("@invoiceId", System::Data::DbType::Int32)->Value = invoice->GetId();
			sqlCommand->Parameters->Add("@productId", System::Data::DbType::Int32)->Value = item->GetProduct()->GetId();
			sqlCommand->Parameters->Add("@quantity", System::Data::DbType::Int32)->Value = item->GetQuantity();
			sqlCommand->ExecuteNonQuery();
		}
		sqlCommand->Parameters->Add("@tableId", System::Data::DbType::Int32)->Value = order->GetTableId();
		sqlCommand->Parameters->Add("@invoiceId", System::Data::DbType::Int32)->Value = invoice->GetId();
		sqlCommand->CommandText = "INSERT INTO Orders (CustomerId, TableId, InvoiceId, Date) VALUES (@customerId, @tableId, @invoiceId, @invoiceDate)";
		sqlCommand->ExecuteNonQuery();
		MessageBox::Show("Заказ успешно обработан.\nИтоговая сумма заказа с учетом скидки клиента - " + totalPrice.ToString("G", CultureInfo::GetCultureInfo("ru-RU")) + " руб.", "Успех", MessageBoxButtons::OK);
		Close();
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
//Обработка события удаления позиции (строки) пользователем
private: System::Void DgvItems_UserDeletingRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^ e) 
{
	if ( !e->Row->IsNewRow)
	{
		System::Windows::Forms::DialogResult response = MessageBox::Show("Вы уверены?", "Удаление позиции",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question,
			MessageBoxDefaultButton::Button2);
		if (response == System::Windows::Forms::DialogResult::Yes)
		{
			if (dgvItems->SelectedRows->Count > 1)
			{
				for (int i = 0; i < dgvItems->SelectedRows->Count; i++)
				{
					dgvItems->Rows->RemoveAt(i);
					totalPrice -= Convert::ToDouble(dgvItems->Rows[i]->Cells[2]->Value);
				}
			}
			lblTotalCost->Text = totalPrice.ToString("G", CultureInfo::GetCultureInfo("ru-RU")) + " руб.";
		}
		if (response == System::Windows::Forms::DialogResult::No)
			e->Cancel = true;
	}
}
private: System::Void DgvItems_UserDeletedRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e) 
{
	totalPrice -= Convert::ToDouble(e->Row->Cells[2]->Value);
	lblTotalCost->Text = totalPrice.ToString("G", CultureInfo::GetCultureInfo("ru-RU")) + " руб.";
}
};
}
