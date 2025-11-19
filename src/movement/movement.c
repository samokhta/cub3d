#include "cub3d.h"

bool	check_collsion(t_data *data, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(new_x);
	map_y = (int)(new_y);
	if (data->map.coor[map_y][map_x] == '1')
		return (false);
	return (true);
}

void	input_check(t_data *data)
{
	if (data->key.w == true && check_collsion(data, data->player.x, data->player.y - 0.2))
		data->player.y -= 0.2;
	if (data->key.a == true && check_collsion(data, data->player.x - 0.2, data->player.y))
		data->player.x -= 0.2;
	if (data->key.s == true && check_collsion(data, data->player.x, data->player.y + 0.2))
		data->player.y += 0.2;
	if (data->key.d == true && check_collsion(data, data->player.x + 0.2, data->player.y))
		data->player.x += 0.2;
	if (data->key.left_arr == true)
		printf("left arrow press\n");
	if (data->key.right_arr == true)
		printf("right arrow press\n");
	if (data->key.esc == true)
		close_window(data);
}

//TODO: update la position wasd de sorte a ce que ca depende de la camera
//TODO: fix leaks/invalid reads
