#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "head.h"

cour *creat(cour *head)					//创建链表（创建新的课程信息）
{
	cour *cur, *pre;
	char cnum[12];
	char cname[20];
	char ctype[10];
	int time;
	int ttime;
	int etime;
	int mark;
	int term;
	printf("请输入课程编号: (回车结束录入)");
	while (gets(cnum) != NULL && cnum[0] != '\0')
	{
		printf("请输入课程名称：");
		gets(cname);
		printf("请输入要增加课程的课程性质：(选修or必修)\n");
		gets(ctype);
		printf("请输入课程学时：");
		scanf("%d",&time);
		printf("请输入课程授课学时：");
		scanf("%d",&ttime);
		printf("请输入课程实验或上机学时：");
		scanf("%d",&etime);
		printf("请输入课程学分：");
		scanf("%d",&mark);
		printf("请输入开课学期：");
		scanf("%d",&term);
		cur = (cour *)malloc(LEN);
		strcpy(cur->cnum, cnum);
		strcpy(cur->cname, cname);
		strcpy(cur->ctype, ctype);
		cur->time = time;
		cur->ttime = ttime;
		cur->etime = etime;
		cur->mark = mark;
		cur->term = term;
		cur->next = NULL;

		if (head == NULL)
		{
			head = cur;
		}
		else
		{
			pre->next = cur;
		}
		pre = cur;
		while (getchar() != '\n');
		{
			printf("请输入课程编号: (回车结束)");
		}
	}
	return head;
}



