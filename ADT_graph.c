#include "ADT_llist.h"
#include "ADT_graph.h"

int compare_vertex(void* x, void* y)
{
	VERTEX* left = (VERTEX*)x;
	VERTEX* right = (VERTEX*)y;

	return left->data - right->data;
}

void print_vertex(void* x)
{
	VERTEX* vertex = (VERTEX*)x;
	printf(" - vertex: %c\n", (char)(vertex->data));
}

int compare_arc(void* x, void* y)
{
	ARC* left = (ARC*)x;
	ARC* right = (ARC*)y;
	
	return compare_vertex(left->to_vertex, right->to_vertex);
}

void print_arc(void* x)
{
	ARC* arc = (ARC*)x;

	printf(" -> : %c\n", (char)(arc->to_vertex->data));
}

GRAPH* create_graph()
{
	GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
	graph->vertex_list = create_list(compare_vertex, print_vertex);
	return graph;
}

bool g_insert_vertex(GRAPH* graph, int data)
{
	VERTEX* new_vertex = (VERTEX*)malloc(sizeof(VERTEX));
	new_vertex->data = data;
	new_vertex->arc_list = create_list(compare_arc, print_arc);
	int vertex_loc = find_data(graph->vertex_list, new_vertex);
	if(vertex_loc != -1)
	{
		return false;
	}
	return add_node_at(graph->vertex_list, graph->vertex_list->count, new_vertex);
}

bool g_delete_vertex(GRAPH* graph, int data)
{
	VERTEX* n_vertex = (VERTEX*)malloc(sizeof(VERTEX));
	n_vertex->data = data;
	n_vertex->arc_list = create_list(compare_arc, print_arc);
	int vertex_loc = find_data(graph->vertex_list, n_vertex);
	if(vertex_loc == -1)
	{
		return false;
	}
	free(n_vertex);
	return del_node_at(graph->vertex_list, vertex_loc);
}

void print_vertex_all(GRAPH* graph)
{
	print_all(graph->vertex_list, graph->vertex_list->front);
}

bool g_insert_arc(GRAPH* graph, int from, int to)
{
	VERTEX tmp_vertex1;
	tmp_vertex1.data = from;
	tmp_vertex1.arc_list = NULL;

	int vertex_loc = find_data(graph->vertex_list, &tmp_vertex1);
	if(vertex_loc == -1)
	{
		printf("from_vertex %c: not found\n", (char)from);
		return false;
	}

	VERTEX* from_vertex = (VERTEX*)get_data_at(graph->vertex_list, vertex_loc);

	VERTEX tmp_vertex2;
	tmp_vertex2.data = to;
	tmp_vertex2.arc_list = NULL;

	vertex_loc = find_data(graph->vertex_list, &tmp_vertex2);
	if(vertex_loc == -1)
	{
		printf("to_vertex %c: not found\n", (char)to);
		return false;
	}

	VERTEX* to_vertex = (VERTEX*)get_data_at(graph->vertex_list, vertex_loc);

	ARC* new_arc = (ARC*)malloc(sizeof(ARC));
	new_arc->to_vertex = to_vertex;

	return add_node_at(from_vertex->arc_list, from_vertex->arc_list->count, new_arc);
}

void print_arc_all(GRAPH* graph)
{
	NODE* pos = graph->vertex_list->front;
	VERTEX* tmp_vertex;

	while (pos != NULL)
	{
		tmp_vertex = (VERTEX*)pos->data_ptr;
		printf("vertex: %c\n", tmp_vertex->data);
		print_all(tmp_vertex->arc_list, tmp_vertex->arc_list->front);
		pos = pos->next;
	}
}
