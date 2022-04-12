/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:50:58 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/09 19:33:46 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	clean_forks(t_fork ***context, int length)
{
	int		i;
	t_fork	**forks;

	if (!context)
		return ;
	forks = *context;
	if (!forks)
		return ;
	i = 0;
	while (i < length)
	{
		pthread_mutex_destroy(&forks[i]->mutex);
		free(forks[i]);
		forks[i] = NULL;
		i++;
	}
	free(forks);
	*context = NULL;
}

void	clean_philos(t_philo ***context, int length)
{
	int		i;
	t_philo	**philos;

	if (!context)
		return ;
	philos = *context;
	if (!philos)
		return ;
	i = 0;
	while (i < length)
	{
		free(philos[i]);
		philos[i] = NULL;
		i++;
	}
	free(philos);
	*context = NULL;
}

void	clean_table(t_table **context)
{
	t_table	*table;

	if (!(*context))
		return ;
	table = *context;
	if (!table)
		return ;
	if (table->philos)
		clean_philos(&table->philos, table->forks_n);
	if (table->forks)
		clean_forks(&table->forks, table->forks_n);
	free(table);
	*context = NULL;
}
