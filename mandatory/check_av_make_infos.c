/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av_make_infos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:28:15 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

static bool	is_num_string(char *string)
{
	int	count;

	count = 0;
	if (string[0] == '-' && string[1] >= '1' && string[1] <= '9')
		count++;
	while (string[count] != '\0')
	{
		if (!(string[count] >= '0' && string[count] <= '9'))
			return (0);
		count ++;
	}
	return (1);
}

static bool	have_space(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == ' ')
			return (1);
		count++;
	}
	return (0);
}

static bool	is_in_int(long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	else
		return (1);
}

bool	ac2_case(char *av1)
{
	if (have_space(av1) || av1[0] == '\0')
	{
		if (count_arg(av1, ' ') == 0)
			exit(put_error());
		if (count_arg(av1, ' ') == 1)
		{
			if (!is_num_string(av1))
				exit(put_error());
		}
		if (count_arg(av1, ' ') > 1)
			return (0);
	}
	else if (is_num_string(av1) && is_in_int(ft_atoll(av1)))
		return (1);
	return (0);
}
