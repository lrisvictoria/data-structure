#include <graphics.h>
#define DataType int
typedef struct Node 
{
	DataType data;
	struct Node *next;
} SLNode;

SLNode *head=NULL;
//1
void LinkInitiate(SLNode **head) 
{
	*head = (SLNode *)malloc(sizeof(SLNode));
	(*head)->data = -1;
	(*head)->next =NULL;



}
//2
int LinkInsertHead(SLNode *head,DataType x) 
{
	SLNode *s=(SLNode *)malloc(sizeof(SLNode));
	s->data=x;
	s->next =head->next;
	head->next=s;
	return 1;
}
//3
void Show()
{
	cleardevice();
	SLNode *p=head;
	int i=0;
	while(p!=NULL) 
	{
		rectangle(100+160*i,100,200+160*i,200);
		xyprintf(100+160*i,100,"%d",p->data);
		line(100+160*i,150,200+160*i,150);
		xyprintf(100+160*i,160,"%x",p->next);
		p=p->next;
		i++;
	}
	for(int u=0; u<i-1; u++) 
	{
		line(220+160*u,150,250+160*u,150);//¼ýÍ·
		line(230+160*u,120,250+160*u,150);
		line(230+160*u,180,250+160*u,150);
	}

}
int main() 
{
	initgraph(800, 600);
	setcolor(BLUE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	setrendermode(RENDER_MANUAL);
	LinkInitiate(&head);
	Show();
	getch();
	LinkInsertHead(head, 5);
	Show();
	getch();
	LinkInsertHead(head, 5);
	Show();
	getch();
	LinkInsertHead(head, 5);
	Show();
	getch();
}
