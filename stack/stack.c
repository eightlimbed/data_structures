/**
 * stack.c - implementation of a stack using a singly-linked list
 *
 * operations:
 * create() creates a new "member" with first_name, last_name, and age attributes
 * push() pushes a member onto the stack
 * pop() removes the member on the top of the stack and returns a value
 * print() prints the state of the stack (all of it's members)
 * len() returns the number of members in the stack
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
 * push: adds a member to the stack
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

	new_member = create(stack, first_name, last_name, age);
	*stack = new_member;
}

/**
 * pop: removes a member from the top of the stack
 * @stack: pointer to the address of the top of the stack (node **)
 *
 * return: void
 */
void pop(node **stack)
{
	node *temp;

	if (stack == NULL || *stack == NULL)
		return;
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}

/**
 * len: computes the number of members in the stack
 * @stack: pointer to the top of the stack (node *)
 *
 * return: number of members (unsigned int)
 */
unsigned int len(node *stack)
{
	unsigned int count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

/**
 * print: prints the length of the stack and all of it's members' first names
 * @stack: pointer to the top of the stack (node *)
 *
 * return: void
 */
void print(node *stack)
{
	if (stack == NULL)
	{
		printf("there are no members on the stack. try push()\n------\n");
		return;
	}
	printf("there are %u member(s) in the stack:\n------\n", len(stack));
	while (stack)
	{
		printf("[%s - age %u]\n", stack->first_name, stack->age);
		stack = stack->next;
	}
}

/**
 * main: entry point used for testing
 *
 * return: 0 (success)
 */
int main(void)
{
	node *stack;

	stack = NULL;
	pop(&stack);
	print(stack);
	push(&stack, "Michael", "Jordan", 49);
	print(stack);
	push(&stack, "Sharon", "Stone", 24);
	print(stack);
	push(&stack, "Wilson", "Holiday", 30);
	print(stack);
	pop(&stack);
	print(stack);
	pop(&stack);
	print(stack);
	push(&stack, "Theo", "Huxtable", 14);
	print(stack);
	pop(&stack);
	print(stack);
	pop(&stack);
	print(stack);
	return (0);
}
