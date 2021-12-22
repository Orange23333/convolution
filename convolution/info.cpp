// INFOrmation

#include "info.h"

const char textLogo[TEXTLOGO_HEIGHT][TEXTLOGO_WIDTH]={
	{ ' ', '/', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '*' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ' },
	{ '|', ' ', ' ', ' ', '/', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '*', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '/', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '\\', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '/', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '\\', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '/', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '\\', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '/', '-', '-', '-', '-', '-', '-', '-', '\\', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '/', '-', '-', '-', '\\', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '*', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '\\', '-', '/', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '\\', '-', '-', '-', '-', '-', '/', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '\\', '-', '-', '-', '-', '-', '-', '-', '-', '-', '/', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '\\', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '/', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '|', ' ', '\\', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '/', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', '\\', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '/', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', ' ', 'C', ' ', '0', 'i', 'N', ' ', 'V', ' ', '0', ' ', 'L', ' ', 'U', ' ', 'T', ' ', 'I', ' ', '0', ' ', 'N', ' ', ' ', ' ', ' ', ' ', '|', ' ' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ' },
	{ ' ', '\\', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '*' },
};

void PrintLogo(){
	int i,j;
	for(i=0;i<TEXTLOGO_HEIGHT;i++){
		for(j=0;j<TEXTLOGO_WIDTH;j++){
			std::cout<<textLogo[i][j];
		}
		std::cout<<std::endl;
	}
}

void PrintInfo(){
	std::cout<<"@ Program Name: "<<INFO_PROGRAM_NAME<<std::endl;
	std::cout<<"@ Program Version: "<<INFO_PROGRAM_VERSION<<std::endl;
	std::cout<<"@ Program Author: "<<INFO_PROGRAM_AUTHOR<<std::endl;
	std::cout<<"@ Program License (If you continue to use our software, that means you agree to the contents of our license): "<<INFO_PROGRAM_LICENSE<<std::endl;
	std::cout<<"@ Program Copyright: "<<INFO_PROGRAM_COPYRIGHT<<std::endl;
	std::cout<<"@ Program Description: "<<INFO_PROGRAM_DESCRIPTION<<std::endl;
	std::cout<<"@ Project URL: "<<INFO_PROJECT_URL<<std::endl;
}

void PrintWelcome(){
	PrintLogo();
	PrintInfo();
	
	//#warning 不使用中文，是因为暂时没有解决GBK，GB2312，GB5位数，UTF8之间的差异问题。
	std::cout<<"欢迎使用卷乙积，现在是一个简易的题库工具。\n你可以通过输入“help”来获取帮助，\n用可以阅读markdown文件的编辑打开（用记事本也能查看，只不过markdown的注记可能会影响阅读）与程序文件在同一文件夹下的“README.md”文件或者访问“https://github.com/Orange23333/convolution/README.md”来查看完整的帮助文档。"<<std::endl;
}