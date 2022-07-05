/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:26:05 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:26:17 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef struct s_list
{
	int				value;
	int				rot_a;
	int				rot_b;
	int				rrot_a;
	int				rrot_b;
	int				pot;
	int				bool;
	int				lst_size;
	int				r_a;
	int				r_b;
	struct s_list	*sort_lst;
	struct s_list	*next;
	struct s_list	*back;
}	t_list;

int		ft_tolower(int n);
int		ft_toupper(int n);
int		ft_atoi(const char *str);
int		ft_isalnum(int n);
int		ft_isalpha(int n);
int		ft_isascii(int n);
int		ft_isdigit(int n);
int		ft_isprint(int n);
int		ft_lstsize(t_list *lst);
int		ft_strlen_char(const char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_itoa(int n);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *str, int a);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *str1, const char *str2, size_t len);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strrchr(const char *str, int a);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *str1, const char *str2, size_t len);
size_t	ft_strlen(const char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
void	*ft_memchr(const void *str, int s, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
#endif
