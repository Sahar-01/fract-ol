#ifndef IMAGE_H
# define IMAGE_H

typedef struct	s_image
{
	void	*image;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_image;

#endif
