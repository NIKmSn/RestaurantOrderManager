#pragma once
#include "AddEmployeeForm.h"

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
	/// Summary for StaffForm
	/// </summary>
	public ref class StaffForm : public System::Windows::Forms::Form
	{
		String^ connStr = L"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Programs\\repos\\RestaurantOrderManager\\RestaurantOrderManager\\RestaurantDatabase\\Restaurant.mdf;Integrated Security=True;Connect Timeout=30";
		SqlConnection^ myConnection;
		SqlCommand^ sqlCommand = gcnew SqlCommand();
		SqlDataAdapter^ sda = gcnew SqlDataAdapter();
		DataTable^ dbDataSet = gcnew DataTable();
		
	public:
		
		StaffForm(void)
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
		~StaffForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::DataGridView^ dgvStaff;
	private: System::Windows::Forms::Label^ lblSearch;
	private: System::Windows::Forms::RadioButton^ rbtnSearchId;
	private: System::Windows::Forms::TextBox^ tbSearch;
	private: System::Windows::Forms::RadioButton^ rbtnSearchTitle;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::Button^ btnRemoveFilters;
	private: System::Windows::Forms::Button^ btnAdd;

	private: System::Windows::Forms::Button^ btnEdit;


	private:
		System::Windows::Forms::RadioButton^ rbtnSearchName;
		void ReadStaffData()
		{
			sqlCommand->CommandText = "SELECT Photo AS 'Фото', Id AS 'ID', Name AS 'ФИО', PhoneNumber AS 'Номер телефона', Title AS 'Должность', Salary AS 'Зарплата' FROM Employee";
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
				dgvStaff->DataSource = bindSource;
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
		void SearchStaffData()
		{
			sqlCommand->Parameters->Clear();
			sqlCommand->CommandText = "SELECT Photo AS 'Фото', Id AS 'ID', Name AS 'ФИО', PhoneNumber AS 'Номер телефона', Title AS 'Должность', FORMAT(Salary, 'C', 'ru-ru') AS 'Зарплата' FROM Employee WHERE (@id IS NULL OR Id = @id) AND (@name IS NULL OR Name = @name) AND (@title IS NULL OR Title = @title)";
				
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

			if (rbtnSearchTitle->Checked)
			{
				sqlCommand->Parameters->AddWithValue("@title", tbSearch->Text);
			}
			else
			{
				sqlCommand->Parameters->AddWithValue("@title", System::DBNull::Value);
			}

			try
			{
				myConnection->Open();
				sda->SelectCommand = sqlCommand;
				dbDataSet = gcnew DataTable();
				sda->Fill(dbDataSet);
				BindingSource^ bindSource = gcnew BindingSource();
				bindSource->DataSource = dbDataSet;
				dgvStaff->DataSource = bindSource;
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
			this->dgvStaff = (gcnew System::Windows::Forms::DataGridView());
			this->lblSearch = (gcnew System::Windows::Forms::Label());
			this->rbtnSearchId = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnSearchName = (gcnew System::Windows::Forms::RadioButton());
			this->tbSearch = (gcnew System::Windows::Forms::TextBox());
			this->rbtnSearchTitle = (gcnew System::Windows::Forms::RadioButton());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnRemoveFilters = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStaff))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvStaff
			// 
			this->dgvStaff->AllowUserToAddRows = false;
			this->dgvStaff->AllowUserToOrderColumns = true;
			this->dgvStaff->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgvStaff->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvStaff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvStaff->Location = System::Drawing::Point(12, 138);
			this->dgvStaff->Name = L"dgvStaff";
			this->dgvStaff->RowTemplate->Height = 120;
			this->dgvStaff->Size = System::Drawing::Size(601, 347);
			this->dgvStaff->TabIndex = 0;
			this->dgvStaff->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &StaffForm::DgvStaff_CellEndEdit);
			this->dgvStaff->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &StaffForm::DgvStaff_RowsRemoved);
			// 
			// lblSearch
			// 
			this->lblSearch->AutoSize = true;
			this->lblSearch->Location = System::Drawing::Point(12, 89);
			this->lblSearch->Name = L"lblSearch";
			this->lblSearch->Size = System::Drawing::Size(57, 13);
			this->lblSearch->TabIndex = 1;
			this->lblSearch->Text = L"Поиск по:";
			// 
			// rbtnSearchId
			// 
			this->rbtnSearchId->AutoSize = true;
			this->rbtnSearchId->Location = System::Drawing::Point(12, 115);
			this->rbtnSearchId->Name = L"rbtnSearchId";
			this->rbtnSearchId->Size = System::Drawing::Size(97, 17);
			this->rbtnSearchId->TabIndex = 2;
			this->rbtnSearchId->TabStop = true;
			this->rbtnSearchId->Text = L"ID сотрудника";
			this->rbtnSearchId->UseVisualStyleBackColor = true;
			// 
			// rbtnSearchName
			// 
			this->rbtnSearchName->AutoSize = true;
			this->rbtnSearchName->Location = System::Drawing::Point(115, 115);
			this->rbtnSearchName->Name = L"rbtnSearchName";
			this->rbtnSearchName->Size = System::Drawing::Size(59, 17);
			this->rbtnSearchName->TabIndex = 3;
			this->rbtnSearchName->TabStop = true;
			this->rbtnSearchName->Text = L"Имени";
			this->rbtnSearchName->UseVisualStyleBackColor = true;
			// 
			// tbSearch
			// 
			this->tbSearch->Location = System::Drawing::Point(269, 111);
			this->tbSearch->Name = L"tbSearch";
			this->tbSearch->Size = System::Drawing::Size(136, 20);
			this->tbSearch->TabIndex = 4;
			// 
			// rbtnSearchTitle
			// 
			this->rbtnSearchTitle->AutoSize = true;
			this->rbtnSearchTitle->Location = System::Drawing::Point(180, 115);
			this->rbtnSearchTitle->Name = L"rbtnSearchTitle";
			this->rbtnSearchTitle->Size = System::Drawing::Size(83, 17);
			this->rbtnSearchTitle->TabIndex = 5;
			this->rbtnSearchTitle->TabStop = true;
			this->rbtnSearchTitle->Text = L"Должности";
			this->rbtnSearchTitle->UseVisualStyleBackColor = true;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(411, 111);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(95, 23);
			this->btnSearch->TabIndex = 6;
			this->btnSearch->Text = L"Найти";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &StaffForm::BtnSearch_Click);
			// 
			// btnRemoveFilters
			// 
			this->btnRemoveFilters->Location = System::Drawing::Point(512, 111);
			this->btnRemoveFilters->Name = L"btnRemoveFilters";
			this->btnRemoveFilters->Size = System::Drawing::Size(101, 23);
			this->btnRemoveFilters->TabIndex = 7;
			this->btnRemoveFilters->Text = L"Отобразить все";
			this->btnRemoveFilters->UseVisualStyleBackColor = true;
			this->btnRemoveFilters->Click += gcnew System::EventHandler(this, &StaffForm::BtnRemoveFilters_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(12, 53);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 8;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &StaffForm::BtnAdd_Click);
			// 
			// btnEdit
			// 
			this->btnEdit->Enabled = false;
			this->btnEdit->Location = System::Drawing::Point(93, 53);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(141, 23);
			this->btnEdit->TabIndex = 10;
			this->btnEdit->Text = L"Сохранить изменения";
			this->btnEdit->UseVisualStyleBackColor = true;
			this->btnEdit->Click += gcnew System::EventHandler(this, &StaffForm::BtnEdit_Click);
			// 
			// StaffForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(625, 497);
			this->Controls->Add(this->btnEdit);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnRemoveFilters);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->rbtnSearchTitle);
			this->Controls->Add(this->tbSearch);
			this->Controls->Add(this->rbtnSearchName);
			this->Controls->Add(this->rbtnSearchId);
			this->Controls->Add(this->lblSearch);
			this->Controls->Add(this->dgvStaff);
			this->Name = L"StaffForm";
			this->Text = L"Сотрудники";
			this->Load += gcnew System::EventHandler(this, &StaffForm::StaffForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStaff))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnSearch_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		SearchStaffData();
	}
