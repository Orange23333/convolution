// Record LisT ForMAt

#ifndef __RLSFMT_H_
	#define __RLSFMT_H_
	
	#include <string>
	#include <stack>
	#include <vector>
	
	#include "qstfmt.h"
	#include "qstnode.h"
	#include "utility.h"

class RecordListFormat : public QuestionFormat{
private:
	inline bool IsNumber(const char ch);
    inline bool IsHexNumber(const char ch);
    inline bool IsWhiteSpace(const char ch);
    
    //����鷶Χ
    inline unsigned char _XToByte(const char hexNumber);
    
    //����鷶Χ
    inline unsigned char _DToByte(const char decNumber);
	
	inline int ReadInQuotes(const std::string &text, const int begin, std::string &_out);
public:
	//����ش��µ�һ�п�ʼ
	int ReadFromText(const std::string text);
	
	RecordListFormat();
	~RecordListFormat();
};

#endif