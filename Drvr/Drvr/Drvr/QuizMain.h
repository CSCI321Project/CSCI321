#include "readQuiz.h"
#include <vector>

#pragma once

namespace Drvr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for QuizMain
	/// </summary>
	public ref class QuizMain : public System::Windows::Forms::Form
	{
		
		//Variables for the timer
		static int Seconds = 0;
		static int Minutes = 0;
		static String^ Sec;
		static String^ Min;

	private: System::Windows::Forms::Label^  timerDisplay;
	private: System::Windows::Forms::RichTextBox^  answer4Content;

	private: System::Windows::Forms::Button^  answer4;
	private: System::Windows::Forms::PictureBox^  questionPicture;

	private: System::Windows::Forms::ProgressBar^  progressBar;

			
	public:
		
		QuizMain(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void startQuiz();
		void moveNextQuestion();
		void resetAll();
		void jumpQuestion(int);
		void selectAnswer(int);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~QuizMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  question15;
	protected:

	private: System::Windows::Forms::Button^  question14;

	private: System::Windows::Forms::Button^  question13;

	private: System::Windows::Forms::Button^  question12;

	private: System::Windows::Forms::Button^  question11;

	private: System::Windows::Forms::Button^  question10;

	private: System::Windows::Forms::Button^  question9;

	private: System::Windows::Forms::Button^  question8;

	private: System::Windows::Forms::Button^  question7;

	private: System::Windows::Forms::Button^  question6;

	private: System::Windows::Forms::Button^  question5;

	private: System::Windows::Forms::Button^  question4;

	private: System::Windows::Forms::Button^  question3;

	private: System::Windows::Forms::Button^  question2;

	private: System::Windows::Forms::Button^  question1;

	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::SplitContainer^  quizContent;
	private: System::Windows::Forms::RichTextBox^  questionNumber;
	private: System::Windows::Forms::RichTextBox^  questionContent;
	private: System::Windows::Forms::RichTextBox^  answer3Content;




	private: System::Windows::Forms::RichTextBox^  answer2Content;

	private: System::Windows::Forms::RichTextBox^  answer1Content;

	private: System::Windows::Forms::Button^  answer3;
	private: System::Windows::Forms::Button^  nextQuestion;


	private: System::Windows::Forms::Button^  answer2;

	private: System::Windows::Forms::Button^  answer1;
	private: System::Windows::Forms::Button^  exit;
	private: System::Windows::Forms::Timer^  quizTimer;

	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(QuizMain::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->question15 = (gcnew System::Windows::Forms::Button());
			this->question14 = (gcnew System::Windows::Forms::Button());
			this->question13 = (gcnew System::Windows::Forms::Button());
			this->question12 = (gcnew System::Windows::Forms::Button());
			this->question11 = (gcnew System::Windows::Forms::Button());
			this->question10 = (gcnew System::Windows::Forms::Button());
			this->question9 = (gcnew System::Windows::Forms::Button());
			this->question8 = (gcnew System::Windows::Forms::Button());
			this->question7 = (gcnew System::Windows::Forms::Button());
			this->question6 = (gcnew System::Windows::Forms::Button());
			this->question5 = (gcnew System::Windows::Forms::Button());
			this->question4 = (gcnew System::Windows::Forms::Button());
			this->question3 = (gcnew System::Windows::Forms::Button());
			this->question2 = (gcnew System::Windows::Forms::Button());
			this->question1 = (gcnew System::Windows::Forms::Button());
			this->quizContent = (gcnew System::Windows::Forms::SplitContainer());
			this->questionPicture = (gcnew System::Windows::Forms::PictureBox());
			this->questionNumber = (gcnew System::Windows::Forms::RichTextBox());
			this->questionContent = (gcnew System::Windows::Forms::RichTextBox());
			this->answer4Content = (gcnew System::Windows::Forms::RichTextBox());
			this->answer4 = (gcnew System::Windows::Forms::Button());
			this->answer3Content = (gcnew System::Windows::Forms::RichTextBox());
			this->answer2Content = (gcnew System::Windows::Forms::RichTextBox());
			this->answer1Content = (gcnew System::Windows::Forms::RichTextBox());
			this->answer3 = (gcnew System::Windows::Forms::Button());
			this->answer2 = (gcnew System::Windows::Forms::Button());
			this->answer1 = (gcnew System::Windows::Forms::Button());
			this->nextQuestion = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->quizTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerDisplay = (gcnew System::Windows::Forms::Label());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quizContent))->BeginInit();
			this->quizContent->Panel1->SuspendLayout();
			this->quizContent->Panel2->SuspendLayout();
			this->quizContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->questionPicture))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->button9);
			this->groupBox1->Controls->Add(this->question15);
			this->groupBox1->Controls->Add(this->question14);
			this->groupBox1->Controls->Add(this->question13);
			this->groupBox1->Controls->Add(this->question12);
			this->groupBox1->Controls->Add(this->question11);
			this->groupBox1->Controls->Add(this->question10);
			this->groupBox1->Controls->Add(this->question9);
			this->groupBox1->Controls->Add(this->question8);
			this->groupBox1->Controls->Add(this->question7);
			this->groupBox1->Controls->Add(this->question6);
			this->groupBox1->Controls->Add(this->question5);
			this->groupBox1->Controls->Add(this->question4);
			this->groupBox1->Controls->Add(this->question3);
			this->groupBox1->Controls->Add(this->question2);
			this->groupBox1->Controls->Add(this->question1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold));
			this->groupBox1->Location = System::Drawing::Point(19, 24);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->groupBox1->Size = System::Drawing::Size(986, 87);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Quick Access Bar";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(843, 23);
			this->button9->Margin = System::Windows::Forms::Padding(4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(135, 40);
			this->button9->TabIndex = 15;
			this->button9->Text = L"Results";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			// 
			// question15
			// 
			this->question15->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question15->Location = System::Drawing::Point(708, 23);
			this->question15->Margin = System::Windows::Forms::Padding(4);
			this->question15->Name = L"question15";
			this->question15->Size = System::Drawing::Size(40, 40);
			this->question15->TabIndex = 14;
			this->question15->Text = L"15";
			this->question15->UseVisualStyleBackColor = false;
			this->question15->Click += gcnew System::EventHandler(this, &QuizMain::question15_Click);
			// 
			// question14
			// 
			this->question14->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question14->Location = System::Drawing::Point(660, 23);
			this->question14->Margin = System::Windows::Forms::Padding(4);
			this->question14->Name = L"question14";
			this->question14->Size = System::Drawing::Size(40, 40);
			this->question14->TabIndex = 13;
			this->question14->Text = L"14";
			this->question14->UseVisualStyleBackColor = false;
			this->question14->Click += gcnew System::EventHandler(this, &QuizMain::question14_Click);
			// 
			// question13
			// 
			this->question13->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question13->Location = System::Drawing::Point(612, 24);
			this->question13->Margin = System::Windows::Forms::Padding(4);
			this->question13->Name = L"question13";
			this->question13->Size = System::Drawing::Size(40, 40);
			this->question13->TabIndex = 12;
			this->question13->Text = L"13";
			this->question13->UseVisualStyleBackColor = false;
			this->question13->Click += gcnew System::EventHandler(this, &QuizMain::question13_Click);
			// 
			// question12
			// 
			this->question12->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question12->Location = System::Drawing::Point(566, 24);
			this->question12->Margin = System::Windows::Forms::Padding(4);
			this->question12->Name = L"question12";
			this->question12->Size = System::Drawing::Size(40, 40);
			this->question12->TabIndex = 11;
			this->question12->Text = L"12";
			this->question12->UseVisualStyleBackColor = false;
			this->question12->Click += gcnew System::EventHandler(this, &QuizMain::question12_Click);
			// 
			// question11
			// 
			this->question11->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question11->Location = System::Drawing::Point(518, 23);
			this->question11->Margin = System::Windows::Forms::Padding(4);
			this->question11->Name = L"question11";
			this->question11->Size = System::Drawing::Size(40, 40);
			this->question11->TabIndex = 10;
			this->question11->Text = L"11";
			this->question11->UseVisualStyleBackColor = false;
			this->question11->Click += gcnew System::EventHandler(this, &QuizMain::question11_Click);
			// 
			// question10
			// 
			this->question10->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question10->Location = System::Drawing::Point(470, 24);
			this->question10->Margin = System::Windows::Forms::Padding(4);
			this->question10->Name = L"question10";
			this->question10->Size = System::Drawing::Size(40, 40);
			this->question10->TabIndex = 9;
			this->question10->Text = L"10";
			this->question10->UseVisualStyleBackColor = false;
			this->question10->Click += gcnew System::EventHandler(this, &QuizMain::question10_Click);
			// 
			// question9
			// 
			this->question9->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question9->Location = System::Drawing::Point(422, 24);
			this->question9->Margin = System::Windows::Forms::Padding(4);
			this->question9->Name = L"question9";
			this->question9->Size = System::Drawing::Size(40, 40);
			this->question9->TabIndex = 8;
			this->question9->Text = L"9";
			this->question9->UseVisualStyleBackColor = false;
			this->question9->Click += gcnew System::EventHandler(this, &QuizMain::question9_Click);
			// 
			// question8
			// 
			this->question8->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question8->Location = System::Drawing::Point(374, 23);
			this->question8->Margin = System::Windows::Forms::Padding(4);
			this->question8->Name = L"question8";
			this->question8->Size = System::Drawing::Size(40, 40);
			this->question8->TabIndex = 7;
			this->question8->Text = L"8";
			this->question8->UseVisualStyleBackColor = false;
			this->question8->Click += gcnew System::EventHandler(this, &QuizMain::question8_Click);
			// 
			// question7
			// 
			this->question7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question7->Location = System::Drawing::Point(326, 23);
			this->question7->Margin = System::Windows::Forms::Padding(4);
			this->question7->Name = L"question7";
			this->question7->Size = System::Drawing::Size(40, 40);
			this->question7->TabIndex = 6;
			this->question7->Text = L"7";
			this->question7->UseVisualStyleBackColor = false;
			this->question7->Click += gcnew System::EventHandler(this, &QuizMain::question7_Click);
			// 
			// question6
			// 
			this->question6->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question6->Location = System::Drawing::Point(278, 23);
			this->question6->Margin = System::Windows::Forms::Padding(4);
			this->question6->Name = L"question6";
			this->question6->Size = System::Drawing::Size(40, 40);
			this->question6->TabIndex = 5;
			this->question6->Text = L"6";
			this->question6->UseVisualStyleBackColor = false;
			this->question6->Click += gcnew System::EventHandler(this, &QuizMain::question6_Click);
			// 
			// question5
			// 
			this->question5->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question5->Location = System::Drawing::Point(230, 23);
			this->question5->Margin = System::Windows::Forms::Padding(4);
			this->question5->Name = L"question5";
			this->question5->Size = System::Drawing::Size(40, 40);
			this->question5->TabIndex = 4;
			this->question5->Text = L"5";
			this->question5->UseVisualStyleBackColor = false;
			this->question5->Click += gcnew System::EventHandler(this, &QuizMain::question5_Click);
			// 
			// question4
			// 
			this->question4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question4->Location = System::Drawing::Point(182, 24);
			this->question4->Margin = System::Windows::Forms::Padding(4);
			this->question4->Name = L"question4";
			this->question4->Size = System::Drawing::Size(40, 40);
			this->question4->TabIndex = 3;
			this->question4->Text = L"4";
			this->question4->UseVisualStyleBackColor = false;
			this->question4->Click += gcnew System::EventHandler(this, &QuizMain::question4_Click);
			// 
			// question3
			// 
			this->question3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question3->Location = System::Drawing::Point(134, 23);
			this->question3->Margin = System::Windows::Forms::Padding(4);
			this->question3->Name = L"question3";
			this->question3->Size = System::Drawing::Size(40, 40);
			this->question3->TabIndex = 2;
			this->question3->Text = L"3";
			this->question3->UseVisualStyleBackColor = false;
			this->question3->Click += gcnew System::EventHandler(this, &QuizMain::question3_Click);
			// 
			// question2
			// 
			this->question2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question2->Location = System::Drawing::Point(86, 23);
			this->question2->Margin = System::Windows::Forms::Padding(4);
			this->question2->Name = L"question2";
			this->question2->Size = System::Drawing::Size(40, 40);
			this->question2->TabIndex = 1;
			this->question2->Text = L"2";
			this->question2->UseVisualStyleBackColor = false;
			this->question2->Click += gcnew System::EventHandler(this, &QuizMain::question2_Click);
			// 
			// question1
			// 
			this->question1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->question1->Location = System::Drawing::Point(38, 23);
			this->question1->Margin = System::Windows::Forms::Padding(4);
			this->question1->Name = L"question1";
			this->question1->Size = System::Drawing::Size(40, 40);
			this->question1->TabIndex = 0;
			this->question1->Text = L"1";
			this->question1->UseVisualStyleBackColor = false;
			this->question1->Click += gcnew System::EventHandler(this, &QuizMain::question1_Click);
			// 
			// quizContent
			// 
			this->quizContent->BackColor = System::Drawing::Color::Transparent;
			this->quizContent->Location = System::Drawing::Point(26, 136);
			this->quizContent->Margin = System::Windows::Forms::Padding(4);
			this->quizContent->Name = L"quizContent";
			// 
			// quizContent.Panel1
			// 
			this->quizContent->Panel1->Controls->Add(this->questionPicture);
			this->quizContent->Panel1->Controls->Add(this->questionNumber);
			this->quizContent->Panel1->Controls->Add(this->questionContent);
			this->quizContent->Panel1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F));
			// 
			// quizContent.Panel2
			// 
			this->quizContent->Panel2->Controls->Add(this->answer4Content);
			this->quizContent->Panel2->Controls->Add(this->answer4);
			this->quizContent->Panel2->Controls->Add(this->answer3Content);
			this->quizContent->Panel2->Controls->Add(this->answer2Content);
			this->quizContent->Panel2->Controls->Add(this->answer1Content);
			this->quizContent->Panel2->Controls->Add(this->answer3);
			this->quizContent->Panel2->Controls->Add(this->answer2);
			this->quizContent->Panel2->Controls->Add(this->answer1);
			this->quizContent->Panel2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F));
			this->quizContent->Size = System::Drawing::Size(973, 480);
			this->quizContent->SplitterDistance = 690;
			this->quizContent->SplitterWidth = 5;
			this->quizContent->TabIndex = 1;
			// 
			// questionPicture
			// 
			this->questionPicture->ImageLocation = L"";
			this->questionPicture->Location = System::Drawing::Point(91, 187);
			this->questionPicture->Name = L"questionPicture";
			this->questionPicture->Size = System::Drawing::Size(509, 239);
			this->questionPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->questionPicture->TabIndex = 2;
			this->questionPicture->TabStop = false;
			this->questionPicture->Visible = false;
			// 
			// questionNumber
			// 
			this->questionNumber->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->questionNumber->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->questionNumber->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->questionNumber->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16));
			this->questionNumber->Location = System::Drawing::Point(40, 23);
			this->questionNumber->Margin = System::Windows::Forms::Padding(4);
			this->questionNumber->Name = L"questionNumber";
			this->questionNumber->Size = System::Drawing::Size(166, 48);
			this->questionNumber->TabIndex = 1;
			this->questionNumber->Text = L"Results";
			// 
			// questionContent
			// 
			this->questionContent->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->questionContent->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->questionContent->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->questionContent->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16));
			this->questionContent->Location = System::Drawing::Point(113, 170);
			this->questionContent->Margin = System::Windows::Forms::Padding(4);
			this->questionContent->Name = L"questionContent";
			this->questionContent->Size = System::Drawing::Size(465, 77);
			this->questionContent->TabIndex = 0;
			this->questionContent->Text = L"";
			// 
			// answer4Content
			// 
			this->answer4Content->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->answer4Content->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->answer4Content->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->answer4Content->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer4Content->Location = System::Drawing::Point(88, 362);
			this->answer4Content->Margin = System::Windows::Forms::Padding(4);
			this->answer4Content->Name = L"answer4Content";
			this->answer4Content->Size = System::Drawing::Size(168, 64);
			this->answer4Content->TabIndex = 22;
			this->answer4Content->Text = L"6 Unanswered Questions";
			// 
			// answer4
			// 
			this->answer4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->answer4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer4->Location = System::Drawing::Point(27, 369);
			this->answer4->Margin = System::Windows::Forms::Padding(4);
			this->answer4->Name = L"answer4";
			this->answer4->Size = System::Drawing::Size(53, 44);
			this->answer4->TabIndex = 21;
			this->answer4->Text = L"4";
			this->answer4->UseVisualStyleBackColor = false;
			this->answer4->Click += gcnew System::EventHandler(this, &QuizMain::answer4_Click);
			this->answer4->Leave += gcnew System::EventHandler(this, &QuizMain::answer4_Leave);
			// 
			// answer3Content
			// 
			this->answer3Content->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->answer3Content->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->answer3Content->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->answer3Content->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer3Content->Location = System::Drawing::Point(88, 252);
			this->answer3Content->Margin = System::Windows::Forms::Padding(4);
			this->answer3Content->Name = L"answer3Content";
			this->answer3Content->Size = System::Drawing::Size(168, 64);
			this->answer3Content->TabIndex = 20;
			this->answer3Content->Text = L"6 Unanswered Questions";
			// 
			// answer2Content
			// 
			this->answer2Content->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->answer2Content->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->answer2Content->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->answer2Content->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer2Content->Location = System::Drawing::Point(88, 144);
			this->answer2Content->Margin = System::Windows::Forms::Padding(4);
			this->answer2Content->Name = L"answer2Content";
			this->answer2Content->Size = System::Drawing::Size(168, 64);
			this->answer2Content->TabIndex = 19;
			this->answer2Content->Text = L"3 Incorrect Questions";
			// 
			// answer1Content
			// 
			this->answer1Content->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->answer1Content->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->answer1Content->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->answer1Content->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer1Content->Location = System::Drawing::Point(88, 36);
			this->answer1Content->Margin = System::Windows::Forms::Padding(4);
			this->answer1Content->Name = L"answer1Content";
			this->answer1Content->Size = System::Drawing::Size(168, 64);
			this->answer1Content->TabIndex = 2;
			this->answer1Content->Text = L"6 Correct Questions";
			// 
			// answer3
			// 
			this->answer3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->answer3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer3->Location = System::Drawing::Point(27, 259);
			this->answer3->Margin = System::Windows::Forms::Padding(4);
			this->answer3->Name = L"answer3";
			this->answer3->Size = System::Drawing::Size(53, 44);
			this->answer3->TabIndex = 18;
			this->answer3->Text = L"3";
			this->answer3->UseVisualStyleBackColor = false;
			this->answer3->Click += gcnew System::EventHandler(this, &QuizMain::answer3_Click);
			this->answer3->Leave += gcnew System::EventHandler(this, &QuizMain::answer3_Leave);
			// 
			// answer2
			// 
			this->answer2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->answer2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer2->Location = System::Drawing::Point(27, 151);
			this->answer2->Margin = System::Windows::Forms::Padding(4);
			this->answer2->Name = L"answer2";
			this->answer2->Size = System::Drawing::Size(53, 44);
			this->answer2->TabIndex = 17;
			this->answer2->Text = L"2";
			this->answer2->UseVisualStyleBackColor = false;
			this->answer2->Click += gcnew System::EventHandler(this, &QuizMain::answer2_Click);
			this->answer2->Leave += gcnew System::EventHandler(this, &QuizMain::answer2_Leave);
			// 
			// answer1
			// 
			this->answer1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->answer1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer1->Location = System::Drawing::Point(27, 43);
			this->answer1->Margin = System::Windows::Forms::Padding(4);
			this->answer1->Name = L"answer1";
			this->answer1->Size = System::Drawing::Size(53, 44);
			this->answer1->TabIndex = 16;
			this->answer1->Text = L"1";
			this->answer1->UseVisualStyleBackColor = false;
			this->answer1->Click += gcnew System::EventHandler(this, &QuizMain::answer1_Click);
			this->answer1->Leave += gcnew System::EventHandler(this, &QuizMain::answer1_Leave);
			// 
			// nextQuestion
			// 
			this->nextQuestion->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->nextQuestion->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->nextQuestion->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13, System::Drawing::FontStyle::Bold));
			this->nextQuestion->Location = System::Drawing::Point(844, 705);
			this->nextQuestion->Margin = System::Windows::Forms::Padding(4);
			this->nextQuestion->Name = L"nextQuestion";
			this->nextQuestion->Size = System::Drawing::Size(167, 44);
			this->nextQuestion->TabIndex = 17;
			this->nextQuestion->Text = L"Next";
			this->nextQuestion->UseVisualStyleBackColor = false;
			this->nextQuestion->Click += gcnew System::EventHandler(this, &QuizMain::nextQuestion_Click);
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13, System::Drawing::FontStyle::Bold));
			this->exit->Location = System::Drawing::Point(12, 704);
			this->exit->Margin = System::Windows::Forms::Padding(4);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(167, 44);
			this->exit->TabIndex = 16;
			this->exit->Text = L"Exit";
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &QuizMain::button17_Click);
			// 
			// quizTimer
			// 
			this->quizTimer->Enabled = true;
			this->quizTimer->Interval = 1000;
			this->quizTimer->Tick += gcnew System::EventHandler(this, &QuizMain::quizTimer_Tick);
			// 
			// timerDisplay
			// 
			this->timerDisplay->AutoSize = true;
			this->timerDisplay->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->timerDisplay->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->timerDisplay->Font = (gcnew System::Drawing::Font(L"Courier New", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timerDisplay->Location = System::Drawing::Point(466, 684);
			this->timerDisplay->Name = L"timerDisplay";
			this->timerDisplay->Size = System::Drawing::Size(93, 38);
			this->timerDisplay->TabIndex = 18;
			this->timerDisplay->Text = L"0:00";
			this->timerDisplay->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(237, 725);
			this->progressBar->Maximum = 150;
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(556, 23);
			this->progressBar->TabIndex = 2;
			this->progressBar->Click += gcnew System::EventHandler(this, &QuizMain::progressBar1_Click);
			// 
			// QuizMain
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1024, 768);
			this->ControlBox = false;
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->timerDisplay);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->quizContent);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->nextQuestion);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"QuizMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"QuizMain";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &QuizMain::QuizMain_Load);
			this->groupBox1->ResumeLayout(false);
			this->quizContent->Panel1->ResumeLayout(false);
			this->quizContent->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->quizContent))->EndInit();
			this->quizContent->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->questionPicture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//The event which is called when the exit button is clicked. 
