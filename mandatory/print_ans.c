/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:36:12 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		count;
	char	tmp;

	count = 0;
	if (s)
	{
		while (s[count] != '\0')
		{
			tmp = s[count];
			write(1, &tmp, fd);
			count++;
		}
	}
}

void	print_ans(t_svi *infos)
{
	t_ans_list	*tmp;
	char		nl;

	nl = '\n';
	tmp = infos->ans;
	while (tmp)
	{
		if (!compare_str(tmp->ans_char, "pp"))
		{
			ft_putstr_fd(tmp->ans_char, 1);
			write(1, &nl, 1);
		}
		tmp = tmp->next;
	}
	return ;
}
