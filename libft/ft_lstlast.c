/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:57:27 by dzubkova          #+#    #+#             */
/*   Updated: 2023/11/22 17:54:00 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst);

/*int	main(void)
{
	t_list *l = NULL;
	ft_lstadd_front(&l, ft_lstnew((void*) 1));
	ft_lstadd_front(&l, ft_lstnew((void*) 2));
	printf("%p\n", ft_lstlast(l));
	return (0);
}*/

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
