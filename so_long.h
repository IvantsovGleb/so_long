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
    NPC = 'S'
}   t_tile_code;

typedef struct s_empty
{
    t_list  *lst_emp;
    void    *ground;
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
    void        *gem_0;
    void        *gem_1;
    void        *gem_2;
    void        *gem_3;
    void        *gem_4;
    t_point     img_sz;
    int         anim_frames;
    int         collects;
}           t_collectable;

typedef struct s_exit
{
    t_point pos;
    void    *ladder;
    t_point img_sz;
    t_bool  opened;
}           t_exit;

enum e_movement_dir
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef enum s_state
{
    DEAD,
    ALIVE,
    WIN
}       t_state;

typedef struct s_player
{
    t_point     coords;
    t_point     old_coords;
    void        *curr_img;
    void        *idle_0;
    void        *idle_1;
    void        *idle_2;
    void        *idle_3;
    void        *dead_0;
    void        *dead_1;
    void        *dead_2;
    void        *dead_3;
    t_point     img_sz;
    int         anim_frames;
    t_bool      visible;
    t_state     state;
}       t_player;

typedef struct s_npc
{
    t_list      *lst_npc;
    void        *curr_img;
    void        *idle_0;
    void        *idle_1;
    void        *idle_2;
    void        *idle_3;
    t_point     img_sz;
    int         anim_frames;
}       t_npc;

typedef struct s_move
{
    int         moves;
    char        *s_moves;
    t_bool      moved;
}       t_move;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_point     win_sz;
    char    **chr_map;

    t_move      move;
    t_empty     empty;
    t_wall      wall;
    t_collectable coll;
    t_exit      exit;
    t_player    player;
    t_npc       npc;
}       t_game;

int     error(char *message);
void    *nll_error(char *message);

t_bool  game_init(t_game *game, int argc, char *argv[]);
t_bool  add_pos(t_list **lst_pos, int x, int y);
t_bool  add_collectible(t_collectable *coll, int x, int y, t_empty *empty);
t_bool  add_player(t_player *plr, int x, int y, t_empty *empty);

void    open_wall_images(t_game *game);
void    open_ece(void *mlx, t_empty *empty, t_collectable *coll, t_exit *exit);
void    open_plr_images(void *mlx, t_player *plr);
void    open_npc_images(void *mlx, t_npc *npc);

int     key_pressed(int keycode, t_game *game);
void    end_game(t_game *game);

t_bool  move_player(enum e_movement_dir dir, t_game *game);
void    reset_pos(enum e_movement_dir dir, t_player *plr);
void    put_moves_count(void *mlx, void *win, t_move *move);

void    update_coll_animation(t_collectable *coll);
void    update_plr_alive_animation(t_player *plr);
void    update_plr_dead_animation(t_player *plr);
void    update_npc_animation(t_npc *npc);

void    draw_empty(t_game *game);
void    draw_walls(t_game *game);
void    draw_collectibles(t_game *game, t_list *lst_cl);
void    draw_exit(t_game *game);
void    draw_mob(t_game *game);
int     render(t_game *game);

#endif
