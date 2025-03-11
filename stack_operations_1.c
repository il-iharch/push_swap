/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:16:19 by iharch            #+#    #+#             */
/*   Updated: 2025/03/04 12:26:19 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

t_node	*ft_stack(t_node **stack_a, char **str)
{
	int	*tab;
	int	i;
	int	j;

	j = 0;
	i = ft_size(str);
	tab = to_tab(str);
	while (j < i)
	{
		ft_lstadd_back(stack_a, lst_new(tab[j]));
		j++;
	}
	free (tab);
	return (*stack_a);
}

t_node	*quick_sort(t_node *stack_a, t_node *stack_b)
{
	if (ft_lstsize(stack_a) == 2 || ft_lstsize(stack_a) == 3)
		sort_2_3(&stack_a);
	else if (ft_lstsize(stack_a) == 4)
		sort_4(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) == 5)
		sort_5(&stack_a, &stack_b);
	return (stack_a);
}

void	index_stack(t_node *stack_a)
{
	int		count;
	t_node	*tmp;
	t_node	*tmp1;

	tmp1 = stack_a;
	count = 0;
	while (stack_a)
	{
		tmp = tmp1;
		count = 0;
		while (tmp)
		{
			if ((stack_a)->content > tmp->content)
				count++;
			tmp = tmp->next;
		}
		(stack_a)->index = count;
		stack_a = (stack_a)->next;
	}
}

int	is_sorted(t_node *stack_a)
{
	t_node	*tmp;

	tmp = stack_a;
	while (stack_a && stack_a->next)
	{
		if (stack_a->content < stack_a->next->content)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}
