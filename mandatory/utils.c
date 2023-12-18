/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:16:16 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

bool	compare_str(char *s1, char *s2)
{
	int	count;

	count = 0;
	while (s1[count] != '\0' && s2[count] != '\0')
	{
		if (s1[count] != s2[count])
			return (0);
		count++;
	}
	return (1);
}

bool	put_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	return ;
}

int	count_arg(char *str, char c)
{
	int	count;
	int	words_flag;
	int	result;

	count = 0;
	result = 0;
	words_flag = 1;
	if (str[del_speace(str)] == '\0')
		exit(put_error());
	while (str[count] != '\0')
	{
		if (str[count] == c)
			words_flag = 1;
		else if (words_flag == 1)
		{
			words_flag = 0;
			result++;
		}
		count++;
	}
	return (result);
}

void	do_rsrr_ope_rep(t_svi *infos, t_list **list,
			void (*ope)(t_svi*, t_list**), int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		ope(infos, list);
		count++;
	}
	return ;
}
