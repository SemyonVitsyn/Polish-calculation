#include "lab.h"

char *post_conversion(char* S) {
	struct Node *top = NULL;
	char *string;
	string = (char *) malloc (strlen(S) * sizeof(char));
	strcpy(string, S);
	int i;
	long int k = 0;
	for	(i = 0; i < strlen(S); i++) {
		if (S[i] == '^') {
			if (isempty(top)) {
				top = push(top, S[i]);
			} else {
				while (!isempty(top)) {
					if (top -> elem == '^') {
						string[k] = top -> elem;
						k++;
						top = pop(top);
					} else break;
				}
				top = push(top, S[i]);
			}
		}	else if (S[i] == '*' || S[i] == '/') {
			if (isempty(top)) {
				top = push(top, S[i]);
			} else {
				while (!isempty(top)) {
					if (top -> elem == '^' || top -> elem == '*' || top -> elem == '/') {
						string[k] = top -> elem;
						k++;
						top = pop(top);
					}	else
							break;
					
				}
				top = push(top, S[i]);
			}
		}	else if (S[i] == '+' || S[i] == '-') {
			if (isempty(top)) {
				top = push(top, S[i]);
			} else {
				while (!isempty(top)) {
					if (top -> elem == '^' || top -> elem == '*' || top -> elem == '/' || top -> elem == '-' || top -> elem == '+') {
						string[k] = top -> elem;
						k++;
						top = pop(top);
					}	else
							break;
					
				}
				top = push(top, S[i]);
				
			}
		}	else if (S[i] == '(') {
				top = push(top, S[i]);
		}	else if (S[i] == ')') {
				while (top -> elem != '(') {
					string[k] = top -> elem;
					k++;
					top = pop(top);
				}
				top = pop(top);
		}	else {
				string[k] = S[i];
				k++;
				//printf("%c\n", S[i]);
		}
	}
	while (!isempty(top)) {
		string[k] = top -> elem;
		k++;
		top = pop(top);
	}
	strcpy(string + k, "");
	return string;
}
