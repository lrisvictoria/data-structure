#include <graphics.h>
#include <stdio.h>
#define MAXSIZE 10
typedef struct{
	char str[MAXSIZE];
	int length;
}SString;
SString s,t,c;
//1初始化
void SStringInitiate(SString *S,int length,char const *string){
	for(int i=0;i<length;i++){
		S->str[i]=string[i];
	}
	S->length=length;
}
//2插入串（T插入S）
int SStringInsert(SString *S,int pos,SString T){
	for(int i=S->length;i>=pos;i--){
		S->str[i+T.length]=S->str[i];
	}
	for(int i=0;i<T.length;i++){
		S->str[pos+i]=T.str[i];
	}
	S->length=S->length+T.length;
	return 1;
}
//3删除串（S[pos,pos+len]）
int	SStringDelete(SString *S,int pos,int len){
		int i;
		if(S->length<=0){
			printf("error,null!");
			return 0;
		}
		else if(pos<0||len<0||pos+len>S->length){
			printf("wrong pos&len");
			return 0;
		}
		else{
			for(i=pos+len;i<=S->length-1;i++)
				S->str[i-len]=S->str[i];
			S->length=S->length-len;
			return 1;
			
		}
	}
//4获取子串（T->S[pos,pos+len]）
	int SubString(SString *S,int pos,int len,SString *T){
		int i;
		if(pos<0||len<0||pos+len>S->length){
			printf("wrong pos&len");
			return 0;
		}
		for(i=0;i<len;i++)
			T->str[i]=S->str[pos+i];
		T->length=len;
		return 1;
	}
void Show(){
	cleardevice();
	xyprintf(4,4,"s.length=%d",s.length);
	for(int i=0;i<s.length;i++){
		circle(34+i*61,54,30); 
		xyprintf(34+i*61,54,"%c",s.str[i]);
	}
	xyprintf(4,104,"t.length=%d",t.length);
		for(int i=0;i<t.length;i++){
			circle(34+i*61,154,30); 
			xyprintf(34+i*61,154,"%c",t.str[i]);
		}
	xyprintf(4,204,"s.length=%d",c.length);
			for(int i=0;i<c.length;i++){
				circle(34+i*61,254,30); 
				xyprintf(34+i*61,254,"%c",c.str[i]);
			}
}
int main(){
	initgraph(800, 600);
	setcolor(BLUE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	setrendermode(RENDER_MANUAL);
	SStringInitiate(&s, 3, "bcd");
	Show();
	getch();
	SStringInitiate(&s, 3, "bcd");
		Show();
		getch();
	SStringInsert(&s, 2, t);
	Show();
	getch();
	SStringDelete(&s, 0, 2);
	Show();
	getch();
	
	SubString(&s, 0, 2, &c);
	Show();
	getch();
}
