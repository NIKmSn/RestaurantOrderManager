#pragma once
#include "Product.h"
namespace RestaurantOrderManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for Service
	/// </summary>
	public ref class Service : public System::Windows::Forms::Form
	{
		String^ connStr = L"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Programs\\repos\\RestaurantOrderManager\\RestaurantOrderManager\\RestaurantDatabase\\Restaurant.mdf;Integrated Security=True;Connect Timeout=30";
		SqlConnection^ myConnection;
		SqlCommand^ sqlCommand = gcnew SqlCommand();
		SqlDataAdapter^ sda = gcnew SqlDataAdapter();
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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
			sqlCommand->CommandText = "SELECT * FROM Customer";
			myConnection->Open();
			sqlReader = sqlCommand->ExecuteReader();
			while (sqlReader->Read())
			{
				cbCustomers->Items->Add(sqlReader["Name"]->ToString());
			}
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
			sqlCommand->CommandText = "SELECT * FROM Employee";
			myConnection->Open();
			sqlReader = sqlCommand->ExecuteReader();
			while (sqlReader->Read())
			{
				cbCustomers->Items->Add(sqlReader["Name"]->ToString());
			}
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
			//TODO: Считать значение KeyValuePair
			String^ str = cbDishType->SelectedValue->ToString();
			sqlCommand->Parameters["@type"]->Value = cbDishType->DisplayMember;
			sqlCommand->CommandText = "SELECT * FROM Product WHERE Type = @type";
			myConnection->Open();
			sqlReader = sqlCommand->ExecuteReader();
			while (sqlReader->Read())
			{
				cbCustomers->Items->Add(sqlReader["Name"]->ToString());
			}
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuantity))->BeginInit();
			this->groupCustomer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTable))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupEmployee->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 96);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(484, 491);
			this->dataGridView1->TabIndex = 0;
			// 
			// btnNewItem
			// 
			this->btnNewItem->Location = System::Drawing::Point(16, 280);
			this->btnNewItem->Name = L"btnNewItem";
			this->btnNewItem->Size = System::Drawing::Size(113, 36);
			this->btnNewItem->TabIndex = 1;
			this->btnNewItem->Text = L"Добавить";
			this->btnNewItem->UseVisualStyleBackColor = true;
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
			this->cbDishType->SelectedIndexChanged += gcnew System::EventHandler(this, &Service::CbDishType_SelectedIndexChanged);
			this->cbDishType->SelectionChangeCommitted += gcnew System::EventHandler(this, &Service::CbDishType_SelectionChangeCommitted);
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
			// Service
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(898, 822);
			this->Controls->Add(this->groupEmployee);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupCustomer);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Service";
			this->Text = L"Service";
			this->Load += gcnew System::EventHandler(this, &Service::Service_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuantity))->EndInit();
			this->groupCustomer->ResumeLayout(false);
			this->groupCustomer->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTable))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupEmployee->ResumeLayout(false);
			this->groupEmployee->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Service_Load(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			myConnection = gcnew SqlConnection(connStr);
			sqlCommand->Connection = myConnection;
			sqlCommand->Parameters->AddWithValue("@type", "");
			FillDishTypeCombo();
			FillCustomerCombo();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
			 
private: System::Void CbDishType_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) 
{
	
}
private: System::Void CbDishType_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	FillDishName();
}
private: System::Void CbDishType_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) 
{
	FillDishName();
}
};
}
