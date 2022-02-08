/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:22:42 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 12:37:36 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	setting_slice_size(t_data *conjunct)
{
	conjunct->slice->size = 18;
	if (conjunct->stack_a->top >= 400)
		conjunct->slice->size = 43;
	return (conjunct->slice->size);
}

int	*set_slice(int *aux_order, int *chunks, int size, t_stack *stack)
{
	int	i;
	int	j;

	chunks = (int *)ft_calloc(sizeof(int *), size);
	i = 0;
	j = stack->top;
	while (j > -1)
	{
		if (j - size > -1)
		{
			chunks[i] = aux_order[j - size];
			i++;
			j = j - size;
		}
		else
		{
			chunks[i] = aux_order[0];
			j = -1;
		}
	}
	return (chunks);
}

void	sort_long(t_data *conjunct, t_stack *stack)
{
	int	i;

	conjunct->slice->size = setting_slice_size(conjunct);
	bubble_sort(conjunct->stack_aux->stack, conjunct->stack_aux->top);
	conjunct->slice->chunks = set_slice(conjunct->stack_aux->stack, \
	conjunct->slice->chunks, conjunct->slice->size, conjunct->stack_a);
	i = 0;
	while (!is_sorted(conjunct->stack_a) && conjunct->stack_a->top > -1)
	{
		setting_push(conjunct, stack, conjunct->slice->chunks[i]);
		i++;
	}
	sort_long_b(conjunct, stack);
	free(conjunct->slice->chunks);
}
