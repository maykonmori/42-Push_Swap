/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:21:01 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 12:21:28 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_higher(t_stack *stack)
{
	int	i;
	int	aux;

	i = stack->top;
	aux = stack->stack[i];
	while (i > -1)
	{
		if (stack->stack[i] > aux)
			aux = stack->stack[i];
		--i;
	}
	return (aux);
}

int	get_lower(t_stack *stack)
{
	int	i;
	int	aux;

	i = stack->top;
	aux = stack->stack[i];
	while (i > -1)
	{
		if (stack->stack[i] < aux)
			aux = stack->stack[i];
		--i;
	}
	return (aux);
}
