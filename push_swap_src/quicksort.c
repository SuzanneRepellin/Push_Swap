/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quicksort.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 14:16:00 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 16:36:27 by srepelli    ###    #+. /#+    ###.fr     */
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
	printf("---a---  ---b---\n");
	while (l < p->lena || k < p->lenb)
	{
		if (l < p->lena)
			printf("%5d", p->a[l]);
		else
			printf("     ");
		printf("   ");
		if (k < p->lenb)
			printf("%5d\n", p->b[k]);
		else
			printf("\n");
		l++;
		k++;
	}
	printf("\n");
}

int		issort(t_piles *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < p->lena - 1 && p->a[i] <= p->a[i + 1])
	{
		if (p->a[i] <= p->a[i + 1])
			i++;
	}
	if (i != p->lena - 1 || p->lenb != 0)
		return (0);
	else
		return (1);
}

int		intpos(int *tab, size_t len, int i)
{
	int		*tmp;
	size_t	j;

	j = 0;
	tmp = ft_arraydup(tab, len);
	ft_sort_int_tab(tmp, len);
	while (j < len)
	{
		if (tmp[j++] == i)
		{
			free(tmp);
			return (j);
		}
	}
	free(tmp);
	return (-1);
}

void	quicksort(t_piles *p)
{
	int		i;
	int		piv;
	int		mil;

	mil = p->lena;
	while (mil > 40)
	{
		i = 0;
		piv = p->a[ft_median(p->a, mil)];
		while (i++ < mil)
		{
			if (p->a[0] > piv)
				pbpr(p);
			else if (p->lenb && p->b[ft_median(p->b, p->lenb)] > p->b[0])
				rrpr(p);
			else
				rapr(p);
		}
		if (mil > 200)
			bigsortb(p);
		mil = mil / 2;
	}
	while (p->lena)
		pbpr(p);
	sortb(p);
}
