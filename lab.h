#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char elem;
    struct Node * next;
};

struct Node_int
{
    int elem;
    struct Node_int * next;
};

int clipping_expressions(FILE * file);

struct Node * push(struct Node * top, char a);
struct Node * pop(struct Node * top);
bool isempty(struct Node * top);
void push_int(struct Node_int ** top, int a);
int pop_int(struct Node_int ** top);
bool isempty_int(struct Node_int * top);
void post_notation(int N);
char * post_conversion(char * S);
void calculating_value();

