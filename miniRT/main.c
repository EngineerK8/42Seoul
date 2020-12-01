#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void		*mlx;
	void		*win;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int             key_hook(int keycode, t_data *vars)
{
    printf("Hello from key_hook!\n");
	return (1);
}

int		main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "miniRT!");
	img.img = mlx_new_image(mlx, 1920, 1080);// 이미지 instance 생성
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	for(int i = 0; i < 1080 ; i++) {
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);// ARGB(alpha red green blue)
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);// 붉은색 선을 세로으로 그린다.
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);// 붉은색 선을 가로으로 그린다.
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);//이미지를 윈도우에 올린다.
	mlx_key_hook(mlx_win, key_hook, &img);
	mlx_loop(mlx);
}
