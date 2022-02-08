/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:33:03 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 12:58:45 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rb_or_sb(t_data *conjunct, t_stack *stack)
{
	int	top;
	int	*stack_b;

	top = conjunct->stack_b->top;
	stack_b = conjunct->stack_b->stack;
	while (conjunct->numb_higher != stack_b[top])
	{
		if ((conjunct->numb_higher != stack_b[top]) && \
		(conjunct->numb_higher != stack_b[top - 1]))
			operations("rb\n", conjunct, stack);
		else if ((conjunct->numb_higher != stack_b[top]) && \
		(conjunct->numb_higher == stack_b[top - 1]))
			operations("sb\n", conjunct, stack);
	}
}

void	sort_long_b(t_data *conjunct, t_stack *stack)
{
	int	middle;
	int	pos_higher;

	while (conjunct->stack_b->top != -1)
	{
		middle = conjunct->stack_b->top / 2;
		conjunct->numb_higher = get_higher(conjunct->stack_b);
		pos_higher = locate_higher_b(conjunct);
		if (pos_higher >= middle)
			rb_or_sb(conjunct, stack);
		else if (pos_higher < middle)
		{
			while (conjunct->numb_higher != \
			conjunct->stack_b->stack[conjunct->stack_b->top])
				operations("rrb\n", conjunct, stack);
		}
		operations("pa\n", conjunct, stack);
	}
}
