/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/18 12:23:13 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 14:06:08 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_tpilescheck(t_piles *p, int *a, int len, char *opt)
{
	int		i;

	i = 0;
	if (!(p->a = (int*)malloc(sizeof(int) * len)))
		return ;
	while (i < len)
	{
		p->a[i] = a[i];
		i++;
	}
	p->lena = len;
	p->lenb = 0;
	p->b = NULL;
	p->vis = opt && !ft_strcmp(opt, "-v") ? 1 : 0;
	ft_strdel(&opt);
}

int		is_legal_move(char *mv)
{
	if (mv && ft_strcmp(mv, "pa") && ft_strcmp(mv, "pb") && ft_strcmp(mv, "rrr")
			&& ft_strcmp(mv, "ra") && ft_strcmp(mv, "rb") && ft_strcmp(mv, "rr")
			&& ft_strcmp(mv, "sb") && ft_strcmp(mv, "sa") && ft_strcmp(mv, "ss")
			&& ft_strcmp(mv, "rra") && ft_strcmp(mv, "rrb"))
		return (0);
	return (1);
}

void	printres(t_piles *p)
{
	int		i;

	i = 0;
	while (i < p->lena - 1 && p->a[i] < p->a[i + 1])
	{
		if (p->a[i] < p->a[i + 1])
			i++;
	}
	if (p->lenb != 0 || i != p->lena - 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(p->a);
	free(p->b);
	free(p);
}

int		read_stde(t_piles *p, char *line)
{
	int		j;

	if ((j = get_next_line(0, &line)) >= 0)
	{
		if (!line || !ft_strcmp(line, "\0"))
		{
			free(line);
			return (0);
		}
		if (!is_legal_move(line))
		{
			write(2, "Error\n", 6);
			free(line);
			return (-1);
		}
		move(p, line);
		free(line);
		if (p->vis)
			visualizer(p);
	}
	return (j);
}

int		checker(int *a, int len, char *opt)
{
	char	*line;
	t_piles	*p;
	int		i;

	line = NULL;
	if (!(p = (t_piles*)malloc(sizeof(t_piles))))
		return (-1);
	fill_tpilescheck(p, a, len, opt);
	while (1)
	{
		if ((i = read_stde(p, line)) == -1)
		{
			free(p->a);
			free(p->b);
			free(p);
			return (0);
		}
		else if (i == 0)
			break ;
	}
	printres(p);
	return (0);
}
