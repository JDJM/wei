#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h>
struct Student
{
	char num[12];  	//学号 
	char name[10];  //姓名 
	int sum;   //三科成绩总分 
	int C;
	int English;
	int Math;
}student[120];

int count=0;  //总人数设为全局变量并赋初值为0
int count_1=0;

void Menu();
int check(char check[]);
int check_1(char check[]);
void Welcome();
void Password();
void Input();
void Output(); 
void Query();
void Query_num();
void Query_name();
void Edit();
void Edit_edit();
void Edit_edit_num(char arr[]);
void Edit_edit_name(char arr2[]);
void Edit_edit_C(char arr[]);
void Edit_edit_Math(char arr[]);
void Edit_edit_English(char arr[]);
void Edit_del();
void Statistic();void Sta_max();void Sta_min();void Sta_avg();void Sta_sort();
void Sta_max_C(),Sta_max_Math(),Sta_max_English();
void Sta_min_C(),Sta_min_Math(),Sta_min_English(),Sta_avg_C(),Sta_avg_English(),Sta_avg_Math(),Sta_sort();

void Welcome()// 欢迎界面函数 
{	printf("%s","\n\n\t\t\t\t\t欢迎进入学生成绩管理系统\n\n\n");
	system("pause");
	system("cls"); 
	printf("					|-------------------------------|\n");
	printf("					|-------------------------------|\n");
	printf("					|  《C语言程序设计》课程设计    |\n");
	printf("					|      学生成绩管理系统1.0版    |\n"); 
	printf("					|-------------------------------|\n");
	printf("					|-------------------------------|\n");
	printf("					%s","程序设计：新工科产业学院\n");
	printf("					%s","专业：软件工程\n");
	printf("					%s","班级：软工206\n");
	printf("					%s","姓名：郑弘毅\n");
	printf("					%s","学号：202012900646\n");
	printf("					%s","2021年1月1日\n"); 
 }
void Password()
{
	char arr[20];
	printf("%s","请输入密码:");
	scanf("%s",arr);
	if(strcmp(arr,"46")==0)
		{
		printf("%s","密码正确\n");
		Menu();}
	else
	{
		printf("%s","密码错误\n");
		Password();
 	} 
}
void Menu()  //菜单界面函数 
{    
	system("cls");
	printf("\t-------------------\n");
 	printf("\t1.学生成绩信息录入\n");         
 	printf("\t2.学生成绩信息查询\n");
 	printf("\t3.学生成绩信息编辑\n");
 	printf("\t4.学生成绩信息统计\n");
 	printf("\t5.学生成绩信息显示\n");
 	printf("\t6.退出系统\n");
	printf("\t------------------\n");
 	printf("\t请选择菜单选项1-6：");  
	switch(getche())
	{
		case '1':system("cls");Input();break;  
		case '2':system("cls");Query();break;
		case '3':system("cls");Edit();break;
		case '4':system("cls");Statistic();break;
		case '5':system("cls");Output();break;
		//case '6':printf("\n\t\t………………………………\n");exit(0);break;
		default:printf("\n请重新输入\n");system("pause");Menu();
	} 

} 

int check_1(char arr[])
{
	int i;int flag=0; 	//引入flag变量，后面的 按学号/姓名  查找学生信息的函数同理。							
	if(count==0)									
	{												
		
		return 1;
	}
	else
	{													//原先是这么写的 ，改版后是为了以后继续录入的时候按原来 
		for(i=0;i<count;i++)  							//的学生顺序继续下去 
														// for(i=0;i<count;i++) 
		{												// {
			if(!strcmp(student[i].num,arr)) 			// 	if(!strcmp(student[i].num,arr))
				{return 0;flag=1;} 						// 		return 0;
			 											//	else
		}												//		return 1; 
		if(flag==0)
			return 1;
	}
}

