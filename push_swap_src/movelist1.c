/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   movelist1.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/18 14:44:51 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 14:39:50 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_piles *p)
{
	int		tmp;
	int		i;

	if (p->lena > 1)
	{
		tmp = p->a[0];
		p->a[0] = p->a[1];
		p->a[1] = tmp;
	}
}

void	sb(t_piles *p)
{
	int		tmp;
	int		i;

	if (p->lenb > 1)
	{
		tmp = p->b[0];
		p->b[0] = p->b[1];
		p->b[1] = tmp;
	}
}

void	ss(t_piles *p)
{
	int		tmp;
	int		i;

	if (p->lena >= 2 && p->lenb >= 2)
	{
		tmp = p->a[0];
		p->a[0] = p->a[1];
		p->a[1] = tmp;
		tmp = p->b[0];
		p->b[0] = p->b[1];
		p->b[1] = tmp;
	}
}

void	pa(t_piles *p)
{
	int		i;
	int		*tmp;

	if (p->lenb > 0)
	{
		tmp = ft_arraydup(p->a, p->lena);
		p->lena++;
		p->a = ft_arraynew(p->lena);
		ft_arraycpy(p->a, tmp, p->lena);
		free(tmp);
		i = p->lena;
		while (i > 0)
		{
			p->a[i] = p->a[i - 1];
			i--;
		}
		p->a[0] = p->b[0];
		i = -1;
		while (++i < p->lenb - 1)
			p->b[i] = p->b[i + 1];
		p->lenb--;
		p->b = ft_arraysub(p->b, 0, p->lenb);
	}
}

void	pb(t_piles *p)
{
	int		i;
	int		*tmp;

	if (p->lena > 0)
	{
		tmp = ft_arraydup(p->b, p->lenb);
		p->lenb++;
		p->b = ft_arraynew(p->lenb);
		ft_arraycpy(p->b, tmp, p->lenb);
		free(tmp);
		i = p->lenb;
		while (i > 0)
		{
			p->b[i] = p->b[i - 1];
			i--;
		}
		p->b[0] = p->a[0];
		i = -1;
		while (++i < p->lena - 1)
			p->a[i] = p->a[i + 1];
		p->lena--;
		p->a = ft_arraysub(p->a, 0, p->lena);
	}
}
