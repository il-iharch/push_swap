/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:49:59 by iharch            #+#    #+#             */
/*   Updated: 2025/03/04 13:50:08 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_is_not_digit(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if (str[c] >= '0' && str[c] <= '9')
			return (0);
		c++;
	}
	return (1);
}

int	ft_cheak(char *str)
{
	int	i;

	i = 0;
	if (!ft_is_not_digit(str))
	{
		if (str[i] == '+' || str[i] == '-' )
		{
			if (!ft_isdigit(str[++i]))
				return (0);
		}
		while (str[i])
		{
			if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i - 1]))
			{
				if (!ft_isdigit(str[++i]))
					return (0);
			}
			if (!ft_isdigit(str[i]) && str[i] != 32)
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

void	parsing(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_cheak(str[i]) == 0 || !str[i][0])
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
	is_repeat(str);
}
