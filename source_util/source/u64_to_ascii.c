/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u64_to_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:56:17 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 15:41:59 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/source_util.h"

u32	u64numlen(u64 n)
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

char	*u64_to_ascii(u64 c)
{
	char	*str;
	u64		num;
	u32		len;

	len = u64numlen(c);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
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