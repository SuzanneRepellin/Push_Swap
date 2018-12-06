/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/21 16:34:00 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 12:42:47 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int ac, char **av)
{
	int		i;
	int		j;
	int		len;
	char	**s;
	int		*pile;

	i = 0;
	j = 0;
	if (ac <= 1)
		return (-1);
	if (ac == 2)
		s = ft_strsplit(av[1], ' ');
	else
		s = av + 1;
	len = ac == 2 ? ft_wordcount(av[1], ' ') : ac - 1;
	if (!(pile = (int*)malloc(sizeof(int) * len)))
		return (0);
	while (i < len)
		pile[j++] = ft_atoi(s[i++]);
	if (error_check(pile, len, s) == -1)
		return (-1);
	push_swap(pile, i);
	free(pile);
	return (0);
}
