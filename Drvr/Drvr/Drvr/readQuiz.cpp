

#include <iostream>
#include "readQuiz.h"
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


//Function to read the questions from the file into a vector. This is also known as the question bank
//The format read is as follows:
//questionDesc, answerList[0], answerList[1], answerList[2], answerList[3], answerNo 
//e.g: What does FWD mean?, Front Wheel Drive, Forward Wheel Drive, Fast Wheel Drive, Frontal Wheel Drive, 1
//questionDesc: the question that will be asked. (Displayed to the user)
//answerList: the list of answers available as a choice. answerList[0] = answer no.1, answerList[1] = answer no.2, etc.etc
//answerNo: the value corresponds to the index of the answerList
void readFile(vector<question> &questionBank)
{
	ifstream infile;
	infile.open("questionBank.txt");

	if (!infile)
		cout << "File does not exist!" << endl;
	else
	{
		srand(time(NULL));
		int totalQuestions = 0;
		int answerVal = 0;
		int questionSelected = 0;
		question temp;

		infile >> totalQuestions;

		//cout << totalQuestions << endl;

		for (int i = 0; i < totalQuestions; i++)
		{
			infile >> temp.picture;
			infile.ignore();

			if (temp.picture)
			{
				getline(infile, temp.pictureLink, ',');
			}

			else
			{
				temp.pictureLink = "N/A";
			}

			getline(infile, temp.questionDesc, ',');

			for (int j = 0; j < 4; j++)
			{
				getline(infile, temp.answerList[j], ',');
			}

			infile >> answerVal;

			temp.answerString = temp.answerList[answerVal];
			questionBank.push_back(temp);

		}


		infile.close();
	}
}

//This function is to select the questions from the vector questionBank.
//Questions retrieved from the bank will be removed from the bank to avoid choosing similar questions
//The questions will then be stored in an array questionList which will be exported to the GUI
void getQuestions(vector<question> questionBank, question questionList[], int noQuestions)
{
	int questionSelected = 0;
	for (int i = 0; i < noQuestions; i++)
	{
		questionSelected = rand() % questionBank.size();
		questionList[i] = questionBank[questionSelected];
		questionBank.erase(questionBank.begin() + questionSelected);
	}
}

/*
//for testing purposes
int main()
{
	vector<question> questionBank;
	question questionList[5];

	readFile(questionBank);
	getQuestions(questionBank, questionList, 5);

	cout << "Questions selected: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << questionList[i].questionDesc << endl;
		cout << "Answer: " << questionList[i].answerString << endl;
	}

	system("PAUSE");
	return 0;
}

*/
