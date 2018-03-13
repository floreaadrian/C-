#include "../Array/array.h"
#include <stdlib.h>

Arrays* createArrays(int capacity)
{
	Arrays* arr = (Arrays*)malloc(sizeof(Arrays));
	// make sure that the space was allocated
	if (arr == NULL)
		return NULL;
	//we define the capacity of the array
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
	//we need to dealocate every Country from the array
	for (int i = 0; i < arr->length; i++)
		destroyCountry(arr->elems[i]);
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
	//we double the capacity of our array
	arr->capacity *= 2;
	Element* aux = (Element*)malloc(arr->capacity * sizeof(Element));
	if (aux == NULL)
		return -1;
	//by making a copy of it
	for (int i = 0; i < arr->length; i++)
		aux[i] = arr->elems[i];
	//freeing the array
	free(arr->elems);
	//then taking the bigger space
	arr->elems = aux;
	return 0;
}

void addToArray(Arrays* arr, Element t)
{
	//if we don't have an array we can't add to it
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;
	//we got to the maximum number of elements so we resize our array
	if (arr->length == arr->capacity)
		resize(arr);
	//we increase the lenght and add the element t at the end of the dynamic array
	arr->elems[arr->length++] = t;
}

void delete(Arrays* arr, int pos)
{
	//if we don't have an array we can't delete it
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;
	//if we've got an invalid position we can't do anything
	if (pos < 0 || pos >= arr->length)
		return;
	//we delete the country by overwritting all the elements starting with this Country
	//and replaced by the right one
	for (int i = pos; i < arr->length - 1; i++)
		arr->elems[i] = arr->elems[i + 1];
	//we just got rid of a country
	arr->length--;
}
//returning the lenght of a given array
int getLength(Arrays* arr)
{
	if (arr == NULL)
		return -1;
	return arr->length;
}
//returning a Country at a certain position from an array
Element getCountry(Arrays* arr, int pos)
{
	return arr->elems[pos];
}
