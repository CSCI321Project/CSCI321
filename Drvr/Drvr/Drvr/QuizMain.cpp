#include "QuizMain.h"
#include "readQuiz.h"
#include <vector>

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


question questionList[10];
bool quizCompleted;

namespace Drvr
{
	int answerSelected[10];
	int result[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int currPosQuiz = 1;

	//initial questionBox location: 113, 170
	//initial questionBox size: 465, 130
	//If pic present, questionBox location: 113, 90
	//questionBox size: 465, 75

	//This is the beginning of the quiz. The questions are read in from the bank and placed into an array
	//which will then be allocated to the respective questions.
	void QuizMain::startQuiz()
	{	
		quizCompleted = false;
		vector<question> questionBank;
		readFile(questionBank);
		getQuestions(questionBank, questionList, 10);

		 questionContent->Text = gcnew String(questionList[0].questionDesc.c_str());
		 answer1Content->Text = gcnew String(questionList[0].answerList[0].c_str());
		 answer2Content->Text = gcnew String(questionList[0].answerList[1].c_str());
		 answer3Content->Text = gcnew String(questionList[0].answerList[2].c_str());
		 answer4Content->Text = gcnew String(questionList[0].answerList[3].c_str());
		 question1->BackColor = System::Drawing::Color::Lime;

		 if (questionList[0].picture)
		 {
			 questionContent->Location = System::Drawing::Point(113, 90);
			 questionContent->Size = System::Drawing::Size(465, 75);
			 questionPicture->Visible = true;
			 questionPicture->Load(gcnew String(questionList[0].pictureLink.c_str()));
		 }

		 else
		 {
			 questionContent->Location = System::Drawing::Point(113, 170);
			 questionContent->Size = System::Drawing::Size(465, 130);
			 questionPicture->Visible = false;
		 }
	}

	void QuizMain::moveNextQuestion()
	{
		if (currPosQuiz <= 14)
		{
			if (currPosQuiz == 1)
			{
				question1->BackColor = System::Drawing::SystemColors::ActiveCaption;
				question2->BackColor = System::Drawing::Color::Lime;

				questionContent->Text = gcnew String(questionList[1].questionDesc.c_str());
				answer1Content->Text = gcnew String(questionList[1].answerList[0].c_str());
				answer2Content->Text = gcnew String(questionList[1].answerList[1].c_str());
				answer3Content->Text = gcnew String(questionList[1].answerList[2].c_str());
				answer4Content->Text = gcnew String(questionList[1].answerList[3].c_str());

			}

			else if (currPosQuiz == 2)
			{
				question2->BackColor = System::Drawing::SystemColors::ActiveCaption;
				question3->BackColor = System::Drawing::Color::Lime;
				questionContent->Text = gcnew String(questionList[2].questionDesc.c_str());
				answer1Content->Text = gcnew String(questionList[2].answerList[0].c_str());
				answer2Content->Text = gcnew String(questionList[2].answerList[1].c_str());
				answer3Content->Text = gcnew String(questionList[2].answerList[2].c_str());
				answer4Content->Text = gcnew String(questionList[2].answerList[3].c_str());
			}

			else if (currPosQuiz == 3)
			{
				question3->BackColor = System::Drawing::SystemColors::ActiveCaption;
				question4->BackColor = System::Drawing::Color::Lime;

				questionContent->Text = gcnew String(questionList[3].questionDesc.c_str());
				answer1Content->Text = gcnew String(questionList[3].answerList[0].c_str());
				answer2Content->Text = gcnew String(questionList[3].answerList[1].c_str());
				answer3Content->Text = gcnew String(questionList[3].answerList[2].c_str());
				answer4Content->Text = gcnew String(questionList[3].answerList[3].c_str());
			}

			else if (currPosQuiz == 4)
			{
				question4->BackColor = System::Drawing::SystemColors::ActiveCaption;
				question5->BackColor = System::Drawing::Color::Lime;

				questionContent->Text = gcnew String(questionList[4].questionDesc.c_str());
				answer1Content->Text = gcnew String(questionList[4].answerList[0].c_str());
				answer2Content->Text = gcnew String(questionList[4].answerList[1].c_str());
				answer3Content->Text = gcnew String(questionList[4].answerList[2].c_str());
				answer4Content->Text = gcnew String(questionList[4].answerList[3].c_str());

			}

			else if (currPosQuiz == 5)
			{
				question5->BackColor = System::Drawing::SystemColors::ActiveCaption;
				question6->BackColor = System::Drawing::Color::Lime;
				questionContent->Text = gcnew String(questionList[5].questionDesc.c_str());
				answer1Content->Text = gcnew String(questionList[5].answerList[0].c_str());
				answer2Content->Text = gcnew String(questionList[5].answerList[1].c_str());
				answer3Content->Text = gcnew String(questionList[5].answerList[2].c_str());
				answer4Content->Text = gcnew String(questionList[5].answerList[3].c_str());
			}

			else if (currPosQuiz == 6)
			{
				question6->BackColor = System::Drawing::SystemColors::ActiveCaption;
				question7->BackColor = System::Drawing::Color::Lime;
				questionContent->Text = gcnew String(questionList[6].questionDesc.c_str());
				answer1Content->Text = gcnew String(questionList[6].answerList[0].c_str());
				answer2Content->Text = gcnew String(questionList[6].answerList[1].c_str());
				answer3Content->Text = gcnew String(questionList[6].answerList[2].c_str());
				answer4Content->Text = gcnew String(questionList[6].answerList[3].c_str());
			}

			else if (currPosQuiz == 7)
			{
				question7->BackColor = System::Drawing::SystemColors::ActiveCaption;
				question8->BackColor = System::Drawing::Color::Lime;

				questionContent->Text = gcnew String(questionList[7].questionDesc.c_str());
				answer1Content->Text = gcnew String(questionList[7].answerList[0].c_str());
				answer2Content->Text = gcnew String(questionList[7].answerList[1].c_str());
				answer3Content->Text = gcnew String(questionList[7].answerList[2].c_str());
				answer4Content->Text = gcnew String(questionList[7].answerList[3].c_str());
			}

			else if (currPosQuiz == 8)
			{
				question8->BackColor = System::Drawing::SystemColors::ActiveCaption;
				question9->BackColor = System::Drawing::Color::Lime;

				questionContent->Text = gcnew String(questionList[8].questionDesc.c_str());
				answer1Content->Text = gcnew String(questionList[8].answerList[0].c_str());
				answer2Content->Text = gcnew String(questionList[8].answerList[1].c_str());
				answer3Content->Text = gcnew String(questionList[8].answerList[2].c_str());
				answer4Content->Text = gcnew String(questionList[8].answerList[3].c_str());

			}

			else if (currPosQuiz == 9)
			{
				question9->BackColor = System::Drawing::SystemColors::ActiveCaption;
				question10->BackColor = System::Drawing::Color::Lime;

				questionContent->Text = gcnew String(questionList[9].questionDesc.c_str());
				answer1Content->Text = gcnew String(questionList[9].answerList[0].c_str());
				answer2Content->Text = gcnew String(questionList[9].answerList[1].c_str());
				answer3Content->Text = gcnew String(questionList[9].answerList[2].c_str());
				answer4Content->Text = gcnew String(questionList[9].answerList[3].c_str());
			}

			else if (currPosQuiz == 10)
			{
				question10->BackColor = System::Drawing::SystemColors::ActiveCaption;
				question11->BackColor = System::Drawing::Color::Lime;
				
			}

			currPosQuiz++;


		}

		if (questionList[currPosQuiz-1].picture)
		{
			questionContent->Location = System::Drawing::Point(113, 90);
			questionContent->Size = System::Drawing::Size(465, 75);
			questionPicture->Visible = true;
			questionPicture->Load(gcnew String(questionList[currPosQuiz-1].pictureLink.c_str()));
		}

		else
		{
			questionContent->Location = System::Drawing::Point(113, 170);
			questionContent->Size = System::Drawing::Size(465, 130);
			questionPicture->Visible = false;
			
		}
	}

	void QuizMain::resetAll()
	{
		currPosQuiz = 1;

		for (int i = 0; i < 10; i++)
		{
			result[i] = -1;
		}
	}

	void QuizMain::jumpQuestion(int jumpTo)
	{
		if (jumpTo != currPosQuiz)
		{
			switch (currPosQuiz)
			{
				case 1:	question1->BackColor = System::Drawing::SystemColors::ActiveCaption;
				case 2:	question2->BackColor = System::Drawing::SystemColors::ActiveCaption;
				case 3:	question3->BackColor = System::Drawing::SystemColors::ActiveCaption;
				case 4:	question4->BackColor = System::Drawing::SystemColors::ActiveCaption;
				case 5:	question5->BackColor = System::Drawing::SystemColors::ActiveCaption;
				case 6:	question6->BackColor = System::Drawing::SystemColors::ActiveCaption;
				case 7:	question7->BackColor = System::Drawing::SystemColors::ActiveCaption;
				case 8:	question8->BackColor = System::Drawing::SystemColors::ActiveCaption;
				case 9:	question9->BackColor = System::Drawing::SystemColors::ActiveCaption;
				case 10:question10->BackColor = System::Drawing::SystemColors::ActiveCaption;
			}

			
				questionContent->Text = gcnew String(questionList[jumpTo-1].questionDesc.c_str());
				answer1Content->Text = gcnew String(questionList[jumpTo-1].answerList[0].c_str());
				answer2Content->Text = gcnew String(questionList[jumpTo-1].answerList[1].c_str());
				answer3Content->Text = gcnew String(questionList[jumpTo-1].answerList[2].c_str());
				answer4Content->Text = gcnew String(questionList[jumpTo-1].answerList[3].c_str());

				if (questionList[jumpTo-1].picture)
				{
					questionContent->Location = System::Drawing::Point(113, 90);
					questionContent->Size = System::Drawing::Size(465, 75);
					questionPicture->Visible = true;
					questionPicture->Load(gcnew String(questionList[jumpTo-1].pictureLink.c_str()));
				}

				else
				{
					questionContent->Location = System::Drawing::Point(113, 170);
					questionContent->Size = System::Drawing::Size(465, 130);
					questionPicture->Visible = false;
				}


				currPosQuiz = jumpTo;
		}
	}

	void QuizMain::selectAnswer(int selection)
	{
		if (result[currPosQuiz - 1] == -1)
		{
			progressBar->Value = progressBar->Value + progressBar->Step;
		}
		answerSelected[currPosQuiz - 1] = selection;
		if (questionList[currPosQuiz - 1].answerString == questionList[currPosQuiz - 1].answerList[selection - 1])
		{
			result[currPosQuiz - 1] = 1;

			nextQuestion->BackColor = System::Drawing::Color::Lime; // to test if the result checker is correct
		}
		else
		{
			result[currPosQuiz - 1] = 0;
			nextQuestion->BackColor = System::Drawing::Color::Red; // to test if the result checker is correct
		}


	}
}

