#ifndef CUSTOM_MONTY_H
#define CUSTOM_MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct custom_stack_s - Structure representing a stack item
 * @number: Integer value stored in the stack item
 * @prev_item: pointer to the previous stack item
 * @next_item: pointer to the next stack item
 *
 * Description: pointer to the next stack item
 */

typedef struct custom_stack_s
{
	int number;
	struct custom_stack_s *prev_item;
	struct custom_stack_s *next_item;
} custom_stack_t;

/**
 * struct custom_bus_s - Structure representing Monty program data
 * @argument: argument value
 * @monty_file: pointer to monty file
 * @line_content: content of the line
 * @status_flag: Flag indicating status of the program
 *
 * Description: Holds various data for monty program execution
 */

typedef struct custom_bus_s
{
	char *argument;
	FILE *monty_file;
	char *line_content;
	int status_flag;
} custom_bus_t;

/**
 * struct custom_instruction_s - Structure representing a monty instruction
 * @operation: operation/opcode of instruction
 * @function: Function to execute the instruction
 *
 * Description: Represents an instruction in the monty language
 */

typedef struct custom_instruction_s
{
	char *operation;
	void (*function)(custom_stack_t **stack, unsigned int line_num);
} custom_instruction_t;

extern custom_bus_t custom_bus;
char *custom_realloc(char *ptr, unsigned int old_size, unsigned int  new_size);
ssize_t custom_get_input(char **lineptr, int file);
char *custom_clean_line(char *content);
void custom_push(custom_stack_t **head, unsigned int value);
void custom_print_all(custom_stack_t **head, unsigned int value);
void custom_print_int(custom_stack_t **head, unsigned int value);
int custom_execute(
		char *content,
		custom_stack_t **head,
		unsigned int counter,
		FILE *file
		);
void custom_free_stack(custom_stack_t *head);
void custom_pop(custom_stack_t **head, unsigned int counter);
void custom_swap(custom_stack_t **head, unsigned int counter);
void custom_add(custom_stack_t **head, unsigned int counter);
void custom_no_op(custom_stack_t **head, unsigned int counter);
void custom_substract(custom_stack_t **head, unsigned int counter);
void custom_divide(custom_stack_t **head, unsigned int  counter);
void custom_multiply(custom_stack_t **head, unsigned int counter);
void custom_modulus(custom_stack_t **head, unsigned int counter);
void custom_print_char(custom_stack_t **head, unsigned int counter);
void custom_print_string(custom_stack_t **head, unsigned int counter);
void custom_rotate_left(custom_stack_t **head, unsigned int counter);
void custom_rotate_right(
		custom_stack_t **head,
		__attribute__((unused)) unsigned int counter
		);
void custom_add_noce(custom_stack_t **head, int value);
void custom_add_queue(custom_stack_t **head, int value);
void custom_stack(custom_stack_t **head, unsigned int counter);
void custom_queue(custom_stack_t **head, unsigned int counter);

#endif /* CUSTOM_MONTY_H */