//The reset function will be called as well to revert everything back to normal.
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
		Seconds = 0;
		Minutes = 0;
		quizTimer->Enabled = false;
		resetAll();
		this->Close();
	}
private: System::Void QuizMain_Load(System::Object^  sender, System::EventArgs^  e) {
	quizTimer->Enabled = true;
	startQuiz();
	
}
private: System::Void quizTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
		Seconds++;

		if (Seconds == 60)
		{
			Seconds = 0;
			Minutes++;
		}

		if (Minutes == 1)
		{
			quizTimer->Enabled = false;
			
		}

		Sec = Convert::ToString(Seconds);
		Min = Convert::ToString(Minutes);

		if (Seconds < 10)
			timerDisplay->Text = Min + ":0" + Sec;
		else
			timerDisplay->Text = Min + ":" + Sec;

}
private: System::Void nextQuestion_Click(System::Object^  sender, System::EventArgs^  e) {
	moveNextQuestion();

}
private: System::Void progressBar1_Click(System::Object^  sender, System::EventArgs^  e) {
}

//The events called for clicking the numbers on the quick access bar
//The events will call a function to jump to the selected question number.
private: System::Void question1_Click(System::Object^  sender, System::EventArgs^  e) {
	jumpQuestion(1);
	question1->BackColor = System::Drawing::Color::Lime;
}
private: System::Void question2_Click(System::Object^  sender, System::EventArgs^  e) {
	jumpQuestion(2);
	question2->BackColor = System::Drawing::Color::Lime;
}

