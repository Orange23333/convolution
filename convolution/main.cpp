#include <iostream>
#include <string>

#include "info.h"

int main(int argc, char** argv){
	std::string _input;
	
	PrintWelcome();
	
	std::getline(std::cin,_input);

	return 0;
}