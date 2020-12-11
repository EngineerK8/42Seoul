#!bin/bash
gcc -L ./mlx -lmlx -framework OpenGl -framework AppKit main.c
./a.out
