// QueSTion NODE

#include "qstnode.h"

std::string QuestionNode::get_Text(){
	return m_text;
}

void QuestionNode::set_Text(const std::string value){
	this->m_text=value;
}

Answers* QuestionNode::get_Answers(){
	return answers;
}

void QuestionNode::init_Answers(){
	answers=new Answers();
}

std::vector<QuestionNode*>* QuestionNode::get_SubNodes(){
	return &subNodes;
}

QuestionNode* QuestionNode::PushBackNew(){
	QuestionNode* r=new QuestionNode();
	subNodes.push_back(r);
	return r;
}

void QuestionNode::Clear(){
	int i;
	for(i=0;i<subNodes.size();i++){
		subNodes[i]->Clear();
		delete[] subNodes[i];
	}
	subNodes.clear();
	
	if(answers!=NULL){
		answers->Clear();
		delete[] answers;
		answers=NULL;
	}
}

QuestionNode::QuestionNode(){
	m_text="";
	answers=NULL;
}

QuestionNode::~QuestionNode(){
	Clear();
}