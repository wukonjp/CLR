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
			Words->Add(L"あああ");
			Words->Add(L"いいい");
			Words->Add(L"ううう");
			Words->Add(L"えええ");

			People = gcnew BindingList<Person^>();
			People->Add(gcnew Person{ L"１１１", 11 });
			People->Add(gcnew Person{ L"２２２", 22 });
			People->Add(gcnew Person{ L"３３３", 33 });
			People->Add(gcnew Person{ L"４４４", 44 });
			People->Add(gcnew Person{ L"５５５", 55 });
		}
	};
}