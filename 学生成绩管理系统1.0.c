#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h>
struct Student
{
	char num[12];  	//ѧ�� 
	char name[10];  //���� 
	int sum;   //���Ƴɼ��ܷ� 
	int C;
	int English;
	int Math;
}student[120];

int count=0;  //��������Ϊȫ�ֱ���������ֵΪ0
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

void Welcome()// ��ӭ���溯�� 
{	printf("%s","\n\n\t\t\t\t\t��ӭ����ѧ���ɼ�����ϵͳ\n\n\n");
	system("pause");
	system("cls"); 
	printf("					|-------------------------------|\n");
	printf("					|-------------------------------|\n");
	printf("					|  ��C���Գ�����ơ��γ����    |\n");
	printf("					|      ѧ���ɼ�����ϵͳ1.0��    |\n"); 
	printf("					|-------------------------------|\n");
	printf("					|-------------------------------|\n");
	printf("					%s","������ƣ��¹��Ʋ�ҵѧԺ\n");
	printf("					%s","רҵ���������\n");
	printf("					%s","�༶����206\n");
	printf("					%s","������֣����\n");
	printf("					%s","ѧ�ţ�202012900646\n");
	printf("					%s","2021��1��1��\n"); 
 }
void Password()
{
	char arr[20];
	printf("%s","����������:");
	scanf("%s",arr);
	if(strcmp(arr,"46")==0)
		{
		printf("%s","������ȷ\n");
		Menu();}
	else
	{
		printf("%s","�������\n");
		Password();
 	} 
}
void Menu()  //�˵����溯�� 
{    
	system("cls");
	printf("\t-------------------\n");
 	printf("\t1.ѧ���ɼ���Ϣ¼��\n");         
 	printf("\t2.ѧ���ɼ���Ϣ��ѯ\n");
 	printf("\t3.ѧ���ɼ���Ϣ�༭\n");
 	printf("\t4.ѧ���ɼ���Ϣͳ��\n");
 	printf("\t5.ѧ���ɼ���Ϣ��ʾ\n");
 	printf("\t6.�˳�ϵͳ\n");
	printf("\t------------------\n");
 	printf("\t��ѡ��˵�ѡ��1-6��");  
	switch(getche())
	{
		case '1':system("cls");Input();break;  
		case '2':system("cls");Query();break;
		case '3':system("cls");Edit();break;
		case '4':system("cls");Statistic();break;
		case '5':system("cls");Output();break;
		//case '6':printf("\n\t\t������������������������\n");exit(0);break;
		default:printf("\n����������\n");system("pause");Menu();
	} 

} 