int Input_1(char arr[],int a)
{	
	
	strcpy(student[a].num,arr);
	printf("请输入第%d位学生的姓名:",a+1);
	scanf("%s",student[a].name);
	printf("请输入第%d位学生的C成绩:",a+1);
	scanf("%d",&student[a].C);
	printf("请输入第%d位学生的数学成绩:",a+1);
	scanf("%d",&student[a].Math);
	printf("请输入第%d位学生的英语成绩:",a+1);
	scanf("%d",&student[a].English); 
	student[a].sum=student[a].C+student[a].Math+student[a].English;
	
}


void Input()  //录入学生成绩信息函数 
{   
	int j,i,count_2=count;char arr[20];
	printf("%s","输入需要录入人数：");
	scanf("%d",&i);
	for(j=count;j-count_2<i;j++)
	{
		printf("输入第%d位学生的学号:",j+1);
		scanf("%s",arr);
		if(check_1(arr))
			{
				Input_1(arr,count);
				count++;
				printf("%s","\n该学生已成功录入！\n");
			}
		else
			{
				
				while(1)
				{	printf("学号重复，请重新输入第%d位学生的学号:",j+1);
					scanf("%s",arr);
					if(check_1(arr))
					{Input_1(arr,count);printf("%s","\n该学生已成功录入！\n");break;}
				}
			}	
	}
	Output();
	system("pause");
	Menu(); 	 
}

void Query() //按学号查找学生成绩信息函数 
{
	if(count==0)
		{
			printf("%s","请先录入学生信息\n");
			system("pause");Menu();
		}
	system("cls");
	printf("\t|-------------------------------|\n");
 	printf("%s","\t|1.按学号查询\t|\n");         
 	printf("%s","\t|2.按姓名查询\t|\n");
 	printf("%s","\t|3.返回主菜单\t|\n");
 	printf("\t|-------------------------------|\n");
 	printf("\t请选择菜单选项1-3：");  
 	switch(getche())  
		{
			case '1':system("cls");Query_num();break;  //按学号查找学生成绩信息函数 
			case '2':system("cls");Query_name();break;  //按姓名查找学生成绩信息函数 
			case '3':Menu();break;//返回主菜单； 
			default:printf("\n请重新输入\n");Query(); 
		}//调用Query_num()、Query_name()等函数
} 

void Query_num()  //按学号查找学生成绩信息函数 
{		
	int flag=0;
		char arr[20];int j;
		system("cls"); 
		printf("\n请输入要查询的学号:");
		scanf("%s",arr);
		for(j=0;j<count;j++)
		{
			if(!strcmp(student[j].num,arr))
			{
				printf("%s","学号\t\t姓名\t\tC成绩\t\t高数\t\t英语\t\t总分\n");
				printf("%s\t\t",student[j].num);
				printf("%s\t\t",student[j].name);
				printf("%d\t\t",student[j].C);
				printf("%d\t\t",student[j].Math);
				printf("%d\t\t",student[j].English);
				printf("%d\t\t",student[j].sum);
				putchar('\n');flag=1;
			}
		}
		if(flag==0)
				printf("%s","未找到！");
		printf("%s","是否继续查找<Y/N>:");
		switch(getche())
		{
			case 'Y':
			case 'y':Query();break;
			case 'N':
			case 'n':
			default:Menu();
		}	
}

void Query_name()  //按姓名查找学生成绩信息函数 
{
	if(count==0)
		{
			printf("%s","请先录入学生信息\n");
			system("pause");Menu();
		}	
	char arr[20];int j;int flag=0;
	system("cls"); 
	printf("\n请输入要查询的姓名:");
	scanf("%s",arr);
	for(j=0;j<count;j++)
	{
		if(!strcmp(student[j].name,arr))
		{
			printf("%s","学号\t\t姓名\t\tC成绩\t\t高数\t\t英语\t\t总分\n");
			printf("%s\t\t",student[j].num);
			printf("%s\t\t",student[j].name);
			printf("%d\t\t",student[j].C);
			printf("%d\t\t",student[j].Math);
			printf("%d\t\t",student[j].English);
			printf("%d\t\t",student[j].sum);
			putchar('\n');flag=1;
		}
	}
	if(flag==0)	
		printf("%s","没有找到");	
	printf("%s","是否继续查找<Y/N>:");
		switch(getche())
		{
			case 'Y':
			case 'y':Query();break;
			case 'N':
			case 'n':
			default:Menu();
			}			
	}

