/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:06:37 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 12:25:11 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_data *conjunct, t_stack *stack)
{
	if (conjunct->stack_a->top <= 9)
		sort_short(conjunct, stack);
	else
		sort_long(conjunct, stack);
}

void	push_swap(t_data *conjunct, t_stack *stack)
{
	if (!is_sorted(conjunct->stack_a))
		sort_stack(conjunct, stack);
}

int	main(int argc, char **argv)
{
	t_data	*conjunct;
	t_stack	*stack;

	if (argc < 3)
		return (1);
	argv = &argv[1];
	argc--;
	if (args_validation(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	conjunct = (t_data *)ft_calloc(sizeof(t_data), 1);
	stack = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	init(argc, argv, conjunct, stack);
	push_swap(conjunct, stack);
	write(1, conjunct->res_step, ft_strlen(conjunct->res_step));
	free_all(conjunct, stack, EXIT_SUCCESS);
}
