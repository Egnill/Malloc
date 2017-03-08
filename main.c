#include <stdio.h>
#include "IntVector.h"

int main()
{
	IntVector *p = int_vector_new(6);
	int i, j;
	/*for (i = 0; i < 5; ++i) {
		p -> data[i] = i + 1;
	}
	p -> size = int_vector_get_size(p);*/
	int_vector_set_item(p, 7, 8);
	printf("%d\n", p -> data[4]);
	//printf("%d\n", p -> data);
	free(p);
	p = 0;
	return 0;
}