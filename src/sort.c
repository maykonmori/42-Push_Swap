/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:54:56 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/24 18:07:29 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	if (stack->top == -1)
		return (EXIT_SUCCESS);
	while (i >= 1)
	{
		if (stack->stack[i] < stack->stack[i - 1])
			return (EXIT_FAILURE);
		i--;
	}
	return (EXIT_SUCCESS);
}

void	sort_stack(t_data *conjunct)
{
	if (conjunct->stack_a->top <= 4)
	{
		sort_short(conjunct);
	}
	// else
	// {
	// 	sort_long(stack_a, stack_b);
	// }

}

void	sort_short(t_data *conjunct)
{
	if (conjunct->stack_a->top == 1)
	{
		printf("chegou aqui\n");
		operations("sa\n", conjunct);
	}
	// else if (/* condition */)
	// {
	// 	/* code */
	// }
	// else
	// {
	// 	/* code */
	// }

}