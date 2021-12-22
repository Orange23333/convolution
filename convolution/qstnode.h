// QueSTion NODE

#ifndef __QSTNODE_H_
	#define __QSTNODE_H_
	
	#include <string>
	#include <vector>

class QuestionNode{
private:
	std::string m_text;
	std::vector<QuestionNode*> subNodes;
public:
	std::string get_Text();
	void get_Text(std::string value);
	
	std::vector<QuestionNode*>* get_SubNodes();
	void Clear();
	
	QuestionNode();
	~QuestionNode();
};
	
#endif