#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<strings.h>
char * sconcat(char *ptr1,char *ptr2);

int main()
{
char string1[10],string2[10],*ptr;
int i;
//clrscr();

printf("Enter String 1 : ");
gets(string1);
printf("Enter String 2 : ");
gets(string2);

ptr = sconcat(string1,string2);

printf("Output String : %s",ptr);
getch();
}
/*---------------------------------------------------------
  Function Definition 
  --------------------------------------------------------*/

char * sconcat(char *ptr1,char *ptr2)
{
int len1,len2;
int i,j;
char *ptr3;

len1 = strlen(ptr1);
len2 = strlen(ptr2);

/*-------------------------------------------------------------
  Note :
    1. Output String has Length len1+len2+1
    2. 1 Character Extra for NULL character
    1. Allocate Dynamic memory using Malloc
  ------------------------------------------------------------*/

  ptr3 = (char *)malloc((len1+len2+1)*sizeof(char));

  for(i=0;ptr1[i]!='\0';i++)
  ptr3[i]=ptr1[i];

  for(j=0;ptr2[j]!='\0';j++,i++)
  ptr3[i]=ptr2[j];

  ptr3[i]='\0';
  return(ptr3);
}
