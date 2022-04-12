/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:56:39 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/13 00:00:45 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t	get_current_time(void)
{
	size_t			time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	serve_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->forks_n)
	{
		table->philos[i]->right = table->forks[i];
		table->philos[i]->left = table->forks[(i + 1) % table->forks_n];
		i++;
	}
}

int	is_dead(t_philo **philos, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (!philos[i]->alive)
		{
			printf("%zu %d died\n", get_current_time(), philos[i]->id);
			return (1);
		}
		i++;
	}
	return (0);
}

int	all_full(t_table *table, int length)
{
	int	i;

	i = 0;
	if (table->eat_times < 0)
		return (0);
	while (i < length)
	{
		if (table->philos[i]->eat_times < table->eat_times)
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_sleep(size_t ms)
{
	size_t	time;

	time = get_current_time();
	while (time + ms > get_current_time())
		usleep(10);
	return (time);
}
