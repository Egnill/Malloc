#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity)
{
	IntVector *o = malloc(sizeof(IntVector));
	o -> data = calloc(1, initial_capacity * sizeof(int));
	o -> size = 0;
	o -> capacity = initial_capacity;
	return o;
} //Создаёт массив нулевого размера

IntVector *int_vector_copy(const IntVector *v)
{
	IntVector *o = malloc(sizeof(IntVector));
	o -> data = malloc(v -> capacity * sizeof(int));
	memcpy(o -> data, v -> data, sizeof(int_vector_get_size(v)));
	o -> size = int_vector_get_size(v);
	o -> capacity = int_vector_get_capacity(v);
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
		int q = v -> data[index];
		return q;
	}
} //Элемента под номером index

void int_vector_set_item(IntVector *v, size_t index, int item)
{
	if (index > v -> capacity) {
		printf("Выход за рамки вектора!");
	} else {
		v -> data[index] = item;
	}
} //Присваивает элементу под index значеник item

size_t int_vector_get_size(const IntVector *v)
{
	int i = 0;
	while (v -> data[i] != 0 && v -> data[i + 1]) {
		++i;
	}
		
	return i;
} //Размер вектора

size_t int_vector_get_capacity(const IntVector *v)
{
	int i = sizeof(v -> data);
	return i;
} //Ёмкость вектора

int int_vector_push_back(IntVector *v, int item)
{
	if (v -> capacity == v -> size) {
		v -> capacity = (v -> capacity) * 2;
		if (realloc(v -> data, (v -> capacity) * sizeof(int)) == 0) {
			return -1;
		} else {
			v -> size = (v -> size) + 1;
			v -> data[v -> size] = item;
			return 0;
		}
	} else {
		v -> data[(v -> size) + 1] = item;
	}
} //Добовляет элемент в конец массива

void int_vector_pop_back(IntVector *v)
{
	if (v -> size == 0) {
		printf("Действие не имеет смысла!");
	} else {
		v -> data[v -> size] = 0;
	}
} //Удаляет последний элемент из массива

int int_vector_shrink_to_fit(IntVector *v)
{
	if (realloc(v -> data, (v -> size) * sizeof(int)) == 0) {
		return -1;
	} else {
		return 0;
	}
} //Уменьшает ёмкость массива до его размера

int int_vector_resize(IntVector *v, size_t new_size)
{
	if (new_size <= v -> size) {
		printf("Для этого действия эта функция не подойдёт!");
	} else {
		if (realloc(v -> data, new_size * sizeof(int)) == 0) {
			return -1;
		} else {
			return 0;
		}
	}
} //Изменяет размер массива

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
	if (new_capacity <= v -> capacity) {
		printf("Действие не имеет смысла!");
	} else {
		if (realloc(v -> data, new_capacity * sizeof(int)) == 0) {
			return -1;
		} else {
			return 0;
		}
	}
} //Изменяет ёмкость массива