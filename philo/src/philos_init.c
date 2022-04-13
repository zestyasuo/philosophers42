/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:59:06 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/13 13:40:38 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philo	*new_philo(int time_to_die, int time_to_eat, int time_to_sleep)
{
	t_philo	*philo;

	philo = malloc(sizeof(*philo));
	if (!philo)
		return (NULL);
	philo->time_to_die = time_to_die;
	philo->time_to_eat = time_to_eat;
	philo->time_to_sleep = time_to_sleep;
	philo->eat_times = 0;
	philo->philo = 0;
	philo->left = NULL;
	philo->right = NULL;
	philo->alive = 1;
	philo->philos_n = 0;
	return (philo);
}

t_fork	*new_fork(int id)
{
	t_fork	*new_fork;

	new_fork = malloc(sizeof(*new_fork));
	if (!new_fork)
		return (NULL);
	pthread_mutex_init(&new_fork->mutex, NULL);
	new_fork->id = id;
	new_fork->holder = NULL;
	return (new_fork);
}

t_philo	**get_philo_arr(t_philo *model, int philo_n)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = malloc(philo_n * sizeof(*philos));
	if (!philos)
		return (NULL);
	while (i < philo_n)
	{
		philos[i] = new_philo(model->time_to_die,
				model->time_to_eat,
				model->time_to_sleep);
		if (!philos[i])
		{
			clean_philos(&philos, i);
			free(model);
			return (NULL);
		}
		philos[i]->id = i + 1;
		philos[i]->philos_n = philo_n;
		i++;
	}
	free(model);
	return (philos);
}

t_fork	**get_forks_arr(int number)
{
	int				i;
	t_fork			**forks;

	i = 0;
	forks = malloc(sizeof(*forks) * number);
	if (!forks)
		return (NULL);
	while (i < number)
	{
		forks[i] = new_fork(i + 1);
		if (!forks[i])
		{
			clean_forks(&forks, i);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

t_table	*new_table(int philo_n, int die, int eat, int sleep)
{
	t_table	*table;

	if (philo_n <= 0 || die <= 0 || eat <= 0 || sleep <= 0)
		return (NULL);
	table = malloc(sizeof(*table));
	if (!table)
		return (NULL);
	table->eat_times = -1;
	table->forks_n = philo_n;
	table->philos = get_philo_arr(new_philo(die,
				eat, sleep), philo_n);
	table->forks = get_forks_arr(philo_n);
	if (!table->philos || !table->forks)
	{
		free(table);
		return (NULL);
	}
	return (table);
}
