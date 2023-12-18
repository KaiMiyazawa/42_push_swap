/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:05:20 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

static int	case_judge(t_list *a)
{
	if (a->index < a->next->index && a->index < a->prev->index)
	{
		if (!(a->prev->index > a->index && a->prev->index > a->next->index))
			return (4);
		return (0);
	}
	else if (a->index > a->next->index && a->index > a->prev->index)
	{
		if (a->next->index < a->index && a->next->index < a->prev->index)
			return (3);
		return (2);
	}
	else
	{
		if (a->next->index < a->index && a->next->index < a->prev->index)
			return (1);
		return (5);
	}
	return (-1);
}

int	sort_three_case(t_svi *infos, t_list **a)
{
	int	a_case;

	a_case = case_judge(*a);
	if (a_case == -1)
		return (-1);
	if (a_case == 1 || a_case == 2 || a_case == 4)
		do_sa(infos, a);
	if (a_case == 3 || a_case == 4)
		do_ra(infos, a);
	if (a_case == 2 || a_case == 5)
		do_rra(infos, a);
	return (0);
}

void	easy_sort(t_svi *infos, t_list **a, t_list **b)
{
	if (infos->stack_size == 3)
	{
		if (sort_three_case(infos, a) == -1)
			free_all(infos, a, b);
	}
	else if (infos->stack_size > 3)
		sort_u_six_case(infos, a, b);
	return ;
}
