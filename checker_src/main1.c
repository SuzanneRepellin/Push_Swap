/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/18 12:23:13 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 14:44:29 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../push_swap.h"

char	**uniarg(int ac, char **av, char *opt)
{
	int		*pile;
	char	**s;
	int		i;
	int		len;

	i = -1;
	if (!(s = ft_strsplit(av[1], ' ')))
		return (NULL);
	opt = ac == 3 && !ft_strcmp(av[2], "-v") ? ft_strdup("-v") : NULL;
	len = ft_wordcount(av[1], ' ');
	if (!(pile = (int*)malloc(sizeof(int) * len)))
		return (s);
	while (++i < len)
		pile[i] = ft_atoi(s[i]);
	if (error_check(pile, len, s))
	{
		free(pile);
		ft_strdel(&opt);
		return (s);
	}
	i = 0;
	checker(pile, len, opt);
	free(pile);
	return (s);
}

void	multiarg(int ac, char **av, char *opt)
{
	int		*pile;
	char	**s;
	int		i;
	int		len;

	i = -1;
	len = ac - 1;
	s = av + 1;
	if (!ft_strcmp(s[len - 1], "-v"))
	{
		opt = ft_strdup("-v");
		len--;
	}
	if (!(pile = (int*)malloc(sizeof(int) * len)))
		return ;
	while (++i < len)
		pile[i] = ft_atoi(s[i]);
	if (error_check(pile, len, s))
	{
		free(pile);
		ft_strdel(&opt);
		return ;
	}
	checker(pile, len, opt);
	free(pile);
}

int		main(int ac, char **av)
{
	char	*opt;
	int		i;
	char	**s;

	i = 0;
	opt = NULL;
	s = NULL;
	if (ac <= 1)
		return (0);
	if (ac == 2 || (ac == 3 && !ft_strcmp(av[2], "-v")))
	{
		if ((s = uniarg(ac, av, opt)))
		{
			while (s[i])
				free(s[i++]);
			free(s);
		}
	}
	else
		multiarg(ac, av, opt);
	return (0);
}
