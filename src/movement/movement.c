#include "cub3d.h"

void	input_check(t_data *data)
{
	if (data->key.w == true)
		printf("w press\n");
	if (data->key.a == true)
		printf("a press\n");
	if (data->key.s == true)
		printf("s press\n");
	if (data->key.d == true)
		printf("d press\n");
	if (data->key.left_arr == true)
		printf("left arrow press\n");
	if (data->key.right_arr == true)
		printf("right arrow press\n");
	if (data->key.esc == true)
		close_window(data);
}

//TODO: changer les prints de sorte a ce que ca update la position
