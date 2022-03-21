/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_upd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:37:44 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 13:37:45 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    update_coll_animation(t_collectable *coll)
{
    static int frame;

    if (coll->anim_frames == 0)
        return ;
    if (frame == coll->anim_frames)
        coll->curr_img = coll->gem_0;
    else if (frame == coll->anim_frames * 2)
        coll->curr_img = coll->gem_1;
    else if (frame == coll->anim_frames * 3)
        coll->curr_img = coll->gem_2;
    else if (frame == coll->anim_frames * 4)
        coll->curr_img = coll->gem_3;
    else if (frame == coll->anim_frames * 5)
    {
        coll->curr_img = coll->gem_4;
        frame = 0;
    }
    ++frame;
}

void    update_plr_alive_animation(t_player *plr)
{
    static int frame;

    if (plr->anim_frames == 0)
        return ;
    if (frame == plr->anim_frames)
        plr->curr_img = plr->idle_0;
    else if (frame == plr->anim_frames * 2)
        plr->curr_img = plr->idle_1;
    else if (frame == plr->anim_frames * 3)
        plr->curr_img = plr->idle_2;
    else if (frame == plr->anim_frames * 4)
    {
        plr->curr_img = plr->idle_3;
        frame = 0;
    }
    ++frame;
}

void    update_plr_dead_animation(t_player *plr)
{
    static int frame;

    if (plr->anim_frames == 0)
        return ;
    if (frame == plr->anim_frames)
        plr->curr_img = plr->dead_0;
    else if (frame == plr->anim_frames * 2)
        plr->curr_img = plr->dead_1;
    else if (frame == plr->anim_frames * 3)
        plr->curr_img = plr->dead_2;
    else if (frame == plr->anim_frames * 4)
    {
        plr->curr_img = plr->dead_3;
        frame = 0;
    }
    ++frame;
}


void    update_npc_animation(t_npc *npc)
{
    static int frame;

    if (npc->anim_frames == 0)
        return ;
    if (frame == npc->anim_frames)
        npc->curr_img = npc->idle_0;
    else if (frame == npc->anim_frames * 2)
        npc->curr_img = npc->idle_1;
    else if (frame == npc->anim_frames * 3)
        npc->curr_img = npc->idle_2;
    else if (frame == npc->anim_frames * 4)
    {
        npc->curr_img = npc->idle_3;
        frame = 0;
    }
    ++frame;
}
