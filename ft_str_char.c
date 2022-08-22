/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 04:19:21 by seungjki          #+#    #+#             */
/*   Updated: 2022/08/17 13:44:47 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	ft_str(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[idx])
	{
		write(1, str + idx, 1);
		idx ++;
	}
	return (idx);
}

int	ft_char(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}
