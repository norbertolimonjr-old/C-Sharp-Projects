#pragma once
#include <string>
#include <cstdlib>
#include <ctime>

// String^


namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		double randomNumber;
		double myNumber = 0;
		double previousGuess;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			srand(time(0)); //sets the seed to a new value with each execution according to te current time.
			randomNumber = (rand() % 10) + 1; //start your form with randomnumber initialized

			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ mainTitleLabel;


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->mainTitleLabel = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(44, 172);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(155, 172);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Retry";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// mainTitleLabel
			// 
			this->mainTitleLabel->AutoSize = true;
			this->mainTitleLabel->Font = (gcnew System::Drawing::Font(L"Rubik", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mainTitleLabel->Location = System::Drawing::Point(12, 33);
			this->mainTitleLabel->Name = L"mainTitleLabel";
			this->mainTitleLabel->Size = System::Drawing::Size(265, 19);
			this->mainTitleLabel->TabIndex = 2;
			this->mainTitleLabel->Text = L"I have a number between 1 and 10";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(90, 104);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(72, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Can you guess the number\?";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SeaShell;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->mainTitleLabel);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"GuessingGame";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Submit a guess
		previousGuess = myNumber;
		myNumber = Convert::ToDouble(this->textBox1->Text);
		if (myNumber > randomNumber) {
			this->mainTitleLabel->Text = "Too High";
			if (abs(myNumber - randomNumber) > abs(previousGuess - randomNumber)) {
				// Colder
				this->BackColor = System::Drawing::Color::Blue;
			}
			else if (abs(myNumber - randomNumber) < abs(previousGuess - randomNumber)) {
				// Warmer
				this->BackColor = System::Drawing::Color::Red;
			}
		}
		else if (myNumber < randomNumber) {
			this->mainTitleLabel->Text = "Too Low";
			if (abs(myNumber - randomNumber) > abs(previousGuess - randomNumber)) {
				// Colder
				this->BackColor = System::Drawing::Color::Blue;
			}
			else if (abs(myNumber - randomNumber) < abs(previousGuess - randomNumber)) {
				// Warmer
				this->BackColor = System::Drawing::Color::Red;
			}
		}
		else {
			this->mainTitleLabel->Text = Convert::ToString("Correct! " + myNumber + " is the right number!");
			this->BackColor = System::Drawing::Color::LimeGreen;
			this->textBox1->Enabled = false;
		}

		String^ myLocalStringPointer = this->textBox1->Text;
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Reset button - Try again.
	CppCLRWinformsProjekt::Form1();
	srand(time(0)); //sets the seed to a new value with each execution according to te current time.
	randomNumber = (rand() % 10) + 1; //start your form with randomnumber initialized
	this->mainTitleLabel->Text = L"I have a number between 1 and 10";
	this->BackColor = System::Drawing::Color::SeaShell;
	this->textBox1->Enabled = true;
}
};
}
