#pragma once
#include "AddNewClientForm.h"
#include "Database.h"
namespace RestaurantOrderManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CustomersForm
	/// </summary>
	public ref class CustomersForm : public System::Windows::Forms::Form
	{
		//Объявление необходимых переменных для связи с БД
		SqlConnection^ myConnection = Database::CreateConnection();
		SqlCommand^ sqlCommand = Database::CreateCommand();
		SqlDataAdapter^ sda = Database::CreateDataAdapter();
		DataTable^ dbDataSet = gcnew DataTable();
	public:
		CustomersForm(void)
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
		~CustomersForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnEdit;
	protected:
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnRemoveFilters;
	private: System::Windows::Forms::Button^ btnSearch;

	private: System::Windows::Forms::TextBox^ tbSearch;
	private: System::Windows::Forms::RadioButton^ rbtnSearchName;
	private: System::Windows::Forms::RadioButton^ rbtnSearchId;
	private: System::Windows::Forms::Label^ lblSearch;
	private: System::Windows::Forms::DataGridView^ dgvCustomers;

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
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnRemoveFilters = (gcnew System::Windows::Forms::Button());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->tbSearch = (gcnew System::Windows::Forms::TextBox());
			this->rbtnSearchName = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnSearchId = (gcnew System::Windows::Forms::RadioButton());
			this->lblSearch = (gcnew System::Windows::Forms::Label());
			this->dgvCustomers = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCustomers))->BeginInit();
			this->SuspendLayout();
			// 
			// btnEdit
			// 
			this->btnEdit->Enabled = false;
			this->btnEdit->Location = System::Drawing::Point(123, 40);
			this->btnEdit->Margin = System::Windows::Forms::Padding(4);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(188, 28);
			this->btnEdit->TabIndex = 20;
			this->btnEdit->Text = L"Сохранить изменения";
			this->btnEdit->UseVisualStyleBackColor = true;
			this->btnEdit->Click += gcnew System::EventHandler(this, &CustomersForm::BtnEdit_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(15, 40);
			this->btnAdd->Margin = System::Windows::Forms::Padding(4);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(100, 28);
			this->btnAdd->TabIndex = 19;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &CustomersForm::BtnAdd_Click);
			// 
			// btnRemoveFilters
			// 
			this->btnRemoveFilters->Location = System::Drawing::Point(682, 112);
			this->btnRemoveFilters->Margin = System::Windows::Forms::Padding(4);
			this->btnRemoveFilters->Name = L"btnRemoveFilters";
			this->btnRemoveFilters->Size = System::Drawing::Size(135, 28);
			this->btnRemoveFilters->TabIndex = 18;
			this->btnRemoveFilters->Text = L"Отобразить все";
			this->btnRemoveFilters->UseVisualStyleBackColor = true;
			this->btnRemoveFilters->Click += gcnew System::EventHandler(this, &CustomersForm::BtnRemoveFilters_Click);
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(547, 112);
			this->btnSearch->Margin = System::Windows::Forms::Padding(4);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(127, 28);
			this->btnSearch->TabIndex = 17;
			this->btnSearch->Text = L"Найти";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &CustomersForm::BtnSearch_Click);
			// 
			// tbSearch
			// 
			this->tbSearch->Location = System::Drawing::Point(245, 112);
			this->tbSearch->Margin = System::Windows::Forms::Padding(4);
			this->tbSearch->Name = L"tbSearch";
			this->tbSearch->Size = System::Drawing::Size(293, 22);
			this->tbSearch->TabIndex = 15;
			// 
			// rbtnSearchName
			// 
			this->rbtnSearchName->AutoSize = true;
			this->rbtnSearchName->Location = System::Drawing::Point(141, 113);
			this->rbtnSearchName->Margin = System::Windows::Forms::Padding(4);
			this->rbtnSearchName->Name = L"rbtnSearchName";
			this->rbtnSearchName->Size = System::Drawing::Size(72, 21);
			this->rbtnSearchName->TabIndex = 14;
			this->rbtnSearchName->TabStop = true;
			this->rbtnSearchName->Text = L"Имени";
			this->rbtnSearchName->UseVisualStyleBackColor = true;
			// 
			// rbtnSearchId
			// 
			this->rbtnSearchId->AutoSize = true;
			this->rbtnSearchId->Location = System::Drawing::Point(18, 112);
			this->rbtnSearchId->Margin = System::Windows::Forms::Padding(4);
			this->rbtnSearchId->Name = L"rbtnSearchId";
			this->rbtnSearchId->Size = System::Drawing::Size(100, 21);
			this->rbtnSearchId->TabIndex = 13;
			this->rbtnSearchId->TabStop = true;
			this->rbtnSearchId->Text = L"ID клиента";
			this->rbtnSearchId->UseVisualStyleBackColor = true;
			// 
			// lblSearch
			// 
			this->lblSearch->AutoSize = true;
			this->lblSearch->Location = System::Drawing::Point(15, 85);
			this->lblSearch->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblSearch->Name = L"lblSearch";
			this->lblSearch->Size = System::Drawing::Size(72, 17);
			this->lblSearch->TabIndex = 12;
			this->lblSearch->Text = L"Поиск по:";
			// 
			// dgvCustomers
			// 
			this->dgvCustomers->AllowUserToAddRows = false;
			this->dgvCustomers->AllowUserToOrderColumns = true;
			this->dgvCustomers->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgvCustomers->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvCustomers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCustomers->Location = System::Drawing::Point(15, 145);
			this->dgvCustomers->Margin = System::Windows::Forms::Padding(4);
			this->dgvCustomers->Name = L"dgvCustomers";
			this->dgvCustomers->RowHeadersWidth = 51;
			this->dgvCustomers->RowTemplate->Height = 120;
			this->dgvCustomers->Size = System::Drawing::Size(801, 427);
			this->dgvCustomers->TabIndex = 11;
			this->dgvCustomers->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CustomersForm::DgvCustomers_CellEndEdit);
			this->dgvCustomers->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &CustomersForm::DgvCustomers_RowsRemoved);
			// 
			// CustomersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(833, 612);
			this->Controls->Add(this->btnEdit);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnRemoveFilters);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->tbSearch);
			this->Controls->Add(this->rbtnSearchName);
			this->Controls->Add(this->rbtnSearchId);
			this->Controls->Add(this->lblSearch);
			this->Controls->Add(this->dgvCustomers);
			this->MaximizeBox = false;
			this->Name = L"CustomersForm";
			this->Text = L"Клиенты";
			this->Load += gcnew System::EventHandler(this, &CustomersForm::CustomersForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCustomers))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//Функция чтения данных о клиентах из БД
