#include <stdio.h>
#include "ADT_llist.h"
#include "ADT_graph.h"


int main(void)
{
	int i;

	GRAPH* graph = create_graph();

	int vertex[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

	for(i = 0; i < 6; i++)
	{
		if(!g_insert_vertex(graph, vertex[i]))
		{
			printf("graph vertex insertion failed: %c\n", (char)vertex[i]);
		}
		else
		{
			printf("graph vertex insertion ok: %c\n", (char)vertex[i]);
		}
	}

	if(!g_insert_vertex(graph, 'C'))
	{
		printf("graph vertex insertion failed: %c already exist\n", 'C');
	}
	else
	{
		printf("graph vertex insertion ok: %c\n", 'C');
	}
	
	printf("\nGraph's Vertex:\n");
	print_vertex_all(graph);
	printf("\n");

	if(!g_delete_vertex(graph, 'B'))
	{
		printf("graph vertex delete failed: %c\n", 'B');
	}
	else
	{
		printf("graph vertex delete ok: %c\n", 'B');
	}

	printf("\nGraph's Vertex:\n");
	print_vertex_all(graph);
	printf("\n");

	if(!g_insert_arc(graph, 'A', 'B'))
	{
		printf("graph arc insertion failed: %c -> %c\n", 'A', 'B');
	}
	else
	{
		printf("graph arc insertion ok: %c -> %c\n", 'A', 'B');
	}

	if(!g_insert_vertex(graph, 'B'))
	{
		printf("graph vertex insertion failed: %c already exist\n", 'B');
	}
	else
	{
		printf("graph vertex insertion ok: %c\n", 'B');
	}

	if(!g_insert_arc(graph, 'A', 'B'))
	{
		printf("graph arc insertion failed: %c -> %c\n", 'A', 'B');
	}
	else
	{
		printf("graph arc insertion ok: %c -> %c\n", 'A', 'B');
	}

	g_insert_arc(graph, 'B', 'A');
	g_insert_arc(graph, 'B', 'C');
	g_insert_arc(graph, 'B', 'E');
	g_insert_arc(graph, 'C', 'B');
	g_insert_arc(graph, 'C', 'D');
	g_insert_arc(graph, 'C', 'E');
	g_insert_arc(graph, 'D', 'C');
	g_insert_arc(graph, 'D', 'E');
	g_insert_arc(graph, 'E', 'B');
	g_insert_arc(graph, 'E', 'C');
	g_insert_arc(graph, 'E', 'D');
	g_insert_arc(graph, 'E', 'F');
	
	printf("\nGraph's Arc:\n");
	print_arc_all(graph);
	printf("\n");

	return 0;
}