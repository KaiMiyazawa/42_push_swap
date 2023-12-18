/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:58:34 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	deal_a_block(t_svi *infos, t_list **a)
{
	t_list	*tmp;
	int		si_position;

	while (infos->a_bl_size--)
	{
		tmp = *a;
		si_position = 1;
		while (tmp->index != infos->sort_i && ++si_position)
			tmp = tmp->next;
		if (si_position != 1)
		{
			do_rsrr_ope_rep(infos, a, do_ra, si_position - 2);
			while (si_position - 2 && si_position--)
			{
				do_sa(infos, a);
				do_rra(infos, a);
			}
			do_sa(infos, a);
		}
		do_ra(infos, a);
		infos->sort_i++;
	}
	return ;
}

int	get_block_size_a(t_svi *infos, t_list **a)
{
	int		max;
	int		count;
	t_list	*tmp;

	max = -1;
	count = 0;
	tmp = *a;
	while (max - infos->sort_i + 1 != count)
	{
		count++;
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	infos->a_bl_size = count;
	return (count);
}

void	pb_block(t_svi *infos, t_list **a, t_list **b)
{
	while (infos->a_bl_size--)
	{
		if ((*a)->index == infos->sort_i && ++infos->sort_i)
			do_ra(infos, a);
		else
			do_pb(infos, a, b);
	}
	return ;
}

bool	is_sort_finish(t_svi *infos, t_list **a, t_list **b)
{
	t_list	*tmp;
	int		a_head_index;

	if (!(*b))
	{
		tmp = (*a);
		a_head_index = (*a)->index;
		while (tmp->next->index != a_head_index)
		{
			if (tmp->index > tmp->next->index)
				return (0);
			tmp = tmp->next;
		}
	}
	else
		return (0);
	infos->a_bl_size = 0;
	return (1);
}
