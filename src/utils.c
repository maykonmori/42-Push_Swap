/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:08:09 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/25 16:17:12 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_misdigit(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (TRUE);
	return (FALSE);
}

long	ft_matoi(const char *str)
{
	long int	resu;
	long int	sign;
	long int	cont;

	resu = 0;
	sign = 1;
	cont = 0;
	while ((str[cont] >= '\t' && str[cont] <= '\r') || str[cont] == ' ')
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			sign *= -1;
		cont++;
	}
	while (ft_isdigit(str[cont]))
	{
		resu = (resu * 10) + (str[cont] - '0');
		cont++;
	}
	return (sign * resu);
}

// int	stack_size(int *stack)
// {
// 	int	i;

// 	i = 0;
// 	while (stack[i])
// 		i++;
// 	return (i);
// }

void	free_all(t_data *data, int error)
{
	free(data->stack_a);
	free(data->stack_b);
	free(data);
	if (error == EXIT_FAILURE)
		exit(1);
	exit(0);
}

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

// int	get_lower(int *stack)
// {
// 	int	i;
// 	int	aux;

// 	i = 0;
// 	printf("size do get lower: %i\n\n", i);
// 	aux = stack[i];
// 	while (stack[i])
// 	{
// 		printf("stack[i]: %i\n\n", stack[i]);
// 		if (stack[i] < aux)
// 			aux = stack[i];
// 		++i;
// 	}
// 	return (aux);
// }

int	*atribute_stack(t_data *conjunct, t_stack *stack, char **argv)
{
	int	i;
	int	size;

	size = conjunct->size;
	i = 0;
	while (size >= 0)
	{
		stack->stack[size] = ft_atoi(argv[i]);
		size--;
		stack->top++;
		i++;
	}
	return (stack->stack);
}