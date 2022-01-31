/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:22:42 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/31 19:32:58 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int locate_lower(t_data *conjunct)
{
	int i;

	i = conjunct->stack_a->top;

	while (conjunct->stack_a->stack[i] != conjunct->num_lower)
	{
		i--;
	}
	return(i);
}

static int locate_higher(t_data *conjunct)
{
	int i;

	i = conjunct->stack_a->top;

	while (conjunct->stack_a->stack[i] != conjunct->num_higher)
	{
		i--;
	}
	return(i);
}

static int test_negative(int c)
{
	if (c < 0)
		c = c * -1;
	return (c);
}

static void sort_long_b(t_data *conjunct, t_stack *stack)
{
	conjunct->numb_lower = get_lower(conjunct->stack_b);
	conjunct->numb_higher = get_higher(conjunct->stack_b);
	while (conjunct->stack_b->stack[0] != conjunct->numb_lower)
	{
		operations("rrb\n", conjunct, stack);
	}
	while (conjunct->stack_b->top != -1)
	{
		operations("pa\n", conjunct, stack);
		conjunct->num_lower = get_lower(conjunct->stack_a);
		conjunct->num_higher = get_higher(conjunct->stack_a);
		if (conjunct->stack_a->stack[0] != conjunct->num_higher)
		{
			operations("ra\n", conjunct, stack);
		}
	}
}

void sort_long(t_data *conjunct, t_stack * stack)
{
	int middle, pos_lower, pos_higher;
	int i;

	while(1)
	{
		conjunct->num_lower = get_lower(conjunct->stack_a);
		conjunct->num_higher = get_higher(conjunct->stack_a);
		middle = conjunct->stack_a->top / 2;
		pos_lower = locate_lower(conjunct);
		pos_higher = locate_higher(conjunct);
		if(conjunct->stack_b->top == -1 && is_sorted(conjunct->stack_a))
		{
			break;
		}
		else if (conjunct->stack_a->top == -1)
			sort_long_b(conjunct, stack);
		else if(test_negative(middle - pos_lower) >= test_negative(middle - pos_higher))
		{
			if(middle - pos_lower <= 0)
			{
				i = conjunct->stack_a->top;
				while (conjunct->stack_a->stack[i] != conjunct->num_lower)
				{
					operations("ra\n", conjunct, stack);
				}
			}
			else
			{
				i = conjunct->stack_a->top;
				while (conjunct->stack_a->stack[i] != conjunct->num_lower)
				{
					operations("rra\n", conjunct, stack);
				}
			}
			operations("pb\n", conjunct, stack);
		}
		else
		{
			if(middle - pos_higher <= 0)
			{
				i = conjunct->stack_a->top;
				while (conjunct->stack_a->stack[i] != conjunct->num_higher)
				{
					operations("ra\n", conjunct, stack);
				}
			}
			else
			{
				i = conjunct->stack_a->top;
				while (conjunct->stack_a->stack[i] != conjunct->num_higher)
				{
					operations("rra\n", conjunct, stack);
				}
			}
			operations("pb\n", conjunct, stack);
			operations("rb\n", conjunct, stack);
		}
	}
}