/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:38:12 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/13 15:53:11 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_fork.h>

int	philo_take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->holder = philo;
	pthread_mutex_lock(philo->print_mutex);
	printf("%zu %d has taken a fork\n", get_current_time(), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	return (1);
}

void	philo_put_fork(t_fork *fork)
{
	fork->holder = NULL;
	pthread_mutex_unlock(&fork->mutex);
}

int	take_forks(t_philo *philo)
{
	if (philo->id == philo->philos_n)
	{
		philo_take_fork(philo, philo->left);
		philo_take_fork(philo, philo->right);
		return (1);
	}
	philo_take_fork(philo, philo->right);
	philo_take_fork(philo, philo->left);
	return (1);
}
