/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   moves.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/18 12:29:43 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 11:40:56 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../push_swap.h"

void	move(t_piles *p, char *mv)
{
	if (mv && !ft_strcmp(mv, "sa"))
		sa(p);
	else if (mv && !ft_strcmp(mv, "sb"))
		sb(p);
	else if (mv && !ft_strcmp(mv, "ss"))
		ss(p);
	else if (mv && !ft_strcmp(mv, "pa"))
		pa(p);
	else if (mv && !ft_strcmp(mv, "pb"))
		pb(p);
	else if (mv && !ft_strcmp(mv, "ra"))
		ra(p);
	else if (mv && !ft_strcmp(mv, "rb"))
		rb(p);
	else if (mv && !ft_strcmp(mv, "rr"))
		rr(p);
	else if (mv && !ft_strcmp(mv, "rra"))
		rra(p);
	else if (mv && !ft_strcmp(mv, "rrb"))
		rrb(p);
	else if (mv && !ft_strcmp(mv, "rrr"))
		rrr(p);
	else if (mv && ft_strcmp(mv, "\0"))
		write(2, "Error\n", 6);
}
