#include "../fdf.h"

int ft_key_hook(int keycode, t_fdf *fdf)
{
	printf("hello form key_hook %d\n", keycode);
	if (keycode == ARROW_RIGHT)
		fdf->camera->position[0] += 1;
	else if (keycode == ARROW_LEFT)
		fdf->camera->position[0] -= 1;
	else if (keycode == ARROW_UP)
		fdf->camera->position[2] += 1;
	else if (keycode == ARROW_DOWN)
		fdf->camera->position[2] -= 1;
	else if (keycode == KT)
		fdf->istriangle += (fdf->istriangle == 0)? 1: -1;
	else if (keycode == PLUS)
		fdf->map->coef += 0.1f;
	else if (keycode == MINUS)
		fdf->map->coef -= 0.1f;
	else if (keycode == KW)
		fdf->xfi += 0.05f;
	else if (keycode == KQ)
		fdf->xfi -= 0.05f;
	else if (keycode == KA)
		fdf->yfi -= 0.05f;
	else if (keycode == KS)
		fdf->yfi += 0.05f;
	return (0);
}	
