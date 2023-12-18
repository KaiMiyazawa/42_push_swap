/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:57:24 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

t_list	*list_new(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = new;
	new->prev = new;
	return (new);
}

void	list_add_back(t_list **list, t_list *new)
{
	t_list	*tmp_list;

	tmp_list = (*list)->prev;
	tmp_list->next = new;
	new->prev = tmp_list;
	new->next = *list;
	(*list)->prev = new;
	return ;
}

t_list	*make_a_list(t_list *a, t_svi *infos)
{
	int	count;

	a = NULL;
	count = 0;
	while (count < infos->stack_size)
	{
		if (count == 0)
			a = list_new(infos->a_origin_int[0]);
		else
			list_add_back(&a, list_new(infos->a_origin_int[count]));
		count++;
	}
	return (a);
}

void	add_index(t_list *a, t_svi *infos)
{
	t_list	*tmp;
	int		count;
	int		count2;
	int		index;

	count = -1;
	while (++count < infos->stack_size)
	{
		index = 0;
		count2 = 0;
		tmp = a->next;
		while (++count2 < infos->stack_size)
		{
			if (a->value > tmp->value)
				index++;
			tmp = tmp->next;
		}
		a->index = index;
		a = a->next;
	}
	return ;
}
