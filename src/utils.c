/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:08:09 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/28 23:27:35 by mjose-ye         ###   ########.fr       */
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

void	free_all(t_data *conjunct, t_stack *stack, int error)
{
	free(stack->stack);
	free(conjunct->stack_a);
	free(conjunct->stack_b);
	free(conjunct);
	free(stack);

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

char	*insert_command(char const *s1, char const *s2)
{
	size_t	cont1;
	size_t	cont2;
	size_t	ts1;
	size_t	ts2;
	char	*dest;

	cont1 = 0;
	cont2 = 0;
	if (!s2)
		return (NULL);
	ts1 = ft_strlen(s1);
	ts2 = ft_strlen(s2);
	dest = ft_calloc((ts1 + ts2 + 1), sizeof(char));
	if (dest == 0)
		return (NULL);
	while (s1[cont1++] != '\0')
		dest[cont1 - 1] = s1[cont1 - 1];
	while (s2[cont2++] != '\0')
		dest[(cont1 - 1) + (cont2 - 1)] = s2[cont2 - 1];
	return (dest);
}