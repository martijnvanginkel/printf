/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 15:50:14 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/12/19 15:54:50 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			no_width_no_pre_hex(char *hex_str)
{
	int index;

	index = 0;
	index += print_hex(hex_str);
	return (index);
}

void		print_hex_string(t_list *info, unsigned int dig, char *hex_str,
			int *index)
{
	if (dig == 0 && info->has_width && info->has_pre && info->pre == 0)
		(*index) += print_char(' ');
	else
		(*index) += print_hex(hex_str);
	while ((*index) < info->width)
		(*index) += print_char(' ');
}
