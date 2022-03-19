#include "../so_long.h"

void    update_coll_animation(t_collectable *coll)
{
    static int frame;

    if (coll->anim_frames == 0)
        return ;
    if (frame == coll->anim_frames)
        coll->curr_img = coll->gem0;
    else if (frame == coll->anim_frames * 2)
        coll->curr_img = coll->gem1;
    else if (frame == coll->anim_frames * 3)
        coll->curr_img = coll->gem2;
    else if (frame == coll->anim_frames * 4)
        coll->curr_img = coll->gem3;
    else if (frame == coll->anim_frames * 5)
    {
        coll->curr_img = coll->gem4;
        frame = 0;
    }
    ++frame;
}

void    update_exit_animation(t_exit *ext)
{
    static int frame;

    if (ext->anim_frames == 0)
        return ;
    if (frame == ext->anim_frames)
        ext->curr_img = ext->idle0;
    else if (frame == ext->anim_frames * 2)
        ext->curr_img = ext->idle1;
    else if (frame == ext->anim_frames * 3)
        ext->curr_img = ext->idle2;
    else if (frame == ext->anim_frames * 4)
        ext->curr_img = ext->idle3;
    else if (frame == ext->anim_frames * 5)
        ext->curr_img = ext->idle4;
    else if (frame == ext->anim_frames * 6)
        ext->curr_img = ext->idle5;
    else if (frame == ext->anim_frames * 7)
    {
        ext->curr_img = ext->idle6;
        frame = 0;
    }
    ++frame;
}

void    update_player_animation(t_mob *plr)
{
    static int frame;

    if (plr->anim_frames == 0)
        return ;
    if (frame == plr->anim_frames)
        plr->curr_img = plr->idle_img0;
    else if (frame == plr->anim_frames * 2)
        plr->curr_img = plr->idle_img1;
    else if (frame == plr->anim_frames * 3)
        plr->curr_img = plr->idle_img2;
    else if (frame == plr->anim_frames * 4)
    {
        plr->curr_img = plr->idle_img3;
        frame = 0;
    }
    ++frame;
}
