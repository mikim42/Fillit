/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 04:54:14 by mikim             #+#    #+#             */
/*   Updated: 2017/03/17 15:45:48 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s2[++i] != '\0')
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

int		ft_cmp(char *tet, char *board)
{
	int i;

	i = -1;
	while (tet[++i] != '\0')
		if (tet[i] != '.' && board[i] != '.')
			return (1);
	return (0);
}

int		ft_check_pcs(char *av)
{
	char	buf[2];
	int		fd;
	int		ret;
	int		i;

	i = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_usage();
	while ((ret = read(fd, buf, 1)))
	{
		buf[ret] = '\0';
		if (buf[0] != '#' && buf[0] != '.' && buf[0] != '\n' && buf[0] != '\0')
			ft_error();
		if (buf[0] == '\n')
			i++;
	}
	if ((i + 1) % 5 == 0)
		if ((i = (i + 1) / 5) < 27)
			return (i);
	return (0);
}
