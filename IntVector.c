#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity)
{
	IntVector *o = malloc(sizeof(IntVector));
	o -> data = calloc(initial_capacity, initial_capacity * sizeof(int));
	o -> size = 0;
	o -> capacity = initial_capacity;
	return o;
} //Создаёт массив нулевого размера

IntVector *int_vector_copy(const IntVector *v)
{
	IntVector *o = malloc(sizeof(IntVector));
	o -> data = malloc(v -> capacity * sizeof(int));
	memcpy(o -> data, v -> data, sizeof(v -> capacity));
	o -> size = v -> size;
	o -> capacity = v -> capacity;
	return o;
} //Указатель на копию вектора v

void int_vector_free(IntVector *v)
{
	free(v -> data);
	v -> data = 0;
} //Освобождает память, выделенную на вектор v

int int_vector_get_item(const IntVector *v, size_t index)
{
	if (index > v -> capacity) {
		printf("Выход за рамки вектора!");
		return 0;
	} else {
		int q = v -> data[index - 1];
		return q;
	}
} //Элемент под номером index

void int_vector_set_item(IntVector *v, size_t index, int item)
{
	if (index > v -> capacity) {
		printf("Выход за рамки вектора!");
	} else {
		v -> data[index - 1] = item;
		v -> size = index;
	}
} //Присваивает элементу под index значеник item

size_t int_vector_get_size(const IntVector *v)
{
	return v -> size;
} //Размер вектора

size_t int_vector_get_capacity(const IntVector *v)
{
	return v -> capacity;
} //Ёмкость вектора

int int_vector_push_back(IntVector *v, int item)
{
	if (v -> capacity == v -> size) {
		v -> capacity = (v -> capacity) * 2;
		v -> data = realloc(v -> data, v -> capacity * sizeof(int));
		v -> size = (v -> size) + 1;
		v -> data[(v -> size) - 1] = item;
	} else {
		v -> data[v -> size] = item;
		v -> size = (v -> size) + 1;
	}

	if (v -> data == NULL) {
		return -1;
	} else {
		return 0;
	}
} //Добовляет элемент в конец массива

void int_vector_pop_back(IntVector *v)
{
	if (v -> size == 0) {
		printf("Действие не имеет смысла!");
	} else {
		v -> data[(v -> size) - 1] = 0;
		v -> size = (v -> size) - 1;
	}
} //Удаляет последний элемент из массива

int int_vector_shrink_to_fit(IntVector *v)
{
	v -> data = realloc(v -> data, (v -> size) * sizeof(int));
	if (v -> data == NULL) {
		return -1;
	} else {
		v -> capacity = v -> size;
		return 0;
	}
} //Уменьшает ёмкость массива до его размера

int int_vector_resize(IntVector *v, size_t new_size)
{
	int i = 0, k;
	if (new_size > v -> capacity) {
		v -> data = realloc(v -> data, new_size * sizeof(int));
		if (v -> data == NULL) {
			i = 1;
		} else {
			for (k = (v -> size); k < new_size; ++k) {
				v -> data[k] = 0;
			}
			v -> size = new_size;
			v -> capacity = new_size;
		}
	}

	if (i == 1) {
		return -1;
	} else {
		return 0;
	}
} //Изменяет размер массива

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
	int i = 0;
	if (new_capacity > v -> capacity) {
		v -> data = realloc(v -> data, new_capacity * sizeof(int));
		if (v -> data == NULL) {
			 i = 1;
		}
	}
	if (i == 1) {
		return -1;
	} else {
		v -> capacity = new_capacity;
		return 0;
	}
} //Изменяет ёмкость массива

void add_item(IntVector *v, size_t item)
{
	if (v -> size >= v -> capacity) {
		printf("Addition not possible!");
	} else {
		v -> data[v -> size] = item;
		(v -> size) += 1;
	}
}

void MprintM(const IntVector *v)
{
	int i, j;

	printf("+");
	for (i = 0; i < v -> capacity; ++i) {
		j = v -> data[i];
		
		if (j == 0) {
			j = 1;
		}

		while (j != 0) {
			printf("-");
			j /= 10;
		}
		printf("+");
	}
	printf("\n");

	printf("|");
	for (i = 0; i < v -> capacity; ++i) {
		if (v -> size > 0 && i <= (v -> size) - 1) {
			printf("%d|", v -> data[i]);
		} else {
			printf(" |");
		}
	}
	printf("\n");

	printf("+");
	for (i = 0; i < v -> capacity; ++i) {
		j = v -> data[i];
		
		if (j == 0) {
			j = 1;
		}

		while (j != 0) {
			printf("-");
			j /= 10;
		}
		printf("+");
	}
	printf("\n");

	printf("Size: %d\n", v -> size);
	printf("Capacity: %d\n", v -> capacity);
	printf("\n");
} //Вывод вектора