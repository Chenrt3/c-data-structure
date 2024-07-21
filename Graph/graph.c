//数组表示有向图无向图和有向网
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100	//顶点数目的最大值
#define INFINITY INT_MAX //无权值在数组中表示正无穷
#define ERROR -1
typedef char VertexType;	//顶点的数据类型
typedef int EdgeType;	//带权图中边上权值的数据类型
typedef int Status; //返回值数据类型
typedef enum{DG,DW,UDG,UDN} Graphkind; //{有向图，有向网，无向图，无向网} 
typedef struct {
	VertexType Vex[MaxVertexNum];	//顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];	//邻接矩阵，边表
	int vexnum, arcnum;	//图的当前顶点数和弧数
	Graphkind kind;
}MGraph;

Status CreateGraph(MGraph G){
		scanf(&G.kind);
		switch(G.kind){
			case(DG):return CreateDG(G,pos);//有向图
			case(DW):return CreateDW(G);//有向网
			case(UDG):return CreateUDG(G);//无向图
			case(UDN):return CreateUDN(G);//无向网
			default: return ERROR;
		}
}

Status CreateDG(MGraph G,int pos){
		G.vexnum=pos;
		char data;
		for(int i=0;i<G.vexnum;i++){
			printf("输入第%d\n",i+1);
			scanf(&data);
			G.Vex[i]=data;
		}
		
}