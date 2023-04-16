#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace CLRTest
{
	ref class App abstract sealed
	{
	public:
		[STAThread]
		static void Main(array<String^>^ args)
		{
			Application::EnableVisualStyles();
			Application::SetCompatibleTextRenderingDefault(false);

			MyForm^ form = gcnew MyForm();
			Application::Run(form);
			delete form;
		}
	};
}
