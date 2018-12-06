/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   generate_list.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 13:37:17 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 14:27:35 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

int		check_duplicate(int *tab, int len, int r)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (r == tab[i])
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		i;
	int		len;
	int		r;
	int		*tab;

	i = 0;
	if (ac != 3)
	{
		printf("usage: ./a.out <list length> <max value>\n");
		return (0);
	}
	tab = malloc(sizeof(int) * ft_atoi(av[1]));
	len = ft_atoi(av[1]);
	srand(time(NULL));
	while (i < len)
	{
		r = rand() % ft_atoi(av[2]);
		if (check_duplicate(tab, i, r))
			tab[i++] = r;
	}
	i = 0;
	while (i < len - 1)
		printf("%d ", tab[i++]);
	printf("%d\n", tab[i]);
	return (0);
}
