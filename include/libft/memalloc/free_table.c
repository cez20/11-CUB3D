/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:42:36 by anarodri          #+#    #+#             */
/*   Updated: 2023/02/22 15:01:46 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_table(char **table)
{
	int	i;

	i = -1;
	if (table)
	{
		while (table[++i])
			xfree(table[i]);
		xfree(table);
	}
}