cour *del(cour *head)				//删除结点（根据编号删除课程信息）
{
	cour *cur, *pre;
	char cnum[12];
	printf("请输入要删除的课程编号: ");
	gets(cnum);
	if (head == NULL)
	{
		printf("课程列表为空，没有可以删除的课程信息!\n");
	}
	else
	{
		cur = head;
		while (strcmp(cur->cnum, cnum) != 0 && cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		if (strcmp(cur->cnum, cnum) == 0)
		{
			if (cur == head)
			{
				head = cur->next;
			}
			else
			{
				pre->next = cur->next;
			}
 			free(cur);
			printf("删除课程信息成功！\n");
		}
		else
		{  
			printf("课程列表中没有匹配要删除的课程编号!\n");
		}
	}
	return head;
}


void display(cour *head)				//输出链表（显示课程信息）
{
	cour *cur;
	printf("\n显示链表结果如下：\n");
	if (head == NULL)
	{
		printf("课程信息列表为空!\n");
	}
	else
	{
		cur = head;
		printf("%-10s%-10s%-10s%-6s", "课程编号", "课程名称", "课程性质","学时");
		printf("%-10s%-15s%-6s%s\n", "授课学时","实验或上机学时","学分","开课学期");
		while (cur != NULL)
		{
			printf("%-10s%-10s%-10s%-10d", cur->cnum, cur->cname, cur->ctype,cur->time);
			printf("%-10d%-12d%-12d%d\n",cur->ttime,cur->etime,cur->mark,cur->term);
			cur = cur->next;
		}
	}
}


cour *insert(cour *head)			//增加结点（增加课程信息）
{
	cour *cur, *pre, *ncour;
	ncour = (cour *)malloc(LEN);
	printf("请输入要增加课程的课程编号: ");
	scanf("%s",ncour->cnum);
	getchar();
	printf("请输入要增加课程的课程名称: ");
	gets(ncour->cname);
	printf("请输入要增加课程的课程性质：(选修or必修)\n");
	gets(ncour->ctype);
	printf("请输入要增加课程的学时: ");
	scanf("%d", &ncour->time);
	printf("请输入要增加课程的授课学时: ");
	scanf("%d", &ncour->ttime);
	printf("请输入要增加课程的实验或上机学时: ");
	scanf("%d", &ncour->etime);
	printf("请输入要增加课程的学分: ");
	scanf("%d", &ncour->mark);
	printf("请输入要增加课程的开课学期: ");
	scanf("%d", &ncour->term);
	ncour->next = NULL;
	if (head == NULL)
	{
		head = ncour;
	}
	else
	{
		cur = head;
		while (strcmp(cur->cnum, ncour->cnum) < 0 && cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		if (strcmp(cur->cnum, ncour->cnum) >= 0)
		{
			if (cur == head)
			{
				head = ncour;
			}
			else
			{
				pre->next = ncour;
			}
			ncour->next = cur;
		}
		else
		{
			cur->next = ncour;
		}
	}
	printf("增加新的课程信息完成\n");
	return head;
}
 

void sname(cour *head);
void sterm(cour *head);

void search(cour *head)					//查询课程信息
{
	int choice;
	while(1)
	{
		menu3();
		choice=getch();
		switch(choice-48)
		{
		case 1:sname(head);break; 
		case 2:sterm(head);break; 
		case 0:return;
		default:printf("\n按键错误，请重新选择！\n");system("color 4E");system("color 1E");
		}
	}
}


	
void sname(cour *head)							 //按课程名称查询课程信息
{		
	int i=0;
	cour *cur;
	char cname[20];
	head=read(head);		
	printf("\t\t请输入课程名称：");
	gets(cname);
	cur=head;
	while (cur != NULL)
	{
		if(strcmp(cur->cname,cname)==0)
		{
			i++;
			printf("%-10s%-10s%-10s%-6s", "课程编号", "课程名称", "课程性质","学时");
			printf("%-10s%-15s%-6s%s\n", "授课学时","实验或上机学时","学分","开课学期");
			printf("%-10s%-10s%-10s%-10d", cur->cnum, cur->cname, cur->ctype,cur->time);
			printf("%-10d%-12d%-6d%d\n",cur->ttime,cur->etime,cur->mark,cur->term);
			system("pause");
		}
		cur=cur->next;
	}
	if(i==0)
	{
		printf("抱歉！没有相关课程\n");
		system("color 4E");
		system("color 1E");
		system("pause");
	}
}



void sterm(cour *head)								//按开课学期查询课程信息
{
    cour *cur;
	int i=0;
	int term;
	head=read(head);
	printf("请输入开课学期：\n");
	scanf("%d",&term);
	cur=head;
	while (cur != NULL)
	{
		if(cur->term==term)
		{
			i++;
			printf("%-10s%-10s%-10s%-6s", "课程编号", "课程名称", "课程性质","学时");
			printf("%-10s%-12s%-6s%s\n", "授课学时","实验或上机学时","学分","开课学期");
			printf("%-10s%-10s%-10s%-10d", cur->cnum, cur->cname, cur->ctype,cur->time);
			printf("%-10d%-12d%-6d%d\n",cur->ttime,cur->etime,cur->mark,cur->term);
			system("pause");
		}
		cur=cur->next;
	}
	if(i==0)
	{
		system("color 4E");
		system("color 1E");
		printf("抱歉！没有相关课程\n");
		system("pause");
	}
}



void alter(cour *head)				//修改某个结点存储的数据（修改课程信息）
{
	cour *cur;
	char ncnum[12];
	char ncname[20];
	int choice,i=0;
	char cnum[12];
	char nctype[10];
	int ntime;
	int nttime;
	int netime;
	int nmark;
	int nterm;
	printf("请输入要修改的课程编号: ");
	scanf("%s",cnum);
	getchar();
	cur = head;
	while (cur!= NULL)
	{
		
		if (strcmp(cur->cnum, cnum) == 0)
		{
			i++;
			choice=menu2();
			switch(choice)
			{
			case 1:
			printf("\t\t请输入修改后的课程编号:");
			gets(ncnum);
			strcpy(cur->cnum,ncnum);
			break;
			case 2:
			printf("\t\t请输入修改后的课程名称:");
			gets(ncname);
			strcpy(cur->cname,ncname);
			break;
			case 3:
			printf("请输入要修改课程的课程性质：(选修or必修)\n");
			gets(nctype);
			break;
			case 4:
			printf("\t\t请输入修改后的课程学时：");
			scanf("%d",&ntime);
			cur->time=ntime;
			break;
			case 5:
			printf("\t\t请输入修改后的授课学时:");
			scanf("%d",&nttime);
			cur->ttime=nttime;
			break;
			case 6:
			printf("\t\t请输入修改后的实验或上机课时：");
			scanf("%d",&netime);
			cur->etime=netime;
			break;
			case 7:
			printf("\t\t请输入修改后的学分：");
			scanf("%d",&nmark);
			cur->mark=nmark;
			break;
			case 8:	
			printf("\t\t请输入修改后的开课学期：");
			scanf("%d",&nterm);
			cur->term=nterm;
			break;
			}
			printf("修改课程信息成功！\n");	
			printf("%-10s%-10s%-10s%-6s", "课程编号", "课程名称", "课程性质","学时");
			printf("%-10s%-15s%-10s%s\n", "授课学时","实验或上机学时","学分","开课学期");
			printf("%-10s%-10s%-10s%-10d", cur->cnum, cur->cname, cur->ctype,cur->time);
			printf("%-10d%-12d%-12d%d\n",cur->ttime,cur->etime,cur->mark,cur->term);
			return;
		}
		cur = cur->next;
	}
	if(i==0)
	{
		printf("未找到该课程编号，请重试！");
		system("color 4E");
		system("color 1E");
		system("pause");
		alter(head);
	}
}


void tcount(cour *head);
void mcount(cour *head);

void count(cour *head)				//统计链表内数据（统计课程信息）
{
	int i;
	while(1)
	{
		system("cls");
		printf("\t\t请选择下一步操作：\n");
		printf("\t\t1.按课程性质统计课程门数\n");
		printf("\t\t2.找出学分大于等于3分的课程，并输出他们的信息\n");
		printf("\t\t0.返回主菜单\n");
		i=getch();
		switch(i-48)
		{
		case 1:tcount(head);break;
		case 2:mcount(head);break;
		case 0:return;
		default:printf("\n按键错误，请重新选择！\n");system("pause");system("color 4E");system("color 1E");
		}
	}
	return;
}
void tcount(cour *head)					//根据cur->term统计课程数量（根据学期统计课程）
{
	cour *cur;
	int sum1=0,sum2=0;
	cur=head;
	while(cur!=NULL)
	{
		if(strcmp(cur->ctype,"选修")==0)

		{
			sum1++;
		}
		if(strcmp(cur->ctype,"必修")==0)
		{
			sum2++;
		}
		cur=cur->next;
	}
	printf("查询结果如下\n");
	printf("其中有选修课:%d门\n",sum1);
	printf("其中有必修课:%d门\n",sum2);
	system("pause");
}
void mcount(cour *head)					//根据cur->mark统计课程数量（根据学分统计课程）
{
	cour *cur;
	cur=head;
	printf("学分大于等于3的课程信息如下所示：\n");
	printf("%-10s%-10s%-10s%-6s", "课程编号", "课程名称", "课程性质","学时");
	printf("%-10s%-15s%-6s%s\n", "授课学时","实验或上机学时","学分","开课学期");
	while(cur!=NULL)
	{
		if(cur->mark>=3)
		{
			printf("%-10s%-10s%-10s%-10d", cur->cnum, cur->cname, cur->ctype,cur->time);
			printf("%-10d%-12d%-12d%d\n",cur->ttime,cur->etime,cur->mark,cur->term);
		}
		cur=cur->next;
	}
	system("pause");
}

