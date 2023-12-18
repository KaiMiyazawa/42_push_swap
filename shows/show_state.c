/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:57:24 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/08/06 12:38:56 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_state(t_list **a, int a_or_b, int ss)
{
	t_list	*a_tmp;
	char	ab;
	int		count;
	int		head_value;

	count = -1;
	if (a_or_b)
		ab = 'a';
	else
		ab = 'b';
	printf("------- %c list -------\n", ab);
	if (!(*a))
	{
		printf("%c : NULL\n", ab);
		return ;
	}
	a_tmp = *a;
	head_value = (*a)->value;
	while (++count < ss && a_tmp->next->value != head_value)
	{
		if (!a_tmp)
			break ;
		printf("%c[%d]:[value:%d index:%d]\n", ab, count, a_tmp->value, a_tmp->index);
		a_tmp = a_tmp->next;
	}
	printf("%c[%d]:[value:%d index:%d]\n", ab, count, a_tmp->value, a_tmp->index);
	return ;
}

void	show_ab_state(t_list **a, t_list **b, int stack_size)
{
	printf("\n");
	show_state(a, 1, stack_size);
	show_state(b, 0, stack_size);
	printf("\n");
	return ;
}
