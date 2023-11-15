#include "InventoryForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	DiplomaOrders::InventoryForm form;
	Application::Run(% form);
}