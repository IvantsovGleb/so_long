#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include <OpenGL/gl3.h>
# include "mlx/mlx.h"
# include "mlx/mlx_new_window.h"
# include "mlx/mlx_int.h"

# include "libft/libft.h"

/* delete when done */
# include <stdio.h>
/*                  */

typedef enum e_bool
{
    FALSE,
    TRUE
}   t_bool;

typedef struct s_point
{
    int x;
    int y;
}       t_point;

enum e_keycode
{
    ESC = 53,
    W = 13,
    A = 0,
    S = 1,
    D = 2
};

# include "map/map.h"

# define TILE_SIZE      64

typedef enum e_tile_code
{
    EMP = '0',
    WLL = '1',
    COLL = 'C',
    EXT = 'E',
    PLR = 'P',
//    NPC = 'N'
}   t_tile_code;

typedef struct s_empty
{
    t_list  *lst_emp;
    void    *empty_img;
    t_point img_sz;
}           t_empty;

typedef struct s_wall
{
    t_list  *lst_wll;
    void    *box;
    void    *wall_top;
    void    *wall_mid;
    void    *up_corner_left;
    void    *up_corner_right;
    void    *left_side;
    void    *right_side;
    void    *down_corner_left;
    void    *down_corner_right;
    void    *down_left;
    void    *down_right;
    t_point img_sz;
}           t_wall;

typedef struct s_cl
{
    t_point pos;
    t_bool  collected;
}       t_cl;

typedef struct s_collectible
{
    t_list      *lst_cl;
    void        *curr_img;
    void        *gem0;
    void        *gem1;
    void        *gem2;
    void        *gem3;
    void        *gem4;
    t_point     img_sz;
    int         anim_frames;
    int         collects;
}           t_collectable;

typedef struct s_exit
{
    t_point pos;
    void    *curr_img;
    void    *idle0;
    void    *idle1;
    void    *idle2;
    void    *idle3;
    void    *idle4;
    void    *idle5;
    void    *idle6;
    t_point img_sz;
    int     anim_frames;
    t_bool  opened;
}           t_exit;

enum e_movement_dir
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef enum e_mob_type
{
    KNIGHT,
    NPC
}   t_mob_type;

typedef struct s_mob
{
    t_point     coords;
    t_point     old_coords;
    void        *curr_img;
    void        *idle_img0;
    void        *idle_img1;
    void        *idle_img2;
    void        *idle_img3;
    t_point     img_sz;
    int         anim_frames;
    t_mob_type  type;
    t_bool      visible;
}       t_mob;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_point     win_sz;
    char    **chr_map;

    t_empty     empty;
    t_wall      wall;
    t_collectable coll;
    t_exit      exit;
    t_mob       player;
//    t_mob       npc;
}       t_game;

int     error(char *message);
void    *nll_error(char *message);

t_bool  game_init(t_game *game, int argc, char *argv[]);

void    open_empty_images(t_game *game);
void    open_wall_images(t_game *game);
void    open_collectible_images(t_game *game);
void    open_exit_images(t_game *game);
void    open_player_images(t_game *game);

int     key_pressed(int keycode, t_game *game);
int     mouse_hook(int keycode, t_game *game);

void    move_player(enum e_movement_dir dir, t_game *game);

void    draw_empty(t_game *game);
void    draw_walls(t_game *game);
void    draw_collectibles(t_game *game, t_list *lst_cl);
void    draw_exit(t_game *game);
void    draw_player(t_game *game);
int     render(t_game *game);

void    update_coll_animation(t_collectable *coll);
void    update_exit_animation(t_exit *ext);
void    update_player_animation(t_mob *plr);

#endif
