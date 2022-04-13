/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:54:49 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/13 13:38:30 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_fork
{
	struct s_philo	*holder;
	pthread_mutex_t	mutex;
	int				id;
}	t_fork;

typedef struct s_philo
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					alive;
	pthread_t			philo;
	int					eat_times;
	int					id;
	t_fork				*left;
	t_fork				*right;
	size_t				born_at;
	pthread_mutex_t		*print_mutex;
	int					philos_n;
}	t_philo;

typedef struct s_table
{
	struct s_philo	**philos;
	t_fork			**forks;
	int				forks_n;
	int				eat_times;
}	t_table;

size_t	get_current_time(void);
int		ft_atoi(const char *str);
t_table	*philos_init(int argc, char **argv);
void	clean_forks(t_fork ***forks, int length);
void	clean_philos(t_philo ***philos, int length);
void	clean_table(t_table **table);

void	serve_table(t_table *table);
void	*start_philo(void *context);
int		all_full(t_table *table, int length);
int		is_dead(t_philo **philos, int length);
int		philo_die(t_philo *philo);
size_t	ft_sleep(size_t ms);
t_table	*new_table(int philo_n, int die, int eat, int sleep);

#endif
