/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   standards_utils1.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 16:16:29 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/20 13:47:18 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	make_upper_on_yes(char c, int yes)
{
	if ((c >= 'a' && c <= 'z') && yes == 1)
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

int		is_digit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}
