#pragma once
#include "../Array/array.h"
#include "../domain/domain.h"
#include <string.h>

typedef struct {
  Country *country;
  Country *countryUpdate;
  char *operationType;
} Operation;

Operation *createOperation(Country *c, Country *c2, char *operationType);
void destroyOperation(Operation *o);
Operation *copyOperation(Operation *o);
char *getOperationType(Operation *o);
Country *getCountryStack(Operation *o);
Country *getCountryStackUpdate(Operation *o);

// ---------------------------------------------------------------
typedef struct {
  Operation *operations[100];
  int length;
} OperationsStack;

OperationsStack *createStack();
void destroyStack(OperationsStack *s);
void push(OperationsStack *s, Operation *o);
Operation *pop(OperationsStack *s);
int isEmpty(OperationsStack *s);
int isFull(OperationsStack *s);

void testsStack();
