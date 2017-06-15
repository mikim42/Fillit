/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:47:08 by mikim             #+#    #+#             */
/*   Updated: 2017/06/14 20:21:24 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_usage();
	ft_fillit(argv[1]);
	return (0);
}

void	ft_fillit(char *av)
{
	char	***tet;
	char	**res;
	char	**board;
	int		pcs;
	int		size;

	res = NULL;
	size = 0;
	if ((pcs = ft_check_pcs(av)) == 0)
		ft_error();
	if (!(tet = ft_create_tet(av, pcs)))
		ft_error();
	while (size * size < pcs * 4)
		size++;
	size += 5;
	while (res == NULL)
	{
		board = ft_create_board(size);
		if (ft_fill(tet, board, 2, 2))
			res = ft_board_dup(board, ft_strlen(board[0]));
		size++;
		free(board);
	}
	ft_print(res);
}
