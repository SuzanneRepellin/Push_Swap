/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/21 16:34:00 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 16:30:05 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_tpiles(t_piles *p, int *a, int len)
{
	int		i;

	i = 0;
	if (!(p->a = (int*)malloc(sizeof(int) * len + 1)))
		return ;
	while (i < len)
	{
		p->a[i] = a[i];
		i++;
	}
	p->lena = len;
	p->lenb = 0;
	p->b = NULL;
}

int		checksort(t_piles *p)
{
	int		*tab;
	int		i;
	int		tmp;

	tab = ft_arraydup(p->a, p->lena);
	while (!is_min(tab, p->lena, tab[0]))
	{
		i = -1;
		if (p->lena > 0)
		{
			tmp = tab[0];
			while (++i < p->lena)
				tab[i] = tab[i + 1];
			tab[i - 1] = tmp;
		}
	}
	if (ft_arrayissort(tab, p->lena) == 1)
	{
		free(tab);
		return (1);
	}
	free(tab);
	return (0);
}

void	push_swap(int *a, int len)
{
	t_piles	*p;

	if (!(p = (t_piles*)malloc(sizeof(t_piles))))
		return ;
	fill_tpiles(p, a, len);
	if (p->lena < 25 || checksort(p))
		simplesort(p);
	else if (!issort(p))
		quicksort(p);
	free(p->b);
	free(p->a);
	free(p);
}
