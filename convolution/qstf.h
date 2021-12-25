// QueSTion File

#ifndef __QSTF_H_
	#define __QSTF_H_
	
	#include <cstdio>
	
	#include <iostream>
	#include <string>
	
	#include "rlsfmt.h"
	#include "qstfmt.h"
	#include "qstnode.h"
	#include "utility.h"

class QuestionFile{
private:
	QuestionFormat* questionFormat;
	
	void Clear();
	int LoadFromText(const std::string text);
public:
	QuestionNode* get_RootQuestionNode(){
		if(questionFormat){
			return questionFormat->get_Root();
		}else{
			return NULL;
		}
	}
	
	//int LoadFromFile(std::string path);
	int LoadFromFile(const std::string path);
	
	QuestionFile(){
		questionFormat=NULL;
	}
	~QuestionFile(){
		Clear();
	}
};

#endif