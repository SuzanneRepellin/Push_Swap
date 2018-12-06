/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   simplesort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 15:21:55 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 16:37:01 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../push_swap.h"

int		is_min(int *a, int len, int k)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (k > a[i])
			return (0);
		i++;
	}
	return (1);
}

int		whereismin(int *tab, size_t len)
{
	int		mil;
	int		i;

	i = 0;
	mil = len / 2;
	while (i <= mil)
	{
		if (is_min(tab, len, tab[i]))
			return (1);
		i++;
	}
	return (0);
}

void	simplesort(t_piles *p)
{
	while (!issort(p))
	{
		if ((p->lena > 2 && p->a[0] > p->a[1] && checksort(p) != 1) ||
				is_min(p->a, p->lena, p->a[1]))
			sapr(p);
		while (p->lena > 2 && checksort(p) != 1)
		{
			if (is_min(p->a, p->lena, p->a[0]))
				pbpr(p);
			else
			{
				if (!whereismin(p->a, p->lena))
					rrapr(p);
				else
					rapr(p);
			}
		}
		if (!issort(p) && !ft_arrayissort(p->a, p->lena)
				&& !whereismin(p->a, p->lena))
			rrapr(p);
		else if (!issort(p) && !ft_arrayissort(p->a, p->lena))
			rapr(p);
		if (p->lenb)
			papr(p);
	}
}