void Edit() //编辑学生成绩信息菜单 
{
	if(count==0)
		{
			printf("%s","\n请先录入学生信息\n");
			system("pause");Menu();
		}
	system("cls");
	printf("\t|-------------------------------|\n"); 
	printf("%s","\t|1.学生信息修改|\n");
 	printf("%s","\t|2.学生信息删除|\n");         
 	printf("%s","\t|3.返回主菜单|\n");
 	printf("\t|-------------------------------|\n"); 
 	printf("\t请选择菜单选项1-3：");  
 	switch(getche())
		{
			case '1':Edit_edit();break;  
			case '2':Edit_del();break;
			case '3':Menu();break;
			default:printf("\n请重新输入\n");system("pause");Edit();
		}//调用Edit_edit()、 Edit_del() 等函数
}
void Edit_edit()  //  学生信息修改函数 
{	
	
	int j;
    system("cls");
	printf("请输入要修改学生的学号:");
	char arr[20];char arr2[20];int C,Math,English;
	scanf("%s",arr);
	for(j=0;j<count;j++)
	{
		if(!strcmp(student[j].num,arr))
		{	
			strcpy(arr2,student[j].name);C=student[j].C;Math=student[j].Math;English=student[j].English;
			printf("%s","此学生的信息如下：\n");
			printf("%s","学号\t\t姓名\t\tC成绩\t\t高数\t\t英语\t\t总分\n");
			printf("%s\t\t",student[j].num);
			printf("%s\t\t",student[j].name);
			printf("%d\t\t",student[j].C);
			printf("%d\t\t",student[j].Math);
			printf("%d\t\t",student[j].English);
			printf("%d\t\t",student[j].sum);
			putchar('\n');
		}
	}
	printf("\t|-------------------------------|\n"); 
	printf("%s","\t|1.修改学号|\n");
	printf("%s","\t|2.修改姓名|\n");
	printf("%s","\t|3.修改C成绩|\n");
	printf("%s","\t|4.修改数学成绩|\n");
	printf("%s","\t|5.修改英语成绩|\n");
	printf("\t|-------------------------------|\n");
	printf("%s","\t请选择菜单1-5:"); 
	switch(getche())
	{
		case '1':Edit_edit_num(arr);break;
		case '2':Edit_edit_name(arr2);break;
		case '3':Edit_edit_C(arr);break;
		case '4':Edit_edit_Math(arr);break;
		case '5':Edit_edit_English(arr);break;
		default:Edit_edit();
	}
}
void Edit_edit_num(char arr[])//修改学号函数 
{	
	
	char JC[20];int i;//JC数组用于存放修改后的学号，将该数组传入check函数来检测修改后的学号是否已经存在。 

	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].num,arr))
		{	
			printf("%s","\n修改后的学号是：");
			scanf("%s",JC);
			if(check(JC))
				{printf("%s","学号重复,请重新输入");Edit_edit_num(arr); }
			else
				strcpy(student[i].num,JC);	
		}
	}	
	printf("%s","是否继续修改<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Edit_edit();break;
		case 'N':
		case 'n': 
		default :Menu();
	 } 
}
void Edit_edit_name(char arr2[])//修改姓名函数 
{
	int i;
	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].name,arr2))
		{printf("%s","修改后的姓名是：");
	 	scanf("%s",student[i].name);} 
	}
	printf("%s","是否继续修改<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Edit_edit();break;
		case 'N':
		case 'n': 
		default :Menu();
	 } 
 } 
 
