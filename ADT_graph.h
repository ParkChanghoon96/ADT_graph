#ifndef ADT_GRAPH
#define ADT_GRAPH

#include <stdio.h>
#include <stdlib.h>

typedef struct vertex
{
	int data;
	LLIST* arc_list;
} VERTEX;

typedef struct arc
{
	struct vertex* to_vertex;
} ARC;

typedef struct
{
	LLIST* vertex_list;
} GRAPH;

GRAPH*	create_graph();
bool	g_insert_vertex(GRAPH* graph, int data);
bool	g_delete_vertex(GRAPH* graph, int data);
void	print_vertex_all(GRAPH* graph);
bool	g_insert_arc(GRAPH* graph, int from, int to);
void	print_arc_all(GRAPH* graph);

#endif