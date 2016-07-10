#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void main()
{
	int i;
	char k[32][9]={"break","else","long","switch","case","enum","register","typedef","char",
				"extern","return","union","const","float","short","unsigned","continue","for",
				"signed","void","default","goto","sizeof","volatile","do","if","static","while"},s[10];
	FILE *f;
	f=fopen("test.txt","r");
	for(;EOF!=fscanf(f,"%s\n",s);)
	{
		for(i=0;i<9;i++)
		{
			if(!strcmp(k[i],s))
			{
				printf("%s is keyword\n",s);
				break;
			}
		}
		if(i==9)
			if(indeti(s))
				printf("%s is identifier\n",s);
			else
				printf("%s is neither identifier nor keyword\n",s);
	}
}
int indeti(char *s)
{
	int i;
	if(isdigit(s[0]))
			return 0;
	for(i=0;i<strlen(s);i++)
	{
		if(!(isalpha(s[i])||isdigit(s[i])||s[i]=='_'))
			return 0;
	}
	return 1;
}
