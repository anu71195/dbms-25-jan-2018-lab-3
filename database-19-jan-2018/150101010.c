// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <dirent.h>
// #define nl printf("\n");
// /*
// this file should be run from the place where the file '19-jan-2018.pdf' is there in the tgz file
// */
// struct course
// {
// 	char name[10];
// 	char credits[5];
// };
// struct exam
// {
// 	char name[10];
// 	char date[15],start[10],end[10];
// };
// struct student
// {
// 	char roll[15],name[100],email[100],course[200],credits[20];
// 	int credit_sum;
// };
// typedef struct course course;
// typedef struct exam exam;
// typedef struct student student;
// /*
// INSERT INTO table_name (column1, column2, column3, ...)
// VALUES (value1, value2, value3, ...); 
// */

// // int main()
// // {
// // 	FILE * fpr,*fpw;
// // 	int no_courses=0,temp,i,j;
// // 	char buff[100];
// // 	course *courses;
// // 	fpr=fopen("database-19-jan-2018/course-credits.csv","r");
// // 	fpw=fopen("150101010_cc.sql","w");
// // 	while(!feof(fpr))
// // 	{
// // 		fscanf(fpr,"%s",buff);
// // 		// printf("%s",buff);
// // 		no_courses++;

// // 	}
// // 	// printf("%d",no_courses);
// // 	courses=(course*)malloc(sizeof(course)*no_courses);
// // 	rewind(fpr);
// // 	j=0;
// // 	while(!feof(fpr))
// // 	{
// // 		fscanf(fpr,"%s",buff);
// // 	 	i=0;
// // 		printf("%s",buff);nl
// // 	 	while(buff[i]!=',')
// // 	 	{
// // 	 		courses[j].name[i]=buff[i];
// // 	 		i++;
// // 	 	}

// // 	 	i++;
// // 	 	temp=i;
// // 	 	while(buff[i]!='\0')
// // 		{
// // 			courses[j].credits[i-temp]=buff[i];
// // 			i++;
// // 		}
// // 	 	fprintf(fpw,"INSERT INTO cc (course_id , number_of_credits) VALUES (\"%s\",%s);\n",courses[j].name,courses[j].credits);
// // 	 	fprintf(fpw,"INSERT INTO cc_temp (course_id , number_of_credits) VALUES (\"%s\",%s);\n",courses[j].name,courses[j].credits);
// // 	 	fprintf(fpw,"INSERT INTO cc_clone (course_id , number_of_credits) VALUES (\"%s\",%s);\n",courses[j].name,courses[j].credits);

// // 	 	j++;


// // 	}



// // }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define nl printf("\n");



/*
the file is stored where the question pdf is given
*/


struct course
{
	char name[10];
	char credits[5];
};
struct exam
{
	char name[10];
	char date[15],start[10],end[10];
};
struct student
{

	char roll[15],name[100],email[100],course[200],credits[20];
	int credit_sum;

};

typedef struct course course;
typedef struct exam exam;
typedef struct student student;
int get_time(char * str)
{
	int time=0;
	time=(str[0]-48)*1000+(str[1]-48)*100+(str[3]-48)*10+str[4] -48;
	return time;
}
int get_number(char * str)
{
	// printf("%s",str);
	int temp=0,i=0,sum=0;
	while(str[i]!='\0')
	{
		temp=0;
		while(str[i]!=',')
		{
			temp=10*temp+str[i]-48;
			i++;
			if(str[i]=='\0')
				break;
		}

		sum+=temp;

		if(str[i]=='\0')
		break;
		i++;
		temp=0;
	}
	// printf("%d\n",sum);

	return sum;
}

