/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:38:29 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/10 20:39:49 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FORK_H
# define PHILO_FORK_H
# include <philo.h>

int		philo_take_fork(t_philo *philo, t_fork *fork);
int		take_forks(t_philo *philo);
void	philo_put_fork(t_fork *fork);
#endif