// ANSwerS

#ifndef __ANSS_H_
	#define __ANSS_H_
	
	#include <cstring>
	
	#include <vector>
	
	#include "array.h"

class Answers{
private:
	Array<std::string>* texts;
	Array<int>* rightAnswers;
public:
	Array<std::string>* get_Texts();
	Array<int>* get_RightAnswers();
	
	bool IsAnswerRight(const int* answerIndexes, const int answerIndexesN);
	
	void set_Answers(const std::string* texts, const int textsN, const int* rightAnswerIndexes, const int rightAnswerIndexesN);
	
	void Clear();
	
	Answers();
	~Answers();
};

#endif