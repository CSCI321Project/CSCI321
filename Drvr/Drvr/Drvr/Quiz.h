#pragma once
#include "QuizMain.h"

namespace Drvr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Quiz
	/// </summary>
	public ref class Quiz : public System::Windows::Forms::Form
	{
	public:
		Quiz(void)
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
		~Quiz()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  returnMainMenu;
	protected:

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  proceed;

	private: System::Windows::Forms::RichTextBox^  rulesAndRegulations;



	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Quiz::typeid));
			this->returnMainMenu = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->proceed = (gcnew System::Windows::Forms::Button());
			this->rulesAndRegulations = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// returnMainMenu
			// 
			this->returnMainMenu->BackColor = System::Drawing::Color::LightSteelBlue;
			this->returnMainMenu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"returnMainMenu.BackgroundImage")));
			this->returnMainMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->returnMainMenu->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->returnMainMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->returnMainMenu->Location = System::Drawing::Point(13, 709);
			this->returnMainMenu->Margin = System::Windows::Forms::Padding(4);
			this->returnMainMenu->Name = L"returnMainMenu";
			this->returnMainMenu->Size = System::Drawing::Size(50, 46);
			this->returnMainMenu->TabIndex = 1;
			this->returnMainMenu->UseVisualStyleBackColor = false;
			this->returnMainMenu->Click += gcnew System::EventHandler(this, &Quiz::returnMainMenu_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->proceed);
			this->groupBox1->Controls->Add(this->rulesAndRegulations);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(57, 59);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(910, 650);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"BEFORE YOU BEGIN...";
			// 
			// proceed
			// 
			this->proceed->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->proceed->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->proceed->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Bold));
			this->proceed->Location = System::Drawing::Point(314, 501);
			this->proceed->Margin = System::Windows::Forms::Padding(4);
			this->proceed->Name = L"proceed";
			this->proceed->Size = System::Drawing::Size(283, 53);
			this->proceed->TabIndex = 1;
			this->proceed->Text = L"PROCEED!";
			this->proceed->UseVisualStyleBackColor = false;
			this->proceed->Click += gcnew System::EventHandler(this, &Quiz::proceed_Click);
			// 
			// rulesAndRegulations
			// 
			this->rulesAndRegulations->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->rulesAndRegulations->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->rulesAndRegulations->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13, System::Drawing::FontStyle::Bold));
			this->rulesAndRegulations->Location = System::Drawing::Point(28, 73);
			this->rulesAndRegulations->Margin = System::Windows::Forms::Padding(4);
			this->rulesAndRegulations->Name = L"rulesAndRegulations";
			this->rulesAndRegulations->Size = System::Drawing::Size(854, 356);
			this->rulesAndRegulations->TabIndex = 0;
			this->rulesAndRegulations->Text = resources->GetString(L"rulesAndRegulations.Text");
			// 
			// Quiz
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1024, 768);
			this->ControlBox = false;
			this->Controls->Add(this->returnMainMenu);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Quiz";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Quiz";
			this->TopMost = true;
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void returnMainMenu_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
	private: System::Void proceed_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Hide();
				 QuizMain ^form = gcnew QuizMain;
				 form->ShowDialog();
				 this->Close();
	}

};
}
