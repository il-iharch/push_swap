/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharch <iharch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:11:58 by iharch            #+#    #+#             */
/*   Updated: 2025/02/23 11:28:26 by iharch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_node *node)
{
	int	i;

	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	ft_lstadd_front(t_node **head, t_node *new)
{
	if (!new)
		return ;
	else
	{
		new->next = *head;
		*head = new;
	}
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!new)
		return ;
	if (!*head)
	{
		(*head) = new;
		new->next = NULL;
		return ;
	}
	tmp = *head;
	tmp = ft_lstlast(*head);
	tmp->next = new;
	new->next = NULL;
}
