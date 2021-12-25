// QueSTion File

#include "qstf.h"

void QuestionFile::Clear(){
	if(questionFormat!=NULL){
		delete[] questionFormat;
	}
}

int QuestionFile::LoadFromText(const std::string text){
	int i, r;
	std::string temp="";
	
	for(i=0;i<text.size();i++){
		if(text[i]=='#'){
			for(;i<text.size();i++){
				if(text[i]=='\n'){
					break;
				}
			}
			if(i>=text.size()){
				PrintMessage("������", "����⡶");
				return -1;
			}
		}else if(text[i]=='@'){
			i++;
			for(;i<text.size();i++){
				if(text[i]=='\n'){
					break;
				}else if(text[i]=='#'){
					for(++i;i<text.size();i++){
						if(text[i]=='\n'){
							break;
						}
					}
					break;
				}else{
					temp+=text[i];
				}
			}
			break;
		}else if(text[i]==' ' || text[i]=='\t'){
			;
		}else{
			temp=="csq";
			break;
		}
	}
	
	if(temp=="rls"){
		Clear();
		RecordListFormat* rlsFormat=new RecordListFormat();
		r=rlsFormat->ReadFromText(text.substr(i+1));
		if(r<0){
			return r;
		}
		questionFormat=rlsFormat;
	}else{
		PrintMessage("������", "��֧�ֵĸ�ʽ��"+temp);
		return -1;
	}
	
	return 0;
}

//int LoadFromFile(const std::string path){
//	long line, row;
//	long i;
//	char _input;
//	std::ifstream qstf;
//	
//	qstf.open(path, std::ios::in);
//	if(!qstf.is_open()){
//		PrintMessage("������", "�ļ��޷��򿪣�");
//		return -1;
//	}
//	
//	//qstf.seekg(0, std::ios::end); //seekg����������seek��seekp���������seek��
//	//n=qstf.tellg();
//	//qstf.seekg(0, std::ios::beg);
//	
//	line = 1, row = 1;
//	do{
//		qstf.get(_input);
//		if(_input
//	}while(true);
//	for(i=0;i<n;i++){
//		if()
//	}
//	
//	qstf.close();
//}

int QuestionFile::LoadFromFile(const std::string path){
	FILE *fp;
	int i, n;
	char temp,*buffer,*ptr;
	
	fopen_s(&fp,path.c_str(),"r");
	if(fp==NULL){
		PrintMessage("������", "�ļ��޷��򿪣�");
		return -1;
	}
	
	fseek(fp,0,SEEK_END);
	n = ftell(fp);
	fseek(fp,0,SEEK_SET);
	
	buffer=(char*)malloc((n+1)*sizeof(char));
	if(buffer==NULL){
		fclose(fp);
		PrintMessage("������", "�ڴ治�㣬�޷���ȡ�ļ���");
		return -1;
	}
	
	ptr=buffer;
	while((temp=fgetc(fp))!=EOF){
		*(ptr++)=temp;
	}
	*ptr='\0';
	fclose(fp);
	
	return LoadFromText(buffer);
}