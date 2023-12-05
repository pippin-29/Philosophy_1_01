/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:27:24 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 11:05:42 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SOURCE_UTIL_H
# define SOURCE_UTIL_H
# include <stdarg.h>
# include <stdlib.h>

typedef unsigned long long	u64;
typedef unsigned int		u32;

typedef struct s_strjoin_e
{
	va_list	arg;
	char	*out;
	char	*tmp;
	int		i;
	int		j;
}	t_sje;

/// STRJOIN_E_C ///
int		ft_strlen(char *s);
void	*malloc_strlen_n(unsigned int c, va_list arg);
char	*strjoin_e(unsigned int c, ...);

/// U32_TO_ASCII ///
char	*u32_to_ascii(u32 c);

/// U64_TO_ASCII ///
char	*u64_to_ascii(u64 c);
u32		numlen(int n);

#endif
