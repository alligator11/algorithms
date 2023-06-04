#include<stdio.h>

struct edges{
    int start;
    int end;
    int cost;
}edge[1000],edge_copy[1000],neighbors[1000];

int nodes[1000];

int checkIfNull(int n){
    int i,c=0;
    for (i=0;i<n;i++){
	if(nodes[i]==500)
	    c++;
    }
    if(c==n)
	return 1;
    else
	return 2;
}

int min_cost_neighbor(int n, int selected){
    int i,min=neighbors[0].cost,min_index=-1,min_neigh;
    for(i=0;i<n;i++){
	if(nodes[neighbors[i].start]==500 && nodes[neighbors[i].end]==500)
	    continue;
	if(neighbors[i].cost<=min){
	    min=neighbors[i].cost;
	    min_neigh=i;
	    if(selected==neighbors[i].start)
		min_index=neighbors[i].end;
	    else if(selected==neighbors[i].end)
		min_index=neighbors[i].start;
	    else if(nodes[neighbors[i].start]==500)
		min_index=neighbors[i].end;
	    else if(nodes[neighbors[i].end]==500)
		min_index=neighbors[i].start;
	}
    }
    if(min_index!=500){
    neighbors[min_neigh].cost=500;
    neighbors[min_neigh].start=500;
    neighbors[min_neigh].end=500;
    }
    return min_index;
}

void removeNode(int node, int n){
    int i;
    for(i=0;i<n;i++){
	if(nodes[i]==node)
	    nodes[i]=500;
    }
}
int alreadyPresent(int k,int n){
	int j;
	for(j=0;j<n;j++){
		if(edge[k].start==neighbors[j].start && edge[k].end==neighbors[j].end)
			return 1;
	}
	return 2;
}

void main(){
    int n,e,i,j=0,k,selected_node,index,min_cost=0;
    printf("Name: Farin Khan\n");
    printf("SAP Id: 60009210140\n");
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    for(i=0;i<e;i++){
		printf("enter start node: ");
		scanf("%d",&edge[i].start);
		printf("enter end node: ");
		scanf("%d",&edge[i].end);
		printf("enter cost: ");
		scanf("%d",&edge[i].cost);
		edge_copy[i]=edge[i];
    }
    for(i=0;i<n;i++){
		nodes[i]=i;
    }
    selected_node=nodes[0];
    while(checkIfNull(n)!=1){
	for(i=0;i<e;i++){
	    if((edge[i].start==selected_node||edge[i].end==selected_node) && alreadyPresent(i,j)!=1){
			neighbors[j]=edge[i];
			j++;
			edge[i].start=500;
			edge[i].end=500;
			edge[i].cost=500;
	    }
	}
	removeNode(selected_node,n);
	index=min_cost_neighbor(j,selected_node);
	if(index!=-1)
	selected_node=nodes[index];
    }
	for(i=0;i<e;i++){
	for(k=0;k<j;k++){
	    if(neighbors[k].start==edge_copy[i].start && neighbors[k].end==edge_copy[i].end && neighbors[k].cost==edge_copy[i].cost){
		edge_copy[i].cost=500;
		edge_copy[i].start=500;
		edge_copy[i].end=500;
	    }
	}
    }
    for(i=0;i<e;i++)
    {
	if(edge_copy[i].cost!=500){
		printf("(%d,%d)",edge_copy[i].start,edge_copy[i].end);
		min_cost+=edge_copy[i].cost;
	}
    }
    printf("\nMinimum cost: %d",min_cost);
    return 0;
}
