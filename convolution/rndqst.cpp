// RaNDom QueSTion node

#include "rndqst.h"

//不检查是否min<max
inline int RandomQuestionNode::GetRandomValue(const int min, const int max){
	return rand()%(max-min+1)+min;
}

std::vector<RandomQuestionNode*>* RandomQuestionNode::get_SubNodes(){
	return &subNodes;
}

QuestionNode* RandomQuestionNode::get_OriginQuestionNode(){
	return originQuestionNode;
}

//原答案索引是从0开始的，而随机答案是从1开始的。
void RandomQuestionNode::Set(QuestionNode* node){
	int i;
	Clear();
	
	if(node->get_Answers()->get_Texts()->get_Size()>0){
		int temp;
		std::vector<int> _indexes(node->get_Answers()->get_Texts()->get_Size());
		for(i=0;i<node->get_Answers()->get_Texts()->get_Size();i++){
			_indexes.push_back(i);
		}
		//其实这里可以直接用indexes.size()代替i。
		for(i=node->get_Answers()->get_Texts()->get_Size()-1;i>=0;i--){
			temp=GetRandomValue(0,i);
			randomAnswerToOriginAnswer.insert(std::make_pair(i,_indexes[temp])); //不知道是i更好还是get_Size()-i-1更好
			_indexes.erase(_indexes.begin()+temp);
		}
	}else{
		for(i=0;i<node->get_SubNodes()->size();i++){
			RandomQuestionNode* newNode=new RandomQuestionNode();
			newNode->Set((*(node->get_SubNodes()))[i]);
			subNodes.push_back(newNode);
		}
	}
	
	this->originQuestionNode=node;
}

void RandomQuestionNode::Clear(){
	int i;
	for(i=0;i<subNodes.size();i++){
		subNodes[i]->Clear();
		delete[] subNodes[i];
	}
	subNodes.clear();
	randomAnswerToOriginAnswer.clear();
}

RandomQuestionNode::RandomQuestionNode(){
	originQuestionNode=NULL;
}
RandomQuestionNode::~RandomQuestionNode(){
	Clear();
}