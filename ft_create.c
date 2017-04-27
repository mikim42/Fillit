/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:00:51 by mikim             #+#    #+#             */
/*   Updated: 2017/03/17 15:45:07 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_create_tet2(char *buf, int n)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(tmp = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	tmp[4] = NULL;
	while (i < 4)
	{
		if (!(tmp[i] = (char*)malloc(5)))
			return (NULL);
		j = 0;
		while (j < 4)
			tmp[i][j++] = buf[k++];
		tmp[i++][j] = '\0';
		k++;
	}
	ft_check_block(tmp);
	ft_convert_block(tmp, n);
	return (tmp);
}

char	***ft_create_tet(char *av, int pcs)
{
	char	***tet;
	char	buf[22];
	int		ret;
	int		fd;
	int		i;

	i = -1;
	if (!(tet = (char***)malloc(sizeof(char**) * pcs + 1)))
		return (NULL);
	tet[pcs] = NULL;
	if (0 > (fd = open(av, O_RDONLY)))
		ft_usage();
	while ((ret = read(fd, buf, 21)) && ++i < 27)
	{
		buf[ret] = '\0';
		if (ret != 21 && buf[ret - 2] == '\n')
			ft_error();
		tet[i] = ft_create_tet2(buf, i);
	}
	return (tet);
}

char	**ft_board_dup(char **board, int size)
{
	char	**tmp;
	int		i;

	i = 0;
	if (!(tmp = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	tmp[size] = NULL;
	while (i < size)
	{
		if (!(tmp[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		tmp[i] = ft_strcpy(tmp[i], board[i]);
		i++;
	}
	return (tmp);
}

void	ft_format_board(char **board, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i < 3 || j < 3 || j > size - 4 || i > size - 4)
				board[i][j++] = '*';
			else
				board[i][j++] = '.';
		}
	}
}

char	**ft_create_board(int size)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(board = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	board[size] = NULL;
	while (i < size)
	{
		if (!(board[i] = (char*)malloc(sizeof(char*) * size + 1)))
			return (NULL);
		board[i][size] = '\0';
		i++;
	}
	ft_format_board(board, size);
	return (board);
}
