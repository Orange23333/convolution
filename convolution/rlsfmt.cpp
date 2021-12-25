// Record LisT ForMAt

#include "rlsfmt.h"

inline bool RecordListFormat::IsNumber(const char ch)
{
    return '0' <= ch && ch <= '9';
}
inline bool RecordListFormat::IsHexNumber(const char ch)
{
    return IsNumber(ch) || ('A' <= ch && ch <= 'F') || ('a' <= ch && ch <= 'f');
}
inline bool RecordListFormat::IsWhiteSpace(const char ch)
{
    return ch == ' ' || ch == '\t';
}

//����鷶Χ
inline unsigned char RecordListFormat::_XToByte(const char hexNumber){
	if('0' <= hexNumber && hexNumber <= '9'){
		return hexNumber-'0';
	}else if('A' <= hexNumber && hexNumber <= 'F'){
		return hexNumber-'A'+10;
	}else{
		return hexNumber-'a'+10;
	}
}

//����鷶Χ
inline unsigned char RecordListFormat::_DToByte(const char decNumber){
	return decNumber-'0';
}

inline int RecordListFormat::ReadInQuotes(const std::string &text, const int begin, std::string &_out){
	int i, j;
	std::string tempStr="";
	
	for(i=begin;i<text.length();i++){
		if(text[i]=='\\'){
			if(i+1<text.length()){
				switch (text[++i])
                {
                    case 'a':
                        tempStr+='\a';
                        break;
                    case 'b':
                        tempStr+='\b';
                        break;
                    case 'f':
                        tempStr+='\f';
                        break;
                    case 'n':
                        tempStr+='\n';
                        break;
                    case 'r':
                        tempStr+='\r';
                        break;
                    case 't':
                        tempStr+='\t';
                        break;
                    case 'v':
                        tempStr+='\v';
                        break;
                    case '\\':
                        tempStr+='\\';
                        break;
                    case '\'':
                        tempStr+='\'';
                        break;
                    case '"':
                        tempStr+='"';
                        break;
                    case '?':
                        tempStr+='?';
                        break;
                    case '\n':
                    case '\r':
						break;
                    case 'U':
                    case 'u':
                        if (i + 4 >= text.length() || !IsHexNumber(text[i+1]) || !IsHexNumber(text[i+2]) || !IsHexNumber(text[i+3]) || !IsHexNumber(text[i+4]))
                        {
                            PrintMessage("������", "Unicodeת���ַ���ʽ�������������ҽ���4��ʮ���������֡���");
							return -1;
                        }
                        
                        tempStr+=(_XToByte(text[i])<<4)|_XToByte(text[i+1]);
                        tempStr+=(_XToByte(text[i+2])<<4)|_XToByte(text[i+3]);
                        i += 4;
                        break;
                    case 'x':
                        if (i + 2 > text.length() || !IsHexNumber(text[i+1]) || !IsHexNumber(text[i+2]))
                        {
                            PrintMessage("������", "ʮ������ת���ַ���ʽ�������������ҽ���2��ʮ���������֡���");
							return -1;
                        }
                        
                        tempStr+=(_XToByte(text[i])<<4)|_XToByte(text[i+1]);
                        i += 2;
                        break;
                    default:
                        if (text[i] == '0' && i + 1 < text.length() && (!IsNumber(text[i + 1])))
                        {
                            tempStr+='\0';
                        }
                        else if (IsNumber(text[i]))//Ŀǰ���ð��쳣�׳�������ָ�ʽ����
                        {
							for(j=1;j<=3;j++){
								if(text[i+j]=='8' || text[i+j]=='9'){
									PrintMessage("������", "�˽���ת���ַ���ʽ�������в��ܳ�������8��9����");
									return -1;
								}else if(!IsNumber(text[i+j])){
									PrintMessage("������", "�˽���ת���ַ���ʽ�������������ҽ���3���˽������֡���");
									return -1;
								}
							}
							if(text[i]>='4'){
								PrintMessage("������", "�˽���ת���ַ���ʽ��������ֵӦ��С��0400����");
								return -1;
							}
                            
                            tempStr+=(_DToByte(text[i])<<6)|(_DToByte(text[i+1])<<3)|_DToByte(text[i+2]);
                            i += 2;
                        }
                        else
                        {
                            PrintMessage("������", "δ֪��ת���ַ���");
							return -1;
                        }
                        break;
                }
			}
			// û�б�Ҫ
			//else{
			//	PrintMessage("������", "ȱʧ�ַ�'\"'��");
			//	return -1;
			//}
		}else if(text[i]=='\n'){
			//_out=tempStr;
			//return i - begin + 1;
			break;
		}else{
			tempStr+=text[i];
		}
	}
	
	_out=tempStr;
	return i - begin;
}

