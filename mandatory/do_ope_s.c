/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:11:25 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	do_swap(t_list *list)
{
	int	tmp_value;
	int	tmp_index;

	tmp_value = list->value;
	tmp_index = list->index;
	list->value = list->next->value;
	list->index = list->next->index;
	list->next->value = tmp_value;
	list->next->index = tmp_index;
	return ;
}

void	do_sa(t_svi *infos, t_list **a)
{
	do_swap(*a);
	ans_listadd_back(&(infos->ans), ans_lstnew("sa"));
	return ;
}

void	do_sb(t_svi *infos, t_list **b)
{
	do_swap(*b);
	ans_listadd_back(&(infos->ans), ans_lstnew("sb"));
	return ;
}
