// ANSwerS

#include "anss.h"

Array<std::string>* Answers::get_Texts(){
	return texts;
}

Array<int>* Answers::get_RightAnswers(){
	return rightAnswers;
}

bool Answers::IsAnswerRight(const int* answerIndexes, const int answerIndexesN){
	int i,j;
	
	std::vector<int> _answers(answerIndexesN);
	for(i=0;i<answerIndexesN;i++){
		_answers.push_back(answerIndexes[i]);
	}
	
	for(i=0;i<rightAnswers->get_Size();i++){
		for(j=0;j<_answers.size();j++){
			if(rightAnswers->get_DataPointer()[i]==_answers[j]){
				for(std::vector<int>::iterator it=_answers.begin(); it!=_answers.end();){
					if(*it==rightAnswers->get_DataPointer()[i]){
						it=_answers.erase(it); //记住erase后原迭代器失效，但是erase返回新的下一个迭代器。
					}else{
						it++;
					}
				}
				break;
			}
		}
		if(j>=_answers.size()){
			return false;
		}
	}
	
	return _answers.size() == 0;
}

void Answers::set_Answers(const std::string* texts, const int textsN, const int* rightAnswerIndexes, const int rightAnswerIndexesN){
	Clear();
	
	this->texts=new Array<std::string>(textsN);
	memcpy(this->texts->get_DataPointer(),texts,sizeof(std::string)*textsN);
	this->rightAnswers=new Array<int>(rightAnswerIndexesN);
	memcpy(this->rightAnswers->get_DataPointer(),rightAnswerIndexes,sizeof(int)*rightAnswerIndexesN);
}

void Answers::Clear(){
	if(texts!=NULL){
		texts->Free();
		delete[] texts;
	}
	if(rightAnswers!=NULL){
		rightAnswers->Free();
		delete[] rightAnswers;
	}
}

Answers::Answers(){
	texts=NULL;
	rightAnswers=NULL;
}

Answers::~Answers(){
	Clear();
}