int check_1(char arr[])
{
	int i;int flag=0; 	//����flag����������� ��ѧ��/����  ����ѧ����Ϣ�ĺ���ͬ��							
	if(count==0)									
	{												
		
		return 1;
	}
	else
	{													//ԭ������ôд�� ���İ����Ϊ���Ժ����¼���ʱ��ԭ�� 
		for(i=0;i<count;i++)  							//��ѧ��˳�������ȥ 
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
	printf("�������%dλѧ��������:",a+1);
	scanf("%s",student[a].name);
	printf("�������%dλѧ����C�ɼ�:",a+1);
	scanf("%d",&student[a].C);
	printf("�������%dλѧ������ѧ�ɼ�:",a+1);
	scanf("%d",&student[a].Math);
	printf("�������%dλѧ����Ӣ��ɼ�:",a+1);
	scanf("%d",&student[a].English); 
	student[a].sum=student[a].C+student[a].Math+student[a].English;
	
}


void Input()  //¼��ѧ���ɼ���Ϣ���� 
{   
	int j,i,count_2=count;char arr[20];
	printf("%s","������Ҫ¼��������");
	scanf("%d",&i);
	for(j=count;j-count_2<i;j++)
	{
		printf("�����%dλѧ����ѧ��:",j+1);
		scanf("%s",arr);
		if(check_1(arr))
			{
				Input_1(arr,count);
				count++;
				printf("%s","\n��ѧ���ѳɹ�¼�룡\n");
			}
		else
			{
				
				while(1)
				{	printf("ѧ���ظ��������������%dλѧ����ѧ��:",j+1);
					scanf("%s",arr);
					if(check_1(arr))
					{Input_1(arr,count);printf("%s","\n��ѧ���ѳɹ�¼�룡\n");break;}
				}
			}	
	}
	Output();
	system("pause");
	Menu(); 	 
}

void Query() //��ѧ�Ų���ѧ���ɼ���Ϣ���� 
{
	if(count==0)
		{
			printf("%s","����¼��ѧ����Ϣ\n");
			system("pause");Menu();
		}
	system("cls");
	printf("\t|-------------------------------|\n");
 	printf("%s","\t|1.��ѧ�Ų�ѯ\t|\n");         
 	printf("%s","\t|2.��������ѯ\t|\n");
 	printf("%s","\t|3.�������˵�\t|\n");
 	printf("\t|-------------------------------|\n");
 	printf("\t��ѡ��˵�ѡ��1-3��");  
 	switch(getche())  
		{
			case '1':system("cls");Query_num();break;  //��ѧ�Ų���ѧ���ɼ���Ϣ���� 
			case '2':system("cls");Query_name();break;  //����������ѧ���ɼ���Ϣ���� 
			case '3':Menu();break;//�������˵��� 
			default:printf("\n����������\n");Query(); 
		}//����Query_num()��Query_name()�Ⱥ���
} 

void Query_num()  //��ѧ�Ų���ѧ���ɼ���Ϣ���� 
{		
	int flag=0;
		char arr[20];int j;
		system("cls"); 
		printf("\n������Ҫ��ѯ��ѧ��:");
		scanf("%s",arr);
		for(j=0;j<count;j++)
		{
			if(!strcmp(student[j].num,arr))
			{
				printf("%s","ѧ��\t\t����\t\tC�ɼ�\t\t����\t\tӢ��\t\t�ܷ�\n");
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
				printf("%s","δ�ҵ���");
		printf("%s","�Ƿ��������<Y/N>:");
		switch(getche())
		{
			case 'Y':
			case 'y':Query();break;
			case 'N':
			case 'n':
			default:Menu();
		}	
}

void Query_name()  //����������ѧ���ɼ���Ϣ���� 
{
	if(count==0)
		{
			printf("%s","����¼��ѧ����Ϣ\n");
			system("pause");Menu();
		}	
	char arr[20];int j;int flag=0;
	system("cls"); 
	printf("\n������Ҫ��ѯ������:");
	scanf("%s",arr);
	for(j=0;j<count;j++)
	{
		if(!strcmp(student[j].name,arr))
		{
			printf("%s","ѧ��\t\t����\t\tC�ɼ�\t\t����\t\tӢ��\t\t�ܷ�\n");
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
		printf("%s","û���ҵ�");	
	printf("%s","�Ƿ��������<Y/N>:");
		switch(getche())
		{
			case 'Y':
			case 'y':Query();break;
			case 'N':
			case 'n':
			default:Menu();
			}			
	}

void Edit() //�༭ѧ���ɼ���Ϣ�˵� 
{
	if(count==0)
		{
			printf("%s","\n����¼��ѧ����Ϣ\n");
			system("pause");Menu();
		}
	system("cls");
	printf("\t|-------------------------------|\n"); 
	printf("%s","\t|1.ѧ����Ϣ�޸�|\n");
 	printf("%s","\t|2.ѧ����Ϣɾ��|\n");         
 	printf("%s","\t|3.�������˵�|\n");
 	printf("\t|-------------------------------|\n"); 
 	printf("\t��ѡ��˵�ѡ��1-3��");  
 	switch(getche())
		{
			case '1':Edit_edit();break;  
			case '2':Edit_del();break;
			case '3':Menu();break;
			default:printf("\n����������\n");system("pause");Edit();
		}//����Edit_edit()�� Edit_del() �Ⱥ���
}
void Edit_edit()  //  ѧ����Ϣ�޸ĺ��� 
{	
	
	int j;
    system("cls");
	printf("������Ҫ�޸�ѧ����ѧ��:");
	char arr[20];char arr2[20];int C,Math,English;
	scanf("%s",arr);
	for(j=0;j<count;j++)
	{
		if(!strcmp(student[j].num,arr))
		{	
			strcpy(arr2,student[j].name);C=student[j].C;Math=student[j].Math;English=student[j].English;
			printf("%s","��ѧ������Ϣ���£�\n");
			printf("%s","ѧ��\t\t����\t\tC�ɼ�\t\t����\t\tӢ��\t\t�ܷ�\n");
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
	printf("%s","\t|1.�޸�ѧ��|\n");
	printf("%s","\t|2.�޸�����|\n");
	printf("%s","\t|3.�޸�C�ɼ�|\n");
	printf("%s","\t|4.�޸���ѧ�ɼ�|\n");
	printf("%s","\t|5.�޸�Ӣ��ɼ�|\n");
	printf("\t|-------------------------------|\n");
	printf("%s","\t��ѡ��˵�1-5:"); 
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
void Edit_edit_num(char arr[])//�޸�ѧ�ź��� 
{	
	
	char JC[20];int i;//JC�������ڴ���޸ĺ��ѧ�ţ��������鴫��check����������޸ĺ��ѧ���Ƿ��Ѿ����ڡ� 

	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].num,arr))
		{	
			printf("%s","\n�޸ĺ��ѧ���ǣ�");
			scanf("%s",JC);
			if(check(JC))
				{printf("%s","ѧ���ظ�,����������");Edit_edit_num(arr); }
			else
				strcpy(student[i].num,JC);	
		}
	}	
	printf("%s","�Ƿ�����޸�<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Edit_edit();break;
		case 'N':
		case 'n': 
		default :Menu();
	 } 
}
void Edit_edit_name(char arr2[])//�޸��������� 
{
	int i;
	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].name,arr2))
		{printf("%s","�޸ĺ�������ǣ�");
	 	scanf("%s",student[i].name);} 
	}
	printf("%s","�Ƿ�����޸�<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Edit_edit();break;
		case 'N':
		case 'n': 
		default :Menu();
	 } 
 } 
 
