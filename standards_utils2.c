/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   standards_utils2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 16:17:16 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/22 14:55:51 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_string(char *str)
{
	int printed_chars;

	printed_chars = 0;
	if (str == 0)
	{
		return (-1);
	}
	while (str[printed_chars] != '\0')
	{
		print_char(str[printed_chars]);
		printed_chars++;
	}
	return (printed_chars);
}

int		print_unsigned(unsigned int number)
{
	if (number >= 10)
	{
		print_number((number / 10));
	}
	print_char(((number % 10) + '0'));
	return (get_unsigned_len(number));
}

void	put_number(long number)
{
	if (number < 0)
	{
		print_char('-');
		number = number * -1;
	}
	if (number >= 10)
	{
		print_number((number / 10));
	}
	print_char(((number % 10) + '0'));
}

int		print_number(long number)
{
	put_number(number);
	return (get_diglen(number));
}

int		print_hex(char *hex_str)
{
	int	hex_length;

	hex_length = print_string(hex_str);
	return (hex_length);
}
