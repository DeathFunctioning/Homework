/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:17:30 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/30 15:48:57 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int x)
{
	if (x >= 48 && x <= 57)
		return (1);
	else
		return (0);
}
