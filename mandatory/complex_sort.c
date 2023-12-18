/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:07:34 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

static void	make_half_list(t_svi *infos, t_list **a, t_list **b)
{
	int		count;
	int		pivot;

	count = infos->stack_size;
	pivot = infos->stack_size / 2;
	while (count--)
	{
		if ((*a)->index < pivot)
			do_pb(infos, a, b);
		else
			do_ra(infos, a);
	}
	return ;
}

static int	get_stack_size(t_svi *infos, t_list *list)
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
	infos->b_size_now = count;
	return (count);
}

static void	divide_b(t_svi *infos, t_list **a, t_list **b)
{
	int	count;
	int	pivot;
	int	b_size;

	b_size = infos->b_size_now;
	count = -1;
	pivot = infos->sort_i + (b_size - 1) / 2;
	while (++count < b_size)
	{
		if ((*b)->index == infos->sort_i && ++infos->sort_i)
		{
			do_pa(infos, a, b);
			do_ra(infos, a);
		}
		else if ((*b)->index > pivot)
			do_pa(infos, a, b);
		else
			do_rb(infos, b);
	}
}

static void	sort_determine(t_svi *infos, t_list **a, t_list **b)
{
	while (infos->b_size_now)
	{
		if ((*b)->index == infos->sort_i && ++infos->sort_i)
		{
			do_pa(infos, a, b);
			do_ra(infos, a);
		}
		else
			do_rb(infos, b);
	}
	return ;
}

void	complex_sort(t_svi *infos, t_list **a, t_list **b)
{
	make_half_list(infos, a, b);
	while (infos->sort_i != infos->stack_size)
	{
		while (get_stack_size(infos, *b) > 4)
			divide_b(infos, a, b);
		if (infos->b_size_now)
			sort_determine(infos, a, b);
		while (!is_sort_finish(infos, a, b) && get_block_size_a(infos, a) <= 4)
			deal_a_block(infos, a);
		if (infos->a_bl_size)
			pb_block(infos, a, b);
	}
	return ;
}
