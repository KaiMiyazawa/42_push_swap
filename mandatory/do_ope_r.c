/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:14:13 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:59 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

int	count_stack_size(t_list *list)
{
	int	head_value;
	int	count;

	if (!list)
		return (0);
	count = 1;
	head_value = list->value;
	list = list->next;
	while (list->value != head_value)
	{
		count++;
		list = list->next;
	}
	return (count);
}

static void	do_rotate(t_list **list, int ss)
{
	t_list	*t_tmp;
	int		count;

	count = 0;
	t_tmp = *list;
	ss = count_stack_size(*list);
	while (count < ss - 1)
	{
		do_swap(t_tmp);
		t_tmp = t_tmp->next;
		count++;
	}
	return ;
}

void	do_ra(t_svi *infos, t_list **a)
{
	do_rotate(a, infos->stack_size);
	ans_listadd_back(&(infos->ans), ans_lstnew("ra"));
	return ;
}

void	do_rb(t_svi *infos, t_list **b)
{
	do_rotate(b, infos->stack_size);
	ans_listadd_back(&(infos->ans), ans_lstnew("rb"));
	return ;
}
