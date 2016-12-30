/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:12:13 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/22 15:21:33 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef unsigned char	t_byte;
typedef int				t_bool;
typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

# define ABS(value) (Value >= 0 ? Value : -Value)

int						ft_atoi(char const *str);
void					ft_bzero(void *s, size_t n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_islower(int c);
int						ft_isprint(int c);
int						ft_isspace(char c);
int						ft_isupper(int c);
int						ft_iswhite(char c);
char					*ft_itoa_base(int value, int base);
char					*ft_itoa(int value);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dst, void const *src,\
										int c, size_t n);
void					*ft_memchr(void const *s, int c, size_t n);
int						ft_memcmp(void const *s1, void const *s2, size_t n);
void					*ft_memcpy(void *dst, void const *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, void const *src, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					ft_print_memory(const void *addr, size_t size);
void					ft_putchar_fd(char c, int fd);
void					ft_putchar(char c);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putendl(char const *s);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr(int n);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putstr(char const *s);
char					**ft_split_whitespaces(char *str);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strchr(char const *s, int c);
void					ft_strclr(char *s);
int						ft_strcmp(char const *s1, char const *s2);
char					*ft_strcnew(size_t size, char c);
char					*ft_strcpy(char *dst, char const *src);
void					ft_strdel(char **as);
char					*ft_strdup(char const *s1);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dst, char const *src, size_t size);
size_t					ft_strlen(char const *s);
char					*ft_strlowcase(char *str);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,\
										char (*f)(unsigned int, char));
char					*ft_strncat(char *s1, const char *s2, size_t n);
int						ft_strncmp(char const *s1, char const *s2, size_t n);
char					*ft_strncpy(char *dst, char const *src, size_t len);
char					*ft_strndup(char const *s1, size_t n);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(char const *big, char const *little,\
									size_t len);
char					*ft_strrchr(char const *s, int c);
char					**ft_strsplit(char const *s, char c);
char					*ft_strstr(char const *big, char const *little);
char					*ft_strsub(char const *s, unsigned int start,\
									size_t len);
char					*ft_strtrim(char const *s);
char					*ft_strupcase(char *str);
void					ft_swap(int *a, int *b);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						get_next_line(const int fd, char **line);

#endif
