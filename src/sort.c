/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:54:56 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/28 22:45:53 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	if (stack->top == -1)
		return (0);
	while (i > 0)
	{
		if (stack->stack[i] > stack->stack[i - 1])
			return (0);
		else
			i--;
	}
	printf("saio do while do is_sorted\n");
	return (1);
}

int	is_sortedb(t_stack *stack)
{
	int	i;

	i = stack->top;
	if (stack->top == -1)
		return (0);
	while (i > 0)
	{
		if (stack->stack[i] < stack->stack[i - 1])
			return (0);
		else
			i--;
	}
	printf("saio do while do is_sortedb\n");
	return (1);
}

static void sort_short_b(t_data *conjunct)
{
	while (1)
	{
		if(is_sortedb)
		{
			while (conjunct->stack_b->top != -1)
				operations("pa\n", conjunct);
			break ;
		}
		if (conjunct->stack_b->stack[conjunct->stack_b->top] == conjunct->numb_lower)
			operations("rb\n", conjunct);
		else if (conjunct->stack_b->stack[0] == conjunct->numb_lower)
			operations("rrb\n", conjunct);
		else if (conjunct->stack_b->stack[conjunct->stack_b->top] < conjunct->stack_b->stack[conjunct->stack_b->top - 1])
			operations("sb\n", conjunct);
		else
			operations("rb\n", conjunct);
	}

}


static void	sort_short(t_data *conjunct)
{
	while(1)
	{
		if(is_sorted(conjunct->stack_a))
		{
			if(!is_sortedb(conjunct->stack_b) && conjunct->stack_b->top == -1)
				break;
			else
				sort_short_b(conjunct);
		}
		else if (conjunct->stack_a->stack[conjunct->stack_a->top] == \
		conjunct->num_higher && conjunct->stack_a->top > 1)
			operations("ra\n", conjunct);
		else if (conjunct->stack_a->stack[conjunct->stack_a->top] > conjunct->stack_a->stack[conjunct->stack_a->top - 1] && conjunct->stack_b->stack[conjunct->stack_b->top] < conjunct->stack_b->stack[conjunct->stack_b->top - 1] && conjunct->stack_b->stack[conjunct->stack_b->top] != conjunct->numb_higher)
			operations("ss\n", conjunct);
		else if (conjunct->stack_a->stack[conjunct->stack_a->top] > conjunct->stack_a->stack[conjunct->stack_a->top - 1])
			operations("sa\n", conjunct);
		else if (conjunct->stack_a->stack[conjunct->stack_a->top] != conjunct->num_lower || conjunct->stack_a->stack[conjunct->stack_a->top]!= conjunct->num_higher)
			operations("pb\n", conjunct);
		else
			operations("rr\n", conjunct);
	}
}

void	sort_stack(t_data *conjunct)
{
	if (conjunct->stack_a->top <= 9)
	{
		sort_short(conjunct);
	}
	// else
	// {
	// 	sort_long(stack_a, stack_b);
	// }

}