void Edit_edit_C(char arr[])//�޸�c�ɼ����� 
{
	int i;
	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].num,arr))
			{	
				printf("%s","\n�޸ĺ��C�ɼ��ǣ�"); 
				scanf("%d",&student[i].C);
				student[i].sum=student[i].English+student[i].Math+student[i].C;
			}
	}
	printf("%s","\n�Ƿ�����޸�<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Edit_edit();break;
		case 'N':
		case 'n':
		default:Menu();	
	}
 } 

void Edit_edit_Math(char arr[])//�޸���ѧ�ɼ����� 
{
	int i;
	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].num,arr))
			{	
				printf("%s","\n�޸ĺ����ѧ�ɼ��ǣ�"); 
				scanf("%d",&student[i].Math);
				student[i].sum=student[i].English+student[i].Math+student[i].C;
			}
	}
	printf("%s","\n�Ƿ�����޸�<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Edit_edit();break;
		case 'N':
		case 'n':
		default:Menu();	
	}
 } 
 
void Edit_edit_English(char arr[])//�޸�Ӣ��ɼ����� 
{
	int i;
	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].num,arr))
			{	
				printf("%s","\n�޸ĺ��Ӣ��ɼ��ǣ�"); 
				scanf("%d",&student[i].English);
				student[i].sum=student[i].English+student[i].Math+student[i].C;
			}
	}
	printf("%s","\n�Ƿ�����޸�<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Edit_edit();break;
		case 'N':
		case 'n':
		default:Menu();	
	}
		
 } 
 
