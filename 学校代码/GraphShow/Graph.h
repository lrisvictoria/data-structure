#include <stdio.h>
#include <conio.h>
#define MaxGraphSize 100
#define DataType char
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
			if(i==j){
				G->weight[i][j]=0;
			}else{
				G->weight[i][j]=MaxGraphValue;
			}
		}
	}
	G->v_size=0;
}
void Show(Graph *G){
	for(int i=0;i<G->v_size;i++){
		printf("%5c",G->vextex[i]);
	}
	printf("\n-------------------------------------\n");
	for(int i=0;i<G->v_size;i++){
		for(int j=0;j<G->v_size;j++){
			printf("%5d",G->weight[i][j]);
		}
		printf("\n");
	}
}
#define N 5
DataType vextex[N+1]="ABCDE";
Graph g;
Edge edge[5]={{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
int main(){
	GraphInitiate(&g,vextex,N); 
	Show(&g);
}
