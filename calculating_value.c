#include "lab.h"

void calculating_value(){
	FILE* fp = fopen("postfix_notation.txt", "r");
	FILE* rez = fopen("rez.dat", "w");
	char str[50];
	char ch;
	int i, len;
	int a, b, c, d = 0;
	struct Node_int *top1 = NULL; 
	while (!feof(fp)){
		fscanf(fp, "%s", str);
		if (feof(fp)) break;
		len = strlen(str);
		if (str == "\n")
			break;
		for (i = 0; i < len; i++){
			ch = str[i];
			if (ch >= '0' && ch <= '9'){
				push_int(&top1, (int)ch-48);				
			}
			else if (ch == '+'){
				a = pop_int(&top1);
				b = pop_int(&top1);
				c = a + b;
				push_int(&top1, c);
			}
			else if (ch == '*'){
				a = pop_int(&top1);
				b = pop_int(&top1);
				c = a * b;
				push_int(&top1, c);
			}
			else if (ch == '-'){
				a = pop_int(&top1);
				if (!isempty_int(top1)) {
					b = pop_int(&top1);
				} else {
					b = 0;
				}
				c = b - a;
				push_int(&top1, c);
			}
			else if (ch == '/'){
				a = pop_int(&top1);
				b = pop_int(&top1);
				c = (int)(b / a);
				push_int(&top1, c);
			}
			else if (ch == '^'){
				a = pop_int(&top1);
				b = pop_int(&top1);
				c = (int)(pow(b, a));
				
				push_int(&top1, c);
			}					
		} 
		d = pop_int(&top1);
		printf("%d\n", d); 
		fprintf(rez,"%d\n", d);
	}
	fclose(fp);
}
