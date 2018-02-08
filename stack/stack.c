/**
 * stack.c - implementation of a stack using a singly-linked list
 *
 * operations:
 * create() creates a new "member" with first_name, last_name, and age attributes
 * push() pushes a member onto the stack
 * pop() removes the member on the top of the stack and returns a value
 * print() prints the state of the stack (all of it's members)
 * len() returns the number of members in the stack
 * reverse() reverses the order of the stack (?)
 *
 * author: lee gaines (@eightlimbed) - feb 7, 2018
 */

#include <stdio.h>
#include <stdlib.h>

/* each member will have first_name, last_name, and age attributes */
typedef struct node {
	char *first_name;
	char *last_name;
	unsigned int age;
	struct node *next;
} node;

/**
 * create: creates a new member of the list
 * @stack: pointer to address of the top of the stack (node **)
 * @first_name: first name (char *)
 * @last_name: last name (char *)
 * @age: age (unsigned int)
 *
 * return: a pointer to the node struct, or NULL if malloc() fails
 */
node *create(node **stack, char *first_name, char *last_name, unsigned int age)
{
	node *member;

	member = malloc(sizeof(node));
	if (member == NULL)
		return NULL;
	member->first_name = first_name;
	member->last_name = last_name;
	member->age = age;
	if (*stack)
		member->next = *stack;
	else
		member->next = NULL;
	return (member);
}

/**
 * push: adds a member to the stack and prints a message
 * @stack: pointer to address of the top of the stack (node **)
 * @first_name: first name attribute (char *)
 * @last_name: last name attribute (char *)
 * @age: age attribute (unsigned int)
 *
 * return: void
 */
void push(node **stack, char *first_name, char *last_name, unsigned int age)
{
	node *new_member;

	printf("adding %s to the stack\n", first_name);
	new_member = create(stack, first_name, last_name, age);
	*stack = new_member;
}

/**
 * pop: removes a member from the top of the stack and prints a message
 * @stack: pointer to the address of the top of the stack (node **)
 *
 * return: void
 */
void pop(node **stack)
{
	node *temp;

	if (stack == NULL || *stack == NULL)
		return;
	printf("removing %s from the stack\n", (*stack)->first_name);
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}

int main(void)
{
	node *stack;

	stack = NULL;
	push(&stack, "Derrick", "Gaines", 32);
	push(&stack, "Sally", "Henderson", 24);
	push(&stack, "Lee", "Gaines", 30);
	pop(&stack);
	pop(&stack);
	push(&stack, "Theo", "Huxtable", 14);
	pop(&stack);
	pop(&stack);
	return (0);
}
