/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:50:08 by seungjki          #+#    #+#             */
/*   Updated: 2022/08/18 15:21:38 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ftt_base_put_in(char *hex)
{
	int	idx;

	idx = 0;
	while (idx < 10)
	{
		hex[idx] = '0' + idx;
		idx ++;
	}
	while (idx - 10 < 6)
	{
		hex[idx] = 'a' - 10 + idx;
		idx ++;
	}
	hex[idx] = '\0';
}

unsigned long long	hexi(unsigned long long n)
{
	unsigned long long	front_numb;

	front_numb = 1;
	while (n / front_numb != 0)
		front_numb = front_numb * 16;
	front_numb = front_numb / 16;
	return (front_numb);
}

int	ft_memory(unsigned long long n)
{
	int					idx;
	unsigned long long	front_numb;
	char				hex[17];

	idx = 0;
	ftt_base_put_in(hex);
	if (n == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else if (n >= 0x1000000000000000)
		front_numb = 0x1000000000000000;
	else
		front_numb = hexi(n);
	idx = 2;
	write(1, "0x", 2);
	while (front_numb > 0)
	{
		write(1, hex + (n / front_numb), 1);
		n = n % front_numb;
		front_numb = front_numb / 16;
		idx ++;
	}
	return (idx);
}
