/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:57:49 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 17:16:00 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

static bool	is_sorted(t_svi *infos)
{
	int	count;
	int	num;

	count = 0;
	num = infos->a_origin_int[0];
	while (count < infos->stack_size - 1)
	{
		if (infos->a_origin_int[count + 1] < num)
			return (0);
		num = infos->a_origin_int[count + 1];
		count++;
	}
	return (1);
}

static bool	is_dep(t_svi *infos)
{
	int	count;
	int	count2;
	int	num;

	count = 0;
	while (count < infos->stack_size - 1)
	{
		num = infos->a_origin_int[count];
		count2 = count + 1;
		while (count2 < infos->stack_size)
		{
			if (num == infos->a_origin_int[count2])
				return (1);
			count2++;
		}
		count++;
	}
	return (0);
}

static void	sort_dep_etc_check(t_svi *infos)
{
	int	count;

	count = -1;
	while (++count < infos->stack_size)
	{
		if (infos->a_origin_char
			[count][del_speace(infos->a_origin_char[count])] == '\0')
		{
			free_infos(infos);
			exit(put_error());
		}
	}
	if (is_dep(infos))
	{
		free_infos(infos);
		exit(put_error());
	}
	if (is_sorted(infos) || infos->stack_size == 1)
	{
		free_infos(infos);
		exit(0);
	}
	return ;
}

static void	push_swap(t_list **a, t_list **b, t_svi *infos)
{
	if (infos->stack_size == 2)
		do_sa(infos, a);
	else if (infos->stack_size < 7)
		easy_sort(infos, a, b);
	else
		complex_sort(infos, a, b);
	return ;
}

int	main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;
	t_svi	*infos;

	if (ac > ARG_LIMIT)
		exit(put_error());
	infos = NULL;
	infos = check_av_make_infos(ac, av, infos);
	if (infos->stack_size > ARG_LIMIT)
	{
		free(infos);
		exit(put_error());
	}
	sort_dep_etc_check(infos);
	b = NULL;
	a = NULL;
	a = make_a_list(a, infos);
	add_index(a, infos);
	push_swap(&a, &b, infos);
	trim_ans(infos);
	print_ans(infos);
	free_list(&a);
	free_list(&b);
	free_infos(infos);
	return (0);
}

//ma
