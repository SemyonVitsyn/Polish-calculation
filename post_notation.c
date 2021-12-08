#include "lab.h"

void post_notation(int N) {
	FILE *fp;
	FILE *pf;
	fp = fopen("constans_expression.txt", "r");
	pf = fopen("postfix_notation.txt", "w");
	int i = 0;
	char s[50];
//	printf("^_^\n");
	for (i = 0; i < N; i++) {
//		printf("I : %d\n", i);
		strcpy(s, "");
		fscanf(fp, "%s", s);
		strcpy(s, post_conversion(s));
		fprintf(pf, "%s\n", s);
	}
	fclose(fp);
	fclose(pf);
	return;
}