void Edit_del()  //  ѧ����Ϣɾ������ 
{   
	
	int i;char arr[20];int flag;int find;//find�����ж��Ƿ��ҵ�ѧ����flag�����ж��Ƿ�ɾ���ɹ� 
 	system("cls"); 
	printf("������Ҫɾ��ѧ����ѧ��:"); 
	scanf("%s",arr);
	
	
	for(i=0;i<count;i++)
	{
		if(!strcmp(student[i].num,arr))
		{ 
			memset(&student[i], '\0', sizeof(student[i]));
			;flag=1;find=1;
		}
		if(flag==1){printf("%s","��ѧ����ɾ��");count--;flag=0;}
	}
	if(find!=1)
		printf("%s","δ�ҵ���ѧ��");
	printf("%s","\n�Ƿ����ɾ������ѧ��<Y/N>:");
	if(getche()=='y'||getche()=='Y')	
		Edit_del();
	if(getche()=='n'||getche()=='N')
	{
		int j;
		printf("\n������:%d\n",count);
		printf("%s","ѧ��\t\t����\t\tC�ɼ�\t\t����\t\tӢ��\t\t�ܷ�\n");
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
	printf("%s","����������ز˵�\n");
	system("pause");Menu();
	 
}

void Statistic() //ͳ��ѧ���ɼ���Ϣ�˵�����
{
	if(count==0)
		{
			printf("%s","\n����¼��ѧ����Ϣ\n");
			system("pause");Menu();
		}
	system("cls");
	printf("\t|-------------------------------|\n");
 	printf("%s","\t|1.��ɼ���߷�\t\n");         
 	printf("%s","\t|2.��ɼ���ͷ�\t\n");
 	printf("%s","\t|3.��ƽ����\t\n");
 	printf("%s","\t|4.���ܷ�����\t\n");
 	printf("%s","\t|5.�������˵�\t\n");  
 	printf("\t|-------------------------------|\n");
 	printf("%s","��ѡ��˵�ѡ��1-5��");
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
	printf("%s""\n�����Ľ��Ϊ��\n");
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
	
	printf("������:%d\n",count);
	printf("%s","ѧ��\t\t����\t\tC�ɼ�\t\t����\t\tӢ��\t\t�ܷ�\n");
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

void Sta_min()  // ͳ�Ƴɼ���ͷֺ��� 
{	
	system("cls");
	printf("\t|-------------------------------|\n");
 	printf("%s","\t|1.C�ɼ���ͷ�\t\n");         
 	printf("%s","\t|2.�����ɼ���ͷ�\t\n");
 	printf("%s","\t|3.Ӣ��ɼ���ͷ�\t\n");
 	printf("%s","\t|4.������һ��\t\n");
 	printf("\t|-------------------------------|\n");
 	printf("%s","��ѡ��˵�ѡ��1-4��");
 	switch(getche())
	 {
	 	case '1':Sta_min_C();break;
	 	case '2':Sta_min_Math();break;
	 	case '3':Sta_min_English();break;
	 	case '4':Statistic();break;
	 	default:printf("\n����������\n");system("pause");Sta_min();	
	}
}

void Sta_min_C()//��C��ͷֺ��� 
{
	int min=student[0].C;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].C<min)
			min=student[i].C;
	}
	printf("%s","C�ɼ�����ͷ��ǣ�");
	printf("%d",min); putchar('\n');
	printf("%s","�Ƿ������������Ŀ<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_min();break;
		case 'N':
		case 'n':
		default:Menu();	
	 } 
		
}

void Sta_min_Math()//�������ͷֺ��� 
{
	int min=student[0].Math;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].Math<min)
			min=student[i].Math;
	}
	printf("%s","�����ɼ�����ͷ��ǣ�");
	printf("%d",min); putchar('\n');
	printf("%s","�Ƿ������������Ŀ<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_min();break;
		case 'N':
		case 'n':
		default:Menu();	
	}
}

void Sta_min_English()//��Ӣ����ͷֺ��� 
{
	int min=student[0].English;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].English<min)
			min=student[i].English;
	}
	printf("%s","Ӣ��ɼ�����ͷ��ǣ�");
	printf("%d",min); putchar('\n');
	printf("%s","�Ƿ������������Ŀ<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_min();break;
		case 'N':
		case 'n':
		default:Menu();	
	}
}

