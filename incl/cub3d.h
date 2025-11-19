/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sravizza <sravizza@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:38:47 by sravizza          #+#    #+#             */
/*   Updated: 2025/11/19 13:32:47 by sravizza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <sys/types.h>
# include <stdbool.h>
# include "../libft/libft_src/libft.h"
# include "../libft/printf_src/ft_printf.h"
# include "../libft/gnl_src/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "struct.h"
# include "proto.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define WHITE 0xdddddd
# define BLACK 0x1c1c1c
# define GRAY 0x6b6b6b
# define GREEN 0x27e427
# define RED 0xc30d0d
# define BLUE 0x0d5cb7

# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

# define KEY_ESC		65307
# define KEY_SPACE		32
# define KEY_E			101

#endif