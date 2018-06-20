#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "graph.h"
#include <string.h>

#define MAX_BUF 1024

int GetMatrixDimFromFile(char * fileName){
	int dim=0;
	char * p;
	char buf[MAX_BUF];
	FILE * fp;
	fp=fopen(fileName, "r");
	if(fp==0x0){
		printf("file open Error");
	}

	fgets(buf, sizeof(buf)/4, fp);
	p = strtok(buf, "\t\n\r ");

	while(p!=0x0){
		dim++;
		p = strtok(0x0, "\t\n\r ");
	}
	fclose(fp);
	return dim;
}

void ReadGraphFromFile(ALGraph * g, char * fileName, int numV){
	char buf[MAX_BUF];
        char *p;
        FILE * fp;

        int i;
        int j;

        Edge e;

        fp=fopen(fileName, "r");
        if(fp==0x0){
        	printf("file open error");
        }

        for(i=-1;i<numV;i++){
                fgets(buf, sizeof(buf)/4, fp);
                p = strtok(buf, "\t \n\r");

                for(j=-1;j<numV;j++){
                        if(i<0 && j<9){
				//printf("i:%d j:%d p:%s\n", i, j, p);	
				strcpy(g->vertexArr[j+1].name, p);
			}
			if(j<0|i<0);
                        else{
                                //printf("%d%5s ",j, p);
                                if(!strcmp(p, "INF"));
                                else if(!strcmp(p, "0"));
                                else{
                                        e.fromV=i;
                                        e.toV=j;
                                        e.weight=atoi(p);
                                        AddEdge(g, &e);
                                }
			}
			p=strtok(0x0, "\t\n\r ");	
			
		}
		//printf("\n");
	}
	fillWeightMatrix(g); //fill weight matrix

	fclose(fp);
	return;
}	


int compare(int d1, int d2){
	if(d1<d2) return 0;
	else return 1;
}

void GraphInit(ALGraph * pg, int numV){
	int i;

	pg->numV = numV;
	pg->numE = 0;

	pg->edgeTop=-1;
	
	pg->adjList = (List*)calloc(sizeof(List), MAX_VERTEX);	

	for(i=0;i<numV;i++){
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), compare);
	}

	pg->D = (int*)calloc(sizeof(int),(numV*numV));
	pg->PI = (int*)calloc(sizeof(int),(numV*numV));
}
	

void GraphDestroy(ALGraph * pg){
	free(pg->adjList);
	free(pg->D);
	free(pg->PI);
}

void AddEdge(ALGraph * pg, Edge * edge){
	pg->numE++;	

	LInsert(&(pg->adjList[edge->fromV]), edge->toV);

	pg->edgeArr[pg->numE-1] = *edge;
}

void ShowGraphEdgeInfo(ALGraph * pg){
	int i;
	LData data;

	for(i=0;i<pg->numV;i++){
		printf("Vertex %d : ", i);
		if(LFirst(&(pg->adjList[i]), &data)){
			printf("->%d", data);
			while(LNext(&pg->adjList[i], &data)){
				printf("->%d", data);
			}
		}
		printf("\n");
	}

	printf("edges :\n");
	
	for(i=0;i<pg->numE;i++){
		printf("{%d, %d, %d}\n", pg->edgeArr[i].fromV, pg->edgeArr[i].toV, pg->edgeArr[i].weight);
	}
}

void fillWeightMatrix(ALGraph * g){
	int i;
	Edge e;
	g->W = (int*)calloc(sizeof(int), (g->numV * g->numV));

	for(i=0;i<g->numE;i++){
		e = g->edgeArr[i];
		g->W[e.fromV * g->numV + e.toV] = e.weight;
	}
}
