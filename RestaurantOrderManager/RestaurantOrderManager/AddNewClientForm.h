#pragma once
#include "Customer.h"

namespace RestaurantOrderManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddNewItemForm
	/// </summary>
	public ref class AddNewClientForm : public System::Windows::Forms::Form
	{
		String^ connStr = L"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Programs\\repos\\RestaurantOrderManager\\RestaurantOrderManager\\RestaurantDatabase\\Restaurant.mdf;Integrated Security=True;Connect Timeout=30";
		SqlConnection^ myConnection;
		SqlCommand^ sqlCommand = gcnew SqlCommand();
		SqlDataAdapter^ sda = gcnew SqlDataAdapter();
		DataTable^ dbDataSet = gcnew DataTable();
	public:
		AddNewClientForm(void)
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
		~AddNewClientForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::TextBox^ tbEmail;
	protected:

	private: System::Windows::Forms::TextBox^ tbPhoneNumber;
	private: System::Windows::Forms::Label^ lblSalary;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Label^ lblPhoneNumber;
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: Customer^ CreateNewCustomer()
	{
		if (!String::IsNullOrEmpty(tbName->Text))
		{
			if (!String::IsNullOrEmpty(tbPhoneNumber->Text))
			{
				if (!String::IsNullOrEmpty(tbEmail->Text))
				{
					if (!String::IsNullOrEmpty(numericUpDown1->Value.ToString()))
					{
						Decimal discount = System::Decimal::Divide(numericUpDown1->Value, 100);

						Customer^ newCustomer = gcnew Customer(tbName->Text, tbPhoneNumber->Text, tbEmail->Text, discount);
						return newCustomer;

					}
					else
					{
						MessageBox::Show("Введите скидку", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return nullptr;
					}
				}
				else
				{
					MessageBox::Show("Введите Email", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return nullptr;
				}
			}
			else
			{
				MessageBox::Show("Введите номер телефона", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return nullptr;
			}
		}
		else
		{
			MessageBox::Show("Введите имя", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return nullptr;
		}
	}
	

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->tbPhoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->lblSalary = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblPhoneNumber = (gcnew System::Windows::Forms::Label());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(149, 345);
			this->btnSave->Margin = System::Windows::Forms::Padding(4);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(196, 66);
			this->btnSave->TabIndex = 24;
			this->btnSave->Text = L"Сохранить";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &AddNewClientForm::BtnSave_Click);
			// 
			// tbEmail
			// 
			this->tbEmail->Location = System::Drawing::Point(222, 195);
			this->tbEmail->Margin = System::Windows::Forms::Padding(4);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(195, 22);
			this->tbEmail->TabIndex = 22;
			// 
			// tbPhoneNumber
			// 
			this->tbPhoneNumber->Location = System::Drawing::Point(222, 147);
			this->tbPhoneNumber->Margin = System::Windows::Forms::Padding(4);
			this->tbPhoneNumber->Name = L"tbPhoneNumber";
			this->tbPhoneNumber->Size = System::Drawing::Size(195, 22);
			this->tbPhoneNumber->TabIndex = 21;
			// 
			// lblSalary
			// 
			this->lblSalary->AutoSize = true;
			this->lblSalary->Location = System::Drawing::Point(48, 258);
			this->lblSalary->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblSalary->Name = L"lblSalary";
			this->lblSalary->Size = System::Drawing::Size(81, 17);
			this->lblSalary->TabIndex = 19;
			this->lblSalary->Text = L"Скидка (%)";
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Location = System::Drawing::Point(48, 199);
			this->lblTitle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(47, 17);
			this->lblTitle->TabIndex = 18;
			this->lblTitle->Text = L"E-mail";
			// 
			// lblPhoneNumber
			// 
			this->lblPhoneNumber->AutoSize = true;
			this->lblPhoneNumber->Location = System::Drawing::Point(48, 147);
			this->lblPhoneNumber->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblPhoneNumber->Name = L"lblPhoneNumber";
			this->lblPhoneNumber->Size = System::Drawing::Size(121, 17);
			this->lblPhoneNumber->TabIndex = 17;
			this->lblPhoneNumber->Text = L"Номер телефона";
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Location = System::Drawing::Point(48, 95);
			this->lblName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(35, 17);
			this->lblName->TabIndex = 16;
			this->lblName->Text = L"Имя";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(222, 92);
			this->tbName->Margin = System::Windows::Forms::Padding(4);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(195, 22);
			this->tbName->TabIndex = 15;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 45);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 17);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Введите данные:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(222, 258);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 25;
			// 
			// AddNewClientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(498, 464);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->tbPhoneNumber);
			this->Controls->Add(this->lblSalary);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->lblPhoneNumber);
			this->Controls->Add(this->lblName);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label1);
			this->Name = L"AddNewClientForm";
			this->Text = L"AddNewClientForm";
			this->Load += gcnew System::EventHandler(this, &AddNewClientForm::AddNewClientForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnSave_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		sqlCommand->Parameters->Clear();
		sqlCommand->CommandText = "INSERT INTO Customer (Name, PhoneNumber, Email, Discount) VALUES (@name, @phone, @email, @discount)";

		Customer^ newCustomer = CreateNewCustomer();
		if (newCustomer != nullptr)
		{
			sqlCommand->Parameters->AddWithValue("@name", newCustomer->GetName());
			sqlCommand->Parameters->AddWithValue("@phone", newCustomer->GetPhoneNumber());
			sqlCommand->Parameters->AddWithValue("@email", newCustomer->GetEmail());
			sqlCommand->Parameters->AddWithValue("@discount", newCustomer->GetDiscount());
			try
			{
				myConnection->Open();
				sqlCommand->ExecuteNonQuery();
				sda = gcnew SqlDataAdapter();
				sda->SelectCommand = sqlCommand;
				Close();
			}
			catch (Exception^ e)
			{
				MessageBox::Show(e->Message, "Ошибка добавления", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally
			{
				myConnection->Close();
			}
		}
		else
		{
			MessageBox::Show("Не удалось добавить нового клиента", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void AddNewClientForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		numericUpDown1->Maximum = 100;
		numericUpDown1->Minimum = 0;
		try
		{
			myConnection = gcnew SqlConnection(connStr);
			sqlCommand->Connection = myConnection;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};

}
