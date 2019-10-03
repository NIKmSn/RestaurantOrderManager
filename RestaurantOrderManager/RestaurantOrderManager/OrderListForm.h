#pragma once
namespace RestaurantOrderManager {

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

	/// <summary>
	/// Summary for OrderListForm
	/// </summary>
	public ref class OrderListForm : public System::Windows::Forms::Form
	{
	public:
		void ReadOrderData();
		OrderListForm(void)
		{
			InitializeComponent();
			ReadOrderData();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OrderListForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		void SearchOrderData()
		{
			String^ connStr = L"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Programs\\repos\\RestaurantOrderManager\\RestaurantOrderManager\\RestaurantDatabase\\Restaurant.mdf;Integrated Security=True;Connect Timeout=30";
			SqlConnection^ myConnection = gcnew SqlConnection(connStr);
			SqlCommand^ sqlCommand = gcnew SqlCommand();
			sqlCommand->Connection = myConnection;
			if (tbSearchId->Enabled)
			{
				sqlCommand->Parameters->AddWithValue("@id", tbSearchId->Text);
			}
			else
			{
				sqlCommand->Parameters->AddWithValue("@id", System::DBNull::Value);
			}

			if (tbSearchCustomerId->Enabled)
			{
				sqlCommand->Parameters->AddWithValue("@customerId", tbSearchCustomerId->Text);
			}
			else
			{
				sqlCommand->Parameters->AddWithValue("@customerId", System::DBNull::Value);
			}

			if (tbSearchTable->Enabled)
			{
				sqlCommand->Parameters->AddWithValue("@table", tbSearchTable->Text);
			}
			else
			{
				sqlCommand->Parameters->AddWithValue("@table", System::DBNull::Value);
			}

			if (tbSearchInvoice->Enabled)
			{
				sqlCommand->Parameters->AddWithValue("@invoiceId", tbSearchInvoice->Text);
			}
			else
			{
				sqlCommand->Parameters->AddWithValue("@invoiceId", System::DBNull::Value);
			}

			if (dtPicker->Checked)
			{
				sqlCommand->Parameters->AddWithValue("@date",System::Convert::ToDateTime(dtPicker->Value.ToString("dd.MM.yyyy  HH:mm:ss")));
			}
			else
			{
				sqlCommand->Parameters->AddWithValue("@date", System::DBNull::Value);
			}
			sqlCommand->CommandText = "SELECT Id AS 'Номер заказа', CustomerId AS 'ID Клиента', TableId AS 'Столик', InvoiceId AS 'Номер чека', Date AS 'Дата' FROM Orders WHERE (@id IS NULL OR Id = @id) AND (@customerId IS NULL OR CustomerId = @customerId) AND (@table IS NULL OR TableId = @table) AND (@invoiceId IS NULL OR InvoiceId = @invoiceId) AND (@date IS NULL OR Date = @date)";
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
				MessageBox::Show(e->Message, "Ошибка поиска", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally
			{
				myConnection->Close();
			}

		}


	private: System::Windows::Forms::DataGridView^ dgvOrderList;
	private: System::Windows::Forms::Label^ lblSearch;
	private: System::Windows::Forms::CheckBox^ cbSearchId;
	private: System::Windows::Forms::CheckBox^ cbSearchCustomerId;
	private: System::Windows::Forms::CheckBox^ cbSearchTable;
	private: System::Windows::Forms::CheckBox^ cbSearchInvoice;

	private: System::Windows::Forms::TextBox^ tbSearchId;
	private: System::Windows::Forms::TextBox^ tbSearchCustomerId;
	private: System::Windows::Forms::TextBox^ tbSearchTable;
	private: System::Windows::Forms::TextBox^ tbSearchInvoice;

	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::DateTimePicker^ dtPicker;
	private: System::Windows::Forms::Label^ lblSearchDate;









	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OrderListForm::typeid));
			this->dgvOrderList = (gcnew System::Windows::Forms::DataGridView());
			this->lblSearch = (gcnew System::Windows::Forms::Label());
			this->cbSearchId = (gcnew System::Windows::Forms::CheckBox());
			this->cbSearchCustomerId = (gcnew System::Windows::Forms::CheckBox());
			this->cbSearchTable = (gcnew System::Windows::Forms::CheckBox());
			this->cbSearchInvoice = (gcnew System::Windows::Forms::CheckBox());
			this->tbSearchId = (gcnew System::Windows::Forms::TextBox());
			this->tbSearchCustomerId = (gcnew System::Windows::Forms::TextBox());
			this->tbSearchTable = (gcnew System::Windows::Forms::TextBox());
			this->tbSearchInvoice = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->dtPicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblSearchDate = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvOrderList))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvOrderList
			// 
			this->dgvOrderList->AllowUserToAddRows = false;
			this->dgvOrderList->AllowUserToDeleteRows = false;
			this->dgvOrderList->AllowUserToOrderColumns = true;
			this->dgvOrderList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgvOrderList->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvOrderList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvOrderList->Location = System::Drawing::Point(13, 130);
			this->dgvOrderList->Name = L"dgvOrderList";
			this->dgvOrderList->ReadOnly = true;
			this->dgvOrderList->Size = System::Drawing::Size(571, 355);
			this->dgvOrderList->TabIndex = 0;
			// 
			// lblSearch
			// 
			this->lblSearch->AutoSize = true;
			this->lblSearch->Location = System::Drawing::Point(14, 17);
			this->lblSearch->Name = L"lblSearch";
			this->lblSearch->Size = System::Drawing::Size(57, 13);
			this->lblSearch->TabIndex = 1;
			this->lblSearch->Text = L"Поиск по:";
			// 
			// cbSearchId
			// 
			this->cbSearchId->AutoSize = true;
			this->cbSearchId->Location = System::Drawing::Point(77, 16);
			this->cbSearchId->Name = L"cbSearchId";
			this->cbSearchId->Size = System::Drawing::Size(99, 17);
			this->cbSearchId->TabIndex = 2;
			this->cbSearchId->Text = L"Номер заказа";
			this->cbSearchId->UseVisualStyleBackColor = true;
			this->cbSearchId->CheckedChanged += gcnew System::EventHandler(this, &OrderListForm::CbSearchId_CheckedChanged);
			// 
			// cbSearchCustomerId
			// 
			this->cbSearchCustomerId->AutoSize = true;
			this->cbSearchCustomerId->Location = System::Drawing::Point(77, 42);
			this->cbSearchCustomerId->Name = L"cbSearchCustomerId";
			this->cbSearchCustomerId->Size = System::Drawing::Size(82, 17);
			this->cbSearchCustomerId->TabIndex = 3;
			this->cbSearchCustomerId->Text = L"ID Клиента";
			this->cbSearchCustomerId->UseVisualStyleBackColor = true;
			this->cbSearchCustomerId->CheckedChanged += gcnew System::EventHandler(this, &OrderListForm::CbSearchCustomerId_CheckedChanged);
			// 
			// cbSearchTable
			// 
			this->cbSearchTable->AutoSize = true;
			this->cbSearchTable->Location = System::Drawing::Point(77, 68);
			this->cbSearchTable->Name = L"cbSearchTable";
			this->cbSearchTable->Size = System::Drawing::Size(62, 17);
			this->cbSearchTable->TabIndex = 4;
			this->cbSearchTable->Text = L"Столик";
			this->cbSearchTable->UseVisualStyleBackColor = true;
			this->cbSearchTable->CheckedChanged += gcnew System::EventHandler(this, &OrderListForm::CbSearchTable_CheckedChanged);
			// 
			// cbSearchInvoice
			// 
			this->cbSearchInvoice->AutoSize = true;
			this->cbSearchInvoice->Location = System::Drawing::Point(356, 13);
			this->cbSearchInvoice->Name = L"cbSearchInvoice";
			this->cbSearchInvoice->Size = System::Drawing::Size(86, 17);
			this->cbSearchInvoice->TabIndex = 5;
			this->cbSearchInvoice->Text = L"Номер чека";
			this->cbSearchInvoice->UseVisualStyleBackColor = true;
			this->cbSearchInvoice->CheckedChanged += gcnew System::EventHandler(this, &OrderListForm::CbSearchInvoice_CheckedChanged);
			// 
			// tbSearchId
			// 
			this->tbSearchId->Enabled = false;
			this->tbSearchId->Location = System::Drawing::Point(182, 13);
			this->tbSearchId->Name = L"tbSearchId";
			this->tbSearchId->Size = System::Drawing::Size(100, 20);
			this->tbSearchId->TabIndex = 7;
			// 
			// tbSearchCustomerId
			// 
			this->tbSearchCustomerId->Enabled = false;
			this->tbSearchCustomerId->Location = System::Drawing::Point(182, 39);
			this->tbSearchCustomerId->Name = L"tbSearchCustomerId";
			this->tbSearchCustomerId->Size = System::Drawing::Size(100, 20);
			this->tbSearchCustomerId->TabIndex = 8;
			// 
			// tbSearchTable
			// 
			this->tbSearchTable->Enabled = false;
			this->tbSearchTable->Location = System::Drawing::Point(182, 65);
			this->tbSearchTable->Name = L"tbSearchTable";
			this->tbSearchTable->Size = System::Drawing::Size(100, 20);
			this->tbSearchTable->TabIndex = 9;
			// 
			// tbSearchInvoice
			// 
			this->tbSearchInvoice->Enabled = false;
			this->tbSearchInvoice->Location = System::Drawing::Point(442, 13);
			this->tbSearchInvoice->Name = L"tbSearchInvoice";
			this->tbSearchInvoice->Size = System::Drawing::Size(123, 20);
			this->tbSearchInvoice->TabIndex = 10;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(356, 68);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(209, 29);
			this->btnSearch->TabIndex = 12;
			this->btnSearch->Text = L"Найти";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &OrderListForm::BtnSearch_Click);
			// 
			// dtPicker
			// 
			this->dtPicker->AllowDrop = true;
			this->dtPicker->Checked = false;
			this->dtPicker->CustomFormat = L"dd.MM.yyyy  HH:mm:ss";
			this->dtPicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtPicker->Location = System::Drawing::Point(400, 42);
			this->dtPicker->Name = L"dtPicker";
			this->dtPicker->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->dtPicker->ShowCheckBox = true;
			this->dtPicker->Size = System::Drawing::Size(165, 20);
			this->dtPicker->TabIndex = 13;
			// 
			// lblSearchDate
			// 
			this->lblSearchDate->AutoSize = true;
			this->lblSearchDate->Location = System::Drawing::Point(353, 42);
			this->lblSearchDate->Name = L"lblSearchDate";
			this->lblSearchDate->Size = System::Drawing::Size(33, 13);
			this->lblSearchDate->TabIndex = 14;
			this->lblSearchDate->Text = L"Дата";
			// 
			// OrderListForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 497);
			this->Controls->Add(this->lblSearchDate);
			this->Controls->Add(this->dtPicker);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->tbSearchInvoice);
			this->Controls->Add(this->tbSearchTable);
			this->Controls->Add(this->tbSearchCustomerId);
			this->Controls->Add(this->tbSearchId);
			this->Controls->Add(this->cbSearchInvoice);
			this->Controls->Add(this->cbSearchTable);
			this->Controls->Add(this->cbSearchCustomerId);
			this->Controls->Add(this->cbSearchId);
			this->Controls->Add(this->lblSearch);
			this->Controls->Add(this->dgvOrderList);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"OrderListForm";
			this->Text = L"Список заказов";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvOrderList))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void CbSearchId_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	if (cbSearchId->Checked)
	{
		tbSearchId->Enabled = true;
	}
	else 
	{ 
		tbSearchId->Enabled = false;
		tbSearchId->Text = "";
	}
}

