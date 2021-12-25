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
	
	//������Ƿ�min<max
	inline int GetRandomValue(const int min, const int max);
public:
	std::vector<RandomQuestionNode*>* get_SubNodes();
	
	QuestionNode* get_OriginQuestionNode();
	
	//ԭ�������Ǵ�0��ʼ�ģ���������Ǵ�1��ʼ�ġ�
	void Set(QuestionNode* node);
	void Clear();
	
	RandomQuestionNode();
	~RandomQuestionNode();
};

#endif