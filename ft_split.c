/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:40:49 by iharch            #+#    #+#             */
/*   Updated: 2025/01/26 11:20:37 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char *s)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		while (!(s[i] >= '0' && s[i] <= '9') && s[i])
			i++;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if ((s[i - 1] >= '0' && s[i - 1] <= '9'))
			a++;
		if (s[i])
			i++;
	}
	return (a);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*ft_dup(char *s, int st)
{
	char	*str;
	int		j;
	int		i;
	int		a;

	j = 0;
	a = 0;
	i = st;
	while (s[i] && (s[i] != 32))
	{
		i++;
		a++;
	}
	str = malloc((a + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (j < a)
	{
		str[j] = s[st + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char *s)
{
	char	**str;
	int		i;
	int		j;

	if (!s || !ft_cheak(s))
		return (NULL);
	str = malloc((ft_count(s) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_count((char *)s))
	{
		if (s[i] && s[i] != 32)
		{
			str[j] = ft_dup(s, i);
			if (str[j] == NULL)
				return (ft_free(str), NULL);
			j++;
		}
		while (s[i] && s[i] != 32)
			i++;
		i++;
	}
	return (str[j] = NULL, str);
}
