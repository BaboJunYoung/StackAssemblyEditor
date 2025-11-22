#include "Stack.h"

void init_stack(struct Stack* s) {
	s->top = -1;
}

int is_empty(struct Stack* s) {
	return (s->top == -1);
}

int is_full(struct Stack* s) {
	return (s->top == 49);
}

int push(struct Stack* s, int value) {
	if (is_full(s)) {
		return 0;
	}

	s->top++;
	s->value[s->top] = value;

	return 1;
}

int pop(struct Stack* s, int *value) {
	if (is_empty(s)) {
		return 0;
	}

	*value = s->value[s->top];
	s->top--;

	return 1;
}