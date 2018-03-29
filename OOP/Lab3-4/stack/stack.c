#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

Operation *createOperation(Country *p, Country *c, char *operationType) {
  Operation *o = (Operation *)malloc(sizeof(Operation));
  o->country = copyCountry(p);
  if (c != NULL)
    o->countryUpdate = copyCountry(c);
  else
    o->countryUpdate = NULL;
  if (operationType != NULL) {
    o->operationType =
        (char *)malloc(sizeof(char) * (strlen(operationType) + 1));
    strcpy(o->operationType, operationType);
  } else
    o->operationType = NULL;

  return o;
}

void destroyOperation(Operation *o) {
  if (o == NULL)
    return;

  // first destroy the Country
  destroyCountry(o->country);
  if (o->countryUpdate != NULL)
    destroyCountry(o->countryUpdate);
  // then the operationType
  free(o->operationType);
  // then free the operation
  free(o);
}

Operation *copyOperation(Operation *o) {
  if (o == NULL)
    return NULL;

  Operation *newOp =
      createOperation(o->country, o->countryUpdate, o->operationType);
  return newOp;
}

char *getOperationType(Operation *o) { return o->operationType; }

Country *getCountryStack(Operation *o) { return o->country; }
Country *getCountryStackUpdate(Operation *o) { return o->countryUpdate; }

// ---------------------------------------------------------------

OperationsStack *createStack() {
  OperationsStack *s = (OperationsStack *)malloc(sizeof(OperationsStack));
  s->length = 0;

  return s;
}

void destroyStack(OperationsStack *s) {
  if (s == NULL)
    return;

  // first deallocate memory of operations (this is allocated when a new
  // operation is pushed onto the stack)
  for (int i = 0; i < s->length; i++)
    destroyOperation(s->operations[i]);

  // then free the stack
  free(s);
}

void push(OperationsStack *s, Operation *o) {
  if (isFull(s))
    return;

  s->operations[s->length++] =
      copyOperation(o); // copies of operations are added, such that the stask
                        // manages its own operations
}

Operation *pop(OperationsStack *s) {
  if (isEmpty(s))
    return NULL;
  s->length--;
  return s->operations[s->length];
}

int isEmpty(OperationsStack *s) { return (s->length == 0); }

int isFull(OperationsStack *s) { return s->length == 100; }

// Tests
void testsStack() {
  OperationsStack *s = createStack();

  Country *p1 = createCountry("Romania", "Europa", 19);
  Country *p2 = createCountry("Ghana", "Africa", 30);
  Operation *o1 = createOperation(p1, NULL, "add");
  Operation *o2 = createOperation(p2, p1, "add");
  Operation *o3 = createOperation(p1, NULL, "remove");

  // the Countrys may be destroyed, as the operations contain copies of these
  // Countrys
  destroyCountry(p1);
  destroyCountry(p2);

  push(s, o1);
  push(s, o2);
  push(s, o3);

  // the operations may be destroyed, as the stack contains copies of these
  // operations
  destroyOperation(o1);
  destroyOperation(o2);
  destroyOperation(o3);

  assert(isFull(s) == 0);
  assert(isEmpty(s) == 0);
  Operation *o = pop(s);
  assert(strcmp(o->operationType, "remove") == 0);
  // after each pop, the operations must be destroyed
  destroyOperation(o);

  o = pop(s);
  assert(strcmp(o->operationType, "add") == 0);
  destroyOperation(o);

  o = pop(s);
  assert(strcmp(o->operationType, "add") == 0);
  destroyOperation(o);

  assert(isEmpty(s) == 1);

  // destroy the stack
  destroyStack(s);
}
