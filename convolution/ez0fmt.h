// EaZy 0 ForMAt

#ifndef __EZ0FMT_H_
	#define __EZ0FMT_H_
	
	#include <string>
	#include <stack>
	
	#include "qstfmt.h"
	#include "qstnode.h"

class EasyFormat : public QuestionFormat{
private:
	inline void _NewLine(int &line, int &row);
	inline void _LevelUp();
	inline void _LevelDown(std::vector<QuestionNode*> &leveledNodes);
public:
	//请务必从新的一行开始
	int ReadFromText(const std::string text){
		
	}
	
	EasyFormat();
	~EasyFormat();
};

#endif