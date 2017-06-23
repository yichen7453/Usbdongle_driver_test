// USBDongle_driver_test.cpp: 主要專案檔。

#include "stdafx.h"

#include "MyForm.h"

using namespace USBDongle_driver_test;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew MyForm());

	return 0;
}
