#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	int i,j,w,h;
	char buffer;

	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	scanf("%d%d",&w,&h);
	scanf("%c",&buffer);
	
	printf("const char textLogo[%d][%d]={\n",h,w);
	for(i=0;i<h;i++){
		printf("\t{ ");
		for(j=0;j<1;j++){
			scanf("%c",&buffer);
			printf("'%c'",buffer);
		}
		for(j=0;j<w-1;j++){
			scanf("%c",&buffer);
			printf(", '%c'",buffer);
		}
		scanf("%c",&buffer);
		puts(" },");
	}
	puts("};");
	
	return 0;
}
