/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:41:51 by vvoytenk          #+#    #+#             */
/*   Updated: 2017/11/20 19:41:53 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitespaces(char c)
{
	return (c == '\n' || c == ' ' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r');
}
