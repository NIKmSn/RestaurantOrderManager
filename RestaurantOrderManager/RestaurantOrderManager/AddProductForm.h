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
	/// Summary for AddProductForm
	/// </summary>
	public ref class AddProductForm : public System::Windows::Forms::Form
	{
		String^ connStr = L"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=D:\\Programs\\repos\\RestaurantOrderManager\\RestaurantOrderManager\\RestaurantDatabase\\Restaurant.mdf;Integrated Security=True;Connect Timeout=30";
		SqlConnection^ myConnection;
		SqlCommand^ sqlCommand = gcnew SqlCommand();
		SqlDataAdapter^ sda = gcnew SqlDataAdapter();
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ cbDishType;

			 DataTable^ dbDataSet = gcnew DataTable();
		public:
			AddProductForm(void)
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
			~AddProductForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::TextBox^ tbPhoto;
		protected:
		private: System::Windows::Forms::Button^ btnImage;
		private: System::Windows::Forms::Button^ btnSave;
		private: System::Windows::Forms::TextBox^ tbPrice;
		private: System::Windows::Forms::TextBox^ tbDescription;
		private: System::Windows::Forms::Label^ lblPhoto;
		private: System::Windows::Forms::Label^ lblPrice;
		private: System::Windows::Forms::Label^ lblDescription;
		private: System::Windows::Forms::Label^ lblName;
		private: System::Windows::Forms::TextBox^ tbName;
		private: System::Windows::Forms::Label^ label1;

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
				this->tbPhoto = (gcnew System::Windows::Forms::TextBox());
				this->btnImage = (gcnew System::Windows::Forms::Button());
				this->btnSave = (gcnew System::Windows::Forms::Button());
				this->tbPrice = (gcnew System::Windows::Forms::TextBox());
				this->tbDescription = (gcnew System::Windows::Forms::TextBox());
				this->lblPhoto = (gcnew System::Windows::Forms::Label());
				this->lblPrice = (gcnew System::Windows::Forms::Label());
				this->lblDescription = (gcnew System::Windows::Forms::Label());
				this->lblName = (gcnew System::Windows::Forms::Label());
				this->tbName = (gcnew System::Windows::Forms::TextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->cbDishType = (gcnew System::Windows::Forms::ComboBox());
				this->SuspendLayout();
				// 
				// tbPhoto
				// 
				this->tbPhoto->Location = System::Drawing::Point(161, 232);
				this->tbPhoto->Name = L"tbPhoto";
				this->tbPhoto->Size = System::Drawing::Size(147, 20);
				this->tbPhoto->TabIndex = 26;
				// 
				// btnImage
				// 
				this->btnImage->Location = System::Drawing::Point(312, 232);
				this->btnImage->Name = L"btnImage";
				this->btnImage->Size = System::Drawing::Size(72, 28);
				this->btnImage->TabIndex = 25;
				this->btnImage->Text = L"Выбрать...";
				this->btnImage->UseVisualStyleBackColor = true;
				this->btnImage->Click += gcnew System::EventHandler(this, &AddProductForm::BtnImage_Click);
				// 
				// btnSave
				// 
				this->btnSave->Location = System::Drawing::Point(161, 315);
				this->btnSave->Name = L"btnSave";
				this->btnSave->Size = System::Drawing::Size(147, 54);
				this->btnSave->TabIndex = 24;
				this->btnSave->Text = L"Сохранить";
				this->btnSave->UseVisualStyleBackColor = true;
				this->btnSave->Click += gcnew System::EventHandler(this, &AddProductForm::BtnSave_Click);
				// 
				// tbPrice
				// 
				this->tbPrice->Location = System::Drawing::Point(161, 190);
				this->tbPrice->Name = L"tbPrice";
				this->tbPrice->Size = System::Drawing::Size(147, 20);
				this->tbPrice->TabIndex = 23;
				// 
				// tbDescription
				// 
				this->tbDescription->Location = System::Drawing::Point(161, 147);
				this->tbDescription->Name = L"tbDescription";
				this->tbDescription->Size = System::Drawing::Size(147, 20);
				this->tbDescription->TabIndex = 21;
				// 
				// lblPhoto
				// 
				this->lblPhoto->AutoSize = true;
				this->lblPhoto->Location = System::Drawing::Point(30, 235);
				this->lblPhoto->Name = L"lblPhoto";
				this->lblPhoto->Size = System::Drawing::Size(35, 13);
				this->lblPhoto->TabIndex = 20;
				this->lblPhoto->Text = L"Фото";
				// 
				// lblPrice
				// 
				this->lblPrice->AutoSize = true;
				this->lblPrice->Location = System::Drawing::Point(30, 193);
				this->lblPrice->Name = L"lblPrice";
				this->lblPrice->Size = System::Drawing::Size(33, 13);
				this->lblPrice->TabIndex = 19;
				this->lblPrice->Text = L"Цена";
				// 
				// lblDescription
				// 
				this->lblDescription->AutoSize = true;
				this->lblDescription->Location = System::Drawing::Point(30, 147);
				this->lblDescription->Name = L"lblDescription";
				this->lblDescription->Size = System::Drawing::Size(57, 13);
				this->lblDescription->TabIndex = 17;
				this->lblDescription->Text = L"Описание";
				// 
				// lblName
				// 
				this->lblName->AutoSize = true;
				this->lblName->Location = System::Drawing::Point(30, 105);
				this->lblName->Name = L"lblName";
				this->lblName->Size = System::Drawing::Size(57, 13);
				this->lblName->TabIndex = 16;
				this->lblName->Text = L"Название";
				// 
				// tbName
				// 
				this->tbName->Location = System::Drawing::Point(161, 102);
				this->tbName->Name = L"tbName";
				this->tbName->Size = System::Drawing::Size(147, 20);
				this->tbName->TabIndex = 15;
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(30, 26);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(93, 13);
				this->label1->TabIndex = 14;
				this->label1->Text = L"Введите данные:";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(30, 63);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(61, 13);
				this->label2->TabIndex = 27;
				this->label2->Text = L"Тип блюда";
				// 
				// cbDishType
				// 
				this->cbDishType->FormattingEnabled = true;
				this->cbDishType->Location = System::Drawing::Point(161, 63);
				this->cbDishType->Name = L"cbDishType";
				this->cbDishType->Size = System::Drawing::Size(147, 21);
				this->cbDishType->TabIndex = 28;
				// 
				// AddProductForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(453, 404);
				this->Controls->Add(this->cbDishType);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->tbPhoto);
				this->Controls->Add(this->btnImage);
				this->Controls->Add(this->btnSave);
				this->Controls->Add(this->tbPrice);
				this->Controls->Add(this->tbDescription);
				this->Controls->Add(this->lblPhoto);
				this->Controls->Add(this->lblPrice);
				this->Controls->Add(this->lblDescription);
				this->Controls->Add(this->lblName);
				this->Controls->Add(this->tbName);
				this->Controls->Add(this->label1);
				this->Name = L"AddProductForm";
				this->Text = L"AddProductForm";
				this->Load += gcnew System::EventHandler(this, &AddProductForm::AddProductForm_Load);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion
		private: Product^ CreateNewProduct()
		{
			if (!String::IsNullOrEmpty(tbName->Text))
			{
				if (!String::IsNullOrEmpty(tbDescription->Text))
				{
					if (!String::IsNullOrEmpty(tbPrice->Text))
					{
						Decimal price;
						if (Decimal::TryParse(tbPrice->Text, price))
						{
							price = Decimal::Parse(tbPrice->Text);
							{
								Product^ newProduct = gcnew Product((int)cbDishType->SelectedValue, tbName->Text, tbDescription->Text, price, tbPhoto->Text);
								return newProduct;
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
						MessageBox::Show("Введите цену", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return nullptr;
					}
				}
				else
				{
					MessageBox::Show("Введите описание", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return nullptr;
				}
			}
			else
			{
				MessageBox::Show("Введите название", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return nullptr;
			}	
		}

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

		private: System::Void BtnSave_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			sqlCommand->Parameters->Clear();
			sqlCommand->CommandText = "INSERT INTO Product (Type, Name, Description, Price, Picture) VALUES (@type, @name, @description, @price, @photo)";

			Product^ newProduct = CreateNewProduct();
			if (newProduct != nullptr)
			{
				if (!String::IsNullOrWhiteSpace(newProduct->GetPhoto()))
				{
					MemoryStream^ ms = gcnew MemoryStream();
					Image^ image = image->FromFile(newProduct->GetPhoto());
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
				sqlCommand->Parameters->AddWithValue("@type", newProduct->GetDishType());
				sqlCommand->Parameters->AddWithValue("@name", newProduct->GetName());
				sqlCommand->Parameters->AddWithValue("@description", newProduct->GetDescription());
				sqlCommand->Parameters->AddWithValue("@price", newProduct->GetPrice());
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
				MessageBox::Show("Не удалось добавить новый продукт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	private: System::Void AddProductForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		try
		{
			myConnection = gcnew SqlConnection(connStr);
			sqlCommand->Connection = myConnection;
			Product::InitDishDictionary();
			BindingSource^ bindSource = gcnew BindingSource(Product::dishDictionary, nullptr);
			cbDishType->DataSource = bindSource;
			cbDishType->DisplayMember = "Value";
			cbDishType->ValueMember = "Key";
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
