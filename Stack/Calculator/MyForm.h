#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include "../Stack/Calculator.h"

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;




	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(20, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(290, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(328, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(55, 19);
			this->button1->TabIndex = 1;
			this->button1->Text = L"=";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(405, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(10, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L" ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 298);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string infix;
		infix = msclr::interop::marshal_as<std::string>(textBox1->Text);
		TCalculator calc;
		calc.SetExpression(infix);
		calc.ToPostfix();
		double res = calc.CalcPostfix();
		//label1->Text = Convert::ToString(res);
		label1->Text = msclr::interop::marshal_as<String^>(calc.GetPostfix());
	}*/
	private: System::Void Button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		std::string infix;
		infix = msclr::interop::marshal_as<std::string>(textBox1->Text);
		TCalculator calc;
		calc.SetExpression(infix);
		calc.ToPostfix();
		double res = calc.CalcPostfix();
		label1->Text = Convert::ToString(res);
		//label1->Text = msclr::interop::marshal_as<String^>(calc.GetPostfix());

	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == 13) 
		{
			Button1_Click_1(sender,e);
			//button1_Click(sender, e);
		}
	}
};
}
