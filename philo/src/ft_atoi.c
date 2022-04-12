/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:08:22 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/08 17:33:47 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

static int	out_of_bounds(char c, int sign)
{
	if (c == '8' && sign == 1)
		return (-1);
	else if (c == '8' && sign == -1)
		return (-2147483648);
	else if (c == '7' && sign == 1)
		return (2147483647);
	else if (c == '7' && sign == -1)
		return (-2147483647);
	else if (c >= '7' && sign == 1)
		return (-1);
	else if (c >= '8' && sign == -1)
		return (-1);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while (isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (ft_isdigit(str[i]))
	{
		if ((i == 9 && sign == 1) || (i == 10 && sign == -1))
			return (out_of_bounds(str[i], sign));
		if (i > 9)
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		result = result * 10 + (str[i++] - '0');
	}
	return (sign * result);
}
