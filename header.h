/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:27:06 by mikim             #+#    #+#             */
/*   Updated: 2017/03/19 00:40:24 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

void	ft_fillit(char *av);
void	ft_usage(void);
void	ft_error(void);
void	ft_print(char **res);
int		ft_strlen(char *s);
char	*ft_strcpy(char *s1, char *s2);
int		ft_cmp(char *tet, char *board);
int		ft_check_pcs(char *av);
void	ft_check_block(char **tet);
int		ft_check_block2(char **t);
void	ft_check_r(char **t, int x, int y, int *i);
void	ft_check_d(char **t, int x, int y, int *i);
void	ft_check_l(char **t, int x, int y, int *i);
void	ft_check_point(char **tet, int *ycnt, int *xcnt);
void	ft_convert_block(char **tmp, int n);
char	***ft_create_tet(char *av, int pcs);
char	**ft_create_tet2(char *buf, int n);
char	**ft_create_board(int size);
void	ft_format_board(char **board, int size);
char	**ft_board_dup(char **board, int size);
int		ft_fill(char ***tet, char **board, int y, int x);
void	ft_fill_back(char **board, int *y, int *x, int *n);
int		ft_fill_chk(char **tet, char **board, int y, int x);
void	ft_fill_put(char **tet, char **board, int y, int x);

#endif
