#ifndef HEAD_H
#define HEAD_H
#define LEN sizeof(struct cour)
typedef struct cour
{
	char cnum[12];
	char cname[20];
	char ctype[10];
	int time;
	int ttime;
	int etime;
	int mark;
	int term;
	struct cour *next;
}cour;

int menu1();
int menu2();
void menu3();
cour *creat(cour *head);
cour *del(cour *head);
cour *insert(cour *head);
cour *read(cour *head);
void alter(cour *head);
void search(cour *head);
void count(cour *head);
void display(cour *head);
void clean(cour *head);
void save(cour *head);
void judge(cour *head);
int main();
#endif
