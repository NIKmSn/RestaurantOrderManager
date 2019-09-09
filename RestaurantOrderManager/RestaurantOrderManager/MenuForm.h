#pragma once
#include "AddProductForm.h"
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
	/// Summary for MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
		String^ connStr = L"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Programs\\repos\\RestaurantOrderManager\\RestaurantOrderManager\\RestaurantDatabase\\Restaurant.mdf;Integrated Security=True;Connect Timeout=30";
		SqlConnection^ myConnection;
		SqlCommand^ sqlCommand = gcnew SqlCommand();
		SqlDataAdapter^ sda = gcnew SqlDataAdapter();
		DataTable^ dbDataSet = gcnew DataTable();
	public:
		MenuForm(void)
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
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblSearch;
	protected:
	private: System::Windows::Forms::RadioButton^ rbtnSearchID;
	private: System::Windows::Forms::RadioButton^ rbtnSearchName;

	private: System::Windows::Forms::TextBox^ tbSearch;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::Button^ btnRemoveFilters;
	private: System::Windows::Forms::Button^ btnEdit;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::DataGridView^ dgvMenu;
			 void ReadMenuData()
			 {
				 sqlCommand->CommandText = "SELECT Id AS 'ID', Picture AS 'Фото', Type AS 'Тип блюда', Name AS 'Название', Description AS 'Описание', Price AS 'Цена за 1шт/100гр' FROM Product";
				 try
				 {
					 myConnection->Open();
					 sda = gcnew SqlDataAdapter();
					 sda->SelectCommand = sqlCommand;
					 dbDataSet = gcnew DataTable();
					 sda->Fill(dbDataSet);
					 BindingSource^ bindSource = gcnew BindingSource();
					 bindSource->DataSource = dbDataSet;
					 dgvMenu->DataSource = bindSource;
					 sda->Update(dbDataSet);
				 }
				 catch (Exception^ e)
				 {
					 MessageBox::Show(e->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
				 finally
				 {
					 myConnection->Close();
					 btnEdit->Enabled = false;
				 }
			 }
			 void SearchMenuData()
			 {
				 sqlCommand->Parameters->Clear();
				
				 if (rbtnSearchID->Checked)
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
				 sqlCommand->CommandText = "SELECT Id AS 'ID', Picture AS 'Фото', Type AS 'Тип блюда', Name AS 'Название', Description AS 'Описание', FORMAT(Price, 'C', 'ru-ru') AS 'Цена за 1шт/100гр' FROM Product WHERE(@id IS NULL OR Id = @id) AND (@name IS NULL OR Name = @name)";
				 try
				 {
					 myConnection->Open();
					 sda = gcnew SqlDataAdapter();
					 sda->SelectCommand = sqlCommand;
					 dbDataSet = gcnew DataTable();
					 sda->Fill(dbDataSet);
					 BindingSource^ bindSource = gcnew BindingSource();
					 bindSource->DataSource = dbDataSet;
					 dgvMenu->DataSource = bindSource;
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
			this->dgvMenu = (gcnew System::Windows::Forms::DataGridView());
			this->lblSearch = (gcnew System::Windows::Forms::Label());
			this->rbtnSearchID = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnSearchName = (gcnew System::Windows::Forms::RadioButton());
			this->tbSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnRemoveFilters = (gcnew System::Windows::Forms::Button());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMenu))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvMenu
			// 
			this->dgvMenu->AllowUserToAddRows = false;
			this->dgvMenu->AllowUserToOrderColumns = true;
			this->dgvMenu->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgvMenu->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvMenu->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvMenu->Location = System::Drawing::Point(13, 98);
			this->dgvMenu->Name = L"dgvMenu";
			this->dgvMenu->Size = System::Drawing::Size(600, 387);
			this->dgvMenu->TabIndex = 0;
			this->dgvMenu->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MenuForm::DgvMenu_CellEndEdit);
			this->dgvMenu->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &MenuForm::DgvMenu_RowsRemoved);
			// 
			// lblSearch
			// 
			this->lblSearch->AutoSize = true;
			this->lblSearch->Location = System::Drawing::Point(12, 74);
			this->lblSearch->Name = L"lblSearch";
			this->lblSearch->Size = System::Drawing::Size(57, 13);
			this->lblSearch->TabIndex = 1;
			this->lblSearch->Text = L"Поиск по:";
			// 
			// rbtnSearchID
			// 
			this->rbtnSearchID->AutoSize = true;
			this->rbtnSearchID->Location = System::Drawing::Point(75, 73);
			this->rbtnSearchID->Name = L"rbtnSearchID";
			this->rbtnSearchID->Size = System::Drawing::Size(39, 17);
			this->rbtnSearchID->TabIndex = 2;
			this->rbtnSearchID->TabStop = true;
			this->rbtnSearchID->Text = L"ID ";
			this->rbtnSearchID->UseVisualStyleBackColor = true;
			// 
			// rbtnSearchName
			// 
			this->rbtnSearchName->AutoSize = true;
			this->rbtnSearchName->Location = System::Drawing::Point(120, 73);
			this->rbtnSearchName->Name = L"rbtnSearchName";
			this->rbtnSearchName->Size = System::Drawing::Size(77, 17);
			this->rbtnSearchName->TabIndex = 3;
			this->rbtnSearchName->TabStop = true;
			this->rbtnSearchName->Text = L"Названию";
			this->rbtnSearchName->UseVisualStyleBackColor = true;
			// 
			// tbSearch
			// 
			this->tbSearch->Location = System::Drawing::Point(203, 73);
			this->tbSearch->Name = L"tbSearch";
			this->tbSearch->Size = System::Drawing::Size(183, 20);
			this->tbSearch->TabIndex = 4;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(392, 71);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(105, 23);
			this->btnSearch->TabIndex = 5;
			this->btnSearch->Text = L"Найти";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &MenuForm::BtnSearch_Click);
			// 
			// btnRemoveFilters
			// 
			this->btnRemoveFilters->Location = System::Drawing::Point(503, 71);
			this->btnRemoveFilters->Name = L"btnRemoveFilters";
			this->btnRemoveFilters->Size = System::Drawing::Size(110, 23);
			this->btnRemoveFilters->TabIndex = 6;
			this->btnRemoveFilters->Text = L"Отобразить все";
			this->btnRemoveFilters->UseVisualStyleBackColor = true;
			this->btnRemoveFilters->Click += gcnew System::EventHandler(this, &MenuForm::BtnRemoveFilters_Click);
			// 
			// btnEdit
			// 
			this->btnEdit->Enabled = false;
			this->btnEdit->Location = System::Drawing::Point(93, 34);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(141, 23);
			this->btnEdit->TabIndex = 12;
			this->btnEdit->Text = L"Сохранить изменения";
			this->btnEdit->UseVisualStyleBackColor = true;
			this->btnEdit->Click += gcnew System::EventHandler(this, &MenuForm::BtnEdit_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(12, 34);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 11;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MenuForm::BtnAdd_Click);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(625, 497);
			this->Controls->Add(this->btnEdit);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnRemoveFilters);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->tbSearch);
			this->Controls->Add(this->rbtnSearchName);
			this->Controls->Add(this->rbtnSearchID);
			this->Controls->Add(this->lblSearch);
			this->Controls->Add(this->dgvMenu);
			this->Name = L"MenuForm";
			this->Text = L"Меню";
			this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMenu))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void BtnSearch_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SearchMenuData();
}
private: System::Void BtnRemoveFilters_Click(System::Object^ sender, System::EventArgs^ e) 
{
	rbtnSearchID->Checked = false;
	rbtnSearchName->Checked = false;
	tbSearch->Text = "";
	ReadMenuData();
}
private: System::Void MenuForm_Load(System::Object^ sender, System::EventArgs^ e) 
{
	try
	{
		myConnection = gcnew SqlConnection(connStr);
		sqlCommand->Connection = myConnection;
		dgvMenu->RowTemplate->Height = 120;
		ReadMenuData();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void BtnEdit_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SqlCommandBuilder^ sqlCommandBuilder = gcnew SqlCommandBuilder(sda);
	sda->UpdateCommand = sqlCommandBuilder->GetUpdateCommand();
	sda->Update(dbDataSet);
	btnEdit->Enabled = false;
}
private: System::Void DgvMenu_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e) 
{
	btnEdit->Enabled = true;
}
private: System::Void DgvMenu_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
{
	btnEdit->Enabled = true;
}
private: System::Void BtnAdd_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Form^ addingForm = Application::OpenForms["AddProductForm"];
	if (addingForm != nullptr)
		addingForm->BringToFront();
	else
	{
		AddProductForm^ addingForm = gcnew AddProductForm();
		addingForm->Show();
	}
}
};
}
