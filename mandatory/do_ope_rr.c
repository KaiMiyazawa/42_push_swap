/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:15:34 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

static void	do_r_rotate(t_list **list, int ss)
{
	t_list	*t_tmp;
	int		count;

	count = 0;
	t_tmp = (*list)->prev->prev;
	ss = count_stack_size(*list);
	while (count < ss - 1)
	{
		do_swap(t_tmp);
		t_tmp = t_tmp->prev;
		count++;
	}
	return ;
}

void	do_rra(t_svi *infos, t_list **a)
{
	do_r_rotate(a, infos->stack_size);
	ans_listadd_back(&(infos->ans), ans_lstnew("rra"));
	return ;
}

void	do_rrb(t_svi *infos, t_list **b)
{
	do_r_rotate(b, infos->stack_size);
	ans_listadd_back(&(infos->ans), ans_lstnew("rrb"));
	return ;
}
