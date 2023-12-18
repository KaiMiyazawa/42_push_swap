/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:13:15 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

static void	do_push2(t_list **dst, t_list *tmp_src)
{
	t_list	*tmp_dst;

	tmp_dst = *dst;
	*dst = tmp_src;
	if (tmp_dst == NULL)
	{
		(*dst)->next = *dst;
		(*dst)->prev = *dst;
	}
	else
	{
		(*dst)->prev = tmp_dst->prev;
		(*dst)->prev->next = *dst;
		(*dst)->next = tmp_dst;
		tmp_dst->prev = *dst;
	}
}

static void	do_push(t_list **src, t_list **dst)
{
	t_list	*tmp_src;

	if (*src == NULL)
		return ;
	tmp_src = *src;
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		*src = (*src)->next;
		(*src)->prev = tmp_src->prev;
		(*src)->prev->next = *src;
	}
	do_push2(dst, tmp_src);
	return ;
}

void	do_pa(t_svi *infos, t_list **a, t_list **b)
{
	do_push(b, a);
	ans_listadd_back(&(infos->ans), ans_lstnew("pa"));
	infos->b_size_now--;
	return ;
}

void	do_pb(t_svi *infos, t_list **a, t_list **b)
{
	do_push(a, b);
	ans_listadd_back(&(infos->ans), ans_lstnew("pb"));
	infos->b_size_now++;
	return ;
}