void Edit_edit_C(char arr[])//修改c成绩函数 
{
	int i;
	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].num,arr))
			{	
				printf("%s","\n修改后的C成绩是："); 
				scanf("%d",&student[i].C);
				student[i].sum=student[i].English+student[i].Math+student[i].C;
			}
	}
	printf("%s","\n是否继续修改<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Edit_edit();break;
		case 'N':
		case 'n':
		default:Menu();	
	}
 } 

void Edit_edit_Math(char arr[])//修改数学成绩函数 
{
	int i;
	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].num,arr))
			{	
				printf("%s","\n修改后的数学成绩是："); 
				scanf("%d",&student[i].Math);
				student[i].sum=student[i].English+student[i].Math+student[i].C;
			}
	}
	printf("%s","\n是否继续修改<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Edit_edit();break;
		case 'N':
		case 'n':
		default:Menu();	
	}
 } 
 
void Edit_edit_English(char arr[])//修改英语成绩函数 
{
	int i;
	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].num,arr))
			{	
				printf("%s","\n修改后的英语成绩是："); 
				scanf("%d",&student[i].English);
				student[i].sum=student[i].English+student[i].Math+student[i].C;
			}
	}
	printf("%s","\n是否继续修改<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Edit_edit();break;
		case 'N':
		case 'n':
		default:Menu();	
	}
		
 } 
 
void Edit_del()  //  学生信息删除函数 
{   
	
	int i;char arr[20];int flag;int find;//find用于判断是否找到学生，flag用于判断是否删除成功 
 	system("cls"); 
	printf("请输入要删除学生的学号:"); 
	scanf("%s",arr);
	
	
	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].num,arr))
		{ 
			memset(&student[i], '\0', sizeof(student[i]));
			;flag=1;find=1;
		}
		if(flag==1){printf("%s","该学生已删除");count--;flag=0;}
	}
	if(find!=1)
		printf("%s","未找到该学生");
	printf("%s","\n是否继续删除其他学生<Y/N>:");
	if(getche()=='y'||getche()=='Y')	
		Edit_del();
	if(getche()=='n'||getche()=='N')
	{
		int j;
		printf("\n总人数:%d\n",count);
		printf("%s","学号\t\t姓名\t\tC成绩\t\t高数\t\t英语\t\t总分\n");
		for(j=0;j<=count;j++)
	{           
		printf("%s\t\t",student[j].num);
		printf("%s\t\t",student[j].name);
		printf("%d\t\t",student[j].C);
		printf("%d\t\t",student[j].Math);
		printf("%d\t\t",student[j].English);
		printf("%d\t\t",student[j].sum);
		putchar('\n');
	 } 
	}
	printf("%s","按任意键返回菜单\n");
	system("pause");Menu();
	 
}

void Statistic() //统计学生成绩信息菜单界面
{
	if(count==0)
		{
			printf("%s","\n请先录入学生信息\n");
			system("pause");Menu();
		}
	system("cls");
	printf("\t|-------------------------------|\n");
 	printf("%s","\t|1.求成绩最高分\t\n");         
 	printf("%s","\t|2.求成绩最低分\t\n");
 	printf("%s","\t|3.求平均分\t\n");
 	printf("%s","\t|4.按总分排序\t\n");
 	printf("%s","\t|5.返回主菜单\t\n");  
 	printf("\t|-------------------------------|\n");
 	printf("%s","请选择菜单选项1-5：");
 	switch(getche())
		{
			case '1': Sta_max();break;
			case '2': Sta_min();break;
			case '3': Sta_avg();break;
			case '4': Sta_sort();break;
		} 

}

