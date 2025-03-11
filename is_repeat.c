/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_repeat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:23:51 by iharch            #+#    #+#             */
/*   Updated: 2025/02/23 12:12:45 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static long	ft_atoi(char *str)
{
	long		r;
	long		s;
	long		i;

	r = 0;
	s = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		if (r * s > INT_MAX || r * s < INT_MIN)
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (r * s);
}

int	ft_size(char **str)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (str[i])
	{
		count += ft_count(str[i]);
		i++;
	}
	return (count);
}

int	*to_tab(char **str)
{
	int		i;
	int		j;
	int		*tab;
	char	**s;
	int		count;

	i = 1;
	count = 0;
	tab = malloc(ft_size(str) * sizeof(int));
	if (!tab)
		return (0);
	while (str[i])
	{
		j = 0;
		s = ft_split(str[i]);
		while (s[j])
		{
			tab[count++] = ft_atoi(s[j]);
			j++;
		}
		ft_free(s);
		i++;
	}
	return (tab);
}

int	is_repeat(char **str)
{
	int	*tab;
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	tab = to_tab(str);
	while (i < ft_size(str))
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] == tab[j])
			{
				write (2, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
		count++;
	}
	free (tab);
	return (1);
}