int main()
{
	FILE * fp,*fpw;
	DIR * fd,*fd2;
	struct dirent* in_file,*in_file2;
	char buff[100],directory[100],file[100],temp_char[100];
	char** exam_colisoin;
	char ** credit_p;
	int exam_colisoin_index=0;
	int * credit_score;
	course * courses;
	exam * exams;
	student * students;
	int no_courses=0,i,j,no_exams=0,temp,no_students=0,memory=100,memory_filled=0;
	fp=fopen("database-19-jan-2018/course-credits.csv","r");
	fpw=fopen("150101010_cc.sql","w");
	while(!feof(fp))
	{
		fscanf(fp,"%s",buff);
		// printf("%s",buff);
		no_courses++;

	}
	// printf("%d",no_courses);
	courses=(course*)malloc(sizeof(course)*no_courses);
	rewind(fp);
	j=0;
	while(!feof(fp))
	{
		fscanf(fp,"%s",buff);
	 	i=0;
		// printf("%s",buff);nl
	 	while(buff[i]!=',')
	 	{
	 		courses[j].name[i]=buff[i];
	 		i++;
	 	}
	 	i++;
	 	temp=i;
	 	while(buff[i]!='\0')
		{
			courses[j].credits[i-temp]=buff[i];
			i++;
		}
	 	fprintf(fpw,"INSERT INTO cc (course_id , number_of_credits) VALUES (\"%s\",%s);\n",courses[j].name,courses[j].credits);
	 	fprintf(fpw,"INSERT INTO cc_temp (course_id , number_of_credits) VALUES (\"%s\",%s);\n",courses[j].name,courses[j].credits);
	 	fprintf(fpw,"INSERT INTO cc_clone (course_id , number_of_credits) VALUES (\"%s\",%s);\n",courses[j].name,courses[j].credits);

	 	j++;

	}
	if(!strcmp(courses[no_courses-2].name,courses[no_courses-1].name))
		no_courses--;
	fclose(fp);
	fp=fopen("database-19-jan-2018/exam-time-table.csv","r");
	fpw=fopen("150101010_ett.sql","w");

	while(!feof(fp))
	{
		fscanf(fp,"%s",buff);
		// printf("%s",buff);nl
		no_exams++;
	}
	// printf("%d",no_exams);
	exams=(exam*)malloc(sizeof(exam)*no_exams);
	rewind(fp);
	j=0;
	
	while(!feof(fp))
	{
		fscanf(fp,"%s",buff);
		i=0;
		while(buff[i]!=',')
		{
			exams[j].name[i]=buff[i];
			i++;
		}
		i++;
		temp=i;
		while(buff[i]!=',')
		{
			exams[j].date[i-temp]=buff[i];
			i++;
		}
		i++;
		temp=i;
		while(buff[i]!=',')
		{
			exams[j].start[i-temp]=buff[i];
			i++;
		}
		i++;
		temp=i;
		while(buff[i]!='\0')
		{
			exams[j].end[i-temp]=buff[i];
			i++;
		}
		fprintf(fpw,"INSERT INTO ett (course_id , exam_date , start_time , end_time) VALUES (\"%s\",\'%s\', \'%s:00\', \'%s:00\');\n",exams[j].name,exams[j].date,exams[j].start,exams[j].end);
		fprintf(fpw,"INSERT INTO ett_temp (course_id , exam_date , start_time , end_time) VALUES (\"%s\",\'%s\', \'%s:00\', \'%s:00\');\n",exams[j].name,exams[j].date,exams[j].start,exams[j].end);
		fprintf(fpw,"INSERT INTO ett_clone (course_id , exam_date , start_time , end_time) VALUES (\"%s\",\'%s\', \'%s:00\', \'%s:00\');\n",exams[j].name,exams[j].date,exams[j].start,exams[j].end);

		for(int t=0;t<j;t++)
		{
			if(!strcmp(exams[j].name,exams[t].name))
			{
				if(!strcmp(exams[j].date,exams[t].date))
				{
					if(!strcmp(exams[j].start,exams[t].start))
					{
						if(!strcmp(exams[j].end,exams[t].end))
						{
							j--;
							break;
						}

					}

				}
			}
		}
		j++;



	}
	fpw=fopen("150101010_cwsl.sql","w");
	exam_colisoin=(char**)malloc(sizeof(char*)*no_exams);
	for(int i=0;i<no_exams;i++)
	{
		exam_colisoin[i]=(char*)malloc(sizeof(char)*100);
	}
	if(!strcmp(exams[no_exams-2].name,exams[no_exams-1].name))
		no_exams--;
	fclose(fp);
	students=(student*)malloc(sizeof(student)*memory);
	fd = opendir ("database-19-jan-2018/course-wise-students-list/.");
	while (in_file = readdir(fd))
          if(in_file->d_name[0]!='.')  
          	{
          		// printf("%s\n", in_file->d_name);
				strcpy(directory,"database-19-jan-2018/course-wise-students-list/");
				strcat(directory,in_file->d_name);
          		// printf("%s------------------------------------------\n", directory);
          		fd2=opendir(directory);
          		// i=0;
          		while(in_file2=readdir(fd2))
          			if(in_file2->d_name[0]!='.')
          			{
						strcpy(file,directory);
						strcat(file,"/");						
						strcat(file,in_file2->d_name);
						fp=fopen(file,"r");
						while(!feof(fp))
						{
							fgets(buff,100,fp);
							i=0;
							while(buff[i]!=',')
							{
								temp_char[i]=buff[i];
								i++;
							}
							i++;
							temp_char[i-1]='\0';
							temp=0;						
							while(buff[i]!=',')
							{

								temp_char[temp]=buff[i];
								temp++;
								i++;
							}
							i++;
							temp_char[temp]='\0';
							int flag=0;
							for(int k=0;k<memory_filled;k++)
							{
								if(!strcmp(students[k].roll,temp_char))
								{
									flag=1;
									strcat(students[k].course,",");
									strcat(students[k].course,in_file2->d_name);
									strcat(students[k].credits,",");
									int li=0;
									strcpy(temp_char,in_file2->d_name);
									while(temp_char[li]!='.')
									{
										li++;
									}
									temp_char[li]='\0';
									for(int li=0;li<no_courses;li++)
									{
										if(!strcmp(temp_char,courses[li].name))
										{
											strcat(students[k].credits,courses[li].credits);
											break;
										}
									}
									int t=0;
									while(students[k].course[t]!='.')
										t++;
									students[k].course[t]='\0';

								}
							}
							if(!flag)
							{
								strcpy(students[memory_filled].roll,temp_char);

								strcpy(students[memory_filled].course,in_file2->d_name);
								int li=0;
								while(students[memory_filled].course[li]!='.')
								{
									li++;
								}
								students[memory_filled].course[li]='\0';

								for(int li=0;li<no_courses;li++)
								{
									if(!strcmp(students[memory_filled].course,courses[li].name))
									{
										strcpy(students[memory_filled].credits,courses[li].credits);
										break;
									}
								}								 
								temp=0;
								while(buff[i]!=',')
								{
									temp_char[temp]=buff[i];
									temp++;
									i++;
								}
								i++;
								temp_char[temp]='\0';
								strcpy(students[memory_filled].name,temp_char);

								temp=0;
								
								if(buff[i]!='\n')
								{
									while(buff[i]!='\n')
									{
										temp_char[temp]=buff[i];
										temp++;
										i++;
									}
									i++;
									temp_char[temp]='\0';
									strcpy(students[memory_filled].email,temp_char);
								}
								else
									strcpy(students[memory_filled].email,"NULL");
								// printf("%s %s %s %s\n",students[memory_filled].course,students[memory_filled].name,students[memory_filled].roll,students[memory_filled].email);
								fprintf(fpw,"INSERT INTO cwsl (cid ,  roll_number , name , email) VALUES (\"%s\", %s, \"%s\" , \"%s\");\n",students[memory_filled].course,students[memory_filled].roll,students[memory_filled].name,students[memory_filled].email);
								fprintf(fpw,"INSERT INTO cwsl_temp (cid ,  roll_number , name , email) VALUES (\"%s\", %s, \"%s\" , \"%s\");\n",students[memory_filled].course,students[memory_filled].roll,students[memory_filled].name,students[memory_filled].email);
								fprintf(fpw,"INSERT INTO cwsl_clone (cid ,  roll_number , name , email) VALUES (\"%s\", %s, \"%s\" , \"%s\");\n",students[memory_filled].course,students[memory_filled].roll,students[memory_filled].name,students[memory_filled].email);

								// fprintf(fpw,"INSERT INTO ett_temp (course_id , exam_date , start_time , end_time) VALUES (\"%s\",%s, %s:00, %s:00);\n",exams[j].name,exams[j].date,exams[j].start,exams[j].end);
								// fprintf(fpw,"INSERT INTO ett_clone (course_id , exam_date , start_time , end_time) VALUES (\"%s\",%s, %s:00, %s:00);\n",exams[j].name,exams[j].date,exams[j].start,exams[j].end);


								memory_filled++;
								if(memory_filled==memory)
								{
									memory*=2;
									students=(student*)realloc(students,sizeof(student)*memory);
								}

							}
						}
						fclose(fp);
          			}

          	}

     int c_sum=0;
    for(int i=0;i<memory_filled;i++)
	{
	     students[i].credit_sum= get_number(students[i].credits);
	}
	int number=0;
	credit_p=(char**)malloc(sizeof(char*)*memory_filled);
	for(int i=0;i<memory_filled;i++)
	{
		credit_p[i]=(char*)malloc(sizeof(char)*100);
	}
	int credit_pindex=0;
	credit_score=(int*)malloc(sizeof(int)*memory_filled);
	for(int i=0;i<memory_filled;i++)
	{
		if(students[i].credit_sum>40)
		{
			number++;
			char* temporary=(char*)malloc(sizeof(char)*100);
			strcpy(temporary,students[i].roll);
			strcat(temporary," ");
			strcat(temporary,buff);
			strcat(temporary," ");
			strcat(temporary,students[i].name);
			int flag=0;
			for(int i=0;i<credit_pindex;i++)
			{
				if(!strcmp(temporary,credit_p[i]))
					flag=1;
			}
			if(!flag)
			{
				strcpy(credit_p[credit_pindex],temporary);
				credit_pindex++;
				credit_score[credit_pindex]=students[i].credit_sum;
			}
		}
	}
	char course_temp[100];
	int li=0;
	for(int i=0;i<memory_filled;i++)
	{
		j=0;
		int course_index=0;
		char ** exam_time=(char**)malloc(sizeof(char*)*20);
		for(int t=0;t<20;t++)
		{
			exam_time[t]=(char*)malloc(sizeof(char)*100);
		}
		while(1)
		{
			li=0;	
			while(students[i].course[j]!=',')
			{
				course_temp[li]=students[i].course[j];
				li++;
				j++;
				if(students[i].course[j]=='\0'||students[i].course[j]=='\n')
					break;

			}

			course_temp[li]='\0';
			strcpy(exam_time[course_index],course_temp);
			course_index++;

			if(students[i].course[j]=='\0'||students[i].course[j]=='\n')
				break;
			j++;
	
		}
		for(int t=0;t<course_index;t++)
		{

			for(int t2=0;t2<no_exams;t2++)
			{
				if(!strcmp(exam_time[t],exams[t2].name))
				{
					for(int t3=t+1;t3<course_index;t3++)
					{
						for(int t4=0;t4<no_exams;t4++)
						{
							if(!strcmp(exam_time[t3],exams[t4].name))
							{
								if(!strcmp(exams[t2].date,exams[t4].date))
								{
									int s1,s2,e1,e2,flag=0;
									s1=get_time(exams[t2].start);
									s2=get_time(exams[t4].start);
									e1=get_time(exams[t2].end);
									e2=get_time(exams[t4].end);
									if(strcmp(exam_time[t3],exam_time[t]))
									{
										char * temporary=(char*)malloc(sizeof(char)*100);
										if(s1==s2)
										{
											strcpy(temporary,students[i].roll);
											strcat(temporary," ");
											strcat(temporary,students[i].name);
											strcat(temporary," ");
											strcat(temporary,exam_time[t]);
											strcat(temporary," ");
											strcat(temporary,exam_time[t3]);

											for(int abc=0;abc<exam_colisoin_index;abc++)
											{
												if(!strcmp(temporary,exam_colisoin[abc]))
													flag=1;
											}
											if(!flag)
												{
													strcpy(exam_colisoin[exam_colisoin_index],temporary);
													exam_colisoin_index++;
												}

										}
										else if(s1<s2)
										{
											if(e1>s2)
											{
												strcpy(temporary,students[i].roll);
												strcat(temporary," ");
												strcat(temporary,students[i].name);
												strcat(temporary," ");
												strcat(temporary,exam_time[t]);
												strcat(temporary," ");
												strcat(temporary,exam_time[t3]);

												for(int abc=0;abc<exam_colisoin_index;abc++)
												{
													if(!strcmp(temporary,exam_colisoin[abc]))
														flag=1;
												}
												if(!flag)
												{
													strcpy(exam_colisoin[exam_colisoin_index],temporary);
													exam_colisoin_index++;
												}
											}

										}
										else
										{
											if(e2>s1)
											{
												strcpy(temporary,students[i].roll);
												strcat(temporary," ");
												strcat(temporary,students[i].name);
												strcat(temporary," ");
												strcat(temporary,exam_time[t]);
												strcat(temporary," ");
												strcat(temporary,exam_time[t3]);

												for(int abc=0;abc<exam_colisoin_index;abc++)
												{
													if(!strcmp(temporary,exam_colisoin[abc]))
														flag=1;
												}
												if(!flag)
													{
														strcpy(exam_colisoin[exam_colisoin_index],temporary);
														exam_colisoin_index++;
													}
											}

										}
									
										free(temporary);
									}


								}
							}
						}
					}
				}

			}
		}
		free(exam_time);
		
	}
  
int options;
while(1)
{
// 	printf("\n\n\ntype 1 for question 1, 2 for question 2 and 3 to exit\n\n\n\n");
// scanf("%d",&options);
options=3;
if(options==1)
{
	for(int i=0;i<exam_colisoin_index;i++)
{
	printf("%s\n",exam_colisoin[i]);
}
}
credit_pindex=0;
if(options==2)
{
for(int i=0;i<memory_filled;i++)
	{
		if(students[i].credit_sum>40)
		{
			printf("%s\t%40s\t%d\n",students[i].roll,students[i].name,students[i].credit_sum);
			number++;
			char* temporary=(char*)malloc(sizeof(char)*100);
			strcpy(temporary,students[i].roll);
			strcat(temporary," ");
			strcat(temporary,buff);
			strcat(temporary," ");
			strcat(temporary,students[i].name);
			int flag=0;
			for(int i=0;i<credit_pindex;i++)
			{
				if(!strcmp(temporary,credit_p[i]))
					flag=1;
			}
			if(!flag)
			{
				strcpy(credit_p[credit_pindex],temporary);
				credit_pindex++;
				credit_score[credit_pindex]=students[i].credit_sum;
			}
		}
	}
}
if(options==3)
	break;
	}
}