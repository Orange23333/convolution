#include <cstdlib>
#include <ctime>

#include <iostream>

#include <string>

#include "info.h"

#include "exam.h"
#include "qstf.h"
#include "qstnode.h"

int main(int argc, char** argv){
	int r;
	std::string _input;
	
	srand(time(NULL));
	
	PrintWelcome();
	
	QuestionFile qstf;
	r=qstf.LoadFromFile("D:/Work/Project/inSeay/ToeCheese/plugins/convolution/convolution/Debug/思修.多选题.ASCII.qstf");
	if(r>=0){
		View(*qstf.get_RootQuestionNode());
	}
	
	std::getline(std::cin,_input);

	return 0;
}