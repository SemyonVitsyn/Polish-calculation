#include "lab.h"

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1],"r");  
	FILE *answ;
	int n = 0;
	int d = 0;
	n = clipping_expressions(file);	
	post_notation(n);
	calculating_value();
	return 0;
}
