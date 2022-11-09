#include <graphics.h>
#include <cmath>
#define DataType char
#define MaxTreeSize 128
typedef struct {
	DataType biTree[MaxTreeSize];
	int size;
	int depth;
} SeqBiTree;
SeqBiTree st;
char result[MaxTreeSize];
int current;
//��ʼ��
void SeqBiTreeInitiate(SeqBiTree *T, char *x) {
	int i = 0;
	while (x[i] != '\0') {
		T->biTree[i] = x[i];
		i++;
	}
	T->size = i;
	double d = log2(i);
	T->depth = d + 1;
}
int Precase = 0;
//ǰ�����(DLR)
void SeqBiTreePreOrder(SeqBiTree *T, int n) {
	result[current++] = T->biTree[n];//D
	if (n * 2 + 1 < T->size) {
		SeqBiTreePreOrder(T, n * 2 + 1);
	}//L
	if (n * 2 + 2 < T->size) {
		SeqBiTreePreOrder(T, n * 2 + 2);
	}//R
	Precase = 1;
}
//�������(LDR)
void SeqBiTreeInOrder(SeqBiTree *T, int n) {
	if (n * 2 + 1 < T->size) {
		SeqBiTreeInOrder(T, n * 2 + 1);
	}//L
	result[current++] = T->biTree[n];//D
	if (n * 2 + 2 < T->size) {
		SeqBiTreeInOrder(T, n * 2 + 2);
	}//R
	Precase = 2;
}
//�������(LRD)
void SeqBiTreePosOrder(SeqBiTree *T, int n){
	if (n * 2 + 1 < T->size) {
		SeqBiTreePosOrder(T, n * 2 + 1);
	}//L
	if (n * 2 + 2 < T->size) {
		SeqBiTreePosOrder(T, n * 2 + 2);
	}//R
	result[current++] = T->biTree[n];//D
	Precase = 3;
}
void show() {
	//�ڵ���ӻ�
	for (int j = 0; j < st.depth; j++) {
		int w = (int)pow(2, st.depth - j + 1);
		for (int i = 0; i < pow(2, j); i++) {
			int index = (int)pow(2, j) - 1 + i;
			if (index < st.size) {
				if (st.biTree[index] == '^') {
					continue;
				}
		//��֦���ӻ�
//				int linex=60/pow(2,j-1);
//				int linex=120/(2*(pow(2,j-1)+1/pow(2,j-1)));x
//int linex=80/(2*(w+1)/w)*(pow(2,w-1)+1)/(pow(2,w)+1);x
//				2(w+1)/w
				//�����Ϊ3����������ñ�׼��ʹ��i��/i�����->1/2����������̫��
				int linex=75/((2*(pow(2,j-1)+1/pow(2,j-1)))*(pow(2,w-1)+1)/(pow(2,w)+1));
				int u=10;
				if(st.biTree[index]!='^'&&index!=0&&index%2==1){
				line(10*w+i*w*10*2+24+linex,26+60*j-u,10*w+i*w*10*2+24-linex,26+60*j+u);//��(/)
				
				}
				if(st.biTree[index]!='^'&&index!=0&&index%2==0){
				line(10*w+i*w*10*2-20-linex,26+60*j-u,10*w+i*w*10*2-20+linex,26+60*j+u);//��(\)
				}
								circle(4 + 10 * w + i * w * 10 * 2, 60 + 60 * j, 20);
				xyprintf(4+10*w+i*w*10*2,60+60*j,"%c",st.biTree[index]);
			}
		}
	}
	//�¼����
	if (Precase == 1) {
		xyprintf(10, 300, "PreOrder:");
		for (int i = 0; i < current; i++) {
			xyprintf(10 + 10 * i, 320, "%c", result[i]);
		}
		Precase=0;
	}
	if (Precase == 2) {
		xyprintf(10, 400, "InOrder:");
		for (int i = 0; i < current; i++) {
			xyprintf(10 + 10 * i, 420, "%c", result[i]);
		}
		Precase=0;
	}
	if (Precase == 3) {
		xyprintf(10, 500, "PosOrder:");
		for (int i = 0; i < current; i++) {
			xyprintf(10 + 10 * i, 520, "%c", result[i]);
		}
		Precase=0;
	}
	current = 0;
	getch();
}
int main() {
	initgraph(800, 600);
	setcolor(BLUE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	setrendermode(RENDER_MANUAL);
	char t[] = "ADEB^F^CG^^IH";
	SeqBiTreeInitiate(&st, t);//��ʼ��
	show();
	SeqBiTreePreOrder(&st, 0);//ǰ��
	show();
	SeqBiTreeInOrder(&st, 0);//����
	show();
	SeqBiTreePosOrder(&st, 0);//����
	show();
}
