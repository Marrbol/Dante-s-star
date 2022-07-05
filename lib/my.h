/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** for the function
*/

#ifndef MY_H_
    #define MY_H_
        void my_putchar(char c);
        int my_putstr(char const *str);
        int my_printf(char *s, ...);
        int my_strlen(char const *str);
        int my_getnbr(char const *str);
        char *my_read(char *buffer, char *filepath);
        char **my_str_to_array(char *str, char delim);
        int **char_to_binair(char **map, int size);
        char **load_2d_arr_from_file(char const *str, int nb_rows,
        int nb_cols);
        int my_strlen_first_line(char const *str);
        void print_2d_func(char **str);
        void print_2d_int_func(int **str);
        char **str_to_array(char const *str, char delim);
        int my_strcmp(char const *s1, char const *s2);
        int one_line(char **map);
        int get_nbr_line(char **str);
    typedef struct pos {
        int counter;
        int counter2;
        int x;
        int y;
        int number;
    }struct_pos;
#endif
