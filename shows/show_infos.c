/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:45:50 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/10/01 16:23:58 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	show_infos(t_svi *infos)
{
	int	count;

	count = 0;
	printf("\n");
	printf("-----------infos------------\n");
	printf("stack_size:%d\n", infos->stack_size);
	if (infos->case_split)
		printf("===[split case]===\n");
	else
		printf("===[normal case]===\n");
	if (!(infos->ll_not_set))
		printf("ll_list setted.\n");
	if (!(infos->int_not_set))
		printf("int_list setted.\n");

	printf("char_list----------\n");
	while (count < infos->stack_size + 1)
	{
		printf("char[%d]:%s\n", count, infos->a_origin_char[count]);
		count++;
	}
	count = 0;
	printf("long_long_list-----\n");
	if (infos->ll_not_set)
		printf("NULL (maybe not yet)\n");
	else
	{
		while (count < infos->stack_size)
		{
			printf("ll[%d]:%lld\n", count, infos->a_origin_ll[count]);
			count++;
		}
	}
	count = 0;
	printf("int_list-----------\n");
	if (infos->int_not_set)
		printf("NULL (maybe not yet)\n");
	else
	{
		while (count < infos->stack_size)
		{
			printf("int[%d]:%d\n", count, infos->a_origin_int[count]);
			count++;
		}
	}
	printf("\nsort_i:%d\n", infos->sort_i);
	return ;
}
