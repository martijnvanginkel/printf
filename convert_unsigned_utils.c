/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_unsigned_utils.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 16:44:08 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/19 16:47:13 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_digit_string_u(t_list *info, unsigned int digit, int *index)
{
	if (digit == 0 && info->has_width && info->has_pre && info->pre == 0)
		(*index) += print_char(' ');
	else
		(*index) += print_unsigned(digit);
	while ((*index) < info->width)
		(*index) += print_char(' ');
}

int			only_precision_u(t_list *info, unsigned int digit, int dig_length)
{
	int index;

	index = 0;
	if (digit == 0 && info->pre == 0)
		return (0);
	while (index < info->pre - dig_length)
		index += print_char('0');
	index += print_unsigned(digit);
	return (index);
}
