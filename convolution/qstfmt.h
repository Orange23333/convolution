// QueSTion ForMaT

#ifndef __QSTFMT_H_
	#define __QSTFMT_H_
	
	#include "qstnode.h"

class QuestionFormat{
protected:
	QuestionNode* root;
public:
	QuestionNode* get_Root();
	QuestionNode* NewRoot();
	
	void Clear();
	
	QuestionFormat();
	~QuestionFormat();
};

#endif