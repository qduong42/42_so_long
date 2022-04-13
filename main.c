#include "mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main (void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	

	mlx = mlx_init();
	mlx_win = mlx_new_window (mlx, 1920, 1080, "Hello World!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int offset = (1080 * img.line_length + 1920 * (img.bits_per_pixel / 8));
	int x = 50;
	int y = 50;
	while (x <= 1000)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FFFF00);
		while(y <= 1000)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FFFF00);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