void Sta_max() // ͳ�Ƴɼ���߷ֺ��� 
{
	system("cls");
	printf("\t|-------------------------------|\n");
 	printf("%s","\t|1.C�ɼ���߷�\t\n");         
 	printf("%s","\t|2.�����ɼ���߷�\t\n");
 	printf("%s","\t|3.Ӣ��ɼ���߷�\t\n");
 	printf("%s","\t|4.������һ��\t\n");
 	printf("\t|-------------------------------|\n");
 	printf("%s","��ѡ��˵�ѡ��1-4��");
 	switch(getche())
	 {
	 	case '1':Sta_max_C();break;
	 	case '2':Sta_max_Math();break;
	 	case '3':Sta_max_English();break;
	 	case '4':Statistic();break;
	 	default:printf("\n����������\n");system("pause");Sta_max();
	  } 
	
}

void Sta_max_C()//��C��߷ֺ��� 
{
	int max=student[0].C;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].C>max)
			max=student[i].C;
	}
	printf("%s","C�ɼ�����߷��ǣ�");
	printf("%d",max); putchar('\n');
	printf("%s","�Ƿ������������Ŀ<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_max();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
}

void Sta_max_Math()//�������߷ֺ��� 
{
	int max=student[0].Math;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].Math>max)
			max=student[i].Math;
	}
	printf("%s","�����ɼ�����߷��ǣ�");
	printf("%d",max); putchar('\n');
	printf("%s","�Ƿ������������Ŀ<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_max();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
}

void Sta_max_English()//��Ӣ����߷ֺ��� 
{
	int max=student[0].English;int i;
	for(i=0;i<count;i++)
	{
		if(student[i].English>max)
			max=student[i].English;
	}
	printf("%s","Ӣ��ɼ�����߷��ǣ�");
	printf("%d",max); putchar('\n');
	printf("%s","�Ƿ������������Ŀ<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_max();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
}

void Sta_avg()  // ͳ�Ƴɼ�ƽ���ֺ��� 
{
	system("cls");
	printf("\t|-------------------------------|\n");
 	printf("%s","\t|1.��Cƽ����\t\n");         
 	printf("%s","\t|2.�����ƽ����\t\n");
 	printf("%s","\t|3.��Ӣ��ƽ����\t\n");
 	printf("%s","\t|4.������һ��\t\n");
 	printf("\t|-------------------------------|\n");
 	printf("%s","��ѡ��˵�ѡ��1-4��");
 	switch(getche())
	 {
	 	case '1':Sta_avg_C();break;
	 	case '2':Sta_avg_Math();break;
		case '3':Sta_avg_English();break;
	 	case '4':Statistic();break;
	 	default:printf("\n����������\n");system("pause");Sta_avg();
	  } 
}

void Sta_avg_Math()//�����ƽ���ֺ��� 
{
	double sum,avg;int i;
	for(i=0;i<count;i++)
	{	sum=sum+student[i].Math;}
	avg=sum/count;
	printf("%s","������ƽ���ɼ��ǣ�");
	printf("%.2lf",avg);putchar('\n');
	printf("%s","�Ƿ������������Ŀ<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_avg();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
	
}

void Sta_avg_English()//��Ӣ��ƽ���ֺ��� 
{
	double sum,avg;int i;
	for(i=0;i<count;i++)
	{	sum=sum+student[i].English;}
	avg=sum/count;
	printf("%s","Ӣ���ƽ���ɼ��ǣ�");
	printf("%.2lf",avg);putchar('\n');
	printf("%s","�Ƿ������������Ŀ<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_avg();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
	
}
void Sta_avg_C()//��Cƽ���ֺ��� 
{
	double sum,avg;int i;
	for(i=0;i<count;i++)
	{	sum=sum+student[i].C;}
	avg=sum/count;
	printf("%s","C��ƽ���ɼ��ǣ�");
	printf("%.2lf",avg);putchar('\n');
	printf("%s","�Ƿ������������Ŀ<Y/N>:");
	switch(getche())
	{
		case 'Y':
		case 'y':Sta_avg();break;
		case 'N':
		case 'n':
		default:Menu();	
	}	
	
}

void Sta_pr()//��ʾ��������ĺ���
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

void Output() //���ѧ���ɼ���Ϣ���� 
{   
	int j;
	printf("������:%d\n",count);
	printf("%s","ѧ��\t\t����\t\tC�ɼ�\t\t����\t\tӢ��\t\t�ܷ�\n");
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

int check(char check[])//���ѧ���ظ����� 
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
