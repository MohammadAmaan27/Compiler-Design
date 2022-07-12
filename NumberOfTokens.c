#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	char str[50];
	int len,i;
	int op=0,alpha=0,num=0,punct=0,tokens=0,d=0;
	printf("Enter a string: ");
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(isalpha(str[i]))
		alpha++;
		else if(str[i]=='%'||str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-'||str[i]=='=')
		op++;
		else if(isdigit(str[i]))
		{
			while(isdigit(str[i]))
			{
				i++;
			}
		  num++;
		}
	  else if(ispunct(str[i]))
	  punct++;
	  else
	  d++;	
	}
  tokens=alpha+op+num+punct;
  printf("Total no. of tokens are: %d" ,tokens);
  return 0;	
}
