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
    
    //不检查范围
    inline unsigned char _XToByte(const char hexNumber);
    
    //不检查范围
    inline unsigned char _DToByte(const char decNumber);
	
	inline int ReadInQuotes(const std::string &text, const int begin, std::string &_out);
public:
	//请务必从新的一行开始
	int ReadFromText(const std::string text);
	
	RecordListFormat();
	~RecordListFormat();
};

#endif