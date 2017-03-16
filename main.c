#include <stdio.h>
#include "IntVector.h"

int main()
{
	IntVector *p = int_vector_new(0);
	IntVector *w = NULL;
	int j, k = 0, i = 0, e;
	int index, item = 0, ent;
	int new_s, new_c;
	
	while (k != 1) {

		printf("Vector operetion\n");
		MprintM(p);
		if (i == 1) {
			MprintM(w);
		}

		printf("Enter option:\n");
		printf("(1) <-- Add item\n");
		printf("(2) <-- Get item\n");
		printf("(3) <-- Set item\n");
		printf("(4) <-- Push back\n");
		printf("(5) <-- Pop back\n");
		printf("(6) <-- Shrink to fit\n");
		printf("(7) <-- Resize\n");
		printf("(8) <-- Reserve\n");
		if (i == 0) {
			printf("(9) <-- Vector copy\n");
		} else {
			printf("(9) <-- Vector delete\n");
		}
		printf("(0) <-- Exit\n");
		printf("\n");
		
		printf("()--> ");
		scanf("%d", &j);

		if (j == 9 && i == 1) {
			j = 10;
		}

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
				if (ent == -1) {
					printf("Failed to allocate memory!");
				}
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
				if (ent == -1) {
					printf("Failed to allocate memory!");
				}

			}
			break;
			case 7:
			{
				scanf("%d", &new_s);
				ent = int_vector_resize(p, new_s);
				if (ent == -1) {
					printf("Failed to allocate memory!");
				}
			}
			break;
			case 8:
			{
				scanf("%d", &new_c);
				ent = int_vector_reserve(p, new_c);
				if (ent == -1) {
					printf("Failed to allocate memory!");
				}
			}
			break;
			case 9:
			{
				w = int_vector_copy(p);
				if (ent == -1) {
					printf("Failed to allocate memory!");
				} else {
					i = 1;
					for (e = 0; e < p -> size; ++e) {
						w -> data[e] = p -> data[e];
					}
				}
			}
			break;
			case 10:
			{
				int_vector_free(w);
				i = 0;
			}
			break;
			case 0:
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