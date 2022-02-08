/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:54:56 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 12:30:34 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_short_extended(t_data *conjunct, t_stack *stack)
{
	int	pos_lower;
	int	middle;

	middle = conjunct->stack_a->top + 1 / 2;
	pos_lower = locate_lower(conjunct) + 1;
	if (pos_lower < middle)
	{
		while (conjunct->stack_a->stack[conjunct->stack_a->top] != \
		conjunct->num_lower)
			operations("rra\n", conjunct, stack);
	}
	else
	{
		while (conjunct->stack_a->stack[conjunct->stack_a->top] != \
		conjunct->num_lower)
			operations("ra\n", conjunct, stack);
	}
	operations("pb\n", conjunct, stack);
}

void	sort_short(t_data *conjunct, t_stack *stack)
{
	while (!is_sorted(conjunct->stack_a))
	{
		conjunct->num_lower = get_lower(conjunct->stack_a);
		if (conjunct->stack_a->top > 2)
			sort_short_extended(conjunct, stack);
		if (conjunct->stack_a->top <= 2)
		{
			if (conjunct->stack_a->stack[conjunct->stack_a->top] == \
			conjunct->num_higher)
				operations("ra\n", conjunct, stack);
			else if (conjunct->stack_a->stack[conjunct->stack_a->top] > \
			conjunct->stack_a->stack[conjunct->stack_a->top - 1])
				operations("sa\n", conjunct, stack);
			else
				operations("rra\n", conjunct, stack);
		}
	}
	while (conjunct->stack_b->top != -1)
		operations("pa\n", conjunct, stack);
}
