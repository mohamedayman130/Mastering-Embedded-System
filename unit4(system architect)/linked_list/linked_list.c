#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	int id;
	int height;
	char name[40];
	struct student * next;

};


typedef enum{
    doublicated,
    not_doublicated
}doublication;

struct student *head=NULL;
int g_count=1;
void add_item()
{
	struct student *std,*find=head;
	std=(struct student* )malloc(sizeof(struct student));
	if(head==NULL) {head=std;std->next=NULL;}
	else{
		while(find->next!=NULL)
                find=find->next;
                find->next=std;
		        std->next=NULL;}


        printf("========enter data for student %d ===========\n",g_count++);
		printf("enter id::>> ");scanf("%d",&std->id);
		if(doublicated_id(std->id)==doublicated){printf("=============id is doublicated=============");free(std);find->next=NULL;g_count--;}
		else{
		printf("enter name::>> ");fflush(stdin);gets(std->name);
		printf("enter height::>> ");scanf("%d",&std->height);
		}


}

int doublicated_id(int id)
{
    struct student *find=head;
    while(find->next!=NULL)
        {
            if(find->id==id) return doublicated;
           else{ find=find->next;}
           }
           return not_doublicated;

}
void delete_item()
{
    int rm_id,count=1,flag=0;
    struct student *find=head;
    struct student *prev=head;

    if(find==NULL) printf("===========linked list is empty=======\n");
    else{
        printf("enter id that you want to remove::>> ");scanf("%d",&rm_id);
    while(find!=NULL)
    {
        if(find->id==rm_id) {flag=1;break;}
        else{find=find->next;count++;}
    }
    if(flag==0) printf("===========not found===========\n");
    else if(flag==1 && count==1)
    {
        head=find->next;
    }
    else{int find_count=2;
        while(find_count<count)
        {prev=prev->next;find_count++;}
        prev->next=find->next;
        free(find);g_count--;
    }

    }

}
void print_items()
{
	int count=1;
	if(head==NULL) printf("%s\n","========linked list is empty===========" );
	else{
		struct student *find=head;
		while(find!=NULL)
		{
			printf("=======student number ::>> %d=========\n",count++);
			printf("id ::>> %d\n",find->id);
			printf("name ::>> %s\n",find->name);
			printf("height::>> %d\n",find->height);
			find=find->next;

		}
	}
}
void delete_all()
{
    struct student *next=head;
    if(next==NULL) printf("%s\n","========linked list is empty===========" );
    else{
    while(next!=NULL)
    {
        struct student *temp=next;
        next=next->next;
        free(temp);
    }
    head=NULL;g_count=1;
    }
}

int number_of_nodes()
{
    int count=0;
    struct student *next=head;
        while(next!=NULL)
        {
            count++;
            next=next->next;
        }
        printf("===number of elements ::>> %d\n",count);
        return count;
}

    int count1=0;
int number_of_nodes_with_recursion(struct student *find)
{
    //if(find==NULL) {printf("%s\n","========linked list is empty===========" );return 0;}
    if(find!=NULL){number_of_nodes_with_recursion(find->next);count1++;return count1;}
    else{return count1;}

}
void middle_of_linkedlist_data()//you can make it by another methode
{
    int size=number_of_nodes();
    if(size%2==0){size/=2;size++;}
    else{size/=2;size++;}
        int count=0;
    if(head==NULL) printf("%s\n","========linked list is empty===========" );
    else{
            struct student *next=head;
            while(count<size-1)
               {next=next->next;count++;}
            printf("===========data of index %d========\n",size);
            printf("id::>> %d\n",next->id);
            printf("name::>> %s\n",next->name);
            printf("height::>> %d\n",next->height);

    }


}
void find_node_with_revers_index()
{
    if(head==NULL) printf("%s\n","========linked list is empty===========" );
    else{
            int count=0;
        printf("enter index(from zero)::>> ");int index;scanf("%d",&index);
        if(number_of_nodes()<=index) printf("==========out of size==========\n");
        else{struct student *next=head,*prev=head;
        while(count<index){next=next->next;count++;}
        while(next->next!=NULL)
        {
            next=next->next;
            prev=prev->next;
        }

            printf("===========data of  index from last element %d========\n",index);
            printf("id::>> %d\n",prev->id);
            printf("name::>> %s\n",prev->name);
            printf("height::>> %d\n",prev->height);
            }

    }

}

void find_node_with_index()
{
    int index,count=0;
    printf("enter the index(from zero)::>> ");scanf("%d",&index);
    if(head==NULL) printf("%s\n","========linked list is empty===========" );
    else{
            struct student *next=head;
            if(number_of_nodes()<=index) printf("==========out of size==========\n");
            else{while(count<index)
               {next=next->next;count++;}
            printf("===========data of index %d========\n",index);
            printf("id::>> %d\n",next->id);
            printf("name::>> %s\n",next->name);
            printf("height::>> %d\n",next->height);
            }
    }
}
int main()
{
	int chose;
	while(1)
    {
printf("=======================\n");
        printf("add element::> 1\n");
        printf("delete element::> 2\n");
        printf("print all elements::> 3\n");
        printf("delete all elements::> 4\n");
        printf("number of elements::> 5\n");
        printf("middle_of_linkedlist_data::> 6\n");
        printf("find_node_with_revers_index::> 7\n");
        printf("find_node_with_index::> 8\n");
        printf("number_of_elements_with_recursion::> 9\n");
        printf("=======================\n");
        printf("==enter your choice::>> ");scanf("%d",&chose);
printf("=======================\n");
            switch(chose)
            {
                case 1 :{add_item();break;}
                case 2 :{delete_item();break;}
                case 3 :{print_items();break;}
                case 4 :{delete_all();break;}
                case 5 :{number_of_nodes();break;}
                case 6 :{middle_of_linkedlist_data();break;}
                case 7 :{find_node_with_revers_index();break;}
                case 8 :{find_node_with_index();break;}
                case 9 :{printf("===number of elements ::>> %d\n",number_of_nodes_with_recursion(head));count1=0;break;}
                default :{printf("==========out of size===========");}


            }
        }

    }

