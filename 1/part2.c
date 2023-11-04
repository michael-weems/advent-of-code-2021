#include <stdio.h>
#include <stdlib.h>

int wrapIndex(int index){
	if (index > 3){
		return index - 4; 
	}
	return index;
}
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
	int scan[4] = {-1, -1, -1, -1};
	int a_index = 0;
	int b_index = 1;
	int insert_index = 0;
	int start_comparing_index = 3;

	int index = 0;

	while ((read = getline(&line, &len, fp)) != -1) {
		int depth = atoi(line);
		scan[insert_index++] = depth;	
		
		if (index < start_comparing_index){
			index++;
			continue;
		}	
		
		if (insert_index > 3) {
			insert_index = 0;
		}
		
		int sum_a = scan[wrapIndex(a_index)] + scan[wrapIndex(a_index + 1)] + scan[wrapIndex(a_index + 2)];
		int sum_b = scan[wrapIndex(b_index)] + scan[wrapIndex(b_index + 1)] + scan[wrapIndex(b_index + 2)];

	if (index < 15){	

printf("A: %d, %d, %d, sum: %d i: %d, i+1: %d, i+2: %d\n", scan[wrapIndex(a_index)], scan[wrapIndex(a_index + 1)], scan[wrapIndex(a_index + 2)], sum_a, wrapIndex(a_index), wrapIndex(a_index+1), wrapIndex(a_index+2)); 
printf("B: %d, %d, %d, sum: %d i: %d, i+1: %d, i+2: %d\n", scan[wrapIndex(b_index)], scan[wrapIndex(b_index + 1)], scan[wrapIndex(b_index + 2)], sum_b, wrapIndex(b_index), wrapIndex(b_index+1), wrapIndex(b_index+2)); 

printf("----------------------\n");
		}
		if (sum_b > sum_a) {
			// printf("increased\n");
			count++;
		} else {
			// printf("decreased\n");
		} 	
		a_index++;
		if (a_index > 3){
			a_index = 0;
		}
		b_index++;
		if (b_index > 3){
			b_index = 0;
		}
		index++;
	}
	printf("%zu increases", count);	
	fclose(fp);
	if (line) {
		free(line);
	}
	exit(EXIT_SUCCESS);
}
