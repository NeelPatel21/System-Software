#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
int iskey(char *s);
int isnum(char *s);
int isop(char *s);
int ispar(char *s);
void main()
{
	int i;
	char s[10];
	FILE *f;
	f=fopen("test.txt","r");
	for(;EOF!=fscanf(f,"%s\n",s);)
	{
		if(iskey(s))
			printf("%s is keyword..\n\n",s);
		else if(isind(s))
			printf("%s is identifier..\n\n",s);
		else if(isnum(s))
			printf("%s is Number..\n\n",s);
		else if(ispar(s))
			printf("%s is paranthesis..\n\n",s);
		else if(isop(s))
			printf("%s is opertor..\n\n",s);
		else
			printf("%s undefine symbol\n\n",s);
		memset(s,'\0',10);
	}
}
int isind(char *s)
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
int iskey(char *s)
{
	int i;
	char k[31][9]={"break","else","long","switch","case","enum","register","typedef","char",
				"extern","return","union","const","float","short","unsigned","continue","for",
				"signed","void","default","goto","sizeof","volatile","do","if","static","while",
				"int","double","char",""};
	for(i=0;i<31;i++)
	{
		if(strcmp(k[i],s)==0)
			return 1;
	}
	return 0;
}
int isnum(char *s)
{
	int i,f=0;
	for(i=0;i<strlen(s);i++)
	{
		if(!(isdigit(s[i])))
			if(s[i]=='.'&&!f)
				f++;
		else
			return 0;
	}
}
int isop(char *s)
{
	int i=0;
	if(strlen(s)>1)
		return 0;
	if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%')
		return 1;
	return 0;	
}
int ispar(char *s)
{
	int i=0;
	if(strlen(s)>1)
		return 0;
	if(s[i]=='['||s[i]==']'||s[i]=='{'||s[i]=='}'||s[i]=='('||s[i]==')')
		return 1;
	return 0;
}
