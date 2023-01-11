/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:53:40 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/11 19:50:34 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define X 0
# define Y 1
# define Z 2

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define ROJO 		0xc1272d
# define VERDE		0x33cc55
# define FUCSIA 	0xff255c
# define AZUL		0x1B8EFA
# define CARBON		0x151515
# define WHITE		0xBBBBBB
# define DISCO		0x9A1F6A
# define BRICK_RED	0xC2294E
# define FLAMINGO	0xEC4B27
# define JAFFA		0xEF8633
# define SAFFRON	0xF3AF3D
# define BLACK		0x000000

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_point{
	float	axes[3];
	int		color;
}	t_point;

typedef struct	s_map{
	t_point	*points;
	t_point	limits;
	t_point	source;
	float	ang[3];
	float	divisor;
	int		len;
	float	scale;
	int		total;
}	t_map;

typedef struct	s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_vars;

typedef struct	s_meta {
	t_vars	vars;
	t_data	data;
	t_map	map;
}	t_meta;

#endif
