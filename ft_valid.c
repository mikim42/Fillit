/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 00:36:53 by mikim             #+#    #+#             */
/*   Updated: 2017/03/19 00:41:25 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_check_l(char **t, int y, int x, int *i)
{
	t[y][x] = '0';
	if (x > 0 && t[y][x - 1] == '#')
	{
		*i += 1;
		ft_check_l(t, y, x - 1, i);
	}
	if (y < 3 && t[y + 1][x] == '#')
	{
		*i += 1;
		ft_check_d(t, y + 1, x, i);
	}
}

void	ft_check_d(char **t, int y, int x, int *i)
{
	t[y][x] = '0';
	if (x > 0 && t[y][x - 1] == '#')
	{
		*i += 1;
		ft_check_l(t, y, x - 1, i);
	}
	if (y < 3 && t[y + 1][x] == '#')
	{
		*i += 1;
		ft_check_d(t, y + 1, x, i);
	}
	if (x < 3 && t[y][x + 1] == '#')
	{
		*i += 1;
		ft_check_r(t, y, x + 1, i);
	}
}

void	ft_check_r(char **t, int y, int x, int *i)
{
	t[y][x] = '0';
	if (x < 3 && t[y][x + 1] == '#')
	{
		*i += 1;
		ft_check_r(t, y, x + 1, i);
	}
	if (y < 3 && t[y + 1][x] == '#')
	{
		*i += 1;
		ft_check_d(t, y + 1, x, i);
	}
}
