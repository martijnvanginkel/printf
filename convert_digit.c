/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_digit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 13:00:00 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/22 14:57:44 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_pre_chars(t_list *inf, int dig_l, int *i)
{
	if (!inf->pos && *i == (inf->width - inf->pre) - 1 && inf->pre > dig_l)
	{
		*i += print_char('-');
	}
	else if (!inf->pos && inf->pre <= dig_l && *i == (inf->width - dig_l) - 1)
	{
		*i += print_char('-');
	}
	else
	{
		if (*i > (inf->width - inf->pre) - 1)
			*i += print_char('0');
		else if (*i < inf->width - dig_l)
			*i += print_char(' ');
	}
}

int			bigger_diglen_than_pre(t_list *inf, int dig_l, long digit)
{
	int i;

	i = 0;
	while (inf->has_minus && i < inf->pre - dig_l)
	{
		if (i == 0 && !inf->pos)
		{
			dig_l--;
			i += print_char('-');
		}
		i += print_char('0');
	}
	while (!inf->has_minus && i < inf->width - dig_l)
	{
		print_pre_chars(inf, dig_l, &i);
	}
	print_digit_string(inf, digit, &i);
	return (i);
}

int			width_and_precision(t_list *info, long digit, int diglen)
{
	int	index;

	index = 0;
	if (info->pre >= info->width)
		index = only_precision(info, digit, diglen);
	else
	{
		if (info->width > info->pre && info->pre <= diglen && !info->has_zero)
			index = only_width(info, digit, diglen);
		else
		{
			index = bigger_diglen_than_pre(info, diglen, digit);
		}
	}
	return (index);
}

int			no_width_no_pre(t_list *info, long digit)
{
	int index;

	index = 0;
	if (!info->pos)
		index += print_char('-');
	index += print_number(digit);
	return (index);
}

int			convert_digit(t_list *info, long digit)
{
	int			index;
	int			dig_length;

	index = 0;
	dig_length = get_diglen(digit);
	if (digit < 0)
	{
		digit = digit * -1;
	}
	else
		info->pos = 1;
	if (info->has_width && !info->has_pre)
		index += only_width(info, digit, dig_length);
	else if (!info->has_width && info->has_pre)
		index += only_precision(info, digit, dig_length);
	else if (!info->has_width && !info->has_pre)
		index += no_width_no_pre(info, digit);
	else
		index += width_and_precision(info, digit, dig_length);
	free(info);
	return (index);
}
