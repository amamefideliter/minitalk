/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:11:12 by dzubkova          #+#    #+#             */
/*   Updated: 2024/02/09 11:40:02 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst);

/*int	main(void)
{
	t_list *l =  ft_lstnew(malloc(1));
	ft_lstdelone(l, free);
	printf("%d\n", ft_lstsize(l));
}*/

void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		free(lst);
	}
}
