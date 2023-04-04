#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/ioctl.h>


typedef struct s_vec2
{
	float x;
	float y;
} t_vec2;

typedef struct s_vec3
{
	float x;
	float y;
	float z;
} t_vec3;

void	matmul2(t_vec2 *t_vec2, float n)
{
	t_vec2->x *= n;
	t_vec2->y *= n;
}

void	matmul3(t_vec3 *t_vec3, float n)
{
	t_vec3->x *= n;
	t_vec3->y *= n;
	t_vec3->z *= n;
}

float length2(t_vec2 *vec2)
{
	return sqrtf((vec2->x * vec2->x) + (vec2->y * vec2->y));
}

void	norm2(t_vec2 *vec2)
{
	float len; 

	len = length2(vec2);
	vec2->x /= len;
	vec2->y /= len;
}

int main()
{
	int w, h;
	char *screen;
	char pixel;
	float x, y;
	float aspect, pixel_aspect;
	t_vec2 uv;
	t_vec3 camera = {
		.x = 5,
		.y = 0,
		.z = 0
	};
	t_vec2 rd;

	struct winsize win;
	ioctl(1, TIOCGWINSZ, &win);

	w = win.ws_col;
	h = win.ws_row;

	aspect = (float)w / h;
	pixel_aspect = 8.0f / 17.0f;

	screen = (char *)malloc(sizeof(char) * (w * h + 1));
	screen[w * h] = 0;

	for (int t = 0; t < 10000; t++)
	{
		for (int col = 0; col < w; col++)
		{
			for (int row = 0; row < h; row++)
			{
				uv.x = (float)col / w * 2.0f - 1.0f;
				uv.y = (float)row / h * 2.0f - 1.0f;
				uv.x = uv.x * aspect * pixel_aspect;
				rd.x = x;
				rd.y = y;
				norm2(&rd);

				pixel = '#';
				uv.x = uv.x + sin(t * 0.001);

				if (uv.x * uv.x + uv.y * uv.y > 0.5) pixel = ' ';
				screen[col + row * w] = pixel;
			}
		}
		printf("\033[2H");
		printf("%s", screen);
	}
	/* printf("%d %d\n", w, h); */
	return (0);
}
