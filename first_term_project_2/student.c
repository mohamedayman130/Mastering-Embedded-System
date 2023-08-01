#include<stdio.h>
#include<stdlib.h>
#include"init.h"
student_data std_base[50];
std_init first_group;


void main()
{
	init_queue(&first_group,std_base,50);
while(1)
{


int choice;
printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
printf("->add student manually::>> 1\n");
printf("->add student from file::>> 2\n");
printf("->delete a student::>> 3\n");
printf("->number of students::>> 4\n");
printf("->print all students::>> 5\n");
printf("->search by first name::>> 6\n");
printf("->search by id::>> 7\n");
printf("->update data::>> 8\n");
printf("->number of students who rolled in one course::>> 9\n");
printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
printf("enter your choice::>> ");scanf("%d",&choice);
printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");

switch(choice)
{
	case 2 :{add_std_from_file(&first_group,std_base);break;}
	case 1 :{add_student(&first_group,std_base);break;}
	case 3 :{delete_std(&first_group,std_base);break;}
	case 4 :{std_number(&first_group,std_base);break;}	
	case 5 :{print_all(&first_group,std_base);break;}
	case 6 :{search_by_first_name(&first_group,std_base);break;}
	case 7 :{search_by_id(&first_group,std_base);break;}
	case 8 :{update_data(&first_group,std_base);break;}
	case 9 : {num_of_student_in_one_course(&first_group,std_base);break;}
	default : {printf("==============wrong choice !!!!!!!!! try again==============\n");}	
}
}
}