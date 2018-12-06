/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quicksort.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 14:16:00 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 10:41:54 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../push_swap.h"

int		is_max(int *tab, size_t len, int k)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (k < tab[i])
			return (0);
		i++;
	}
	return (1);
}

int		whereismax(int *tab, size_t len)
{
	int		mil;
	int		i;

	i = 0;
	mil = len / 2;
	while (i <= mil)
	{
		if (is_max(tab, len, tab[i]))
			return (1);
		i++;
	}
	return (0);
}

void	sortb(t_piles *p)
{
	while (p->lenb)
	{
		if (is_max(p->b, p->lenb, p->b[1]))
			sbpr(p);
		if (is_max(p->b, p->lenb, p->b[0]))
			papr(p);
		else
		{
			if (!whereismax(p->b, p->lenb))
				rrbpr(p);
			else
				rbpr(p);
		}
		if (p->lenb == 1)
			papr(p);
	}
}

void	bigsortb(t_piles *p)
{
	int		i;
	int		j;
	int		piv;
	int		mil;

	mil = p->lenb;
	j = 0;
	while (mil > 10)
	{
		i = 0;
		piv = p->b[ft_median(p->b, mil)];
		while (i++ < mil)
		{
			if (p->b[0] > piv)
			{
				papr(p);
				j++;
			}
			else
				rbpr(p);
		}
		mil = mil / 2;
	}
	while (j--)
		pbpr(p);
}
