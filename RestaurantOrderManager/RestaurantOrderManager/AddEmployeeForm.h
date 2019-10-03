#pragma once
#include "Employee.h"
namespace RestaurantOrderManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Drawing::Imaging;
	using namespace std;
	using namespace System::Data::Sql;
	using namespace System::Data::SqlClient;
	using namespace System::Data::SqlTypes;
	using namespace Microsoft::SqlServer::Server;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for AddEmployeeForm
	/// </summary>
	public ref class AddEmployeeForm : public System::Windows::Forms::Form
	{
		String^ connStr = L"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Programs\\repos\\RestaurantOrderManager\\RestaurantOrderManager\\RestaurantDatabase\\Restaurant.mdf;Integrated Security=True;Connect Timeout=30";
		SqlConnection^ myConnection;
		SqlCommand^ sqlCommand = gcnew SqlCommand();
		SqlDataAdapter^ sda = gcnew SqlDataAdapter();
		DataTable^ dbDataSet = gcnew DataTable();

		public:
			AddEmployeeForm(void)
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
			~AddEmployeeForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::TextBox^ tbName;
		protected:

		private: System::Windows::Forms::Label^ lblName;
		private: System::Windows::Forms::Label^ lblPhoneNumber;
		private: System::Windows::Forms::Label^ lblTitle;
		private: System::Windows::Forms::Label^ lblSalary;
		private: System::Windows::Forms::Label^ lblPhoto;
		private: System::Windows::Forms::TextBox^ tbPhoneNumber;
		private: System::Windows::Forms::TextBox^ tbTitle;
		private: System::Windows::Forms::TextBox^ tbSalary;



		private: System::Windows::Forms::Button^ btnSave;


		private: System::Windows::Forms::Button^ btnImage;
		private: System::Windows::Forms::TextBox^ tbPhoto;


		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container^ components;
		private: Employee^ CreateNewEmployee()
		{
			if (!String::IsNullOrEmpty(tbName->Text))
			{
				if (!String::IsNullOrEmpty(tbPhoneNumber->Text))
				{
					if (!String::IsNullOrEmpty(tbTitle->Text))
					{
						if (!String::IsNullOrEmpty(tbSalary->Text))
						{
							Decimal salary;
							if (Decimal::TryParse(tbSalary->Text, salary))
							{
								salary = Decimal::Parse(tbSalary->Text);
								{
									Employee^ newEmployee = gcnew Employee(tbName->Text, tbPhoneNumber->Text, tbTitle->Text, salary, tbPhoto->Text);
									return newEmployee;
								}
							}
							else
							{
								MessageBox::Show("Введите число", "Ошибка ввода зарплаты", MessageBoxButtons::OK, MessageBoxIcon::Error);
								return nullptr;
							}
						}
						else
						{
							MessageBox::Show("Введите зарплату", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return nullptr;
						}
					}
					else
					{
						MessageBox::Show("Введите должность", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
					 this->label1 = (gcnew System::Windows::Forms::Label());
					 this->tbName = (gcnew System::Windows::Forms::TextBox());
					 this->lblName = (gcnew System::Windows::Forms::Label());
					 this->lblPhoneNumber = (gcnew System::Windows::Forms::Label());
					 this->lblTitle = (gcnew System::Windows::Forms::Label());
					 this->lblSalary = (gcnew System::Windows::Forms::Label());
					 this->lblPhoto = (gcnew System::Windows::Forms::Label());
					 this->tbPhoneNumber = (gcnew System::Windows::Forms::TextBox());
					 this->tbTitle = (gcnew System::Windows::Forms::TextBox());
					 this->tbSalary = (gcnew System::Windows::Forms::TextBox());
					 this->btnSave = (gcnew System::Windows::Forms::Button());
					 this->btnImage = (gcnew System::Windows::Forms::Button());
					 this->tbPhoto = (gcnew System::Windows::Forms::TextBox());
					 this->SuspendLayout();
					 // 
					 // label1
					 // 
					 this->label1->AutoSize = true;
					 this->label1->Location = System::Drawing::Point(14, 17);
					 this->label1->Name = L"label1";
					 this->label1->Size = System::Drawing::Size(93, 13);
					 this->label1->TabIndex = 0;
					 this->label1->Text = L"Введите данные:";
					 // 
					 // tbName
					 // 
					 this->tbName->Location = System::Drawing::Point(145, 55);
					 this->tbName->Name = L"tbName";
					 this->tbName->Size = System::Drawing::Size(147, 20);
					 this->tbName->TabIndex = 1;
					 // 
					 // lblName
					 // 
					 this->lblName->AutoSize = true;
					 this->lblName->Location = System::Drawing::Point(14, 58);
					 this->lblName->Name = L"lblName";
					 this->lblName->Size = System::Drawing::Size(29, 13);
					 this->lblName->TabIndex = 2;
					 this->lblName->Text = L"Имя";
					 // 
					 // lblPhoneNumber
					 // 
					 this->lblPhoneNumber->AutoSize = true;
					 this->lblPhoneNumber->Location = System::Drawing::Point(14, 100);
					 this->lblPhoneNumber->Name = L"lblPhoneNumber";
					 this->lblPhoneNumber->Size = System::Drawing::Size(93, 13);
					 this->lblPhoneNumber->TabIndex = 3;
					 this->lblPhoneNumber->Text = L"Номер телефона";
					 // 
					 // lblTitle
					 // 
					 this->lblTitle->AutoSize = true;
					 this->lblTitle->Location = System::Drawing::Point(14, 142);
					 this->lblTitle->Name = L"lblTitle";
					 this->lblTitle->Size = System::Drawing::Size(65, 13);
					 this->lblTitle->TabIndex = 4;
					 this->lblTitle->Text = L"Должность";
					 // 
					 // lblSalary
					 // 
					 this->lblSalary->AutoSize = true;
					 this->lblSalary->Location = System::Drawing::Point(14, 190);
					 this->lblSalary->Name = L"lblSalary";
					 this->lblSalary->Size = System::Drawing::Size(55, 13);
					 this->lblSalary->TabIndex = 5;
					 this->lblSalary->Text = L"Зарплата";
					 // 
					 // lblPhoto
					 // 
					 this->lblPhoto->AutoSize = true;
					 this->lblPhoto->Location = System::Drawing::Point(14, 229);
					 this->lblPhoto->Name = L"lblPhoto";
					 this->lblPhoto->Size = System::Drawing::Size(35, 13);
					 this->lblPhoto->TabIndex = 6;
					 this->lblPhoto->Text = L"Фото";
					 // 
					 // tbPhoneNumber
					 // 
					 this->tbPhoneNumber->Location = System::Drawing::Point(145, 100);
					 this->tbPhoneNumber->Name = L"tbPhoneNumber";
					 this->tbPhoneNumber->Size = System::Drawing::Size(147, 20);
					 this->tbPhoneNumber->TabIndex = 7;
					 // 
					 // tbTitle
					 // 
					 this->tbTitle->Location = System::Drawing::Point(145, 139);
					 this->tbTitle->Name = L"tbTitle";
					 this->tbTitle->Size = System::Drawing::Size(147, 20);
					 this->tbTitle->TabIndex = 8;
					 // 
					 // tbSalary
					 // 
					 this->tbSalary->Location = System::Drawing::Point(145, 183);
					 this->tbSalary->Name = L"tbSalary";
					 this->tbSalary->Size = System::Drawing::Size(147, 20);
					 this->tbSalary->TabIndex = 9;
					 // 
					 // btnSave
					 // 
					 this->btnSave->Location = System::Drawing::Point(145, 306);
					 this->btnSave->Name = L"btnSave";
					 this->btnSave->Size = System::Drawing::Size(147, 54);
					 this->btnSave->TabIndex = 11;
					 this->btnSave->Text = L"Сохранить";
					 this->btnSave->UseVisualStyleBackColor = true;
					 this->btnSave->Click += gcnew System::EventHandler(this, &AddEmployeeForm::btnSave_Click);
					 // 
					 // btnImage
					 // 
					 this->btnImage->Location = System::Drawing::Point(296, 229);
					 this->btnImage->Name = L"btnImage";
					 this->btnImage->Size = System::Drawing::Size(72, 28);
					 this->btnImage->TabIndex = 12;
					 this->btnImage->Text = L"Выбрать...";
					 this->btnImage->UseVisualStyleBackColor = true;
					 this->btnImage->Click += gcnew System::EventHandler(this, &AddEmployeeForm::BtnImage_Click);
					 // 
					 // tbPhoto
					 // 
					 this->tbPhoto->Location = System::Drawing::Point(145, 229);
					 this->tbPhoto->Name = L"tbPhoto";
					 this->tbPhoto->Size = System::Drawing::Size(147, 20);
					 this->tbPhoto->TabIndex = 13;
					 // 
					 // AddEmployeeForm
					 // 
					 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
					 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
					 this->ClientSize = System::Drawing::Size(453, 404);
					 this->Controls->Add(this->tbPhoto);
					 this->Controls->Add(this->btnImage);
					 this->Controls->Add(this->btnSave);
					 this->Controls->Add(this->tbSalary);
					 this->Controls->Add(this->tbTitle);
					 this->Controls->Add(this->tbPhoneNumber);
					 this->Controls->Add(this->lblPhoto);
					 this->Controls->Add(this->lblSalary);
					 this->Controls->Add(this->lblTitle);
					 this->Controls->Add(this->lblPhoneNumber);
					 this->Controls->Add(this->lblName);
					 this->Controls->Add(this->tbName);
					 this->Controls->Add(this->label1);
					 this->Name = L"AddEmployeeForm";
					 this->Text = L"AddEmployeeForm";
					 this->Load += gcnew System::EventHandler(this, &AddEmployeeForm::AddEmployeeForm_Load);
					 this->ResumeLayout(false);
					 this->PerformLayout();

				 }
	#pragma endregion
		private: System::Void BtnImage_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ filePath;
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "JPEG (*.jpg, *.jpeg)|*.jpg;*.jpeg|BMP|*.bmp|PNG|*.png|All pictures|*.jpg;*.jpeg;*.png;*.bmp";
			openFileDialog->FilterIndex = 4;
			openFileDialog->RestoreDirectory = true;
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				tbPhoto->Text = openFileDialog->FileName;
			}

		}
		private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
		{
			sqlCommand->Parameters->Clear();
			sqlCommand->CommandText = "INSERT INTO Employee (Name, PhoneNumber, Title, Salary, Photo) VALUES (@name, @phone, @title, @salary, @photo)";

			Employee^ newEmployee = CreateNewEmployee();
			if (newEmployee != nullptr)
			{
				if (!String::IsNullOrWhiteSpace(newEmployee->GetPhoto()))
				{
					MemoryStream^ ms = gcnew MemoryStream();
					Image^ image = image->FromFile(newEmployee->GetPhoto());
					Bitmap^ bitmap = gcnew Bitmap(image, 100, 100);
					bitmap->Save(ms, Imaging::ImageFormat::Jpeg);
					auto bytes = ms->ToArray();
					sqlCommand->Parameters->Add("@photo", SqlDbType::VarBinary, -1)->Value = bytes;
				}
				else
				{
					sqlCommand->Parameters->Add("@photo", SqlDbType::VarBinary, -1);
					sqlCommand->Parameters["@photo"]->Value = DBNull::Value;
				}
				sqlCommand->Parameters->AddWithValue("@name", newEmployee->GetName());
				sqlCommand->Parameters->AddWithValue("@phone", newEmployee->GetPhoneNumber());
				sqlCommand->Parameters->AddWithValue("@title", newEmployee->GetTitle());
				sqlCommand->Parameters->AddWithValue("@salary", newEmployee->GetSalary());
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
				MessageBox::Show("Не удалось добавить нового сотрудника", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}	
		}
	private: System::Void AddEmployeeForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
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
