/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:03:43 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 12:03:13 by mjose-ye         ###   ########.fr       */
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
	return (1);
}

int	is_number(int argc, char **argv)
{
	int	index;

	index = argc - 1;
	while (index > -1)
	{
		if (!ft_misdigit(*argv[index]))
			return (TRUE);
		index--;
	}
	return (FALSE);
}

int	is_duplicate(int argc, char **argv)
{
	int	index;
	int	position;

	index = argc - 1;
	position = index - 1;
	while (index > -1)
	{
		while (position > -1)
		{
			if (ft_atoi(argv[index]) == ft_atoi(argv[position]))
				return (TRUE);
			position--;
		}
		index--;
		position = index - 1;
	}
	return (FALSE);
}

int	is_integer(int argc, char **argv)
{
	long int	num;
	int			position;

	position = argc - 1;
	while (position > -1)
	{
		num = ft_matoi(argv[position]);
		if (num < INT_MIN || num > INT_MAX)
		{
			return (TRUE);
		}
		position--;
	}
	return (FALSE);
}

int	args_validation(int argc, char **argv)
{
	if (is_number(argc, argv) && is_duplicate(argc, argv) \
	&& is_integer(argc, argv))
		return (TRUE);
	return (FALSE);
}
