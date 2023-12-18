/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av_make_infos2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:24:15 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

static char	**make_char_list_split(t_svi *infos, char **av_char, char *av[])
{
	infos->stack_size = count_arg(av[1], ' ');
	av_char = ft_split(av[1], ' ');
	if (!av_char)
	{
		free(av_char);
		free(infos);
		exit(put_error());
	}
	infos->case_split = 1;
	return (av_char);
}

t_svi	*check_av_make_infos(int ac, char **av, t_svi *infos)
{
	char	**av_char;

	if (ac == 1 || (ac == 2 && ac2_case(av[1])))
		exit(0);
	infos = (t_svi *)malloc(sizeof(t_svi));
	if (!infos)
		exit(put_error());
	av_char = NULL;
	if (ac == 2 && count_arg(av[1], ' ') >= 2)
		av_char = make_char_list_split(infos, av_char, av);
	else
	{
		infos->case_split = 0;
		infos->stack_size = ac - 1;
		av_char = ++av;
	}
	infos->a_origin_char = av_char;
	infos->a_origin_ll = make_ll_list(infos);
	infos->a_origin_int = make_int_list(infos);
	infos->ans = NULL;
	infos->b_size_now = 0;
	infos->sort_i = 0;
	return (infos);
}
