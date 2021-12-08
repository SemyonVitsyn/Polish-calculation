#include "lab.h"

int clipping_expressions(FILE * file)
{
    int size = 0;
    char s;
    bool str = false;
    FILE *input = fopen("constans_expression.txt", "w");
    while(!feof(file))
    {
	s = getc(file);

	if(s == '=')
	{
            str = true;

	    continue;
	
	}

	if(s == ';' && str)
	{
            putc('\n', input);
	    str = false;
	    size++;

	    continue;
	}

	if(str)
	{
	    putc(s, input);

	    continue;
	}
    }
    fclose(input);
    fclose(file); 
    return size;
}
