// INFOrmation

#ifndef __INFO_H_
	#define __INFO_H_
	
	#include <iostream>
	
	#define INFO_PROGRAM_NAME "convolution"
	#define INFO_PROGRAM_VERSION "1.0.0.0"
	#define INFO_PROGRAM_AUTHOR "Orange233"
	#define INFO_PROGRAM_LICENSE "MIT LICENSE"
	#define INFO_PROGRAM_COPYRIGHT "Copyright (c) Bisitsoft 2021"
	#define INFO_PROGRAM_DESCRIPTION "A study tool."
	#define INFO_PROJECT_URL "https://github.com/Orange23333/convolution"

#define TEXTLOGO_HEIGHT 19
#define TEXTLOGO_WIDTH 33
extern const char textLogo[TEXTLOGO_HEIGHT][TEXTLOGO_WIDTH];

void PrintLogo();
void PrintInfo();
void PrintWelcome();

#endif