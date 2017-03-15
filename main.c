#include <stdio.h>
#include "IntVector.h"

int main()
{
	IntVector *p = int_vector_new(2);
	int j, k = 0, i = 0;
	int index, item = 0, ent;
	int new_s, new_c;
	
	while (k != 1) {

		printf("Vector operetion\n");
		MprintM(p);

		printf("Enter option:\n");
		printf("(1) <-- Add item\n");
		printf("(2) <-- Get item\n");
		printf("(3) <-- Set item\n");
		printf("(4) <-- Push back\n");
		printf("(5) <-- Pop back\n");
		printf("(6) <-- Shrink to fit\n");
		printf("(7) <-- Resize\n");
		printf("(8) <-- Reserve\n");
		printf("(9) <-- Exit\n");
		printf("\n");
		
		printf("()--> ");
		scanf("%d", &j);

		switch(j) {
			case 1:
			{
				scanf("%d", &item);
				add_item(p, item);
			}
			break;
			case 2:
			{
				scanf("%d", &index);
				ent = int_vector_get_item(p, index);
				printf("%d", ent);
			}
			break;
			case 3:
			{
				scanf("%d%d", &index, &item);
				int_vector_set_item(p, index, item);
			}
			break;
			case 4:
			{
				scanf("%d", &item);
				ent = int_vector_push_back(p, item);
			}
			break;
			case 5:
			{
				int_vector_pop_back(p);
			}
			break;
			case 6:
			{
				ent = int_vector_shrink_to_fit(p);
			}
			break;
			case 7:
			{
				scanf("%d", &new_s);
				ent = int_vector_resize(p, new_s);
			}
			break;
			case 8:
			{
				scanf("%d", &new_c);
				ent = int_vector_reserve(p, new_c);
			}
			break;
			case 9:
			{
				k = 1;
			}
			break;
			default:
				printf("There is no such option!\n");
		}
		printf("\n");
	}

	int_vector_free(p);

	return 0;
}