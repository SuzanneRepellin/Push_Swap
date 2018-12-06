/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 16:22:38 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 11:16:39 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct		s_piles
{
	int		*a;
	int		*b;
	int		lena;
	int		lenb;
	int		vis;
}					t_piles;

int					checker(int *a, int len, char *opt);
void				push_swap(int *a, int len);
int					issort(t_piles *p);
int					is_min(int *tab, int len, int k);
int					whereismin(int *tab, size_t len);
void				visualizer(t_piles *p);
int					checksort(t_piles *p);
int					error_check(int *pile, int len, char **s);
int					intpos(int *tab, size_t len, int i);
void				bigsortb(t_piles *p);
void				sortb(t_piles *p);

void				sa(t_piles *p);
void				sb(t_piles *p);
void				ss(t_piles *p);
void				pa(t_piles *p);
void				pb(t_piles *p);
void				ra(t_piles *p);
void				rb(t_piles *p);
void				rr(t_piles *p);
void				rra(t_piles *p);
void				rrb(t_piles *p);
void				rrr(t_piles *p);

void				sapr(t_piles *p);
void				sbpr(t_piles *p);
void				sspr(t_piles *p);
void				papr(t_piles *p);
void				pbpr(t_piles *p);
void				rapr(t_piles *p);
void				rbpr(t_piles *p);
void				rrpr(t_piles *p);
void				rrapr(t_piles *p);
void				rrbpr(t_piles *p);
void				rrrpr(t_piles *p);

void				move(t_piles *p, char *mv);
void				fill_tpilescheck(t_piles *p, int *a, int len, char *opt);
void				fill_tpiles(t_piles *p, int *a, int len);

void				swaptopdown(t_piles *p);
void				invertab(t_piles *p);

void				quicksort(t_piles *p);
void				simplesort(t_piles *p);

#endif
