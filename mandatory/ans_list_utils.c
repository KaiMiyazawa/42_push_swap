/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:10:22 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:08 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

t_ans_list	*ans_lstnew(char *ope_char)
{
	t_ans_list	*new;

	new = (t_ans_list *)malloc(sizeof(t_ans_list));
	if (!new)
		return (NULL);
	ft_strcpy(new->ans_char, ope_char);
	new->next = NULL;
	return (new);
}

static t_ans_list	*ans_lstlast(t_ans_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	ans_listadd_back(t_ans_list **lst, t_ans_list *new)
{
	t_ans_list	*lst_last;

	if (!new)
		return ;
	if (*lst != NULL)
	{
		lst_last = ans_lstlast(*lst);
		lst_last->next = new;
	}
	else
		*lst = new;
	return ;
}
