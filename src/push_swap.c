/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:06:37 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/24 12:35:55 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*init(int argc, char **argv, t_data *conjunct, t_stack *stack)
{

	conjunct->index = 0;
	conjunct->steps = 0;
	conjunct->res_step = NULL;
	conjunct->size = argc - 1;
	stack->stack = (int *)malloc(sizeof(int) * (conjunct->size + 1));
	stack->top = 0;
	conjunct->stack_a = (t_stack *)malloc(sizeof(t_stack));
	conjunct->stack_a->stack = (int *)malloc(sizeof(int) * (conjunct->size + 1));
	conjunct->stack_b = (t_stack *)malloc(sizeof(t_stack));
	conjunct->stack_b->stack = (int *)malloc(sizeof(int) * (conjunct->size + 1));
	conjunct->stack_a->stack = atribute_stack(conjunct, conjunct->stack_a, argv);
	conjunct->num_lower = get_lower(conjunct->stack_a->stack, conjunct);
	conjunct->num_higher = get_higher(conjunct->stack_a->stack, conjunct);
	return (conjunct);
}

int main(int argc, char **argv)
{
	t_data *conjunct;
	t_stack *stack;

	if (argc < 3)
		return(1);
	argv = &argv[1];
	argc--;
	if (args_validation(argc, argv))
	{
		write(2, "\033[31mERROR \e[0m\n", 17);
		return(1);
	}
	conjunct = (t_data *)malloc(sizeof(t_data));
	stack = (t_stack *)malloc(sizeof(t_stack));
	init(argc, argv, conjunct, stack);
	int	i;
	i = conjunct->size;
	while (i >= 0)
	{
		printf("i = %d, a =%d \t b =%d\n", i, conjunct->stack_a->stack[i], conjunct->stack_b->stack[i]);
		i--;
	}
	printf("\n");

	push(conjunct->stack_a, conjunct->stack_b);
	push(conjunct->stack_a, conjunct->stack_b);
	// push(conjunct->stack_a, conjunct->stack_b);
	// push(conjunct->stack_a, conjunct->stack_b);
	// push(conjunct->stack_a, conjunct->stack_b);
	// push(conjunct->stack_b, conjunct->stack_a);
	// push(conjunct->stack_b, conjunct->stack_a);
	// push(conjunct->stack_b, conjunct->stack_a);

	i = conjunct->stack_a->top;
	printf("%d\n", i);
	while (i > 0)
	{
		printf("i = %d, a =%d \t b =%d\n", i, conjunct->stack_a->stack[i - 1], conjunct->stack_b->stack[i - 1]);
		i--;
	}

	push(conjunct->stack_b, conjunct->stack_a);

	i = conjunct->stack_b->top;
	printf("%d\n", i);
	while (i > 0)
	{
		printf("i = %d, a =%d \t b =%d\n", i, conjunct->stack_a->stack[i - 1], conjunct->stack_b->stack[i - 1]);
		i--;
	}
	return (0);
}