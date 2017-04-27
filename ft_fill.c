/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:01:04 by mikim             #+#    #+#             */
/*   Updated: 2017/03/22 04:44:51 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_fill_put(char **tet, char **board, int tx, int bx)
{
	int y;
	int x;

	y = -1;
	while (tet[++y] != NULL)
	{
		x = -1;
		while (tet[y][tx + ++x] != '\0')
			if (tet[y][tx + x] != '.')
				board[y][bx + x] = tet[y][tx + x];
	}
}

void	ft_fill_back(char **board, int *y, int *x, int *n)
{
	int		i;
	int		j;

	i = 2;
	*y += 26;
	*x += 26;
	while (board[++i + 3] != NULL)
	{
		j = 2;
		while (board[i][++j + 3] != '\0')
		{
			if (board[i][j] == *n + 64 && *y >= i)
				*y = i - 1;
			if (board[i][j] == *n + 64 && *x >= j)
				*x = j;
			if (board[i][j] == *n + 64)
				board[i][j] = '.';
		}
	}
	*n -= 1;
}

int		ft_fill_chk(char **tet, char **board, int y, int x)
{
	int i;
	int j;
	int k;

	i = 4;
	j = 4;
	k = -1;
	ft_check_point(tet, &i, &j);
	while (tet[i + ++k] != NULL)
		if (ft_cmp(tet[i + k] + j, board[y + k] + x))
			return (0);
	ft_fill_put(tet + i, board + y, j, x);
	return (1);
}

int		ft_fill(char ***tet, char **board, int y, int x)
{
	int i;

	i = 0;
	while (i >= 0)
	{
		while (board[++y + 3] != NULL)
		{
			while (board[y][++x + 3] != '\0')
			{
				if (ft_fill_chk(tet[i], board, y, x))
				{
					if (tet[++i] == NULL)
						return (1);
					y = 3;
					x = 2;
				}
			}
			x = 2;
		}
		ft_fill_back(board, &y, &x, &i);
	}
	return (0);
}
