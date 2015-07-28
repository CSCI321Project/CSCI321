#ifndef READQUIZ_HEADER
#define READQUIZ_HEADER

#include <fstream>
#include <vector>

//The question's data structure

struct question
{
	std::string questionDesc;
	std::string answerList[4];
	std::string answerString;
	bool picture;
	std::string pictureLink;

};

void readFile(std::vector<question> &questionBank);
void getQuestions(std::vector<question> questionBank, question questionList[], int);

#endif