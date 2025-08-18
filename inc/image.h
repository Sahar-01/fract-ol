/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:51:38 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/18 17:51:44 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;
#endif
