#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("./input", "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}
	
	size_t count = 0;
	int previous = -1;
	while ((read = getline(&line, &len, fp)) != -1) {
		int depth = atoi(line);
		if (previous == -1){
			previous = depth;
			continue;
		}	
		
		if (depth > previous){
			count++;
		}
		previous = depth;
	}
	printf("%zu increases", count);	
	fclose(fp);
	if (line) {
		free(line);
	}
	exit(EXIT_SUCCESS);
}