private: System::Void BtnRemoveFilters_Click(System::Object^ sender, System::EventArgs^ e) 
{
	rbtnSearchId->Checked = false;
	rbtnSearchName->Checked = false;
	rbtnSearchTitle->Checked = false;
	tbSearch->Text = "";
	ReadStaffData();
}
private: System::Void BtnAdd_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Form^ addingForm = Application::OpenForms["AddEmployeeForm"];
	if (addingForm != nullptr)
		addingForm->BringToFront();
	else
	{
		AddEmployeeForm^ addingForm = gcnew AddEmployeeForm();
		addingForm->Show();
	}
}
private: System::Void StaffForm_Load(System::Object^ sender, System::EventArgs^ e) 
{
	try
	{
		myConnection = gcnew SqlConnection(connStr);
		sqlCommand->Connection = myConnection;
		dgvStaff->RowTemplate->Height = 120;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void BtnEdit_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SqlCommandBuilder^ sqlCommandBuilder = gcnew SqlCommandBuilder(sda);
	sqlCommandBuilder->GetUpdateCommand()->UpdatedRowSource = UpdateRowSource::OutputParameters;
	String^ command = sqlCommandBuilder->GetInsertCommand()->CommandText;
	/*sqlCommandBuilder->GetUpdateCommand()->CommandText = "UPDATE [Employee] SET [Photo] = @p1, [Name] = @p2, [PhoneNumber] = @p3, [Title] = @p4, [Salary] = @p5 WHERE (([ID] = @p6) AND ([Name] = @p7) AND ([PhoneNumber] = @p8) AND ([Title] = @p9) AND ([Salary] = @p10))";*/
	sda->UpdateCommand = sqlCommandBuilder->GetUpdateCommand();
	sda->InsertCommand = sqlCommandBuilder->GetInsertCommand();
	sda->DeleteCommand = sqlCommandBuilder->GetDeleteCommand();
	sda->AcceptChangesDuringUpdate = true;
	sda->Update(dbDataSet);
	btnEdit->Enabled = false;
}
private: System::Void DgvStaff_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e) 
{
	btnEdit->Enabled = true;
}
private: System::Void DgvStaff_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
{
	btnEdit->Enabled = true;
}
};
	
}
