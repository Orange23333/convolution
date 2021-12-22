// QueSTion ForMaT

#include "qstfmt.h"

QuestionNode* QuestionFormat::get_Root(){
	return root;
}

QuestionFormat::QuestionFormat(){
	root=NULL;
}

QuestionFormat::~QuestionFormat(){
	if(root!=NULL){
		root->Clear();
	}
}