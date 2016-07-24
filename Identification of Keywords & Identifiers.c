#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define DKEY "keywords.txt"
struct key{
	char *s;
}*k;
int l;
int iskey(char *s);
int isnum(char *s);
int isop(char *s);
int ispar(char *s);
struct key * scana(char *,int *);
void main()
{
	int i;
	char s[10];
	FILE *f;
	k=scana(DKEY,&l);
	f=fopen("test.txt","r");
	for(;EOF!=fscanf(f,"%s\n",s);)
	{
		if(iskey(s))
			printf("%s is Keyword..\n\n",s);
		else if(isind(s))
			printf("%s is Identifier..\n\n",s);
		else if(isnum(s))
			printf("%s is Number..\n\n",s);
		else if(ispar(s))
			printf("%s is Paranthesis..\n\n",s);
		else if(isop(s))
			printf("%s is Opertor..\n\n",s);
		else
			printf("%s Undefine Symbol\n\n",s);
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
	static i;
	for(i=0;i<l;i++)
		if(!strcmp(k[i].s,s))
			return 1;
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
struct key * scana(char *s,int *ln)
{
	int l,i,j;
	FILE *f;
	char a[10],*c;
	struct key *p;
	f=fopen(s,"r");
	l=countlines(s);
	p=(struct key *)calloc(l,sizeof(struct key));
	fseek(f,0,SEEK_SET);
	for(i=0;i<l&&EOF!=fscanf(f,"%s",a);i++)
	{
		p[i].s=(char *)calloc(strlen(a)+1,sizeof(char));
		for(j=0;j<strlen(a);j++)
			p[i].s[j]=a[j];
		p[i].s[j]='\0';
		for(j=0;j<10;j++)a[j]=NULL;
	}
	fclose(f);
	*ln=l;
	return p;
}
int countlines(char *f)
{
	FILE *fp=fopen(DKEY,"r");
	int ch=0;
	int l=0;
	if(fp==NULL)
		return 0;
	for(l=1;(ch = fgetc(fp))!=EOF;)
    {
    	if(ch=='\n')
		l++;
    }
  	fclose(fp);
  	return l;
}
