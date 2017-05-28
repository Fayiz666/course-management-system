#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "head.h"

cour *creat(cour *head)					//�������������µĿγ���Ϣ��
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
	printf("������γ̱��: (�س�����¼��)");
	while (gets(cnum) != NULL && cnum[0] != '\0')
	{
		printf("������γ����ƣ�");
		gets(cname);
		printf("������Ҫ���ӿγ̵Ŀγ����ʣ�(ѡ��or����)\n");
		gets(ctype);
		printf("������γ�ѧʱ��");
		scanf("%d",&time);
		printf("������γ��ڿ�ѧʱ��");
		scanf("%d",&ttime);
		printf("������γ�ʵ����ϻ�ѧʱ��");
		scanf("%d",&etime);
		printf("������γ�ѧ�֣�");
		scanf("%d",&mark);
		printf("�����뿪��ѧ�ڣ�");
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
			printf("������γ̱��: (�س�����)");
		}
	}
	return head;
}



cour *del(cour *head)				//ɾ����㣨���ݱ��ɾ���γ���Ϣ��
{
	cour *cur, *pre;
	char cnum[12];
	printf("������Ҫɾ���Ŀγ̱��: ");
	gets(cnum);
	if (head == NULL)
	{
		printf("�γ��б�Ϊ�գ�û�п���ɾ���Ŀγ���Ϣ!\n");
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
			printf("ɾ���γ���Ϣ�ɹ���\n");
		}
		else
		{  
			printf("�γ��б���û��ƥ��Ҫɾ���Ŀγ̱��!\n");
		}
	}
	return head;
}


void display(cour *head)				//���������ʾ�γ���Ϣ��
{
	cour *cur;
	printf("\n��ʾ���������£�\n");
	if (head == NULL)
	{
		printf("�γ���Ϣ�б�Ϊ��!\n");
	}
	else
	{
		cur = head;
		printf("%-10s%-10s%-10s%-6s", "�γ̱��", "�γ�����", "�γ�����","ѧʱ");
		printf("%-10s%-15s%-6s%s\n", "�ڿ�ѧʱ","ʵ����ϻ�ѧʱ","ѧ��","����ѧ��");
		while (cur != NULL)
		{
			printf("%-10s%-10s%-10s%-10d", cur->cnum, cur->cname, cur->ctype,cur->time);
			printf("%-10d%-12d%-12d%d\n",cur->ttime,cur->etime,cur->mark,cur->term);
			cur = cur->next;
		}
	}
}


cour *insert(cour *head)			//���ӽ�㣨���ӿγ���Ϣ��
{
	cour *cur, *pre, *ncour;
	ncour = (cour *)malloc(LEN);
	printf("������Ҫ���ӿγ̵Ŀγ̱��: ");
	scanf("%s",ncour->cnum);
	getchar();
	printf("������Ҫ���ӿγ̵Ŀγ�����: ");
	gets(ncour->cname);
	printf("������Ҫ���ӿγ̵Ŀγ����ʣ�(ѡ��or����)\n");
	gets(ncour->ctype);
	printf("������Ҫ���ӿγ̵�ѧʱ: ");
	scanf("%d", &ncour->time);
	printf("������Ҫ���ӿγ̵��ڿ�ѧʱ: ");
	scanf("%d", &ncour->ttime);
	printf("������Ҫ���ӿγ̵�ʵ����ϻ�ѧʱ: ");
	scanf("%d", &ncour->etime);
	printf("������Ҫ���ӿγ̵�ѧ��: ");
	scanf("%d", &ncour->mark);
	printf("������Ҫ���ӿγ̵Ŀ���ѧ��: ");
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
	printf("�����µĿγ���Ϣ���\n");
	return head;
}
 

void sname(cour *head);
void sterm(cour *head);

void search(cour *head)					//��ѯ�γ���Ϣ
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
		default:printf("\n��������������ѡ��\n");system("color 4E");system("color 1E");
		}
	}
}


	
void sname(cour *head)							 //���γ����Ʋ�ѯ�γ���Ϣ
{		
	int i=0;
	cour *cur;
	char cname[20];
	head=read(head);		
	printf("\t\t������γ����ƣ�");
	gets(cname);
	cur=head;
	while (cur != NULL)
	{
		if(strcmp(cur->cname,cname)==0)
		{
			i++;
			printf("%-10s%-10s%-10s%-6s", "�γ̱��", "�γ�����", "�γ�����","ѧʱ");
			printf("%-10s%-15s%-6s%s\n", "�ڿ�ѧʱ","ʵ����ϻ�ѧʱ","ѧ��","����ѧ��");
			printf("%-10s%-10s%-10s%-10d", cur->cnum, cur->cname, cur->ctype,cur->time);
			printf("%-10d%-12d%-6d%d\n",cur->ttime,cur->etime,cur->mark,cur->term);
			system("pause");
		}
		cur=cur->next;
	}
	if(i==0)
	{
		printf("��Ǹ��û����ؿγ�\n");
		system("color 4E");
		system("color 1E");
		system("pause");
	}
}



