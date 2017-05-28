#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void clean(cour *head)				//释放链表
{
	cour *cur;
	cur = head;
	while (cur != NULL)
	{
		head = cur->next;
		free(cur);
		cur = head;
	}
} 


cour *read(cour *head)				//读取文件数据到链表
{
	cour *cur,*temp;
	FILE *fp;
	fp=fopen("course.dat","rb+");
	if(fp == NULL)                   
	{ 
		printf("\t读取数据库失败，请创建新的课程信息！\n"); 
		system("pause"); 
		main();
	} 
	else
	{
		clean(head);
		temp = (cour *)malloc(LEN);
		head = temp;
		while(!feof(fp))
		{ 
		
			if (!fread(temp, LEN, 1, fp))
			{
				break;
			}
		
			cur = temp;
			temp = (cour *)malloc(LEN);
			cur->next = temp;		
		}
			free(temp);
			cur->next = NULL;
	}
	fclose(fp);
	return head;
}



void save(cour *head)			//存储链表数据到文件         
{
	cour *cur;
	FILE *fp;
	fp = fopen("course.dat","wb+");
	if(fp == NULL)                   
	{ 
		printf("\t读取数据失败！\n"); 
		system("pause"); 
		return; 
	} 
	else
	{
		cur = head;
		while (cur != NULL)
		{
			fwrite(cur,LEN,1,fp);
			cur = cur->next;
		}
	}
	fclose(fp);                                  
	printf("保存成功！\n"); 
} 


int menu1()				//主菜单
{ 
	int a; 
	do
	{ 
		system("cls"); 
		printf("\t\t+---------------------------+\n");
		printf("\t\t|                           |\n");
		printf("\t\t|  欢迎使用课程信息管理系统 |\n");
		printf("\t\t|                           |\n");
		printf("\t\t+---------------------------+\n");
		printf("\t\t *****课程信息管理系统***** \n");                               
		printf("\t\t    ┌───────--┐\n");                   
		printf("\t\t    │ 1. 创建课程信息│\n"); 
		printf("\t\t    │ 2. 增加课程信息│\n"); 
		printf("\t\t    │ 3. 查询课程信息│\n"); 
		printf("\t\t    │ 4. 修改课程信息│\n"); 
		printf("\t\t    │ 5. 删除课程信息│\n"); 
		printf("\t\t    │ 6. 统计课程信息│\n");
		printf("\t\t    │ 7. 浏览课程信息│\n");
		printf("\t\t    │ 0.   退出程序  │\n"); 
		printf("\t\t    └────--───┘\n"); 
		printf("\t\t请您选择操作选项:"); 
		a=getch();
	}while(a<'0'||a>'7'); 
	return a-48;
} 
int menu2()			//修改功能子菜单
{  
	int a;
	do
	{
		system("cls"); 
		printf("\t\t    ┌───────---┐\n");                   
		printf("\t\t    │ 1.  课程编号    │\n"); 
		printf("\t\t    │ 2.  课程名称    │\n"); 
		printf("\t\t    │ 3.  课程性质    │\n"); 
		printf("\t\t    │ 4.    学时      │\n"); 
		printf("\t\t    │ 5.  授课学时    │\n"); 
		printf("\t\t    │ 6.实验或上机学时│\n");
		printf("\t\t    │ 7.    学分      │\n"); 
		printf("\t\t    │ 8.  开课学期    │\n"); 
		printf("\t\t    └────--──-─┘\n"); 
		printf("\t\t请您选择修改选项:\n");
		a=getch();
	}while(a<'0'||a>'8');
	return a-48;
}
void menu3()			//查询功能子菜单
{ 
	system("cls");
	printf("\n");
	printf("\t\t1.根据课程名称查询\n");
	printf("\t\t2.根据开课学期查询\n");
	printf("\t\t0.返回主菜单\n");
	printf("\n请选择下一步操作选项：\n");
}
void judge(cour *head)
{
	if(head == NULL)
	{
		printf("\n\n\n\n\t\t数据库为空，请先创建新的课程信息！\n");
		system("pause");
		main();
	}
}
