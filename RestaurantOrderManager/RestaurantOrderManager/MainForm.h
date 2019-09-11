#pragma once
#include "OrderListForm.h"
#include "StaffForm.h"
#include "MenuForm.h"
#include "ServiceForm.h"
namespace RestaurantOrderManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ picLogo;
	protected:
	private: System::Windows::Forms::Button^ btnOrderList;
	private: System::Windows::Forms::Button^ btnStatistics;
	private: System::Windows::Forms::Button^ btnMenu;
	private: System::Windows::Forms::Button^ btnService;

	private: System::Windows::Forms::Button^ btnStaff;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::Label^ lblTitle;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->picLogo = (gcnew System::Windows::Forms::PictureBox());
			this->btnOrderList = (gcnew System::Windows::Forms::Button());
			this->btnStatistics = (gcnew System::Windows::Forms::Button());
			this->btnMenu = (gcnew System::Windows::Forms::Button());
			this->btnService = (gcnew System::Windows::Forms::Button());
			this->btnStaff = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLogo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->SuspendLayout();
			// 
			// picLogo
			// 
			this->picLogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picLogo.Image")));
			this->picLogo->Location = System::Drawing::Point(24, 167);
			this->picLogo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->picLogo->Name = L"picLogo";
			this->picLogo->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->picLogo->Size = System::Drawing::Size(565, 427);
			this->picLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picLogo->TabIndex = 0;
			this->picLogo->TabStop = false;
			// 
			// btnOrderList
			// 
			this->btnOrderList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnOrderList->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnOrderList->Location = System::Drawing::Point(617, 194);
			this->btnOrderList->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnOrderList->MinimumSize = System::Drawing::Size(221, 64);
			this->btnOrderList->Name = L"btnOrderList";
			this->btnOrderList->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnOrderList->Size = System::Drawing::Size(316, 98);
			this->btnOrderList->TabIndex = 2;
			this->btnOrderList->Text = L"Журнал заказов";
			this->btnOrderList->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnOrderList->UseVisualStyleBackColor = true;
			this->btnOrderList->Click += gcnew System::EventHandler(this, &MainForm::BtnOrderList_Click);
			// 
			// btnStatistics
			// 
			this->btnStatistics->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnStatistics->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStatistics->Location = System::Drawing::Point(617, 454);
			this->btnStatistics->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnStatistics->MinimumSize = System::Drawing::Size(221, 64);
			this->btnStatistics->Name = L"btnStatistics";
			this->btnStatistics->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnStatistics->Size = System::Drawing::Size(316, 98);
			this->btnStatistics->TabIndex = 4;
			this->btnStatistics->Text = L"Статистика";
			this->btnStatistics->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnStatistics->UseVisualStyleBackColor = true;
			// 
			// btnMenu
			// 
			this->btnMenu->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnMenu->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnMenu->Location = System::Drawing::Point(617, 583);
			this->btnMenu->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnMenu->MinimumSize = System::Drawing::Size(221, 64);
			this->btnMenu->Name = L"btnMenu";
			this->btnMenu->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnMenu->Size = System::Drawing::Size(316, 98);
			this->btnMenu->TabIndex = 5;
			this->btnMenu->Text = L"Меню";
			this->btnMenu->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnMenu->UseVisualStyleBackColor = true;
			this->btnMenu->Click += gcnew System::EventHandler(this, &MainForm::BtnMenu_Click);
			// 
			// btnService
			// 
			this->btnService->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnService->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnService->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnService->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnService->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnService->Location = System::Drawing::Point(617, 70);
			this->btnService->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnService->MinimumSize = System::Drawing::Size(221, 64);
			this->btnService->Name = L"btnService";
			this->btnService->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnService->Size = System::Drawing::Size(316, 98);
			this->btnService->TabIndex = 1;
			this->btnService->Text = L"Обслуживание";
			this->btnService->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnService->UseVisualStyleBackColor = false;
			this->btnService->Click += gcnew System::EventHandler(this, &MainForm::BtnService_Click);
			// 
			// btnStaff
			// 
			this->btnStaff->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnStaff->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStaff->Location = System::Drawing::Point(617, 321);
			this->btnStaff->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnStaff->MinimumSize = System::Drawing::Size(221, 64);
			this->btnStaff->Name = L"btnStaff";
			this->btnStaff->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnStaff->Size = System::Drawing::Size(316, 98);
			this->btnStaff->TabIndex = 3;
			this->btnStaff->Text = L"Сотрудники";
			this->btnStaff->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnStaff->UseVisualStyleBackColor = true;
			this->btnStaff->Click += gcnew System::EventHandler(this, &MainForm::BtnStaff_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(629, 85);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 68);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(629, 337);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 68);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(629, 599);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(100, 68);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 8;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(629, 470);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 68);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 9;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(629, 210);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(100, 68);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 10;
			this->pictureBox5->TabStop = false;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Calibri", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblTitle->Location = System::Drawing::Point(16, 26);
			this->lblTitle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(520, 41);
			this->lblTitle->TabIndex = 11;
			this->lblTitle->Text = L"Система учета заказов клиентов";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(949, 708);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnStaff);
			this->Controls->Add(this->btnService);
			this->Controls->Add(this->btnMenu);
			this->Controls->Add(this->btnStatistics);
			this->Controls->Add(this->btnOrderList);
			this->Controls->Add(this->picLogo);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MinimumSize = System::Drawing::Size(833, 509);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Система учета заказов";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLogo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma region EventHandlers
	private: System::Void BtnOrderList_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Form^ orderListForm = Application::OpenForms["OrderListForm"];
		if (orderListForm != nullptr)
			orderListForm->BringToFront();
		else
		{
			OrderListForm^ orderListForm = gcnew OrderListForm();
			orderListForm->Show();
		}
	}
	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) 
	{
		if (MessageBox::Show("Вы действительно хотите выйти?", "Выход",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			Application::ExitThread();
		}
		else
		{
			e->Cancel = true;
		}
	}
	private: System::Void BtnStaff_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Form^ staffForm = Application::OpenForms["StaffForm"];
		if (staffForm != nullptr)
			staffForm->BringToFront();
		else
		{
			StaffForm^ staffForm = gcnew StaffForm();
			staffForm->Show();
		}
	}
	private: System::Void BtnMenu_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Form^ menuForm = Application::OpenForms["MenuForm"];
		if (menuForm != nullptr)
			menuForm->BringToFront();
		else
		{
			MenuForm^ menuForm = gcnew MenuForm();
			menuForm->Show();
		}
	}
private: System::Void BtnService_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Form^ serviceForm = Application::OpenForms["Service"];
	if (serviceForm != nullptr)
		serviceForm->BringToFront();
	else
	{
		Service^ serviceForm = gcnew Service();
		serviceForm->Show();
	}
}
};
#pragma endregion
}
