#include "../Array/array.h"
#include <stdlib.h>

Arrays* createArrays(int capacity)
{
	Arrays* arr = (Arrays*)malloc(sizeof(Arrays));
	// make sure that the space was allocated
	if (arr == NULL)
		return NULL;

	arr->capacity = capacity;
	arr->length = 0;

	// allocate space for the elements
	arr->elems = (Element*)malloc(capacity * sizeof(Element));
	if (arr->elems == NULL)
		return NULL;

	return arr;
}

void destroy(Arrays* arr)
{
	if (arr == NULL)
		return;

	// considering that the dynamic array takes responsibility of all the elements, it will have to deallocate the memory for these
	for (int i = 0; i < arr->length; i++)
		destroyCountry(arr->elems[i]);
	// !!! The function destroyPlanet is called here, so it is assumed that we know that the array contains pointers: Planet*
	// For a more generic implementation, please see the project Seminar1_Version4

	// free the space allocated for the elements
	free(arr->elems);
	arr->elems = NULL;

	// free the space allocated for the dynamic array
	free(arr);
	arr = NULL;
}

// Resizes the array, allocating more space.
// If more space cannot be allocated, returns -1, else it returns 0.
int resize(Arrays* arr)
{
	if (arr == NULL)
		return -1;
	arr->capacity *= 2;
	Element* aux = (Element*)malloc(arr->capacity * sizeof(Element));
	if (aux == NULL)
		return -1;
	for (int i = 0; i < arr->length; i++)
		aux[i] = arr->elems[i];
	free(arr->elems);
	arr->elems = aux;
	return 0;
}

void addToArray(Arrays* arr, Element t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length++] = t;
}

void delete(Arrays* arr, int pos)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	if (pos < 0 || pos >= arr->length)
		return;

	for (int i = pos; i < arr->length - 1; i++)
		arr->elems[i] = arr->elems[i + 1];
	arr->length--;
}

int getLength(Arrays* arr)
{
	if (arr == NULL)
		return -1;
	return arr->length;
}

Element getCountry(Arrays* arr, int pos)
{
	return arr->elems[pos];
}
