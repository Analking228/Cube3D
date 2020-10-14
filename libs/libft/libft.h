/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:41:03 by flexer            #+#    #+#             */
/*   Updated: 2020/05/25 11:15:35 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define ADD 1
# define REMOVE 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <stdlib.h>

/*
						************* MEMORY FUNCTIONS *************
*/

void				*ft_memset(void *dest, int c, size_t n);
void				ft_bzero(void *dest, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
						************* STRING FUNCTIONS *************
*/

void				ft_putstr(char *s);
void				ft_putendl(char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *str, char const *set);
char				**ft_split(char const *s, char c);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
void				*ft_calloc(size_t num, size_t sizeb);
char				*ft_strdup(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_substr(char const *s, unsigned int c, size_t len);
char				*ft_strjoin(char const *prestr, char const *sufstr);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr (const char *big, const char *little, size_t n);

/*
						************* CHAR FUNCTIONS  **************
*/
void				ft_putchar(char c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);
int					ft_isblank(int c);

/*
						********* TYPE CONVERTION FUNCTIONS ***********
*/

int					ft_atoi(const char *s);
char				*ft_itoa(int n);

/*
						************** FD FUNCTIONS ****************
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
						************* LIST FUNCTIONS **************
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*
				******* GNL *******
*/

int					get_next_line(int fd, char **line);

/*
				***** MEMORY_MANAGER *****
*/

void				free_mem(void *ptr);
void				*malloc_mem(size_t size);
void				*calloc_mem(size_t nmem, size_t size);
void				mem_manager(void *ptr, int action);

#endif
