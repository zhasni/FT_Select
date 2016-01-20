/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:26:22 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/09 11:58:09 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_pix_to_image(t_env *env, int x, int y, int color)
{
	int		i;

	if (!env)
		return ;
	i = ((env->bpp / 8) * x) + ((env->sline) * y);
	{
		env->str[i] = color;
		env->str[i + 1] = (color) >> 8;
		env->str[i + 2] = (color) >> 16;
	}
}
