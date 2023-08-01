#include"init.h"
#include<stdio.h>
#include<string.h>
state init_queue(std_init *init,student_data *std,int lenght)
{
	init->head=std;
	//init->tail=std;
	//init->base=std;
	init->count=0;
	init->lenght=lenght;
	return done;
}

state add_student(std_init *init,student_data *std)
{
	if(init->count>init->lenght) {printf("========queue is full=========== ");return faild;}
	student_data *find=std;int temp_id;
	printf("======enter std (%d) data ====== \n->id::>> ",init->count+1);scanf("%d",&temp_id);
	//while(find<init->head)
		//{
	if(douplicate(init,std,temp_id)==done) {printf("=============id(%d) is doublicated==========\n",temp_id);return faild;}
		//	find++;
		//}
		//find=std;
		while(find<init->head)
		{
			if(find->del==0) find++;
			else break;
		}
		find->id=temp_id;
	printf("->first name::>> ");fflush(stdin);scanf("%s",&find->first_name);
	printf("->second name::>> ");fflush(stdin);scanf("%s",&find->last_name);
	printf("->gpa::>> ");scanf("%f",&find->gpa);fflush(stdin);fflush(stdout);
	printf("->first_course::>> ");scanf("%d",&find->first_course);
	printf("->second_course::>> ");scanf("%d",&find->second_course);
	printf("->third_course::>> ");scanf("%d",&find->third_course);
	printf("->fourth_course::>> ");scanf("%d",&find->fourth_course);
	printf("->fifth_course::>> ");scanf("%d",&find->fifth_course);find->del=0;
	printf("=============student data is added===========\n");
	init->count++;
	if(find==init->head) init->head++;
	return done;

}
state douplicate(std_init *init,student_data *std,int val)
{
	student_data *find=std;
	while(find<init->head)
	{
		if(find->id==val && find->del==0) return done;
		find++;
	}
	return faild;
}

state print_all(std_init *init,student_data *std)
{
	student_data *find=std;int c=0;
	if(init->count==0) {printf("=====================empty base=================\n");return faild;}
	while(find<init->head)
	{if(find->del==1) {find++;continue;}
		printf("===============================================================\n");
		printf("================std (%d)==============\n",c+1);
		printf("->id::>> %d\n",find->id);
		printf("->first_name::>> %s\n",find->first_name);
		printf("->last_name::>> %s\n",find->last_name);
		printf("->gpa::>> %.2f\n",find->gpa);
		printf("->first_course::>> %d\n",find->first_course);
		printf("->second_course::>> %d\n",find->second_course);
		printf("->third_name::>> %d\n",find->third_course);
		printf("->fourth_name::>> %d\n",find->fourth_course);
		printf("->fifth_name::>> %d\n",find->fifth_course);
		find++;c++;
	printf("===============================================================\n");
	}
return done;
}
state delete_std(std_init *init,student_data *std)
{
	int temp_id;
	if(init->count==0) {printf("=====================empty base=================\n");return faild;}
	printf("enter id that want to be deleted::>> ");scanf("%d",&temp_id);
	student_data *find=std;
	while(find<init->head)
	{
		if(temp_id==find->id && find->del==0) {find->del=1;printf("============element is deleted=========\n");init->count--;return done;}
		find++;
	}
	printf("============id is not found=================\n");return faild;
         
}


void std_number(std_init *init,student_data *std)
{
	printf("-->>number of students::>> %d \n",init->count);
}


void print_one_struct(int x,std_init *init,student_data *std)
{
	int count=0;
	student_data *find=std;
	while(count<x) {count++;find++;}
	    printf("================data for your search==================\n");
		printf("->id::>> %d\n",find->id);
		printf("->first_name::>> %s\n",find->first_name);
		printf("->last_name::>> %s\n",find->last_name);
		printf("->gpa::>> %.2f\n",find->gpa);
		printf("->first_course::>> %d\n",find->first_course);
		printf("->second_course::>> %d\n",find->second_course);
		printf("->third_name::>> %d\n",find->third_course);
		printf("->fourth_name::>> %d\n",find->fourth_course);
		printf("->fifth_name::>> %d\n",find->fifth_course);

}
state search_by_first_name(std_init *init,student_data *std)
{
	char name_temp[40];
	printf("enter the first name::>> ");fflush(stdin);scanf("%s",&name_temp);
	student_data *find=std;int flag=0,count=0;
	while(find<init->head)
	{
		if(!strcmp(name_temp,find->first_name) && find->del==0)
		{flag=1;
		 print_one_struct(count,init,std);
		}
		find++;count++;

	}
	if(flag==0)
	printf("=========this name is not found======\n");
			return faild;

}

state search_by_id(std_init *init,student_data *std)
{
    student_data *find=std;int count=0,temp_id;
    printf("enter id::>> ");scanf("%d",&temp_id);
	while(find<init->head)
	{
		if(temp_id==find->id && find->del==0){print_one_struct(count,init,std);return done;}
		count++;find++;
		}
		printf("=================id is not found================\n");

}


