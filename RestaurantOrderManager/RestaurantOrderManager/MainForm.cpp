#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	RestaurantOrderManager::MainForm form;
	Application::Run(% form);
}
