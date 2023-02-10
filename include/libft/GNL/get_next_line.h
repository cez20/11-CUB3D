/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:49:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/02/10 16:09:07 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_SIZE 4096
# define BUFFER_SIZE 1

# include "../libft.h"
# include <stddef.h>
# include <stdio.h>

char	*get_next_line(int fd);

#endif