typedef enum {
faild,
done
}state;


typedef struct 
{
	int id;
	char first_name [40];
	char last_name [40];
	float gpa;
	int first_course;
	int second_course;
	int third_course;
	int fourth_course;
	int fifth_course;
	int del;
	
}student_data;


typedef struct  
{
	student_data *head;
	//student_data *tail;
	//student_data *base;
	int count;
	int lenght;
}std_init;

state init_queue(std_init * init,student_data *std,int lenght);
state add_student(std_init *init,student_data *std);
state print_all(std_init *init,student_data *std);
state douplicate(std_init *init,student_data *std,int val);
state delete_std(std_init *init,student_data *std);
void std_number(std_init *init,student_data *std);
state search_by_first_name(std_init *init,student_data *std);
state search_by_id(std_init *init,student_data *std);
void print_one_struct(int x,std_init *init,student_data *std);
state update_data(std_init *init,student_data *std);
void num_of_student_in_one_course(std_init *init,student_data *std);
state add_std_from_file(std_init *init,student_data *std);