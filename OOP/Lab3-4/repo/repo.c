#include "repo.h"
#include "../domain/domain.h"
#include <stdlib.h>


Repo* createRepo(int capacity)
{
	Repo* array = (Repo*)malloc(sizeof(Repo));
	// make sure that the space was allocated
	if (array == NULL)
		return NULL;

	array->capacity = capacity;
	array->length = 0;

	// allocate space for the elements
	array->elems = (Element*)malloc(capacity * sizeof(Element));
	if (array->elems == NULL)
		return NULL;

	return array;
}

void resize(Repo* arr)
{
	if (arr == NULL)
		return;
	arr->capacity *= 2;
	Element* aux = (Element*)realloc(arr->elems, arr->capacity * sizeof(Element));
	if (aux == NULL)
		return; // array cannot be resized (TODO - return error code and check when resizing)
	arr->elems = aux;
}

void addInArray(Repo* arr, Element t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	// resize the array, if necessary
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length] = t;
	arr->length++;
}

void destroy(Repo* arr)
{
	if (arr == NULL)
		return;
	free(arr->elems);
	arr->elems = NULL;
	free(arr);
	arr = NULL;
}

void delete(Repo* arr, int pos)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	if (pos < 0 || pos >= arr->length)
		return;

	// deallocate the memory of the element on position pos
	arr->destroyElemFct(arr->elems[pos]);

	for (int i = pos; i < arr->length - 1; i++)
		arr->elems[i] = arr->elems[i + 1];

	arr->length--;
}

Element get(Repo* arr, int pos)
{
	return arr->elems[pos];
}
