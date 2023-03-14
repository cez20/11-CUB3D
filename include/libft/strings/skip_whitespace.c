/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:32:46 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/14 15:32:47 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#define WHITESPACE " \n\t\v\r\f"

void	skip_whitespaces(char **str)
{
	if (!*str || !**str)
		return ;
	while (**str && ft_isset(**str, WHITESPACE))
		*str += 1;
	return ;
}