//����ش��µ�һ�п�ʼ
int RecordListFormat::ReadFromText(const std::string text){
	int i, j, r;
	std::string quoteText;
	std::stack<QuestionNode*> nodeStack;
	std::vector<std::string> ansTexts;
	std::vector<int> ansRightIndexes;
	std::string *_ansTexts;
	int *_ansRightIndexes;
	bool isSealedNode=false;
	
	for(i=0;i<text.length();i++){
		printf("%d:'%c'",i,text[i]);
		switch(text[i]){
			case ' ':
			case '\t':
			case '\n':
				break;
			case '*':
				isSealedNode=true;
				
				r=ReadInQuotes(text, i+1, quoteText);
				if(r<0){
					return r;
				}
				i+=r;
				
				ansTexts.push_back(quoteText);
				break;
			case '.':
				isSealedNode=true;
				
				quoteText="";
				for(++i;i<text.length();i++){
					printf("%d:'%c'",i,text[i]);
					if(IsNumber(text[i])){
						quoteText+=text[i];
					}else if(IsWhiteSpace(text[i])){
						if(quoteText.length()>0){
							ansRightIndexes.push_back(atoi(quoteText.c_str()));
						}
					}else if(text[i]=='\n'){
						break;
					}else{
						PrintMessage("������", "��ȷ������Ӧ��Ϊ�ɿո�ָ�������һ�����֣���1��ʼ����");
						return -1;
					}
				}
				if(i>=text.length()){
					ansRightIndexes.push_back(atoi(quoteText.c_str()));
				}
				break;
			case '>':
				if(isSealedNode){
					PrintMessage("������", "�ں��д𰸵Ľڵ��в���������ӽڵ㣬ֻ����Ӵ𰸣�");
					return -1;
				}
				if(nodeStack.size()>0){
					QuestionNode* newNode = nodeStack.top()->PushBackNew();
					nodeStack.push(newNode);
				}else{
					nodeStack.push(NewRoot());
				}
				
				r=ReadInQuotes(text, i+1, quoteText);
				if(r<0){
					return r;
				}
				i+=r;
				
				nodeStack.top()->set_Text(quoteText);
				break;
			case '<':
				if(nodeStack.size()==0){
					PrintMessage("������", "�����'<'������֮ǰȱ��'>'��");
					return -1;
				}
				if(i+1<text.length()&&text[i+1]!='\n'){
					PrintMessage("������", "'>'�����У�����֮��Ӧ�����κ����ݣ������ո񣩣�");
					return -1;
				}
				
				_ansTexts=new std::string[ansTexts.size()];
				_ansRightIndexes=new int[ansRightIndexes.size()];
				for(j=0;j<ansTexts.size();j++){
					_ansTexts[j]=ansTexts[j];
				}
				for(j=0;j<ansRightIndexes.size();j++){
					_ansRightIndexes[j]=ansRightIndexes[j];
				}
				nodeStack.top()->get_Answers()->set_Answers(_ansTexts, ansTexts.size(), _ansRightIndexes, ansRightIndexes.size());
				delete[] _ansTexts;
				delete[] _ansRightIndexes;
				ansTexts.clear();
				ansRightIndexes.clear();
				nodeStack.pop();
				isSealedNode=false;
				break;
			default:
				if(nodeStack.size()==0){
					PrintMessage("������", "�ڲ�����֮ǰֻ���пո����ˮƽ�Ʊ����");
					return -1;
				}
				break;
		}
	}
	
	return text.length();
}

RecordListFormat::RecordListFormat(){
	;
}
RecordListFormat::~RecordListFormat(){
	;
}