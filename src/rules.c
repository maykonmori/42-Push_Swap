/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:09:54 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/23 18:16:32 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:45:01 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/06 22:59:21 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_src, t_stack *stack_dest)
{
	int	src_size;
	int	dest_size;


	src_size = stack_size(stack_src->stack);
	dest_size = stack_size(stack_dest->stack);
	stack_dest->top++;
	stack_dest[dest_size] = stack_src[src_size - 1];
	stack_src->top--;
	stack_src[src_size - 1] = stack_src[src_size]; //VERIFICAAAAR DPS
}

void	swap(int *stack)
{
	int	aux;
	int	height;

	height = stack_size(stack);
	aux = stack[height - 1];
	stack[height - 1] = stack[height - 2];
	stack[height - 2] = aux;
}

void	rotate(int *stack)
{
	int	aux;
	int	height;

	height = stack_size(stack);
	if (height < 2)
		return ;
	aux = stack[height - 1];
	while (height > 0)
	{
		stack[height] = stack[height - 1];
		height--;
	}
	stack[height] = aux;
}

void	rrotate(int *stack)
{
	int	aux;
	int	height;
	int i;

	i = 0;
	height = stack_size(stack);
	if (height < 2)
		return ;
	aux = stack[0];
	while (i < height)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[height - 1] = aux;
}
