/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:00:14 by mikim             #+#    #+#             */
/*   Updated: 2017/03/17 15:45:33 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_usage(void)
{
	write(1, "usage: ./fillit <FILE>\n", 23);
	exit(0);
}

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	ft_print(char **res)
{
	int x;
	int y;

	y = 2;
	while (res[++y + 3] != NULL)
	{
		x = 2;
		while (res[y][++x] != '*')
			write(1, &res[y][x], 1);
		write(1, "\n", 1);
	}
}
