// EASY ForMaT

#ifndef __EASYFMT_H_
	#define __EASYFMT_H_
	
	#include <string>
	
	#include "qstnode.h"

class EasyFormat : QuestionFormat{
private:
	std::string 
public:
	//����ش��µ�һ�п�ʼ
	void ReadFromText(const std::string text, const int beginLine){
		int line = beginLine, row = 0;
		char *ptr = text.data(), ptr_end = text.data() + text.length();
		
#warning ���ܴ��ڵ�ַ�ﵽ���ֵ������������
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