/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:08:09 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/02/08 13:14:21 by mjose-ye         ###   ########.fr       */
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

int	con_negative(int c)
{
	if (c < 0)
		c = c * -1;
	return (c);
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = size;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j--;
		}
		i--;
	}
}
