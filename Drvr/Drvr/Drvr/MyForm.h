#pragma once
#include "Infographics.h"
#include "Simulation.h"
#include "Quiz.h"

namespace Drvr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  MainLogo;
	protected:

	private: System::Windows::Forms::Button^  exit;
	private: System::Windows::Forms::Button^  infographicsButton;
	private: System::Windows::Forms::Button^  simulationButton;
	private: System::Windows::Forms::Button^  quizButton;







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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->MainLogo = (gcnew System::Windows::Forms::PictureBox());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->infographicsButton = (gcnew System::Windows::Forms::Button());
			this->simulationButton = (gcnew System::Windows::Forms::Button());
			this->quizButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainLogo))->BeginInit();
			this->SuspendLayout();
			// 
			// MainLogo
			// 
			this->MainLogo->BackColor = System::Drawing::Color::Transparent;
			this->MainLogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MainLogo.Image")));
			this->MainLogo->Location = System::Drawing::Point(260, 49);
			this->MainLogo->Margin = System::Windows::Forms::Padding(4);
			this->MainLogo->Name = L"MainLogo";
			this->MainLogo->Size = System::Drawing::Size(504, 255);
			this->MainLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->MainLogo->TabIndex = 0;
			this->MainLogo->TabStop = false;
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->exit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exit.BackgroundImage")));
			this->exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exit->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit->Location = System::Drawing::Point(13, 700);
			this->exit->Margin = System::Windows::Forms::Padding(4);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(60, 55);
			this->exit->TabIndex = 1;
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &MyForm::exit_Click);
			// 
			// infographicsButton
			// 
			this->infographicsButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(107)));
			this->infographicsButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->infographicsButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->infographicsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->infographicsButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infographicsButton->ForeColor = System::Drawing::Color::White;
			this->infographicsButton->Location = System::Drawing::Point(237, 349);
			this->infographicsButton->Margin = System::Windows::Forms::Padding(4);
			this->infographicsButton->Name = L"infographicsButton";
			this->infographicsButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->infographicsButton->Size = System::Drawing::Size(550, 60);
			this->infographicsButton->TabIndex = 2;
			this->infographicsButton->Text = L"INFOGRAPHICS";
			this->infographicsButton->UseVisualStyleBackColor = false;
			this->infographicsButton->Click += gcnew System::EventHandler(this, &MyForm::infographicsButton_Click);
			// 
			// simulationButton
			// 
			this->simulationButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(107)));
			this->simulationButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->simulationButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->simulationButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->simulationButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->simulationButton->ForeColor = System::Drawing::Color::White;
			this->simulationButton->Location = System::Drawing::Point(237, 465);
			this->simulationButton->Margin = System::Windows::Forms::Padding(4);
			this->simulationButton->Name = L"simulationButton";
			this->simulationButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->simulationButton->Size = System::Drawing::Size(550, 60);
			this->simulationButton->TabIndex = 3;
			this->simulationButton->Text = L"SIMULATION";
			this->simulationButton->UseVisualStyleBackColor = false;
			this->simulationButton->Click += gcnew System::EventHandler(this, &MyForm::simulationButton_Click);
			// 
			// quizButton
			// 
			this->quizButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(107)));
			this->quizButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->quizButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->quizButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->quizButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Bold));
			this->quizButton->ForeColor = System::Drawing::Color::White;
			this->quizButton->Location = System::Drawing::Point(237, 581);
			this->quizButton->Margin = System::Windows::Forms::Padding(4);
			this->quizButton->Name = L"quizButton";
			this->quizButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->quizButton->Size = System::Drawing::Size(550, 60);
			this->quizButton->TabIndex = 4;
			this->quizButton->Text = L"QUIZ";
			this->quizButton->UseVisualStyleBackColor = false;
			this->quizButton->Click += gcnew System::EventHandler(this, &MyForm::quizButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1024, 768);
			this->ControlBox = false;
			this->Controls->Add(this->quizButton);
			this->Controls->Add(this->simulationButton);
			this->Controls->Add(this->infographicsButton);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->MainLogo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Drvr";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainLogo))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
	}
	
private: System::Void infographicsButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Infographics ^ form = gcnew Infographics;
			 form->ShowDialog();
			 
}
private: System::Void simulationButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Simulation ^ form2 = gcnew Simulation;
			 form2->ShowDialog();
			 
}
private: System::Void quizButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Quiz ^form3 = gcnew Quiz;
			 form3->ShowDialog();
			 
}
};
}
