/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:26:30 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 12:30:50 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	locate_lower(t_data *conjunct)
{
	int	i;

	i = conjunct->stack_a->top;
	while (conjunct->stack_a->stack[i] != conjunct->num_lower)
	{
		i--;
	}
	return (i);
}

int	locate_next_down(t_data *conjunct, int higher)
{
	int	i;

	i = 0;
	while (conjunct->stack_a->stack[i] != higher)
	{
		if (conjunct->stack_a->stack[i] < higher)
			return (i);
		i++;
	}
	return (i);
}

int	locate_next_up(t_data *conjunct, int higher)
{
	int	i;

	i = conjunct->stack_a->top;
	while (conjunct->stack_a->stack[i] != higher)
	{
		if (conjunct->stack_a->stack[i] < higher)
			return (i);
		i--;
	}
	return (i);
}

int	locate_higher_b(t_data *conjunct)
{
	int	i;

	i = conjunct->stack_b->top;
	while (conjunct->stack_b->stack[i] != conjunct->numb_higher)
	{
		i--;
	}
	return (i);
}
