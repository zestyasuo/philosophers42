/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:55:39 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/13 13:21:40 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_print_mutex(t_philo **philos,
	pthread_mutex_t *print_mutex, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		philos[i]->print_mutex = print_mutex;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table				*table;
	int					i;
	pthread_mutex_t		print_mutex;

	table = NULL;
	if (argc == 5 || argc == 6)
		table = philos_init(argc, argv);
	if (!table)
		return (write(2, "Invalid arguments\n", 18) - 18);
	serve_table(table);
	pthread_mutex_init(&print_mutex, NULL);
	philo_print_mutex(table->philos, &print_mutex, table->forks_n);
	i = 0;
	while (i < table->forks_n)
	{
		pthread_create(&table->philos[i]->philo, NULL,
			&start_philo, table->philos[i]);
		pthread_detach(table->philos[i]->philo);
		i++;
	}
	while (!is_dead(table->philos, table->forks_n)
		&& !all_full(table, table->forks_n))
		usleep(10);
	pthread_mutex_destroy(&print_mutex);
	clean_table(&table);
}