void Sta_sort()
{
	system("cls");
	printf("%s""\n排序后的结果为：\n");
	int i,j,c,m,e,total;char no[20],name[20];
	for(i=1;i<count;i++)
	{
		for(j=0;j<count-i;j++)
		{
			if(student[j].sum<student[j+1].sum)
			{
				total=student[j].sum;student[j].sum=student[j+1].sum;student[j+1].sum=total;
				c=student[j].C;student[j].C=student[j+1].C;student[j+1].C=c;
				m=student[j].Math;student[j].Math=student[j+1].Math;student[j+1].Math=m;
				e=student[j].English;student[j].English=student[j+1].English;student[j+1].English=e;
				strcpy(no,student[j].num);strcpy(student[j].num,student[j+1].num);strcpy(student[j+1].num,no);
				strcpy(name,student[j].name);strcpy(student[j].name,student[j+1].name);strcpy(student[j+1].name,no);
			}
		}
	}
	
	printf("总人数:%d\n",count);
	printf("%s","学号\t\t姓名\t\tC成绩\t\t高数\t\t英语\t\t总分\n");
	for(j=0;j<count;j++)
	{           
		printf("%s\t\t",student[j].num);
		printf("%s\t\t",student[j].name);
		printf("%d\t\t",student[j].C);
		printf("%d\t\t",student[j].Math);
		printf("%d\t\t",student[j].English);
		printf("%d\t\t",student[j].sum);
		putchar('\n');
	 } 
	system("pause");
	Menu();
}

void Sta_min()  // 统计成绩最低分函数 
{	
	system("cls");
	printf("\t|-------------------------------|\n");
 	printf("%s","\t|1.C成绩最低分\t\n");         
 	printf("%s","\t|2.高数成绩最低分\t\n");
 	printf("%s","\t|3.英语成绩最低分\t\n");
 	printf("%s","\t|4.返回上一级\t\n");
 	printf("\t|-------------------------------|\n");
 	printf("%s","请选择菜单选项1-4：");
 	switch(getche())
	 {
	 	case '1':Sta_min_C();break;
	 	case '2':Sta_min_Math();break;
	 	case '3':Sta_min_English();break;
	 	case '4':Statistic();break;
	 	default:printf("\n请重新输入\n");system("pause");Sta_min();	
	}
}

void Sta_min_C()//求C最低分函数 
{
	int min=student[0].C;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].C<min)
			min=student[i].C;
	}
	printf("%s","C成绩的最低分是：");
	printf("%d",min); putchar('\n');
	printf("%s","是否继续求其他科目<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_min();break;
		case 'N':
		case 'n':
		default:Menu();	
	 } 
		
}

void Sta_min_Math()//求高数最低分函数 
{
	int min=student[0].Math;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].Math<min)
			min=student[i].Math;
	}
	printf("%s","高数成绩的最低分是：");
	printf("%d",min); putchar('\n');
	printf("%s","是否继续求其他科目<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_min();break;
		case 'N':
		case 'n':
		default:Menu();	
	}
}

void Sta_min_English()//求英语最低分函数 
{
	int min=student[0].English;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].English<min)
			min=student[i].English;
	}
	printf("%s","英语成绩的最低分是：");
	printf("%d",min); putchar('\n');
	printf("%s","是否继续求其他科目<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_min();break;
		case 'N':
		case 'n':
		default:Menu();	
	}
}

void Sta_max() // 统计成绩最高分函数 
{
	system("cls");
	printf("\t|-------------------------------|\n");
 	printf("%s","\t|1.C成绩最高分\t\n");         
 	printf("%s","\t|2.高数成绩最高分\t\n");
 	printf("%s","\t|3.英语成绩最高分\t\n");
 	printf("%s","\t|4.返回上一级\t\n");
 	printf("\t|-------------------------------|\n");
 	printf("%s","请选择菜单选项1-4：");
 	switch(getche())
	 {
	 	case '1':Sta_max_C();break;
	 	case '2':Sta_max_Math();break;
	 	case '3':Sta_max_English();break;
	 	case '4':Statistic();break;
	 	default:printf("\n请重新输入\n");system("pause");Sta_max();
	  } 
	
}

void Sta_max_C()//求C最高分函数 
{
	int max=student[0].C;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].C>max)
			max=student[i].C;
	}
	printf("%s","C成绩的最高分是：");
	printf("%d",max); putchar('\n');
	printf("%s","是否继续求其他科目<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_max();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
}

