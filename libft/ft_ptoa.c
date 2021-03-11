/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ptoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 00:19:48 by fbes          #+#    #+#                 */
/*   Updated: 2021/03/11 02:33:22 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ptr_loop(char *ret, intptr_t ptr)
{
	static char	base[] = "0123456789abcdef";

	if (ptr != 0)
	{
		ptr_loop(ret - 1, ptr / 16);
		*ret = base[ptr % 16];
	}
}

char	*ft_ptoa(intptr_t ptr)
{
	char	*ret;
	int		num_len;

	num_len = ft_numlen(ptr, 16);
	ret = ft_calloc(num_len + 3, sizeof(char));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, "0x", 2);
	if (ptr == 0)
		ret[2] = '0';
	else
		ptr_loop(ret + num_len - 1, ptr);
	return (ret);
}
