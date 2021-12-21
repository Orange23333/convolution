// QueSTion NODE

#include "qstnode.h"

std::string QuestionNode::get_Text(){
	return m_text;
}

void QuestionNode::get_Text(std::string value){
	this->m_text=value;
}

std::vector<QuestionNode>* QuestionNode::get_SubNodes(){
	return &subNodes;
}

void QuestionNode::Clear(){
	int i;
	for(i=0;i<subNodes.size();i++){
		subNodes[i].Clear();
	}
	subNodes.clear();
}

QuestionNode::QuestionNode(){
	m_text="";
}

QuestionNode::~QuestionNode(){
	subNodes.clear();
}