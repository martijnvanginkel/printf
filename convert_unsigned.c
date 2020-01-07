/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_unsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 17:28:59 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/19 18:07:06 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			only_width_u(t_list *inf, unsigned int digit, int diglen)
{
	int i;

	i = 0;
	if (inf->has_minus)
	{
		print_digit_string_u(inf, digit, &i);
	}
	else
	{
		while (i < inf->width - diglen)
		{
			inf->has_zero ? print_char('0') : print_char(' ');
			i++;
		}
		if (inf->has_pre && inf->pre == 0 && digit == 0)
			i += print_char(' ');
		else
			i += print_unsigned(digit);
	}
	return (i);
}

int			bigger_diglen_than_pre_u(t_list *inf, int dig_l, unsigned int digit)
{
	int i;

	i = 0;
	while (inf->has_minus && i < inf->pre - dig_l)
	{
		i += print_char('0');
	}
	while (!inf->has_minus && i < inf->width - dig_l)
	{
		if (i > (inf->width - inf->pre) - 1)
			i += print_char('0');
		else if (i < inf->width - dig_l)
			i += print_char(' ');
	}
	print_digit_string_u(inf, digit, &i);
	return (i);
}

int			width_and_precision_u(t_list *info, unsigned int digit, int diglen)
{
	int	index;

	index = 0;
	if (info->pre >= info->width)
		index = only_precision_u(info, digit, diglen);
	else
	{
		if (info->width > info->pre && info->pre <= diglen && !info->has_zero)
			index = only_width_u(info, digit, diglen);
		else
		{
			index = bigger_diglen_than_pre_u(info, diglen, digit);
		}
	}
	return (index);
}

int			no_width_no_pre_u(unsigned int digit)
{
	int index;

	index = 0;
	index += print_unsigned(digit);
	return (index);
}

int			convert_unsigned(t_list *info, unsigned int digit)
{
	int		index;
	int		dig_length;

	index = 0;
	dig_length = get_unsigned_len(digit);
	info->pos = 1;
	if (info->has_width && !info->has_pre)
		index += only_width_u(info, digit, dig_length);
	else if (!info->has_width && info->has_pre)
		index += only_precision_u(info, digit, dig_length);
	else if (!info->has_width && !info->has_pre)
		index += no_width_no_pre_u(digit);
	else
		index += width_and_precision_u(info, digit, dig_length);
	free(info);
	return (index);
}
