/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visualizer.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 14:13:48 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 10:52:59 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../push_swap.h"

void	visualizer(t_piles *p)
{
	int l;
	int k;

	l = 0;
	k = 0;
	ft_printf("---a---  ---b---\n");
	while (l < p->lena || k < p->lenb)
	{
		if (l < p->lena)
			ft_printf("%5d", p->a[l]);
		else
			ft_printf("     ");
		ft_printf("   ");
		if (k < p->lenb)
			ft_printf("%5d\n", p->b[k]);
		else
			ft_printf("\n");
		l++;
		k++;
	}
	ft_printf("\n");
}