void sterm(cour *head)								//������ѧ�ڲ�ѯ�γ���Ϣ
{
    cour *cur;
	int i=0;
	int term;
	head=read(head);
	printf("�����뿪��ѧ�ڣ�\n");
	scanf("%d",&term);
	cur=head;
	while (cur != NULL)
	{
		if(cur->term==term)
		{
			i++;
			printf("%-10s%-10s%-10s%-6s", "�γ̱��", "�γ�����", "�γ�����","ѧʱ");
			printf("%-10s%-12s%-6s%s\n", "�ڿ�ѧʱ","ʵ����ϻ�ѧʱ","ѧ��","����ѧ��");
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
		printf("��Ǹ��û����ؿγ�\n");
		system("pause");
	}
}



void alter(cour *head)				//�޸�ĳ�����洢�����ݣ��޸Ŀγ���Ϣ��
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
	printf("������Ҫ�޸ĵĿγ̱��: ");
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
			printf("\t\t�������޸ĺ�Ŀγ̱��:");
			gets(ncnum);
			strcpy(cur->cnum,ncnum);
			break;
			case 2:
			printf("\t\t�������޸ĺ�Ŀγ�����:");
			gets(ncname);
			strcpy(cur->cname,ncname);
			break;
			case 3:
			printf("������Ҫ�޸Ŀγ̵Ŀγ����ʣ�(ѡ��or����)\n");
			gets(nctype);
			break;
			case 4:
			printf("\t\t�������޸ĺ�Ŀγ�ѧʱ��");
			scanf("%d",&ntime);
			cur->time=ntime;
			break;
			case 5:
			printf("\t\t�������޸ĺ���ڿ�ѧʱ:");
			scanf("%d",&nttime);
			cur->ttime=nttime;
			break;
			case 6:
			printf("\t\t�������޸ĺ��ʵ����ϻ���ʱ��");
			scanf("%d",&netime);
			cur->etime=netime;
			break;
			case 7:
			printf("\t\t�������޸ĺ��ѧ�֣�");
			scanf("%d",&nmark);
			cur->mark=nmark;
			break;
			case 8:	
			printf("\t\t�������޸ĺ�Ŀ���ѧ�ڣ�");
			scanf("%d",&nterm);
			cur->term=nterm;
			break;
			}
			printf("�޸Ŀγ���Ϣ�ɹ���\n");	
			printf("%-10s%-10s%-10s%-6s", "�γ̱��", "�γ�����", "�γ�����","ѧʱ");
			printf("%-10s%-15s%-10s%s\n", "�ڿ�ѧʱ","ʵ����ϻ�ѧʱ","ѧ��","����ѧ��");
			printf("%-10s%-10s%-10s%-10d", cur->cnum, cur->cname, cur->ctype,cur->time);
			printf("%-10d%-12d%-12d%d\n",cur->ttime,cur->etime,cur->mark,cur->term);
			return;
		}
		cur = cur->next;
	}
	if(i==0)
	{
		printf("δ�ҵ��ÿγ̱�ţ������ԣ�");
		system("color 4E");
		system("color 1E");
		system("pause");
		alter(head);
	}
}


void tcount(cour *head);
void mcount(cour *head);

void count(cour *head)				//ͳ�����������ݣ�ͳ�ƿγ���Ϣ��
{
	int i;
	while(1)
	{
		system("cls");
		printf("\t\t��ѡ����һ��������\n");
		printf("\t\t1.���γ�����ͳ�ƿγ�����\n");
		printf("\t\t2.�ҳ�ѧ�ִ��ڵ���3�ֵĿγ̣���������ǵ���Ϣ\n");
		printf("\t\t0.�������˵�\n");
		i=getch();
		switch(i-48)
		{
		case 1:tcount(head);break;
		case 2:mcount(head);break;
		case 0:return;
		default:printf("\n��������������ѡ��\n");system("pause");system("color 4E");system("color 1E");
		}
	}
	return;
}
void tcount(cour *head)					//����cur->termͳ�ƿγ�����������ѧ��ͳ�ƿγ̣�
{
	cour *cur;
	int sum1=0,sum2=0;
	cur=head;
	while(cur!=NULL)
	{
		if(strcmp(cur->ctype,"ѡ��")==0)

		{
			sum1++;
		}
		if(strcmp(cur->ctype,"����")==0)
		{
			sum2++;
		}
		cur=cur->next;
	}
	printf("��ѯ�������\n");
	printf("������ѡ�޿�:%d��\n",sum1);
	printf("�����б��޿�:%d��\n",sum2);
	system("pause");
}
void mcount(cour *head)					//����cur->markͳ�ƿγ�����������ѧ��ͳ�ƿγ̣�
{
	cour *cur;
	cur=head;
	printf("ѧ�ִ��ڵ���3�Ŀγ���Ϣ������ʾ��\n");
	printf("%-10s%-10s%-10s%-6s", "�γ̱��", "�γ�����", "�γ�����","ѧʱ");
	printf("%-10s%-15s%-6s%s\n", "�ڿ�ѧʱ","ʵ����ϻ�ѧʱ","ѧ��","����ѧ��");
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

