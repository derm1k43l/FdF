/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:07:52 by mrusu             #+#    #+#             */
/*   Updated: 2023/10/13 18:04:04 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Return value None
External functs. write
Description Outputs the string ’s’ to the given file
descriptor.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
