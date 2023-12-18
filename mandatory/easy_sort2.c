/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:09:51 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

int	measure_dist_from_head(t_list *list)
{
	int		min_index;
	int		count;
	t_list	*tmp;

	count = 0;
	min_index = list->index;
	tmp = list->next;
	while (tmp->value != list->value)
	{
		if (min_index > tmp->index)
			min_index = tmp->index;
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp->index != min_index)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

static void	make_a_max3(t_svi *infos, t_list **a, t_list **b)
{
	int	ss;
	int	dist_min;

	ss = infos->stack_size;
	while (ss > 3)
	{
		dist_min = measure_dist_from_head(*a);
		if (dist_min <= 2)
			do_rsrr_ope_rep(infos, a, do_ra, dist_min);
		else if (dist_min == 3 && ss <= 5)
			do_rsrr_ope_rep(infos, a, do_rra, ss - dist_min);
		else if (dist_min == 3)
			do_rsrr_ope_rep(infos, a, do_ra, 3);
		else if (dist_min == 4)
			do_rsrr_ope_rep(infos, a, do_rra, ss - dist_min);
		else if (dist_min == 5)
			do_rra(infos, a);
		else
			free_all(infos, a, b);
		do_pb(infos, a, b);
		ss--;
	}
	return ;
}

void	sort_u_six_case(t_svi *infos, t_list **a, t_list **b)
{
	int	count;

	count = infos->stack_size - 3;
	make_a_max3(infos, a, b);
	if (sort_three_case(infos, a) == -1)
		free_all(infos, a, b);
	while (count--)
		do_pa(infos, a, b);
	return ;
}