void Sta_max_Math()//求高数最高分函数 
{
	int max=student[0].Math;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].Math>max)
			max=student[i].Math;
	}
	printf("%s","高数成绩的最高分是：");
	printf("%d",max); putchar('\n');
	printf("%s","是否继续求其他科目<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_max();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
}

void Sta_max_English()//求英语最高分函数 
{
	int max=student[0].English;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].English>max)
			max=student[i].English;
	}
	printf("%s","英语成绩的最高分是：");
	printf("%d",max); putchar('\n');
	printf("%s","是否继续求其他科目<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_max();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
}

void Sta_avg()  // 统计成绩平均分函数 
{
	system("cls");
	printf("\t|-------------------------------|\n");
 	printf("%s","\t|1.求C平均分\t\n");         
 	printf("%s","\t|2.求高数平均分\t\n");
 	printf("%s","\t|3.求英语平均分\t\n");
 	printf("%s","\t|4.返回上一级\t\n");
 	printf("\t|-------------------------------|\n");
 	printf("%s","请选择菜单选项1-4：");
 	switch(getche())
	 {
	 	case '1':Sta_avg_C();break;
	 	case '2':Sta_avg_Math();break;
		case '3':Sta_avg_English();break;
	 	case '4':Statistic();break;
	 	default:printf("\n请重新输入\n");system("pause");Sta_avg();
	  } 
}

void Sta_avg_Math()//求高数平均分函数 
{
	double sum,avg;int i;
	for(i=0;i<count;i++)
	{	sum=sum+student[i].Math;}
	avg=sum/count;
	printf("%s","高数的平均成绩是：");
	printf("%.2lf",avg);putchar('\n');
	printf("%s","是否继续求其他科目<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_avg();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
	
}

void Sta_avg_English()//求英语平均分函数 
{
	double sum,avg;int i;
	for(i=0;i<count;i++)
	{	sum=sum+student[i].English;}
	avg=sum/count;
	printf("%s","英语的平均成绩是：");
	printf("%.2lf",avg);putchar('\n');
	printf("%s","是否继续求其他科目<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_avg();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
	
}
void Sta_avg_C()//求C平均分函数 
{
	double sum,avg;int i;
	for(i=0;i<count;i++)
	{	sum=sum+student[i].C;}
	avg=sum/count;
	printf("%s","C的平均成绩是：");
	printf("%.2lf",avg);putchar('\n');
	printf("%s","是否继续求其他科目<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_avg();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
	
}

void Sta_pr()//显示及格情况的函数
{
	int i,sum_C=0,sum_C1=0,sum_M=0,sum_M1=0,sum_E1=0,sum_E=0;
	for(i=0;i<count;i++)
	{
		 sum_C=sum_C+student[i].C;
		 sum_M=sum_M+student[i].Math;
		 sum_E=sum_E+student[i].English;
		 if(student[i].C>=60)	sum_C1=sum_C1+student[i].C;
		 
	}
	
} 

void Output() //输出学生成绩信息函数 
{   
	int j;
	printf("总人数:%d\n",count);
	printf("%s","学号\t\t姓名\t\tC成绩\t\t高数\t\t英语\t\t总分\n");
	for(j=0;j<count;j++)
	{           
		printf("%s\t\t",student[j].num);
		printf("%s\t\t",student[j].name);
		printf("%d\t\t",student[j].C);
		printf("%d\t\t",student[j].Math);
		printf("%d\t\t",student[j].English);
		printf("%d\t\t",student[j].sum);
		putchar('\n');
	 } 
	system("pause");
	Menu();
}

int check(char check[])//检测学号重复函数 
{
	int i;
	for(i=0;i<count;i++)
	{
		if(!strcmp(check,student[i].num))
			return 1;
	}
	return 0;
}
int main()
{
	Welcome();
	Password(); 
	return 0;
} 
