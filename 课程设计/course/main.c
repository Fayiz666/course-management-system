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
		printf("\n�밴����ʾ�����µĿγ���Ϣ��\n");
		head=creat(head);
		display(head);
		system("pause"); 
		save(head);
		break; 

		case 2: 
		system("cls");
		head=read(head);
		judge(head);
		printf("\n�밴����ʾ�����µĿγ���Ϣ��\n");  
		head=insert(head);
		save(head);
		break;

		case 3: 
		system("cls");
		head=read(head);
		judge(head);
		printf("\n�밴����ʾ��ѯ�γ���Ϣ��\n");
		search(head);								 
		printf("\t"); 
		break;
		
		case 4:
		system("cls");
		head=read(head);
		judge(head);
		printf("\n\t�밴����ʾ�޸Ŀγ���Ϣ\n"); 
		alter(head);
		display(head);
		system("pause"); 
		save(head);
		break; 

		case 5: 
		system("cls");
		head=read(head);
		judge(head);
		printf("\n�밴����ʾɾ���γ���Ϣ\n"); 
		head=del(head);									 
		display(head);
		save(head);
		system("pause"); 
		break; 
		
		case 6:
		system("cls");
		head=read(head);
		judge(head);
		printf("\n�밴����ʾͳ�ƿγ���Ϣ\n"); 
		count(head);
		printf("\t");
		save(head);
		system("pause");
		break;

		case 7:
		system("cls");
		judge(head);
		printf("\n�밴����ʾͳ�ƿγ���Ϣ\n"); 
		display(head);
		printf("\t");
		save(head);
		system("pause");
		break;

		case 0:
		clean(head);
		printf("\n\t\tлл����ʹ��\n");                          
		printf("\n\t\t"); 
		system("pause"); 
		exit(0); 
		}
	} 
	return 0;
}
