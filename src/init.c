/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:09:03 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 12:31:11 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*atribute_stack(t_data *conjunct, t_stack *stack, char **argv)
{
	int	i;
	int	size;

	size = conjunct->size;
	i = 0;
	while (size >= 0)
	{
		stack->stack[size] = ft_atoi(argv[i]);
		size--;
		stack->top++;
		i++;
	}
	return (stack->stack);
}

static void	init_stack(char **argv, t_data *conjunct, t_stack *stack)
{
	stack->stack = (int *)ft_calloc(sizeof(int), (conjunct->size + 1));
	conjunct->stack_a = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	conjunct->stack_a->stack = \
	(int *)ft_calloc(sizeof(int), (conjunct->size + 1));
	conjunct->stack_a->top = -1;
	conjunct->stack_b = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	conjunct->stack_b->stack = \
	(int *)ft_calloc(sizeof(int), (conjunct->size + 1));
	conjunct->stack_b->top = -1;
	conjunct->stack_aux = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	conjunct->stack_aux->stack = \
	(int *)ft_calloc(sizeof(int), (conjunct->size + 1));
	conjunct->stack_aux->top = -1;
	conjunct->stack_a->stack = \
	atribute_stack(conjunct, conjunct->stack_a, argv);
	conjunct->stack_aux->stack = \
	atribute_stack(conjunct, conjunct->stack_aux, argv);
}

void	*init(int argc, char **argv, t_data *conjunct, t_stack *stack)
{
	conjunct->index = 0;
	conjunct->steps = 0;
	conjunct->res_step = NULL;
	conjunct->size = argc - 1;
	init_stack (argv, conjunct, stack);
	conjunct->slice = (t_slice *)ft_calloc(sizeof(t_slice), 1);
	conjunct->slice->size = 0;
	conjunct->num_lower = get_lower(conjunct->stack_a);
	conjunct->num_higher = get_higher(conjunct->stack_a);
	return (conjunct);
}
