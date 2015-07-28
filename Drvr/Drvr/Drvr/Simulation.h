#pragma once
#include "threadmonitor.h"

namespace Drvr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Simulation
	/// </summary>
	public ref class Simulation : public System::Windows::Forms::Form
	{
	public:
		Simulation(void)
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
		~Simulation()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::TextBox^  textBox5;



	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Panel^  panel3;




	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button13;

	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button22;













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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Simulation::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(0, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 62);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Wheel Drive System";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Simulation::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(133, 0);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(128, 62);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Fuel System";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Simulation::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(0, 61);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(136, 61);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Electrical System";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Simulation::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(133, 61);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(128, 61);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Cooling System";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Simulation::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(0, 122);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(136, 59);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Steering System";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Simulation::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(133, 122);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(127, 59);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Braking System";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Simulation::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(1, 178);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(135, 59);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Adding Attachment";
			this->button8->UseVisualStyleBackColor = false;
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(133, 178);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(128, 59);
			this->button9->TabIndex = 6;
			this->button9->Text = L"Alternative Fuel Drivetrains";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Simulation::button9_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button9);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Location = System::Drawing::Point(17, 32);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(261, 238);
			this->panel1->TabIndex = 10;
			// 
			// splitContainer1
			// 
			this->splitContainer1->BackColor = System::Drawing::Color::Transparent;
			this->splitContainer1->Location = System::Drawing::Point(0, 289);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::Color::Transparent;
			this->splitContainer1->Panel1->Controls->Add(this->groupBox3);
			this->splitContainer1->Panel1->Controls->Add(this->button12);
			this->splitContainer1->Panel1->Controls->Add(this->groupBox2);
			this->splitContainer1->Panel1->Controls->Add(this->groupBox1);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulation::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->BackColor = System::Drawing::Color::Transparent;
			this->splitContainer1->Panel2->Controls->Add(this->panel4);
			this->splitContainer1->Panel2->Controls->Add(this->panel3);
			this->splitContainer1->Panel2->Controls->Add(this->pictureBox2);
			this->splitContainer1->Panel2->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->splitContainer1->Size = System::Drawing::Size(1022, 408);
			this->splitContainer1->SplitterDistance = 85;
			this->splitContainer1->TabIndex = 11;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->Controls->Add(this->button19);
			this->groupBox3->Controls->Add(this->button20);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(799, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(180, 79);
			this->groupBox3->TabIndex = 9;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"ALTITUDE (m)";
			// 
			// textBox4
			// 
			this->textBox4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"LCD", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(56, 26);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(64, 47);
			this->textBox4->TabIndex = 5;
			this->textBox4->Text = L"150";
			// 
			// button19
			// 
			this->button19->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button19->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button19.BackgroundImage")));
			this->button19->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button19->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button19->FlatAppearance->BorderSize = 2;
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Location = System::Drawing::Point(7, 36);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(43, 37);
			this->button19->TabIndex = 7;
			this->button19->UseVisualStyleBackColor = false;
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button20->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button20.BackgroundImage")));
			this->button20->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button20->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button20->FlatAppearance->BorderSize = 2;
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Location = System::Drawing::Point(126, 36);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(43, 37);
			this->button20->TabIndex = 6;
			this->button20->UseVisualStyleBackColor = false;
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button12->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(99, 22);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(154, 46);
			this->button12->TabIndex = 10;
			this->button12->Text = L"START ENGINE!";
			this->button12->UseVisualStyleBackColor = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->button10);
			this->groupBox2->Controls->Add(this->button11);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(584, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(180, 79);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"INCLINE (%)";
			// 
			// textBox6
			// 
			this->textBox6->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"LCD", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(56, 26);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(64, 47);
			this->textBox6->TabIndex = 5;
			this->textBox6->Text = L"1";
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button10.BackgroundImage")));
			this->button10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button10->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button10->FlatAppearance->BorderSize = 2;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Location = System::Drawing::Point(6, 36);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(43, 37);
			this->button10->TabIndex = 7;
			this->button10->UseVisualStyleBackColor = false;
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button11.BackgroundImage")));
			this->button11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button11->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button11->FlatAppearance->BorderSize = 2;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Location = System::Drawing::Point(126, 36);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(43, 37);
			this->button11->TabIndex = 6;
			this->button11->UseVisualStyleBackColor = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->button14);
			this->groupBox1->Controls->Add(this->button15);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(360, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(180, 79);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"SPEED (km/h)";
			// 
			// textBox5
			// 
			this->textBox5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"LCD", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(56, 26);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(64, 47);
			this->textBox5->TabIndex = 5;
			this->textBox5->Text = L"10";
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button14.BackgroundImage")));
			this->button14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button14->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button14->FlatAppearance->BorderSize = 2;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Location = System::Drawing::Point(7, 36);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(43, 37);
			this->button14->TabIndex = 7;
			this->button14->UseVisualStyleBackColor = false;
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.BackgroundImage")));
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button15->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button15->FlatAppearance->BorderSize = 2;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Location = System::Drawing::Point(126, 36);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(43, 37);
			this->button15->TabIndex = 6;
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &Simulation::button15_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->button23);
			this->panel4->Controls->Add(this->button17);
			this->panel4->Location = System::Drawing::Point(632, 187);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(332, 118);
			this->panel4->TabIndex = 2;
			this->panel4->Visible = false;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button22);
			this->panel3->Controls->Add(this->button16);
			this->panel3->Controls->Add(this->button13);
			this->panel3->Location = System::Drawing::Point(626, 18);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(370, 163);
			this->panel3->TabIndex = 1;
			this->panel3->Visible = false;
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Location = System::Drawing::Point(222, 30);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(145, 53);
			this->button16->TabIndex = 1;
			this->button16->Text = L"Simulate Filling Fuel";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &Simulation::button16_Click_1);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Location = System::Drawing::Point(0, 30);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(145, 53);
			this->button13->TabIndex = 0;
			this->button13->Text = L"Simulate Low Fuel";
			this->button13->UseVisualStyleBackColor = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(12, 18);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(591, 298);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Location = System::Drawing::Point(305, 17);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(691, 253);
			this->panel2->TabIndex = 12;
			// 
			// textBox3
			// 
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"LCD", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(438, 109);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(60, 37);
			this->textBox3->TabIndex = 3;
			this->textBox3->Text = L"60";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"LCD", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(223, 112);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(64, 37);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"15%";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"LCD", 45.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(325, 83);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(74, 61);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"10";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(55, -5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(606, 254);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Simulation::pictureBox1_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(12, 711);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(45, 45);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Simulation::button1_Click);
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button18->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button18->Location = System::Drawing::Point(879, 724);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(133, 32);
			this->button18->TabIndex = 14;
			this->button18->Text = L"Change Region";
			this->button18->UseVisualStyleBackColor = false;
			// 
			// button21
			// 
			this->button21->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button21->Font = (gcnew System::Drawing::Font(L"Myriad Pro Light", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button21->Location = System::Drawing::Point(743, 724);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(133, 32);
			this->button21->TabIndex = 15;
			this->button21->Text = L"Thread Monitor";
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &Simulation::button21_Click);
			// 
			// button22
			// 
			this->button22->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button22->Location = System::Drawing::Point(117, 89);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(145, 52);
			this->button22->TabIndex = 3;
			this->button22->Text = L"Changing Incline";
			this->button22->UseVisualStyleBackColor = false;
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button17->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Location = System::Drawing::Point(2, 40);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(137, 37);
			this->button17->TabIndex = 0;
			this->button17->Text = L"Petrol";
			this->button17->UseVisualStyleBackColor = false;
			// 
			// button23
			// 
			this->button23->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button23->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button23->Location = System::Drawing::Point(192, 40);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(137, 37);
			this->button23->TabIndex = 1;
			this->button23->Text = L"Diesel";
			this->button23->UseVisualStyleBackColor = false;
			// 
			// Simulation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1024, 768);
			this->ControlBox = false;
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Simulation";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Simulation";
			this->TopMost = true;
			this->panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
	private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 button3->BackColor = System::Drawing::Color::LightSkyBlue;
			 pictureBox2->Visible = true;
			 panel3->Visible = true;
}
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
			 button16->BackColor = System::Drawing::Color::LightSkyBlue;
			 //panel4->Visible = true;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 button2->BackColor = System::Drawing::Color::LightSkyBlue;
			 pictureBox2->Visible = true;
			 panel3->Visible = true;
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 button5->BackColor = System::Drawing::Color::LightSkyBlue;
			 pictureBox2->Visible = true;
			 panel3->Visible = true;
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			 button13->BackColor = System::Drawing::Color::LightSkyBlue;
			 panel4->Visible = true;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 button4->BackColor = System::Drawing::Color::LightSkyBlue;
			 pictureBox2->Visible = true;
			 panel3->Visible = true;
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 button6->BackColor = System::Drawing::Color::LightSkyBlue;
			 pictureBox2->Visible = true;
			 panel3->Visible = true;
			 panel4->Visible = true;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 button7->BackColor = System::Drawing::Color::LightSkyBlue;
			 pictureBox2->Visible = true;
			 panel3->Visible = true;
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 button9->BackColor = System::Drawing::Color::LightSkyBlue;
			 pictureBox2->Visible = true;
			 panel3->Visible = true;
}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
			 button17->BackColor = System::Drawing::Color::LightSkyBlue;
}
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
			 threadmonitor ^form = gcnew threadmonitor;
			 form->ShowDialog();
}
private: System::Void button16_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 button16->BackColor = System::Drawing::Color::LightSkyBlue;
			 panel4->Visible = true;
}
};
}
