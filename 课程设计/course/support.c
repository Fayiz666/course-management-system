#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void clean(cour *head)				//�ͷ�����
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


cour *read(cour *head)				//��ȡ�ļ����ݵ�����
{
	cour *cur,*temp;
	FILE *fp;
	fp=fopen("course.dat","rb+");
	if(fp == NULL)                   
	{ 
		printf("\t��ȡ���ݿ�ʧ�ܣ��봴���µĿγ���Ϣ��\n"); 
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



void save(cour *head)			//�洢�������ݵ��ļ�         
{
	cour *cur;
	FILE *fp;
	fp = fopen("course.dat","wb+");
	if(fp == NULL)                   
	{ 
		printf("\t��ȡ����ʧ�ܣ�\n"); 
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
	printf("����ɹ���\n"); 
} 


int menu1()				//���˵�
{ 
	int a; 
	do
	{ 
		system("cls"); 
		printf("\t\t+---------------------------+\n");
		printf("\t\t|                           |\n");
		printf("\t\t|  ��ӭʹ�ÿγ���Ϣ����ϵͳ |\n");
		printf("\t\t|                           |\n");
		printf("\t\t+---------------------------+\n");
		printf("\t\t *****�γ���Ϣ����ϵͳ***** \n");                               
		printf("\t\t    ����������������--��\n");                   
		printf("\t\t    �� 1. �����γ���Ϣ��\n"); 
		printf("\t\t    �� 2. ���ӿγ���Ϣ��\n"); 
		printf("\t\t    �� 3. ��ѯ�γ���Ϣ��\n"); 
		printf("\t\t    �� 4. �޸Ŀγ���Ϣ��\n"); 
		printf("\t\t    �� 5. ɾ���γ���Ϣ��\n"); 
		printf("\t\t    �� 6. ͳ�ƿγ���Ϣ��\n");
		printf("\t\t    �� 7. ����γ���Ϣ��\n");
		printf("\t\t    �� 0.   �˳�����  ��\n"); 
		printf("\t\t    ����������--��������\n"); 
		printf("\t\t����ѡ�����ѡ��:"); 
		a=getch();
	}while(a<'0'||a>'7'); 
	return a-48;
} 
int menu2()			//�޸Ĺ����Ӳ˵�
{  
	int a;
	do
	{
		system("cls"); 
		printf("\t\t    ����������������---��\n");                   
		printf("\t\t    �� 1.  �γ̱��    ��\n"); 
		printf("\t\t    �� 2.  �γ�����    ��\n"); 
		printf("\t\t    �� 3.  �γ�����    ��\n"); 
		printf("\t\t    �� 4.    ѧʱ      ��\n"); 
		printf("\t\t    �� 5.  �ڿ�ѧʱ    ��\n"); 
		printf("\t\t    �� 6.ʵ����ϻ�ѧʱ��\n");
		printf("\t\t    �� 7.    ѧ��      ��\n"); 
		printf("\t\t    �� 8.  ����ѧ��    ��\n"); 
		printf("\t\t    ����������--����-����\n"); 
		printf("\t\t����ѡ���޸�ѡ��:\n");
		a=getch();
	}while(a<'0'||a>'8');
	return a-48;
}
void menu3()			//��ѯ�����Ӳ˵�
{ 
	system("cls");
	printf("\n");
	printf("\t\t1.���ݿγ����Ʋ�ѯ\n");
	printf("\t\t2.���ݿ���ѧ�ڲ�ѯ\n");
	printf("\t\t0.�������˵�\n");
	printf("\n��ѡ����һ������ѡ�\n");
}
void judge(cour *head)
{
	if(head == NULL)
	{
		printf("\n\n\n\n\t\t���ݿ�Ϊ�գ����ȴ����µĿγ���Ϣ��\n");
		system("pause");
		main();
	}
}
