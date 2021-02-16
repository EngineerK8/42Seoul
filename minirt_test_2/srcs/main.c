/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:08:25 by hekang            #+#    #+#             */
/*   Updated: 2021/02/16 13:14:49 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene *g_scene;
t_mlx_data *g_img;
t_vars g_vars;


int				exit_program(void)
{
	exit(0);
	return (0);
}
int            change_camera(t_scene *scene)
{
    t_img_data *data;
    printf("\n\n%p\n\n", (scene));
    printf("\n\n%p\n\n", (scene->cam));
    printf("\n\n%p\n\n", (scene->cam->next));
    printf("\n\n%p\n\n", (scene->cam->next->content));
    data = ((t_camera *)(scene->cam->next->content))->data;
    scene->cam = scene->cam->next;
    printf("aaaa\n");
    mlx_draw_by_img_data(g_img, data);
    printf("bbbb\n");
    mlx_put_image_to_window(g_vars.mlx, g_vars.win, g_img->img, 0, 0);
    printf("cccc\n");

    mlx_show(g_vars, g_img, data);
    return (1);
}

int				mlx_key_handle(int keycode)
{
    printf("keycode : %d\n", keycode);
	if (keycode == 53)
		return (exit_program());
    if (keycode == 8) // c
        return (change_camera(g_scene));
	return (0);
}

int     mouse_button_handle(int button, int x, int y, void *p)
{
        printf("Mouse_button in Win, button %d at %dx%d.\n", button, x, y); 
        return ((int)p);
}  

int main(int argc, char *argv[])
{
    // t_img_data  *data;
    // t_camera    *cam;
    // double      aspect_ratio;
    // int         image_width;
    // t_sphere    *s;
    // t_list      *hitlst;
    // t_plane     *pl;
    // t_light     *l;
    // t_ambient   *A;
    t_scene     *scene;
    int         n;

    if (argc == 3)
    {
        if (ft_strnstr(argv[2], "--save", 6))
        //    save_bmp;
            argc = 1;
        else
        {
            printf("ERROR : Input Argument\n");
            return (0);
        }

    }
    if (argc == 1)
    {
        printf("ERROR : Input Argument\n");
        return (0);
    }


    // if ((argc = 3 && ft_strnstr(argv[2], "--save", 6)) || argc == 0)
    // {
    //     printf("ERROR : Input Argument\n");
    //     return (0);
    // }
    argc = 1;
    scene = parse(argv[1]);
    // image_width = 1080;
    // double image_height = 720;
    // aspect_ratio = image_width / image_height;
    // // cam = init_cam(vec_create(-2, 2, 5), vec_create(1, -1, -1), aspect_ratio, 130 * PI / 180.0);
    // cam = init_cam(scene, vec_create(-50, 0, 20), vec_create(1, 0, 0), 70 * PI / 180.0);
    // // data = create_img_data(image_width, (int)(image_width / aspect_ratio));
    // data = create_img_data(image_width, image_height);
    // cam->data = data;
    // A = init_ambient(0.2, vec_create(1, 1, 1));
    // l = init_light(vec_create(-40, 20, 20), 0.7, vec_create(1, 1, 1));
    // hitlst = hitlst_new();
    // s = init_sphere(vec_create( -10, 10, 20), 4, vec_create(0, 1, 0));
    // hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
    // s = init_sphere(vec_create( -30, -40, -20), 4, vec_create(0, 1, 0));
    // hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
    // s = init_sphere(vec_create( 0, 0, 30), 4, vec_create(1, 0, 0));
    // hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
    // s = init_sphere(vec_create( 10, 0, 10), 4, vec_create(0, 0, 1));
    // hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
    // pl = init_plane(vec_create(0, -4, 0), vec_create(0, -1, 0), vec_create(0.2, 0.2, 0.2));
    // hitlst_add(hitlst, (void *)pl, OBJ_PLANE);
    // draw_hittable(cam, hitlst, l);
    n = 0;
    // printf("scene->n_cam : %d \n", scene->n_cam);
    // while (n < scene->n_cam)
    // {
    //     printf("111\n");
    //     draw_hittable(scene);
    //     if (scene->cam->next)
    //         scene->cam = scene->cam->next;
    //     n++;
    // }
    t_camera *cam_1 = ((t_camera *)(scene->cam->content));
    t_camera *cam_2 = ((t_camera *)(scene->cam->next->content));
    t_camera *cam_3 = ((t_camera *)(scene->cam->next->next->content));
    t_camera *cam_b = ((t_camera *)(scene->cam->next->next->next->content));
    t_camera *cam_c = ((t_camera *)(scene->cam->next->next->next->next->content));
    double a = cam_1->origin->y;
    double b = cam_2->origin->y;
    double c = cam_3->origin->y;
    double d = cam_b->origin->y;
    double e = cam_c->origin->y;
    printf(" 1 : %f / 2 : %f / 3 : %f / 4 : %f / 5 : %f\n\n\n", a,b,c,d,e);



        draw_hittable(scene);


    t_vars      vars;
    t_img_data *data;
    t_mlx_data  *img;

    data = ((t_camera *)(scene->cam->content))->data;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, data->width, data->height, "miniRT");


    img = (t_mlx_data *)malloc(sizeof(t_mlx_data));
    img->img = mlx_new_image(vars.mlx, data->width, data->height);
    img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
                    &(img->line_length), &(img->endian));

    g_vars = vars;
    g_img = img;
    g_scene = scene;
    mlx_show(vars, img, data);
    mlx_hook(vars.win, X_KEY_PRESS, 0, mlx_key_handle, 0);
    mlx_mouse_hook(vars.win, mouse_button_handle, 0);
    mlx_loop(vars.mlx);
    // mlx_show(scene, ((t_camera *)(scene->cam->content))->data, "miniRT");
    // scene->cam = scene->cam->next;
    // mlx_show(((t_camera *)(scene->cam->next->content))->data, "miniRT2");

    // scene->cam = scene->cam->next;
    // mlx_show(((t_camera *)(scene->cam->content))->data, "miniRT");
}
