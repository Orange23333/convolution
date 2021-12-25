// RaNDom QueSTion node

#ifndef __RNDQST_H_
	#define __RNDQST_H_
	
	#include <cstdlib>
	#include <ctime>
	
	#include <map>
	#include <vector>
	
	#include "qstnode.h"
	
class RandomQuestionNode{
private:
	std::vector<RandomQuestionNode*> subNodes;
	std::map<int, int> randomAnswerToOriginAnswer;
	QuestionNode* originQuestionNode;
	
	//不检查是否min<max
	inline int GetRandomValue(const int min, const int max);
public:
	std::vector<RandomQuestionNode*>* get_SubNodes();
	
	QuestionNode* get_OriginQuestionNode();
	
	//原答案索引是从0开始的，而随机答案是从1开始的。
	void Set(QuestionNode* node);
	void Clear();
	
	RandomQuestionNode();
	~RandomQuestionNode();
};

#endif