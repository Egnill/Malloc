#include <stdio.h>
#include "IntVector.h"

int main()
{
	IntVector *p = int_vector_new(10);
	int i, j, k;

	p -> size = int_vector_get_size(p);
	
		int_vector_set_item(p, 5, 25);
	
	for (i = 0; i < 10; ++i) {
		printf("%d ", p -> data[i]);
	}
	printf("\n");
	
	int_vector_free(p);

	free(p);
	p = 0;
	
	return 0;
}