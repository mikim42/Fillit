/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:00:40 by mikim             #+#    #+#             */
/*   Updated: 2017/03/19 00:41:44 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_check_point(char **tet, int *ycnt, int *xcnt)
{
	int x;
	int y;

	y = -1;
	while (tet[++y] != NULL)
	{
		x = -1;
		while (tet[y][++x] != '\0')
		{
			if (tet[y][x] != '.')
			{
				if (*ycnt > y)
					*ycnt = y;
				if (*xcnt > x)
					*xcnt = x;
			}
		}
	}
}

void	ft_convert_block(char **tmp, int n)
{
	int i;
	int j;

	i = -1;
	while (tmp[++i] != NULL)
	{
		j = -1;
		while (tmp[i][++j] != '\0')
		{
			if (tmp[i][j] == '0')
				tmp[i][j] = n + 65;
		}
	}
}

int		ft_check_block2(char **t)
{
	int i;
	int x;
	int y;

	i = 1;
	x = -1;
	y = 0;
	while (t[y][++x] != '#')
	{
		if (t[y][x] == '\0')
		{
			y++;
			x = -1;
		}
	}
	ft_check_r(t, y, x, &i);
	return (i);
}

void	ft_check_block(char **tet)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = -1;
	while (tet[++k])
	{
		j = -1;
		while (tet[k][++j] != '\0')
		{
			if (tet[k][j] == '#' || tet[k][j] == '\n' || tet[k][j] == '.')
			{
				if (tet[k][j] == '#')
					i--;
				else if (tet[k][j] == '.')
					i++;
			}
			else
				ft_error();
		}
	}
	if (i != 8 || (ft_check_block2(tet) != 4))
		ft_error();
}
