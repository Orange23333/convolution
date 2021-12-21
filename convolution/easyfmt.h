// EASY ForMaT

#ifndef __EASYFMT_H_
	#define __EASYFMT_H_
	
	#include <string>
	
	#include "qstnode.h"

class EasyFormat : QuestionFormat{
private:
	std::string 
public:
	//请务必从新的一行开始
	void ReadFromText(const std::string text, const int beginLine){
		int line = beginLine, row = 0;
		char *ptr = text.data(), ptr_end = text.data() + text.length();
		
#warning 可能存在地址达到最大值导致溢出的情况
		for(;ptr!=ptr_end;ptr++){
			
		}
	}
	
	EasyFormat(){
		;
	}
	~EasyFormat(){
		;
	}
};

#endif