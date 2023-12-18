/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ill_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:29:37 by miyazawa.ka       #+#    #+#             */
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

static bool	is_correct_param(t_svi *infos)
{
	int	count;

	count = 0;
	while (count < infos->stack_size)
	{
		if (!is_num_string(infos->a_origin_char[count]))
			return (0);
		count++;
	}
	return (1);
}

long long	*make_ll_list(t_svi *infos)
{
	int			count;
	long long	*ll_list;

	count = 0;
	infos->ll_not_set = 1;
	ll_list = (long long *)malloc(infos->stack_size
			*sizeof(long long));
	if (!is_correct_param(infos) || !ll_list)
	{
		if (ll_list)
			free(ll_list);
		exit(put_error());
	}
	infos->ll_not_set = 0;
	while (count < infos->stack_size)
	{
		ll_list[count] = ft_atoll(infos->a_origin_char[count]);
		count++;
	}
	return (ll_list);
}

static bool	is_in_int(t_svi *infos)
{
	int	count;

	count = 0;
	while (count < infos->stack_size)
	{
		if (infos->a_origin_ll[count] > INT_MAX
			|| infos->a_origin_ll[count] < INT_MIN)
			return (0);
		count++;
	}
	return (1);
}

int	*make_int_list(t_svi *infos)
{
	int	count;
	int	*int_list;

	count = 0;
	infos->int_not_set = 1;
	int_list = (int *)malloc(infos->stack_size
			*sizeof(int));
	if (!is_in_int(infos) || !int_list)
	{
		if (int_list)
			free(int_list);
		exit(put_error());
	}
	infos->int_not_set = 0;
	while (count < infos->stack_size)
	{
		int_list[count] = (int)(infos->a_origin_ll[count]);
		count++;
	}
	return (int_list);
}
