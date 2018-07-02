/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:20:50 by tcollard          #+#    #+#             */
/*   Updated: 2017/12/11 14:04:07 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>

int					ft_check_nb_line(char *buf);
int					ft_check_nb_char(char *buf);
int					ft_check_char(char *buf);
int					ft_error_arg(int argc);
int					ft_error_file(int error);

typedef struct		s_pos
{
	size_t			x;
	size_t			y;
	size_t			size;
}					t_pos;

typedef	struct		s_tetri
{
	char			*tetri;
	struct s_tetri	*next;
	int				ref;
	int				index;
}					t_tetri;
size_t				ft_sqrt(size_t nb);
size_t				ft_nb_tetris(t_tetri *lst);
t_tetri				*ft_check_is_tetri(char *buf);
t_tetri				*ft_read_src(char *pathname);
t_tetri				*ft_tetri_new(char *str, int *index);
t_tetri				*ft_fill_tetri(char *buf, int *index);
void				*ft_tetri_push_back(t_tetri *begin, t_tetri *new);
void				*ft_lst_tetri(t_tetri *begin, char *buf, int *index);
int					ft_cmp_tetri(char *str);
char				**ft_lib_tetri_init(void);
char				**tetris(t_tetri *lst, t_pos a);
void				ft_fct_tab(int (*ref_tetris[19])(char **, t_tetri *,
					t_pos, t_pos));
void				ft_memdel2(char **ap);
t_pos				pass_char(char *tetris, char c, int equal);
void				tetris_display(char **tetris);
int					tetris_fill(t_tetri *lst, char **tetris_full, t_pos a);
void				ft_memdel2(char **ap);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
int					ref0(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref1(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref2(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref3(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref4(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref5(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref6(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref7(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref8(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref9(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref10(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref11(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref12(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref13(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref14(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref15(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref16(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref17(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
int					ref18(char **tetris_full, t_tetri *lst, t_pos a, t_pos b);
void				tetris_point_fill(char **tetris_full, size_t size);
char				*ft_strreplace(char *str, int index);
char				**ft_lib_tetri_init(void);
char				*ft_strctrim(char *s, char c);
char				*ft_del_char(char *str);
void				ft_lstclear(t_tetri **begin);
char				**grow_size(char **tetris_full);

#endif