private: void ReadCustomersData()
{
	sqlCommand->CommandText = "SELECT Id AS 'ID', Name AS 'ФИО', PhoneNumber AS 'Номер телефона', Email AS 'E-mail', Discount AS 'Скидка (%)' FROM Customer";
	try
	{
		myConnection->Open();
		sqlCommand->UpdatedRowSource = UpdateRowSource::OutputParameters;
		sda = gcnew SqlDataAdapter(sqlCommand);
		sda->SelectCommand = sqlCommand;
		dbDataSet = gcnew DataTable();
		sda->Fill(dbDataSet);
		BindingSource^ bindSource = gcnew BindingSource();
		bindSource->DataSource = dbDataSet;
		dgvCustomers->DataSource = bindSource;
		sda->Update(dbDataSet);
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Ошибка поиска", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally
	{
		myConnection->Close();
		btnEdit->Enabled = false;
	}
}
//Функция поиска в БД клиентов по выбранным фильтрам
private: void SearchCustomersData()
{
	sqlCommand->Parameters->Clear();
	sqlCommand->CommandText = "SELECT Id AS 'ID', Name AS 'ФИО', PhoneNumber AS 'Номер телефона', Email AS 'E-mail', CONVERT(DECIMAL(5,2),Discount * 100) AS 'Скидка (%)' FROM Customer WHERE (@id IS NULL OR Id = @id) AND (@name IS NULL OR Name = @name)";

	if (rbtnSearchId->Checked)
	{
		sqlCommand->Parameters->AddWithValue("@id", tbSearch->Text);
	}
	else
	{
		sqlCommand->Parameters->AddWithValue("@id", System::DBNull::Value);
	}

	if (rbtnSearchName->Checked)
	{
		sqlCommand->Parameters->AddWithValue("@name", tbSearch->Text);
	}
	else
	{
		sqlCommand->Parameters->AddWithValue("@name", System::DBNull::Value);
	}

	try
	{
		myConnection->Open();
		sda->SelectCommand = sqlCommand;
		dbDataSet = gcnew DataTable();
		sda->Fill(dbDataSet);
		BindingSource^ bindSource = gcnew BindingSource();
		bindSource->DataSource = dbDataSet;
		dgvCustomers->DataSource = bindSource;
		sda->Update(dbDataSet);
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Ошибка поиска", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally
	{
		myConnection->Close();
		btnEdit->Enabled = false;
	}
}

//Обработчик события нажатия на кнопку добавления нового клиента
private: System::Void BtnAdd_Click(System::Object^ sender, System::EventArgs^ e) 
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
//Обработчик события нажатия на кнопку "Отобразить все"
private: System::Void BtnRemoveFilters_Click(System::Object^ sender, System::EventArgs^ e)
{
	rbtnSearchId->Checked = false;
	rbtnSearchName->Checked = false;
	tbSearch->Text = "";
	ReadCustomersData();
}
//Обработчик события нажатия на кнопку "Поиск"
private: System::Void BtnSearch_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SearchCustomersData();
}
//Обработчик события загрузки формы
private: System::Void CustomersForm_Load(System::Object^ sender, System::EventArgs^ e) 
{
	try
	{
		sqlCommand->Connection = myConnection;
		dgvCustomers->RowTemplate->Height = 120;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
//Обработчик события нажатия на кнопку "Сохранить изменения"
private: System::Void BtnEdit_Click(System::Object^ sender, System::EventArgs^ e)
{
	SqlCommandBuilder^ sqlCommandBuilder = gcnew SqlCommandBuilder(sda);
	sqlCommandBuilder->GetUpdateCommand()->UpdatedRowSource = UpdateRowSource::OutputParameters;
	String^ command = sqlCommandBuilder->GetInsertCommand()->CommandText;
	sda->UpdateCommand = sqlCommandBuilder->GetUpdateCommand();
	sda->InsertCommand = sqlCommandBuilder->GetInsertCommand();
	sda->DeleteCommand = sqlCommandBuilder->GetDeleteCommand();
	sda->AcceptChangesDuringUpdate = true;
	sda->Update(dbDataSet);
	btnEdit->Enabled = false;
}
//Обработчик события удаления записей
private: System::Void DgvCustomers_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e)
{
	btnEdit->Enabled = true;
}
//Обработчик события изменения данных в ячейке (поле записи)
private: System::Void DgvCustomers_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	btnEdit->Enabled = true;
}
};
}
