/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:43:18 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/09/25 12:08:15 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# define ARG_LIMIT 1001

typedef struct s_stack_list
{
	int					value;
	int					index;
	struct s_stack_list	*next;
	struct s_stack_list	*prev;
}	t_list;

typedef struct s_ans_list
{
	char				ans_char[4];
	struct s_ans_list	*next;
}	t_ans_list;

typedef struct s_various_infos
{
	int				stack_size;

	int				b_size_now;
	int				a_bl_size;
	int				sort_i;

	char			**a_origin_char;
	long long		*a_origin_ll;
	int				*a_origin_int;

	t_ans_list		*ans;

	bool			case_split;
	bool			ll_not_set;
	bool			int_not_set;
}	t_svi;

t_ans_list	*ans_lstnew(char *ope_char);
void		ans_listadd_back(t_ans_list **lst, t_ans_list *new);
bool		ac2_case(char *av1);

t_svi		*check_av_make_infos(int ac, char **av, t_svi *infos);

void		complex_sort(t_svi *infos, t_list **a, t_list **b);

void		deal_a_block(t_svi *infos, t_list **a);
int			get_block_size_a(t_svi *infos, t_list **a);
void		pb_block(t_svi *infos, t_list **a, t_list **b);
bool		is_sort_finish(t_svi *infos, t_list **a, t_list **b);

void		do_pa(t_svi *infos, t_list **a, t_list **b);
void		do_pb(t_svi *infos, t_list **a, t_list **b);

int			count_stack_size(t_list *list);
void		do_ra(t_svi *infos, t_list **a);
void		do_rb(t_svi *infos, t_list **b);

void		do_rra(t_svi *infos, t_list **a);
void		do_rrb(t_svi *infos, t_list **b);

void		do_swap(t_list *list);
void		do_sa(t_svi *infos, t_list **a);
void		do_sb(t_svi *infos, t_list **b);

int			sort_three_case(t_svi *infos, t_list **a);
void		easy_sort(t_svi *infos, t_list **a, t_list **b);

int			measure_dist_from_head(t_list *list);
void		sort_u_six_case(t_svi *infos, t_list **a, t_list **b);

void		free_list(t_list **stack);
void		free_infos(t_svi *infos);
void		free_all(t_svi *infos, t_list **a, t_list **b);

int			del_speace(char *str);
long long	ft_atoll(const char *str);

char		**ft_split(char const *s, char c);

t_list		*make_a_list(t_list *a, t_svi *infos);
void		add_index(t_list *a, t_svi *infos);

long long	*make_ll_list(t_svi *infos);
int			*make_int_list(t_svi *infos);

void		print_ans(t_svi *infos);

void		trim_ans(t_svi *infos);

bool		compare_str(char *s1, char *s2);
bool		put_error(void);
void		ft_strcpy(char *dest, char *src);
int			count_arg(char *str, char c);
void		do_rsrr_ope_rep(t_svi *infos, t_list **list,
				void (*ope)(t_svi*, t_list**), int n);

/*for review*/

//void		show_infos(t_svi *infos);
//void		show_state(t_list **a, int a_or_b, int ss);
//void		show_ab_state(t_list **a, t_list **b, int stack_size);

#endif