#include<stdio.h>

  int cpy(char y [],char x[])
  {int len=0;
  	while(x[len++]!='\0');
  		len--;
  	for (int i = 0; i < len; ++i)
  	  y[i]=x[i];
  	y[len]='\0';
    return len;
  }
 struct Employee
 {char name [100];
 	int id;};
int main()
{
	struct Employee e1;
	struct Employee e2;
	struct Employee *e[]={&e1,&e2};
	struct Employee *(*ptre)[2]=&e;
	char names[100];fflush(stdout),fflush(stdin);
  printf("for e1 : enter your name::>> "),gets(names),cpy((**(*(ptre)+0)).name,names);
  printf("for e1 : enter your id::>> "),scanf("%d",&(*(*ptre +0))->id),fflush(stdout),fflush(stdin);
	printf("for e2 : enter your name::>> "),gets(names),cpy((**(*(ptre)+1)).name,names);
	printf("for e2 : enter your id::>> ");scanf("%d",&(**(*(ptre)+1)).id);
	printf("\n<<--DATA-->>\n");
	printf("e1: \nname::>> %s \nid::>>%d\n",(**(*ptre+0)).name,(**(*ptre+0)).id);
  printf("e2: \nname::>> %s \nid::>>%d",(**(*ptre+1)).name,(**(*ptre+1)).id);
  scanf("%d");
	return 0;
}

