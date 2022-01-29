/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:09:54 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/28 23:07:18 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_src, t_stack *stack_dest)
{
	stack_dest->top++;
	stack_dest->stack[stack_dest->top] = stack_src->stack[stack_src->top];
	stack_src->top--;
}

void	swap(t_stack *stack)
{
	int	aux;
	int	height;

	height = stack->top;
	aux = stack->stack[height];
	stack->stack[height] = stack->stack[height - 1];
	stack->stack[height - 1] = aux;
}

void	rotate(t_stack *stack)
{
	int	aux;
	int	height;

	height = stack->top;
	if (height < 1)
		return ;
	aux = stack->stack[height];
	while (height > 0)
	{
		stack->stack[height] = stack->stack[height - 1];
		height--;
	}
	stack->stack[height] = aux;
}

void	rrotate(t_stack *stack)
{
	int	aux;
	int	height;
	int i;

	i = 0;
	height = stack->top;
	if (height < 1)
		return ;
	aux = stack->stack[0];
	while (i < height)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[height] = aux;
}
