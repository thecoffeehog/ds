#include<stdio.h>
#include<conio.h>
#include<strings.h>
#include<stdlib.h>
char *sconcat(char *ptrs1, char *ptrs2);
int main()
{
	char s1[10],s2[10],*cptr;
	printf("Please enter the first string: ");
	gets(s1);
	printf("Please enter the second string: ");
	gets(s2);
	cptr=sconcat(s1,s2);
	printf("Concatenated string is: %s",cptr);
	getch();
}
char *sconcat(char *ptrs1, char *ptrs2)
{
int lens1,lens2;
int i,j;
char *ptr;
lens1=strlen(ptrs1);
lens2=strlen(ptrs2);
ptr= (char *)malloc((lens1+lens2+1)*sizeof(char));
for(i=0;ptrs1[i]!='\0';i++)
  ptr[i]=ptrs1[i];

  for(j=0;ptrs2[j]!='\0';j++,i++)
  ptr[i]=ptrs2[j];

  ptr[i]='\0';
  
return (ptr);	
}
