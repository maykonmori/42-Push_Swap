/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:34:43 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 13:23:08 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	after_push(t_data *conjunct, t_stack *stack)
{
	int	top_a;
	int	top_b;
	int	*stack_a;
	int	*stack_b;

	top_a = conjunct->stack_a->top;
	top_b = conjunct->stack_b->top;
	stack_a = conjunct->stack_a->stack;
	stack_b = conjunct->stack_b->stack;
	if ((top_b > 1) && (top_a > 1) && (stack_b[top_b] < stack_b[top_b - 1]) && \
	(stack_a[top_a] > stack_a[top_a - 1]))
		operations("ss\n", conjunct, stack);
	else if ((top_b > 1) && (stack_b[top_b] < stack_b[top_b - 1]))
		operations("sb\n", conjunct, stack);
}

static void	rra_or_nothing(t_data *conjunct, t_stack *stack, int next_number)
{
	int	i;
	int	top;
	int	*stack_b;

	i = next_number + 1;
	top = conjunct->stack_b->top;
	stack_b = conjunct->stack_b->stack;
	while (i > 0)
	{
		conjunct->numb_higher = get_higher(conjunct->stack_b);
		if ((conjunct->numb_higher != stack_b[top]))
			operations("rrr\n", conjunct, stack);
		else
			operations("rra\n", conjunct, stack);
		i--;
	}
}

static void	ra_or_sa(t_data *conjunct, t_stack *stack, int next_number)
{
	int	i;
	int	top;
	int	*stack_a;
	int	top_b;
	int	*stack_b;

	top = conjunct->stack_a->top;
	stack_a = conjunct->stack_a->stack;
	top_b = conjunct->stack_b->top;
	stack_b = conjunct->stack_b->stack;
	i = top - next_number;
	while (i > 0)
	{
		conjunct->numb_higher = get_higher(conjunct->stack_b);
		if ((i > 1) && (stack_a[top] > stack_a[top - 1]))
			operations("sa\n", conjunct, stack);
		if ((conjunct->numb_higher != stack_b[top_b]))
			operations("rr\n", conjunct, stack);
		else
			operations("ra\n", conjunct, stack);
		i--;
	}
}

static void	send_push(t_data *conjunct, t_stack *stack, int higher)
{
	int	middle;
	int	next_up;
	int	next_down;

	middle = conjunct->stack_a->top / 2;
	next_up = locate_next_up(conjunct, higher);
	next_down = locate_next_down(conjunct, higher);
	if (con_negative(middle - next_up) >= con_negative(middle - next_down))
	{
		if (middle - next_up <= 0)
			ra_or_sa(conjunct, stack, next_up);
		else
			rra_or_nothing(conjunct, stack, next_up);
		operations("pb\n", conjunct, stack);
		after_push(conjunct, stack);
	}
	else
	{
		if (middle - next_down <= 0)
			ra_or_sa(conjunct, stack, next_down);
		else
			rra_or_nothing(conjunct, stack, next_down);
		operations("pb\n", conjunct, stack);
		after_push(conjunct, stack);
	}
}

void	setting_push(t_data *conjunct, t_stack *stack, int higher)
{
	int	loop;

	if (higher == conjunct->slice->chunks[0])
		loop = conjunct->slice->size;
	else
		loop = conjunct->slice->size - 1;
	while (loop > -1)
	{
		send_push(conjunct, stack, higher);
		if (conjunct->stack_a->top == -1)
			loop = -1;
		loop--;
	}
}
