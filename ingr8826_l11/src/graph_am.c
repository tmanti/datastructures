/* Grahp representation by adjacent matrix
 * modified from textbook example
 * HBF
 * Version  2019-02-25
 * Version 2020-03-25 Rick Magnotta
 * Version 2022-03-24 Heider Ali
 */

#include "My_Definitions.h"
#include "graph_am.h"

void randomGraph(int adj[][MAX])
//==============================
{
	int i, j, v;

	srand(time(NULL));

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (j == i)
				adj[i][j] = 0;
			else {
				v = rand() % 2;
				adj[i][j] = v;
				adj[j][i] = v;
			}
		}
	}
}

void displayAdjacentMatrix(int adj[][MAX])
//========================================
{
	int i, j;

	printf("    ");
	for (i = 0; i < MAX; i++) printf("%d ", i);
	printf("  <=== Node Number\n\n");

	for (i = 0; i < MAX; i++) {
		printf("%d  ", i);

		for (j = 0; j < MAX; j++) printf(" %d", adj[i][j]);

		printf("\n");
	}
    printf("^\n");
    printf("|__ Node Number\n");
    printf("\n");
}

void connected(int adj[][MAX],     // Adjacency Matrix
		       int node      )     // Node in Graph.
//============================
// Given the Graph "adj", and a node "node" present in the graph,
// this routine prints the "node-number" of all the nodes that are
// connected to the node "node".
{
	// <<< Your code here >>>
	int i = node;
	printf("Nodes connected to node %d: [", i);
	int first = 1;
	for(int j = 0; j < MAX; j++){
		if(adj[i][j] == 1){
			if(first){
				printf(" %d", j);
				first = 0;
			} else {
				printf(", %d", j);
			}
		}
	}
	printf("]\n");


	return;
}

void node_counts(int adj[][MAX],   // Adjacency Matrix
		         int count     )   // Target count.
//==============================
// Given the Graph "adj", and the target count "count",
// this routine prints the "node-number" of all the nodes that are
// connected to "count" other nodes.
{
	// <<< Your code here >>>
	int x = count;
	printf("Nodes connected to %d other nodes: [", x);
	int first = 1;
	for(int i = 0; i<MAX; i++){
		int count = 0;
		for(int j = 0; j < MAX; j++){
			if(adj[i][j] == 1){
				count++;
			}
			if(count > x){
				break;
			}
		}
		if(count == x){
			if(first){
				printf(" %d", i);
				first = 0;
			} else {
				printf(", %d", i);
			}
		}
	}
	printf("]\n");

	return;
}
