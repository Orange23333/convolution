// QueSTion ForMaT

#include "qstfmt.h"

QuestionNode* QuestionFormat::get_Root(){
	return root;
}
QuestionNode* QuestionFormat::NewRoot(){
	Clear();
	root=new QuestionNode();
	return get_Root();
}

void QuestionFormat::Clear(){
	if(root!=NULL){
		root->Clear();
		delete[] root;
	}
}

QuestionFormat::QuestionFormat(){
	root=NULL;
}

QuestionFormat::~QuestionFormat(){
	Clear();
}