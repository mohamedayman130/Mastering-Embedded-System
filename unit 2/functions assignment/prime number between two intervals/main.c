#include <stdio.h>
#include <stdlib.h>

void prime (int n1,int n2)
{
if(n2<n1)
{
    int temp=n1;
    n1=n2;
    n2=temp;
}
for(int i=n1;i<=n2;i++)
{
    int temp=0;
    if(i==0||i==1) temp=1;
    for(int j=2;j<i;j++)
    {
        if(i%j==0)
        {temp=1;
            break;
        }
    }
    if(temp==0) printf("%d\n",i);
}

}
int main()
{
    int n1,n2;
    printf("enter (positive)first number ::>> ");fflush(stdin);fflush(stdout);scanf("%d",&n1);
    printf("enter (positive)second number ::>> ");fflush(stdin);fflush(stdout);scanf("%d",&n2);
    prime(n1,n2);


}
