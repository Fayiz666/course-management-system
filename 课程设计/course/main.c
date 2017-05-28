#include <stdio.h>
#include <stdlib.h>
#include "head.h"
int main()                                         
{
	cour *head=NULL;
	system("color 1E");
	system("mode con cols=100 lines=30");
	for(;;) 
	{ 
		switch(menu1()) 
		{ 
		case 1: 
		system("cls");
		printf("\n请按照提示创建新的课程信息：\n");
		head=creat(head);
		display(head);
		system("pause"); 
		save(head);
		break; 

		case 2: 
		system("cls");
		head=read(head);
		judge(head);
		printf("\n请按照提示增加新的课程信息：\n");  
		head=insert(head);
		save(head);
		break;

		case 3: 
		system("cls");
		head=read(head);
		judge(head);
		printf("\n请按照提示查询课程信息：\n");
		search(head);								 
		printf("\t"); 
		break;
		
		case 4:
		system("cls");
		head=read(head);
		judge(head);
		printf("\n\t请按照提示修改课程信息\n"); 
		alter(head);
		display(head);
		system("pause"); 
		save(head);
		break; 

		case 5: 
		system("cls");
		head=read(head);
		judge(head);
		printf("\n请按照提示删除课程信息\n"); 
		head=del(head);									 
		display(head);
		save(head);
		system("pause"); 
		break; 
		
		case 6:
		system("cls");
		head=read(head);
		judge(head);
		printf("\n请按照提示统计课程信息\n"); 
		count(head);
		printf("\t");
		save(head);
		system("pause");
		break;

		case 7:
		system("cls");
		judge(head);
		printf("\n请按照提示统计课程信息\n"); 
		display(head);
		printf("\t");
		save(head);
		system("pause");
		break;

		case 0:
		clean(head);
		printf("\n\t\t谢谢您的使用\n");                          
		printf("\n\t\t"); 
		system("pause"); 
		exit(0); 
		}
	} 
	return 0;
}
