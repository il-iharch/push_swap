/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:08:16 by iharch            #+#    #+#             */
/*   Updated: 2025/01/27 11:09:58 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_cheak(av[i]) == 0 || !av[i][0])
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	if (is_repeat(av) == 0)
		return (write(2, "Error\n", 6), 0);
	
}
