/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error_check.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 11:58:42 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 14:38:25 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./push_swap.h"

int		has_duplicate(int *pile, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i != j && pile[i] == pile[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_word_table(char **s, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		if (ft_atol(s[i]) > 2147483647 || ft_atol(s[i]) < -2147483648 ||
				!ft_strcmp(s[i], "\0"))
			return (-1);
		while (s[i][j])
		{
			if (!ft_isnum(s[i][j]) && s[i][j] != '-' && s[i][j] != '+')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		error_check(int *pile, int len, char **s)
{
	if (has_duplicate(pile, len) || check_word_table(s, len) ||
			(*s && *s[0] == '\0') || !*s)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (0);
}
