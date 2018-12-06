/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   movelist2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/18 15:48:30 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/04 16:13:37 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_piles *p)
{
	int		i;
	int		tmp;

	i = 0;
	if (p->lena > 0)
	{
		tmp = p->a[0];
		while (i < p->lena)
		{
			p->a[i] = p->a[i + 1];
			i++;
		}
		p->a[i - 1] = tmp;
	}
}

void	rb(t_piles *p)
{
	int		i;
	int		tmp;

	i = 0;
	if (p->lenb > 0)
	{
		tmp = p->b[0];
		while (i < p->lenb)
		{
			p->b[i] = p->b[i + 1];
			i++;
		}
		p->b[i - 1] = tmp;
	}
}

void	rr(t_piles *p)
{
	int		tmp;
	int		i;

	i = 0;
	if (p->lena > 0)
	{
		tmp = p->a[0];
		while (i < p->lena)
		{
			p->a[i] = p->a[i + 1];
			i++;
		}
		p->a[i - 1] = tmp;
	}
	i = 0;
	if (p->lenb > 0)
	{
		tmp = p->b[0];
		while (i < p->lenb)
		{
			p->b[i] = p->b[i + 1];
			i++;
		}
		p->b[i - 1] = tmp;
	}
}

void	rra(t_piles *p)
{
	int		tmp;
	int		i;

	i = p->lena - 1;
	if (p->lena > 0)
	{
		tmp = p->a[i];
		while (i > 0)
		{
			p->a[i] = p->a[i - 1];
			i--;
		}
		p->a[0] = tmp;
	}
}

void	rrb(t_piles *p)
{
	int		tmp;
	int		i;

	i = p->lenb - 1;
	if (p->lenb > 0)
	{
		tmp = p->b[i];
		while (i > 0)
		{
			p->b[i] = p->b[i - 1];
			i--;
		}
		p->b[0] = tmp;
	}
}
