/*
** EPITECH PROJECT, 2018
** my_lemin.h
** File description:
** header of my project lemin
*/

#ifndef MY_LEMIN_H_
#define MY_LEMIN_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdbool.h>

struct block
{
    char *nb_block;
    int ants;
    int coord_x;
    int coord_y;
    bool first;
    bool end;
    int weight;
    int status;
    char *at;
    struct block **links;
};
typedef struct block block;

int my_getnbr(char *);
char **my_strcalloc(int);
char *my_calloc(int);
int is_digit(char);
int check_input(char **);
char *get_input(int);
int my_strlen(char *);
char *my_strdup(char *);
void my_putstr(char *);
char *my_strcat(char *, char *);
int get_return(char *, int);
int error_handling(char *);
int my_strncmp(char *, char *, int);
void my_put_nbr(int nb);
char *clear_input(char *);
int get_nb_rooms(char *);
int is_room(char *, int);
int is_link(char *, int);
void create_rooms(char *, block **);
int get_size_malloc(int, char *);
char *get_nb_block(char *, int);
int get_coord_x(char *, int);
int get_coord_y(char *, int);
bool is_first_room(char *, int);
bool is_end_room(char *, int);
int check_room_name(block **);
int my_strcmp(char *, char *);
int error_link(char *, struct block **);
int check_coord(block **);
void display_map(char *);
void set_algo(block *);
int get_distance(block *, block *);
void init_algo(block **, char *);
block **get_path(block **);
int my_put_nbr_to_str(int, char *, int);
void print_moves(block **, int);
void add_back(char *);
void add_move(char *, int, char *, int);
char *move_ants(block **, int);
int is_this_str(char *, char *, int);
void get_links(char *, block **, int);
char *cpy_str(char *, int);
int verif_it(char *, block **, int, int);
int go_to_links(char *);
int get_nb_rooms(char *);
int get_nb_links(char *, char *);
int get_size_str(char *, int);
int my_macro(int);

#endif /*MY_LEMIN_H_*/
