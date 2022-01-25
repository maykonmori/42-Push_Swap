/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:06:37 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/25 18:49:59 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *conjunct)
{
	if (!is_sorted(conjunct->stack_a))
		sort_stack(conjunct);
}

void	*init(int argc, char **argv, t_data *conjunct, t_stack *stack)
{

	conjunct->index = 0;
	conjunct->steps = 0;
	conjunct->res_step = NULL;
	conjunct->size = argc - 1;
	stack->stack = (int *)ft_calloc(sizeof(int), (conjunct->size + 1));
	conjunct->stack_a = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	conjunct->stack_a->stack = (int *)ft_calloc(sizeof(int), (conjunct->size + 1));
	conjunct->stack_a->top = -1;
	conjunct->stack_b = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	conjunct->stack_b->stack = (int *)ft_calloc(sizeof(int), (conjunct->size + 1));
	conjunct->stack_b->top = -1;
	conjunct->stack_a->stack = atribute_stack(conjunct, conjunct->stack_a, argv);
	conjunct->num_lower = get_lower(conjunct->stack_a);
	conjunct->num_higher = get_higher(conjunct->stack_a);
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
	conjunct = (t_data *)ft_calloc(sizeof(t_data), 1);
	stack = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	init(argc, argv, conjunct, stack);

	int	i;
	i = conjunct->stack_a->top;
	while (i > -1)
	{
		printf("i = %d, a =%d\n", i, conjunct->stack_a->stack[i]);
		i--;
	}
	i = conjunct->stack_b->top;
	while (i > -1)
	{
		printf("i = %d, b =%d\n", i, conjunct->stack_b->stack[i]);
		i--;
	}
	printf("\n");

	// push_swap(conjunct);
	printf("top %d\n", conjunct);
	if (conjunct->stack_a->stack[conjunct->stack_a->top] == conjunct->num_higher)
		{
			operations("ra\n", conjunct);
		}
	// rotate(conjunct->stack_a);


	i = conjunct->stack_a->top;
	while (i > -1)
	{
		printf("i = %d, a =%d\n", i, conjunct->stack_a->stack[i] );
		i--;
	}
	i = conjunct->stack_b->top;
	while (i > -1)
	{
		printf("i = %d, b =%d\n", i, conjunct->stack_b->stack[i]);
		i--;
	}
	printf("\n");



	// push(conjunct->stack_b, conjunct->stack_a);

	// i = conjunct->stack_a->top;
	// while (i > -1)
	// {
	// 	printf("i = %d, a =%d\n", i, conjunct->stack_a->stack[i] );
	// 	i--;
	// }
	// i = conjunct->stack_b->top;
	// while (i > -1)
	// {
	// 	printf("i = %d, b =%d\n", i, conjunct->stack_b->stack[i]);
	// 	i--;
	// }
	// printf("\n");
	// return (0);
	// free_all(conjunct, EXIT_SUCCESS);
}