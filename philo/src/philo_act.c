/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:41:59 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/13 12:57:41 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_fork.h>

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("%zu %d is thinking\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("%zu %d is sleeping\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	ft_sleep(philo->time_to_sleep);
	philo_think(philo);
}

int	philo_die(t_philo *philo)
{
	if (philo->born_at + philo->time_to_die < get_current_time())
	{
		philo->alive = 0;
		return (1);
	}
	return (0);
}

void	philo_eat(t_philo *philo)
{
	if (philo->left != philo->right)
		take_forks(philo);
	if (philo->left->holder == philo && philo->right->holder == philo
		&& philo->left != philo->right)
	{
		philo->born_at = get_current_time();
		pthread_mutex_lock(philo->print_mutex);
		printf("%zu %d is eating\n", philo->born_at, philo->id);
		pthread_mutex_unlock(philo->print_mutex);
		ft_sleep(philo->time_to_eat);
		philo_put_fork(philo->left);
		philo_put_fork(philo->right);
		philo->eat_times++;
		philo_sleep(philo);
	}
}

void	*start_philo(void *context)
{
	t_philo	*philo;

	philo = context;
	philo->born_at = get_current_time();
	philo_think(philo);
	while (!philo_die(philo))
		philo_eat(philo);
	return (0);
}
