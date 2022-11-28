#include <stdio.h>
#include <conio.h>
#include "SeqQueue.h"
#define DataType char
#define MaxGraphSize 100
#define MaxGraphValue 999
typedef struct{
	int v_size;
	int e_size;
	DataType vextex[MaxGraphSize];
	int weight[MaxGraphSize][MaxGraphSize];
}Graph;
typedef struct{
	int v1,v2;
	int weight;
}Edge;
void GraphInitiate(Graph *G,DataType *v,int n){
	for(int i=0;i<n;i++){
		G->vextex[i]=v[i];
	}
	G->v_size=n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){G->weight[i][j]=0;}else{G->weight[i][j]=MaxGraphValue;}
		}
	}
	G->e_size=0;
}
void GraphInsertEdge(Graph *G,Edge *E){
	G->weight[E->v1][E->v2]=E->weight;
//	G->weight[E->v2][E->v1]=E->weight;
	G->e_size++;
}
int GraphGetFirstVex(Graph *G,int v){
	if(v<0||v>G->v_size) return -1;
	for(int i=0;i<G->v_size;i++){
		if(G->weight[v][i]>0&&G->weight[v][i]<MaxGraphValue){
			return i;
		}
	}
	return -1;
}
int GraphGetNextVex(Graph *G,int v1,int v2){
	if(v1<0||v1>G->v_size||v2<0||v2>G->v_size){
		return -1;
	}
	for(int i=v2+1;i<=G->v_size;i++){
		if(G->weight[v1][i]){
			if(G->weight[v1][i]>0&& G->weight[v1][i]<MaxGraphValue){
				return i;
			}
		}
	}
	return -1;
}
void GraphDFS(Graph *G,int v,int visited[]){
	int w;
	printf("%c ",G->vextex[v]);
	visited[v]=1;
	w=GraphGetFirstVex(G,v);
	while(w!=-1){
		if(!visited[w]){
			GraphDFS(G,w,visited);
		}
		w=GraphGetNextVex(G,v,w);
	}
}
void GraphBFS(Graph *G,int v,int visited[])
{
	int u,w;
	SeqQueue queue;
	printf("%c",G->vextex[v]);
	visited[v]=1;
	QueueInitiate(&queue);
	QueueAppend(&queue,v);
	while(SeqQueueNotEmpty(queue))
	{
		QueueDelete(&queue,&u);
		w=GraphGetFirstVex(G,u);
		while(w!=-1)
		{
			if(!visited[w])
			{
				printf("%c",G->vextex[w]);
				visited[w]=1;
				QueueAppend(&queue,w);
			}
			w=GraphGetNextVex(G,u,w);
		}
	}
}
void show(Graph *G){
	for(int i=0;i<G->v_size;i++){
		printf("%5c",G->vextex[i]);
	}
	printf("\n------------------------------\n");
	for(int i=0;i<G->v_size;i++){
		for(int j=0;j<G->v_size;j++){
			printf("%5d",G->weight[i][j]);
		}
		printf("\n");
	}
}
Graph g;
DataType vextex[6]="ABCDE";
#define N 5
Edge edge[6]={{0,3,10},{0,4,30},{1,2,40},{3,1,20},{4,2,60},{4,1,50}};
int main(){
	GraphInitiate(&g,vextex,N);
	show(&g);
	getch();
	for(int i=0;i<6;i++){
		GraphInsertEdge(&g,&edge[i]);
	}
	show(&g);
	getch();
	int v=GraphGetFirstVex(&g,4);
	printf("v[%d]=%c\n",v,g.vextex[v]);
	getch();

	v=GraphGetNextVex(&g,4,v);
		printf("v[%d]=%c\n",v,g.vextex[v]);
		getch();
		
	int visited[g.v_size];
	for(int i=0;i<g.v_size;i++){
		visited[i]=0;
	}
	//深度优先遍历
	GraphDFS(&g,0,visited);
	printf("\n");
	for(int i=0;i<g.v_size;i++){
	visited[i] = 0;
	}
		//广度优先遍历
		GraphBFS(&g,0,visited);
}