state update_data(std_init *init,student_data *std)
{
	    student_data *find=std;int temp_id;int count=0;
		printf("enter id that want to be updated::>> ");scanf("%d",&temp_id);
       while(find<init->head)
	    { 
	      if(temp_id==find->id && find->del==0){print_one_struct(count,init,std);break;}
		count++;find++;
		}
		if(find==init->head) {printf("=================id is not found================\n");return faild;}

		while(1){
			int flag=0;
		printf("===================enter type of update==================\n");
		printf("first name update::>> 1\n");
		printf("last name update::>> 2\n");
		printf("gpa update::>> 3\n");
		printf("first_course update::>> 4\n");
		printf("second_course update::>> 5\n");
        printf("third_course update::>> 6\n");
        printf("fourth_course update::>> 7\n");
        printf("fifth_course update::>> 8\n");
        printf("==============================\n--->enter your choice::>> ");
        int choice;scanf("%d",&choice);
        printf("=====================================\n");
        switch(choice)
        {
        case 1 :
        	{
        		printf("enter new first_name::>> ");fflush(stdin);scanf("%s",find->first_name);fflush(stdout);break;
        	}
        case 2 :
        	{
        		printf("enter new last_name::>> ");fflush(stdin);scanf("%s",find->last_name);fflush(stdout);break;
        	}
        case 3 :
        	{
        		printf("enter new gpa::>> ");scanf("%f",&find->gpa);break;
        	}
        case 4 :
        	{
        		printf("enter new first_course::>> ");scanf("%d",&find->first_course);break;
        	}
        case 5 :
        	{
        		printf("enter new second_course::>> ");scanf("%d",&find->second_course);break;
        	}
        case 6 :
        	{
        		printf("enter new third_course::>> ");scanf("%d",&find->third_course);break;
        	}
        case 7 :
        	{
        		printf("enter new fourth_course::>> ");scanf("%d",&find->fourth_course);break;
        	}
        case 8 :
        	{
        		printf("enter new fifth_course::>> ");scanf("%d",&find->fifth_course);break;
        	}	
        	default :{flag=1;printf("==============wrong choice !!!!!!!!! try again==============\n");return faild;}	
        	}	
        	  if(flag==0) printf("=====================update is done=================\n");
        	  return done;

        }

}

void num_of_student_in_one_course(std_init *init,student_data *std)
{
	int temp_course,count=0,flag=0;
	student_data *find=std;
	printf("enter course_num::>> ");scanf("%d",&temp_course);
	while(find<init->head)
	    { 

	      if(temp_course==find->first_course && find->del==0){flag=1;count++;}
	      if(temp_course==find->second_course && find->del==0){flag=1;count++;}
	      if(temp_course==find->third_course && find->del==0){count++;flag=1;}
	      if(temp_course==find->fourth_course && find->del==0){count++;flag=1;}
	      if(temp_course==find->fifth_course && find->del==0){count++;flag=1;}
		  find++;
	}
	if(flag==0)printf("--->>course_num is not found\n");
	else printf("===================================\n-->number of students ::>> %d\n",count);
}


state add_std_from_file(std_init *init,student_data *std)
{
	if(init->count>init->lenght) {printf("========queue is full=========== ");return faild;}
	FILE *file;
  
  file = fopen("m.txt", "r"); 
  
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  int read = 0,flag=0;
    do 
  { flag=0;
   student_data *find=std;student_data temp;
    read = fscanf(file,
                  "%d,%49[^,],%49[^,],%f,%d,%d,%d,%d,%d\n",
                  &temp.id,
                  &temp.first_name, 
                  &temp.last_name, 
                  &temp.gpa, 
                  &temp.first_course,
                  &temp.second_course,
                  &temp.third_course,
                  &temp.fourth_course,
                  &temp.fifth_course); 
   
	if(douplicate(init,std,temp.id)==done) {printf("=============id(%d) is doublicated==========\n",temp.id);flag=1;}

    if(flag==0){
   find=std;
		while(find<init->head)
		{
			if(find->del==0) find++;
			else break;
		}
		strcpy(find->first_name,temp.first_name);
		strcpy(find->last_name,temp.last_name);
		find->id=temp.id;
		find->gpa=temp.gpa;
		find->first_course=temp.first_course;
		find->second_course=temp.second_course;
		find->third_course=temp.third_course;
		find->fourth_course=temp.fourth_course;
		find->fifth_course=temp.fifth_course;
		init->count++;find->del=0;
	if(find==init->head) init->head++;
    if (read != 9 && !feof(file))
    {
      printf("File format incorrect.\n");
      return 1;
    }
    
    
    if (ferror(file))
    {
      printf("Error reading file.\n");
      return 1;
    }
    printf("=============id(%d) is added===========\n",find->id);
    }
  } while (!feof(file));

  
  fclose(file);
  return done;
}