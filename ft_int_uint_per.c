/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_uint_per.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 03:52:26 by seungjki          #+#    #+#             */
/*   Updated: 2022/07/27 20:55:37 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	writing(long long n, long long ten_num)
{
	int		idx;
	char	cha;

	idx = 0;
	cha = 0;
	while (ten_num > 0)
	{
		cha = '0' + n / ten_num;
		write(1, &cha, 1);
		n = n % ten_num;
		ten_num = ten_num / 10;
		idx ++;
	}
	return (idx);
}

int	ft_int(long long n)
{
	int			idx;
	long long	ten_num;
	long long	flag;

	idx = 0;
	ten_num = 1000000000;
	flag = n;
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
		idx ++;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (!(flag / ten_num))
		ten_num = ten_num / 10;
	return (idx + writing(n, ten_num));
}

int	ft_uint(unsigned int n)
{
	long long	ten_num;
	long long	flag;

	ten_num = 1000000000;
	flag = (long long)n;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (!(flag / ten_num))
		ten_num = ten_num / 10;
	return (writing(n, ten_num));
}

int	ft_per(void)
{
	write(1, "%", 1);
	return (1);
}
