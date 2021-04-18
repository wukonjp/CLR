#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections::ObjectModel;

namespace CLRTest
{
	public ref class Person
	{
	public:
		property String^ Name;
		property int Age;

		Person(String^ name, int age)
		{
			Name = name;
			Age = age;
		}
	};

	public ref class MainModel : public INotifyPropertyChanged
	{
	private:
		String^ _text1;

	private:
		static MainModel()
		{
			MainModel::Instance = gcnew CLRTest::MainModel();
		}

	public:
		static property MainModel^ Instance;

		virtual event PropertyChangedEventHandler^ PropertyChanged;
		void RaisePropertyChanged(String^ propertyName)
		{
			PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
		}

		property BindingList<String^>^ Words;
		property BindingList<Person^>^ People;

		property String^ Text1
		{
			String^ get()
			{
				return _text1;
			}
			void set(String^ value)
			{
				if (_text1 != value)
				{
					_text1 = value;
					RaisePropertyChanged(L"Text1");
				}
			}
		}

		MainModel()
		{
			Words = gcnew BindingList<String^>();
			Words->Add(L"‚ ‚ ‚ ");
			Words->Add(L"‚¢‚¢‚¢");
			Words->Add(L"‚¤‚¤‚¤");
			Words->Add(L"‚¦‚¦‚¦");

			People = gcnew BindingList<Person^>();
			People->Add(gcnew Person{ L"‚P‚P‚P", 11 });
			People->Add(gcnew Person{ L"‚Q‚Q‚Q", 22 });
			People->Add(gcnew Person{ L"‚R‚R‚R", 33 });
			People->Add(gcnew Person{ L"‚S‚S‚S", 44 });
			People->Add(gcnew Person{ L"‚T‚T‚T", 55 });
		}
	};
}