private: System::Void question3_Click(System::Object^  sender, System::EventArgs^  e) {
	jumpQuestion(3);
	question3->BackColor = System::Drawing::Color::Lime;
}

private: System::Void question4_Click(System::Object^  sender, System::EventArgs^  e) {
	jumpQuestion(4);
	question4->BackColor = System::Drawing::Color::Lime;
}

private: System::Void question5_Click(System::Object^  sender, System::EventArgs^  e) {
	jumpQuestion(5);
	question5->BackColor = System::Drawing::Color::Lime;
}

private: System::Void question6_Click(System::Object^  sender, System::EventArgs^  e) {
	jumpQuestion(6);
	question6->BackColor = System::Drawing::Color::Lime;
}

private: System::Void question7_Click(System::Object^  sender, System::EventArgs^  e) {
	jumpQuestion(7);
	question7->BackColor = System::Drawing::Color::Lime;
}

private: System::Void question8_Click(System::Object^  sender, System::EventArgs^  e) {
	jumpQuestion(8);
	question8->BackColor = System::Drawing::Color::Lime;
}

private: System::Void question9_Click(System::Object^  sender, System::EventArgs^  e) {
	jumpQuestion(9);
	question9->BackColor = System::Drawing::Color::Lime;
}

private: System::Void question10_Click(System::Object^  sender, System::EventArgs^  e) {
	jumpQuestion(10);
	question10->BackColor = System::Drawing::Color::Lime;
}

