// EXAM

#include "exam.h"

void _View(QuestionNode &node, const int index, std::vector<int> &numbers);
void _PrintNumbers(std::vector<int> &numbers);

void View(QuestionNode &node){
	std::vector<int> numbers;
	_View(node,1,numbers);
}

void _View(QuestionNode &node, const int index, std::vector<int> &numbers){
	int i, j;
	
	numbers.push_back(i);
	
	_PrintNumbers(numbers);
	std::cout<<node.get_Text()<<std::endl;
	
	if(node.get_Answers()->get_Texts()->get_Size()>0){
		for(i=0;i<node.get_Answers()->get_Texts()->get_Size();i++){
			std::cout<<'[';
			for(j=0;j<node.get_Answers()->get_RightAnswers()->get_Size();j++){
				if(i+1==node.get_Answers()->get_RightAnswers()->get_DataPointer()[j]){
					std::cout<<"o";
					break;
				}
			}
			if(j>=node.get_Answers()->get_RightAnswers()->get_Size()){
				std::cout<<' ';
			}
			std::cout<<"] "<<(char)('1'+i)<<". "<<node.get_Answers()->get_Texts()->get_DataPointer()[i]<<std::endl;
		}
	}else{
		for(i=1;i<=node.get_SubNodes()->size();i++){
			_View(*((*(node.get_SubNodes()))[i]),i,numbers);
		}
	}
	
	numbers.pop_back();
}

void _PrintNumbers(std::vector<int> &numbers){
	int i;
	if(numbers.size()>0){
		std::cout<<numbers[0];
		for(i=1;i<numbers.size();i++){
			std::cout<<'.'<<numbers[i];
		}
	}
}