private: System::Void CbSearchCustomerId_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	if (cbSearchCustomerId->Checked)
	{
		tbSearchCustomerId->Enabled = true;
	}
	else
	{
		tbSearchCustomerId->Enabled = false;
		tbSearchCustomerId->Text = "";
	}
}
private: System::Void CbSearchTable_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	if (cbSearchTable->Checked)
	{
		tbSearchTable->Enabled = true;
	}
	else
	{
		tbSearchTable->Enabled = false;
		tbSearchTable->Text = "";
	}
}
private: System::Void CbSearchInvoice_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	if (cbSearchInvoice->Checked)
	{
		tbSearchInvoice->Enabled = true;
	}
	else
	{
		tbSearchInvoice->Enabled = false;
		tbSearchInvoice->Text = "";
	}
}
		//// Create a new DateTimePicker control and initialize it.
		//DateTimePicker^ dtPicker = gcnew DateTimePicker();

		//// Set the MinDate and MaxDate.
		//dtPicker.MinDate = new DateTime(1985, 6, 20);
		//dtPicker.MaxDate = DateTime.Today;

		//// Set the CustomFormat string.
		//dtPicker.CustomFormat = "dd.MM.yyyy HH:mm:ss";
		//dtPicker.Format = DateTimePickerFormat.Custom;

		//// Show the CheckBox and display the control as an up-down control.
		//dtPicker.ShowCheckBox = true;
		//dtPicker.ShowUpDown = true;

private: System::Void BtnSearch_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SearchOrderData();
}
};
}
