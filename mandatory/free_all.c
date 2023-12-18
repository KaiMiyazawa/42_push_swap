/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:42:35 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	free_list(t_list **list)
{
	t_list	*tmp;
	int		head_value;

	if (!list || !(*list))
		return ;
	head_value = (*list)->prev->value;
	while ((*list)->value != head_value)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	free(*list);
	*list = NULL;
	return ;
}

static void	free_ans(t_ans_list **ans)
{
	t_ans_list	*tmp;

	if (!ans || !(*ans))
		return ;
	while (*ans)
	{
		tmp = (*ans)->next;
		free(*ans);
		*ans = tmp;
	}
	*ans = NULL;
	return ;
}

void	free_infos(t_svi *infos)
{
	int			count;

	if (infos->case_split)
	{
		count = -1;
		while (++count < infos->stack_size + 1)
			free(infos->a_origin_char[count]);
		free(infos->a_origin_char);
	}
	if (!(infos->ll_not_set))
		free(infos->a_origin_ll);
	if (!(infos->int_not_set))
		free(infos->a_origin_int);
	if (infos->ans)
		free_ans(&(infos->ans));
	free(infos);
	return ;
}

void	free_all(t_svi *infos, t_list **a, t_list **b)
{
	free_infos(infos);
	free_list(a);
	free_list(b);
	exit(put_error());
}
