/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_ans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:49:17 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

static void	trim_ans_rr(t_ans_list *tmp, t_ans_list *conect)
{
	if (!tmp->next)
		return ;
	if ((compare_str(tmp->ans_char, "ra")
			&& compare_str(tmp->next->ans_char, "rb"))
		|| (compare_str(tmp->ans_char, "rb")
			&& compare_str(tmp->next->ans_char, "ra")))
	{
		ft_strcpy(tmp->ans_char, "rr");
		if (tmp->next->next)
			conect = tmp->next->next;
		if (tmp->next)
			free(tmp->next);
		if (conect)
			tmp->next = conect;
	}
}

static void	trim_ans_rrr(t_ans_list *tmp, t_ans_list *conect)
{
	if (!tmp->next)
		return ;
	if ((compare_str(tmp->ans_char, "rra")
			&& compare_str(tmp->next->ans_char, "rrb"))
		|| (compare_str(tmp->ans_char, "rrb")
			&& compare_str(tmp->next->ans_char, "rra")))
	{
		ft_strcpy(tmp->ans_char, "rrr");
		if (tmp->next->next)
			conect = tmp->next->next;
		if (tmp->next)
			free(tmp->next);
		if (conect)
			tmp->next = conect;
	}
}

static void	trim_ans_ss(t_ans_list *tmp, t_ans_list *conect)
{
	if (!tmp->next)
		return ;
	if ((compare_str(tmp->ans_char, "sa")
			&& compare_str(tmp->next->ans_char, "sb"))
		|| (compare_str(tmp->ans_char, "sb")
			&& compare_str(tmp->next->ans_char, "sa")))
	{
		ft_strcpy(tmp->ans_char, "ss");
		if (tmp->next->next)
			conect = tmp->next->next;
		if (tmp->next)
			free(tmp->next);
		if (conect)
			tmp->next = conect;
	}
}

void	trim_ans(t_svi *infos)
{
	t_ans_list	*tmp;

	tmp = infos->ans;
	while (tmp->next)
	{
		trim_ans_rr(tmp, NULL);
		trim_ans_rrr(tmp, NULL);
		trim_ans_ss(tmp, NULL);
		tmp = tmp->next;
	}
}
