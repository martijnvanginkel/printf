/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_digit_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 15:42:03 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/22 14:38:04 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		only_width_minus(t_list *info, long digit, int *i)
{
	if (!info->pos)
		*i += print_char('-');
	print_digit_string(info, digit, i);
}

int			only_width(t_list *inf, long digit, int diglen)
{
	int i;

	i = 0;
	if (inf->has_minus)
	{
		only_width_minus(inf, digit, &i);
	}
	else
	{
		if (i == 0 && !inf->pos && (inf->has_zero || diglen >= inf->width - 1))
			i += print_char('-');
		while (i < inf->width - diglen)
		{
			inf->has_zero ? print_char('0') : print_char(' ');
			i++;
			if (i == (inf->width - diglen) - 1 && !inf->pos && !inf->has_zero)
				i += print_char('-');
		}
		if (inf->has_pre && inf->pre == 0 && digit == 0)
			i += print_char(' ');
		else
			i += print_number(digit);
	}
	return (i);
}

int			only_precision(t_list *info, long digit, int dig_length)
{
	int index;

	index = 0;
	if (digit == 0 && info->pre == 0)
		return (0);
	if (!info->pos)
	{
		index += print_char('-');
		dig_length--;
	}
	while (index < info->pre - dig_length)
		index += print_char('0');
	index += print_number(digit);
	return (index);
}

void		print_digit_string(t_list *info, long digit, int *index)
{
	if (!info->pos && (*index) == 0)
		(*index) += print_char('-');
	if (digit == 0 && info->has_width && info->has_pre && info->pre == 0)
		(*index) += print_char(' ');
	else
		(*index) += print_number(digit);
	while ((*index) < info->width)
		(*index) += print_char(' ');
}
