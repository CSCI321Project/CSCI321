#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

// has to be done to make a windows form
// default code required :v
[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Drvr::MyForm form;
	Application::Run(%form);
}