private: System::Void question11_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void question12_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void question13_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void question14_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void question15_Click(System::Object^  sender, System::EventArgs^  e) {
}


//When choosing an answer. The following events will be called respectively. 
//The events will then call a function which will store the user's answer choice. 
private: System::Void answer1_Click(System::Object^  sender, System::EventArgs^  e) {
	selectAnswer(1);
	answer1->BackColor = System::Drawing::Color::Lime;
}
private: System::Void answer2_Click(System::Object^  sender, System::EventArgs^  e) {
	selectAnswer(2);
	answer2->BackColor = System::Drawing::Color::Lime;
}
private: System::Void answer3_Click(System::Object^  sender, System::EventArgs^  e) {
	selectAnswer(3);
	answer3->BackColor = System::Drawing::Color::Lime;
}
private: System::Void answer4_Click(System::Object^  sender, System::EventArgs^  e) {
	selectAnswer(4);
	answer4->BackColor = System::Drawing::Color::Lime;
}

//When moving to another question or choosing another answer. It will reset the backcolor of the button
private: System::Void answer1_Leave(System::Object^  sender, System::EventArgs^  e) {
	answer1->BackColor = System::Drawing::SystemColors::ActiveCaption;
}
private: System::Void answer2_Leave(System::Object^  sender, System::EventArgs^  e) {
	answer2->BackColor = System::Drawing::SystemColors::ActiveCaption;
}
private: System::Void answer3_Leave(System::Object^  sender, System::EventArgs^  e) {
	answer3->BackColor = System::Drawing::SystemColors::ActiveCaption;
}
private: System::Void answer4_Leave(System::Object^  sender, System::EventArgs^  e) {
	answer4->BackColor = System::Drawing::SystemColors::ActiveCaption;
}
};
}

