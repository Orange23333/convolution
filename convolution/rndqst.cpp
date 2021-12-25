// RaNDom QueSTion node

#include "rndqst.h"

//������Ƿ�min<max
inline int RandomQuestionNode::GetRandomValue(const int min, const int max){
	return rand()%(max-min+1)+min;
}

std::vector<RandomQuestionNode*>* RandomQuestionNode::get_SubNodes(){
	return &subNodes;
}

QuestionNode* RandomQuestionNode::get_OriginQuestionNode(){
	return originQuestionNode;
}

//ԭ�������Ǵ�0��ʼ�ģ���������Ǵ�1��ʼ�ġ�
void RandomQuestionNode::Set(QuestionNode* node){
	int i;
	Clear();
	
	if(node->get_Answers()->get_Texts()->get_Size()>0){
		int temp;
		std::vector<int> _indexes(node->get_Answers()->get_Texts()->get_Size());
		for(i=0;i<node->get_Answers()->get_Texts()->get_Size();i++){
			_indexes.push_back(i);
		}
		//��ʵ�������ֱ����indexes.size()����i��
		for(i=node->get_Answers()->get_Texts()->get_Size()-1;i>=0;i--){
			temp=GetRandomValue(0,i);
			randomAnswerToOriginAnswer.insert(std::make_pair(i,_indexes[temp])); //��֪����i���û���get_Size()-i-1����
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