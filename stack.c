#include "lab.h"

struct Node* push(struct Node *top, char a)
{
	if (top == NULL)
	{
		top = (struct Node*)calloc(1, sizeof(struct Node));
		top->elem = a;
		top->next = NULL;
		return top;
	}
	else
	{
		struct Node *add;
		add = (struct Node*)calloc(1, sizeof(struct Node));
		add->elem = a;
		add->next = top;
		return add;
	}
}

struct Node* pop(struct Node *top)
{
	struct Node *new;
	new = top->next;
	free(top);
	return new;
}

bool isempty(struct Node *top)
{
	if (top == NULL)
		return true;
	else
		return false;
}

void push_int(struct Node_int **top, int a)
{
        struct Node_int *add = (struct Node_int*)calloc(1, sizeof(struct Node_int));
	add->elem = a;
	add->next = *top;
	*top = add;
}

int pop_int(struct Node_int **top)
{
	int a;
	struct Node_int *new; 
	a = (*top)->elem;
	new = (*top)->next;
	free(*top);
	*top = new;
	return a;	
}

bool isempty_int(struct Node_int *top)
{
	if (top == NULL)
		return true;
	else
		return false;
}
