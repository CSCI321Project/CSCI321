#pragma once
#include "Video.h"
#include "Car.h"
#include "CarPart.h"
#include <Windows.h>
#include <wincon.h>
#include <vector>


namespace Drvr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// Summary for Infographics
	public ref class Infographics : public System::Windows::Forms::Form
	{
	
		public:
			Infographics(void)
			{
				InitializeComponent();
			
			}

			//SELF DEFINED FUNCTIONS 
			void calculateNeededButtons(int, List<Button ^>^ );
			void userClickedZoom();
			void ReadIn();
		
			//this function determines what kind of button layout is required 
			void partInfo(int);
			//function used to allow the useer to go to the next part
			void nextPart();
			//function used to allow the user to go to prev part
			void prevPart();
			//function used to reset the buttons 
			void resetButtons();
			//function used to reset global variables
			void resetVariables();
		

		protected:
			/// Clean up any resources being used.
			~Infographics()
			{
				if (components)
				{
					delete components;
				}
			}

		//All the object declaration
		private: System::Windows::Forms::Button^  returnToMain;
		private: System::Windows::Forms::PictureBox^  mainImage;
		private: System::Windows::Forms::TextBox^  descBox;
		private: System::Windows::Forms::Button^  videoOverlay;

		//Declaration for top 7 components
		private: System::Windows::Forms::Panel^  top7Components;
		private: System::Windows::Forms::Button^  b4Top7;
		private: System::Windows::Forms::Button^  b3Top7;
		private: System::Windows::Forms::Button^  b2Top7;
		private: System::Windows::Forms::Button^  b1Top7;
		private: System::Windows::Forms::Button^  b7Top7;
		private: System::Windows::Forms::Button^  b6Top7;
		private: System::Windows::Forms::Button^  b5Top7;
	
		//Declaration for bottom 7 components
		private: System::Windows::Forms::Panel^  btm7Components;
		private: System::Windows::Forms::Button^  b1Btm7;
		private: System::Windows::Forms::Button^  b2Btm7;
		private: System::Windows::Forms::Button^  b3Btm7;
		private: System::Windows::Forms::Button^  b4Btm7;
		private: System::Windows::Forms::Button^  b5Btm7;
		private: System::Windows::Forms::Button^  b6Btm7;
		private: System::Windows::Forms::Button^  b7Btm7;

		//Declaration for the directional arrows (zoom in, zoom out etc)
		private: System::Windows::Forms::Panel^  directionalArrows;
		private: System::Windows::Forms::PictureBox^  zoomIn;
		private: System::Windows::Forms::PictureBox^  nextView;
		private: System::Windows::Forms::PictureBox^  prevView;
		private: System::Windows::Forms::PictureBox^  zoomOut;

		private:
			/// Required designer variable.
		
			System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Infographics::typeid));
			this->returnToMain = (gcnew System::Windows::Forms::Button());
			this->mainImage = (gcnew System::Windows::Forms::PictureBox());
			this->top7Components = (gcnew System::Windows::Forms::Panel());
			this->b7Top7 = (gcnew System::Windows::Forms::Button());
			this->b6Top7 = (gcnew System::Windows::Forms::Button());
			this->b5Top7 = (gcnew System::Windows::Forms::Button());
			this->b4Top7 = (gcnew System::Windows::Forms::Button());
			this->b3Top7 = (gcnew System::Windows::Forms::Button());
			this->b2Top7 = (gcnew System::Windows::Forms::Button());
			this->b1Top7 = (gcnew System::Windows::Forms::Button());
			this->descBox = (gcnew System::Windows::Forms::TextBox());
			this->directionalArrows = (gcnew System::Windows::Forms::Panel());
			this->nextView = (gcnew System::Windows::Forms::PictureBox());
			this->prevView = (gcnew System::Windows::Forms::PictureBox());
			this->zoomOut = (gcnew System::Windows::Forms::PictureBox());
			this->zoomIn = (gcnew System::Windows::Forms::PictureBox());
			this->videoOverlay = (gcnew System::Windows::Forms::Button());
			this->b1Btm7 = (gcnew System::Windows::Forms::Button());
			this->b2Btm7 = (gcnew System::Windows::Forms::Button());
			this->b3Btm7 = (gcnew System::Windows::Forms::Button());
			this->b4Btm7 = (gcnew System::Windows::Forms::Button());
			this->b5Btm7 = (gcnew System::Windows::Forms::Button());
			this->b6Btm7 = (gcnew System::Windows::Forms::Button());
			this->b7Btm7 = (gcnew System::Windows::Forms::Button());
			this->btm7Components = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainImage))->BeginInit();
			this->top7Components->SuspendLayout();
			this->directionalArrows->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nextView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prevView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zoomOut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zoomIn))->BeginInit();
			this->btm7Components->SuspendLayout();
			this->SuspendLayout();
			// 
			// returnToMain
			// 
			this->returnToMain->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->returnToMain->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->returnToMain->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"returnToMain.BackgroundImage")));
			this->returnToMain->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->returnToMain->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->returnToMain->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->returnToMain->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(124)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->returnToMain->Location = System::Drawing::Point(31, 682);
			this->returnToMain->Margin = System::Windows::Forms::Padding(4);
			this->returnToMain->Name = L"returnToMain";
			this->returnToMain->Size = System::Drawing::Size(60, 55);
			this->returnToMain->TabIndex = 0;
			this->returnToMain->UseVisualStyleBackColor = false;
			this->returnToMain->Click += gcnew System::EventHandler(this, &Infographics::button1_Click);
			// 
			// mainImage
			// 
			this->mainImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mainImage->BackColor = System::Drawing::Color::Transparent;
			this->mainImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->mainImage->ImageLocation = L"";
			this->mainImage->Location = System::Drawing::Point(200, 124);
			this->mainImage->Margin = System::Windows::Forms::Padding(4);
			this->mainImage->Name = L"mainImage";
			this->mainImage->Size = System::Drawing::Size(624, 300);
			this->mainImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mainImage->TabIndex = 1;
			this->mainImage->TabStop = false;
			// 
			// top7Components
			// 
			this->top7Components->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->top7Components->BackColor = System::Drawing::Color::Transparent;
			this->top7Components->Controls->Add(this->b7Top7);
			this->top7Components->Controls->Add(this->b6Top7);
			this->top7Components->Controls->Add(this->b5Top7);
			this->top7Components->Controls->Add(this->b4Top7);
			this->top7Components->Controls->Add(this->b3Top7);
			this->top7Components->Controls->Add(this->b2Top7);
			this->top7Components->Controls->Add(this->b1Top7);
			this->top7Components->Cursor = System::Windows::Forms::Cursors::Hand;
			this->top7Components->Location = System::Drawing::Point(47, 30);
			this->top7Components->Margin = System::Windows::Forms::Padding(4);
			this->top7Components->Name = L"top7Components";
			this->top7Components->Size = System::Drawing::Size(938, 89);
			this->top7Components->TabIndex = 2;
			// 
			// b7Top7
			// 
			this->b7Top7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b7Top7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b7Top7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b7Top7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b7Top7->ForeColor = System::Drawing::Color::Black;
			this->b7Top7->Location = System::Drawing::Point(804, 0);
			this->b7Top7->Margin = System::Windows::Forms::Padding(4);
			this->b7Top7->Name = L"b7Top7";
			this->b7Top7->Size = System::Drawing::Size(134, 89);
			this->b7Top7->TabIndex = 6;
			this->b7Top7->Text = L"b7Top7";
			this->b7Top7->UseVisualStyleBackColor = false;
			this->b7Top7->Visible = false;
			// 
			// b6Top7
			// 
			this->b6Top7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b6Top7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b6Top7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b6Top7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b6Top7->ForeColor = System::Drawing::Color::Black;
			this->b6Top7->Location = System::Drawing::Point(670, 0);
			this->b6Top7->Margin = System::Windows::Forms::Padding(4);
			this->b6Top7->Name = L"b6Top7";
			this->b6Top7->Size = System::Drawing::Size(134, 89);
			this->b6Top7->TabIndex = 5;
			this->b6Top7->Text = L"b6Top7";
			this->b6Top7->UseVisualStyleBackColor = false;
			this->b6Top7->Visible = false;
			// 
			// b5Top7
			// 
			this->b5Top7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b5Top7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b5Top7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b5Top7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b5Top7->ForeColor = System::Drawing::Color::Black;
			this->b5Top7->Location = System::Drawing::Point(536, 0);
			this->b5Top7->Margin = System::Windows::Forms::Padding(4);
			this->b5Top7->Name = L"b5Top7";
			this->b5Top7->Size = System::Drawing::Size(134, 89);
			this->b5Top7->TabIndex = 5;
			this->b5Top7->Text = L"b5Top7";
			this->b5Top7->UseVisualStyleBackColor = false;
			this->b5Top7->Visible = false;
			// 
			// b4Top7
			// 
			this->b4Top7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b4Top7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b4Top7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b4Top7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b4Top7->ForeColor = System::Drawing::Color::Black;
			this->b4Top7->Location = System::Drawing::Point(402, 0);
			this->b4Top7->Margin = System::Windows::Forms::Padding(4);
			this->b4Top7->Name = L"b4Top7";
			this->b4Top7->Size = System::Drawing::Size(134, 89);
			this->b4Top7->TabIndex = 4;
			this->b4Top7->Text = L"b4Top7";
			this->b4Top7->UseVisualStyleBackColor = false;
			this->b4Top7->Visible = false;
			// 
			// b3Top7
			// 
			this->b3Top7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b3Top7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b3Top7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b3Top7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b3Top7->ForeColor = System::Drawing::Color::Black;
			this->b3Top7->Location = System::Drawing::Point(268, 0);
			this->b3Top7->Margin = System::Windows::Forms::Padding(4);
			this->b3Top7->Name = L"b3Top7";
			this->b3Top7->Size = System::Drawing::Size(134, 89);
			this->b3Top7->TabIndex = 2;
			this->b3Top7->Text = L"b3Top7";
			this->b3Top7->UseVisualStyleBackColor = false;
			this->b3Top7->Visible = false;
			// 
			// b2Top7
			// 
			this->b2Top7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b2Top7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b2Top7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b2Top7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b2Top7->ForeColor = System::Drawing::Color::Black;
			this->b2Top7->Location = System::Drawing::Point(134, 0);
			this->b2Top7->Margin = System::Windows::Forms::Padding(4);
			this->b2Top7->Name = L"b2Top7";
			this->b2Top7->Size = System::Drawing::Size(134, 89);
			this->b2Top7->TabIndex = 1;
			this->b2Top7->Text = L"b2Top7";
			this->b2Top7->UseVisualStyleBackColor = false;
			this->b2Top7->Visible = false;
			// 
			// b1Top7
			// 
			this->b1Top7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b1Top7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b1Top7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b1Top7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b1Top7->ForeColor = System::Drawing::Color::Black;
			this->b1Top7->Location = System::Drawing::Point(0, 0);
			this->b1Top7->Margin = System::Windows::Forms::Padding(4);
			this->b1Top7->Name = L"b1Top7";
			this->b1Top7->Size = System::Drawing::Size(134, 89);
			this->b1Top7->TabIndex = 0;
			this->b1Top7->Text = L"b1Top7";
			this->b1Top7->UseVisualStyleBackColor = false;
			this->b1Top7->Visible = false;
			this->b1Top7->Click += gcnew System::EventHandler(this, &Infographics::b1Top7_Click);
			this->b1Top7->Enter += gcnew System::EventHandler(this, &Infographics::b1Top7_Enter);
			// 
			// descBox
			// 
			this->descBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->descBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descBox->Location = System::Drawing::Point(132, 538);
			this->descBox->Margin = System::Windows::Forms::Padding(4);
			this->descBox->Multiline = true;
			this->descBox->Name = L"descBox";
			this->descBox->Size = System::Drawing::Size(639, 213);
			this->descBox->TabIndex = 8;
			this->descBox->TextChanged += gcnew System::EventHandler(this, &Infographics::descBox_TextChanged);
			// 
			// directionalArrows
			// 
			this->directionalArrows->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->directionalArrows->BackColor = System::Drawing::Color::Transparent;
			this->directionalArrows->Controls->Add(this->nextView);
			this->directionalArrows->Controls->Add(this->prevView);
			this->directionalArrows->Controls->Add(this->zoomOut);
			this->directionalArrows->Controls->Add(this->zoomIn);
			this->directionalArrows->Location = System::Drawing::Point(779, 551);
			this->directionalArrows->Margin = System::Windows::Forms::Padding(4);
			this->directionalArrows->Name = L"directionalArrows";
			this->directionalArrows->Size = System::Drawing::Size(215, 191);
			this->directionalArrows->TabIndex = 9;
			// 
			// nextView
			// 
			this->nextView->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->nextView->Cursor = System::Windows::Forms::Cursors::Hand;
			this->nextView->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"nextView.Image")));
			this->nextView->Location = System::Drawing::Point(139, 73);
			this->nextView->Margin = System::Windows::Forms::Padding(4);
			this->nextView->Name = L"nextView";
			this->nextView->Size = System::Drawing::Size(56, 48);
			this->nextView->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->nextView->TabIndex = 3;
			this->nextView->TabStop = false;
			this->nextView->Click += gcnew System::EventHandler(this, &Infographics::nextView_Click);
			// 
			// prevView
			// 
			this->prevView->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->prevView->Cursor = System::Windows::Forms::Cursors::Hand;
			this->prevView->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"prevView.Image")));
			this->prevView->Location = System::Drawing::Point(13, 73);
			this->prevView->Margin = System::Windows::Forms::Padding(4);
			this->prevView->Name = L"prevView";
			this->prevView->Size = System::Drawing::Size(56, 48);
			this->prevView->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->prevView->TabIndex = 2;
			this->prevView->TabStop = false;
			this->prevView->Click += gcnew System::EventHandler(this, &Infographics::prevView_Click);
			// 
			// zoomOut
			// 
			this->zoomOut->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->zoomOut->Cursor = System::Windows::Forms::Cursors::Hand;
			this->zoomOut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"zoomOut.Image")));
			this->zoomOut->Location = System::Drawing::Point(77, 124);
			this->zoomOut->Margin = System::Windows::Forms::Padding(4);
			this->zoomOut->Name = L"zoomOut";
			this->zoomOut->Size = System::Drawing::Size(56, 48);
			this->zoomOut->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->zoomOut->TabIndex = 1;
			this->zoomOut->TabStop = false;
			this->zoomOut->Click += gcnew System::EventHandler(this, &Infographics::zoomOut_Click);
			// 
			// zoomIn
			// 
			this->zoomIn->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->zoomIn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->zoomIn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"zoomIn.Image")));
			this->zoomIn->Location = System::Drawing::Point(77, 16);
			this->zoomIn->Margin = System::Windows::Forms::Padding(4);
			this->zoomIn->Name = L"zoomIn";
			this->zoomIn->Size = System::Drawing::Size(56, 48);
			this->zoomIn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->zoomIn->TabIndex = 0;
			this->zoomIn->TabStop = false;
			this->zoomIn->Click += gcnew System::EventHandler(this, &Infographics::zoomIn_Click);
			// 
			// videoOverlay
			// 
			this->videoOverlay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->videoOverlay->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"videoOverlay.BackgroundImage")));
			this->videoOverlay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->videoOverlay->Location = System::Drawing::Point(676, 682);
			this->videoOverlay->Margin = System::Windows::Forms::Padding(4);
			this->videoOverlay->Name = L"videoOverlay";
			this->videoOverlay->Size = System::Drawing::Size(95, 69);
			this->videoOverlay->TabIndex = 10;
			this->videoOverlay->UseVisualStyleBackColor = true;
			this->videoOverlay->Visible = false;
			this->videoOverlay->Click += gcnew System::EventHandler(this, &Infographics::videoOverlay_Click);
			// 
			// b1Btm7
			// 
			this->b1Btm7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b1Btm7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b1Btm7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b1Btm7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b1Btm7->ForeColor = System::Drawing::Color::Black;
			this->b1Btm7->Location = System::Drawing::Point(0, 0);
			this->b1Btm7->Margin = System::Windows::Forms::Padding(4);
			this->b1Btm7->Name = L"b1Btm7";
			this->b1Btm7->Size = System::Drawing::Size(134, 89);
			this->b1Btm7->TabIndex = 0;
			this->b1Btm7->Text = L"b1Btm7";
			this->b1Btm7->UseVisualStyleBackColor = false;
			this->b1Btm7->Visible = false;
			// 
			// b2Btm7
			// 
			this->b2Btm7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b2Btm7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b2Btm7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b2Btm7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b2Btm7->ForeColor = System::Drawing::Color::Black;
			this->b2Btm7->Location = System::Drawing::Point(134, 0);
			this->b2Btm7->Margin = System::Windows::Forms::Padding(4);
			this->b2Btm7->Name = L"b2Btm7";
			this->b2Btm7->Size = System::Drawing::Size(134, 89);
			this->b2Btm7->TabIndex = 1;
			this->b2Btm7->Text = L"b2Btm7";
			this->b2Btm7->UseVisualStyleBackColor = false;
			this->b2Btm7->Visible = false;
			this->b2Btm7->Click += gcnew System::EventHandler(this, &Infographics::b2Btm7_Click);
			// 
			// b3Btm7
			// 
			this->b3Btm7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b3Btm7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b3Btm7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b3Btm7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b3Btm7->ForeColor = System::Drawing::Color::Black;
			this->b3Btm7->Location = System::Drawing::Point(268, 0);
			this->b3Btm7->Margin = System::Windows::Forms::Padding(4);
			this->b3Btm7->Name = L"b3Btm7";
			this->b3Btm7->Size = System::Drawing::Size(134, 89);
			this->b3Btm7->TabIndex = 2;
			this->b3Btm7->Text = L"b3Btm7";
			this->b3Btm7->UseVisualStyleBackColor = false;
			this->b3Btm7->Visible = false;
			// 
			// b4Btm7
			// 
			this->b4Btm7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b4Btm7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b4Btm7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b4Btm7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b4Btm7->ForeColor = System::Drawing::Color::Black;
			this->b4Btm7->Location = System::Drawing::Point(402, 0);
			this->b4Btm7->Margin = System::Windows::Forms::Padding(4);
			this->b4Btm7->Name = L"b4Btm7";
			this->b4Btm7->Size = System::Drawing::Size(134, 89);
			this->b4Btm7->TabIndex = 4;
			this->b4Btm7->Text = L"b4Btm7";
			this->b4Btm7->UseVisualStyleBackColor = false;
			this->b4Btm7->Visible = false;
			// 
			// b5Btm7
			// 
			this->b5Btm7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b5Btm7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b5Btm7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b5Btm7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b5Btm7->ForeColor = System::Drawing::Color::Black;
			this->b5Btm7->Location = System::Drawing::Point(536, 0);
			this->b5Btm7->Margin = System::Windows::Forms::Padding(4);
			this->b5Btm7->Name = L"b5Btm7";
			this->b5Btm7->Size = System::Drawing::Size(134, 89);
			this->b5Btm7->TabIndex = 5;
			this->b5Btm7->Text = L"b5Btm7";
			this->b5Btm7->UseVisualStyleBackColor = false;
			this->b5Btm7->Visible = false;
			// 
			// b6Btm7
			// 
			this->b6Btm7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b6Btm7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b6Btm7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b6Btm7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b6Btm7->ForeColor = System::Drawing::Color::Black;
			this->b6Btm7->Location = System::Drawing::Point(670, 0);
			this->b6Btm7->Margin = System::Windows::Forms::Padding(4);
			this->b6Btm7->Name = L"b6Btm7";
			this->b6Btm7->Size = System::Drawing::Size(134, 89);
			this->b6Btm7->TabIndex = 5;
			this->b6Btm7->Text = L"b6Btm7";
			this->b6Btm7->UseVisualStyleBackColor = false;
			this->b6Btm7->Visible = false;
			// 
			// b7Btm7
			// 
			this->b7Btm7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->b7Btm7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSkyBlue;
			this->b7Btm7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->b7Btm7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold));
			this->b7Btm7->ForeColor = System::Drawing::Color::Black;
			this->b7Btm7->Location = System::Drawing::Point(804, 0);
			this->b7Btm7->Margin = System::Windows::Forms::Padding(4);
			this->b7Btm7->Name = L"b7Btm7";
			this->b7Btm7->Size = System::Drawing::Size(134, 89);
			this->b7Btm7->TabIndex = 6;
			this->b7Btm7->Text = L"b7Btm7";
			this->b7Btm7->UseVisualStyleBackColor = false;
			this->b7Btm7->Visible = false;
			this->b7Btm7->Click += gcnew System::EventHandler(this, &Infographics::b7Btm7_Click);
			// 
			// btm7Components
			// 
			this->btm7Components->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->btm7Components->BackColor = System::Drawing::Color::Transparent;
			this->btm7Components->Controls->Add(this->b7Btm7);
			this->btm7Components->Controls->Add(this->b6Btm7);
			this->btm7Components->Controls->Add(this->b5Btm7);
			this->btm7Components->Controls->Add(this->b4Btm7);
			this->btm7Components->Controls->Add(this->b3Btm7);
			this->btm7Components->Controls->Add(this->b2Btm7);
			this->btm7Components->Controls->Add(this->b1Btm7);
			this->btm7Components->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btm7Components->Location = System::Drawing::Point(47, 431);
			this->btm7Components->Margin = System::Windows::Forms::Padding(4);
			this->btm7Components->Name = L"btm7Components";
			this->btm7Components->Size = System::Drawing::Size(938, 89);
			this->btm7Components->TabIndex = 7;
			// 
			// Infographics
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1024, 768);
			this->ControlBox = false;
			this->Controls->Add(this->top7Components);
			this->Controls->Add(this->directionalArrows);
			this->Controls->Add(this->btm7Components);
			this->Controls->Add(this->videoOverlay);
			this->Controls->Add(this->descBox);
			this->Controls->Add(this->mainImage);
			this->Controls->Add(this->returnToMain);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Infographics";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &Infographics::Infographics_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainImage))->EndInit();
			this->top7Components->ResumeLayout(false);
			this->directionalArrows->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nextView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->prevView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zoomOut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zoomIn))->EndInit();
			this->btm7Components->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		//this is the button that you would click to exit the inforgraphics section
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			//apparently we need to reset the values which are global here, otherwise if the user reenters, it will be loading the previous layer
			resetVariables();
			this->Close();
		}
		private: System::Void Infographics_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			ReadIn();
			mainImage->Image = Image::FromFile("cars/default.png");
		}
		private: System::Void b1Top7_Enter(System::Object^  sender, System::EventArgs^  e) 
		{
			mainImage->Image = Image::FromFile("cars/frontsidemirror.png");
			b1Top7->BackColor = System::Drawing::Color::LightSkyBlue;
			descBox->Text = "The side mirror is a mirror found on the exterior of motor vehicles for the purposes of helping the driver see areas behind and to the sides of the vehicle, outside of the driver's peripheral vision (in the 'blind spot').";
		}
		private: System::Void videoOverlay_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Video ^ overlay = gcnew Video;
			overlay->ShowDialog();
		}
		private: System::Void b2Btm7_Click(System::Object^  sender, System::EventArgs^  e) 
		{

		}
		private: System::Void zoomIn_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			userClickedZoom();
		}
		private: System::Void descBox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
	
		}
		private: System::Void zoomOut_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			
		}
		private: System::Void b7Btm7_Click(System::Object^  sender, System::EventArgs^  e) 
		{
	
		}
		//the right button
		private: System::Void nextView_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			nextPart();
		}
		//left button
		private: System::Void prevView_Click(System::Object^  sender, System::EventArgs^  e) \
		{
			prevPart();
		}
		private: System::Void b1Top7_Click(System::Object^  sender, System::EventArgs^  e) 
		{
	
		}
		
	};
}