/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u32_to_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:56:14 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 15:42:06 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/source_util.h"

u32	u32numlen(u32 n)
{
	u32	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*u32_to_ascii(u32 c)
{
	char	*str;
	u32		num;
	u32		len;

	len = u32numlen(c);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (c < 0)
	{
		str[0] = '-';
		num = -c;
	}
	else
		num = c;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}