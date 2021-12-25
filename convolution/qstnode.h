// QueSTion NODE

#ifndef __QSTNODE_H_
	#define __QSTNODE_H_
	
	#include <string>
	#include <vector>
	
	#include "anss.h"

class QuestionNode{
private:
	std::string m_text;
	std::vector<QuestionNode*> subNodes;
	Answers* answers;
public:
	std::string get_Text();
	void set_Text(const std::string value);
	
	Answers* get_Answers();
	void init_Answers();
	
	std::vector<QuestionNode*>* get_SubNodes();
	QuestionNode* QuestionNode::PushBackNew();
	void Clear();
	
	QuestionNode();
	~QuestionNode();
};
	
#endif