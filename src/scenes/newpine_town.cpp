#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_titlebg.h"
#include "newpine_town.h"
#include "bn_log.h"
#include "bn_string.h"
#include "pk_scenemanager.h"
#include "bn_core.h"
#include "bn_keypad.h"

#include "pk_common.h"
#include "pk_taskmanager.h"
#include "pk_task.h"

#include "bn_music_items.h"
#include "bn_regular_bg_map_item.h"
#include "bn_bg_palette_items_txtpal1.h"

#include "pk_map_items_newpine_town.h"
#include "bn_regular_bg_tiles_items_outdoors.h"
#include "bn_bg_palette_items_gpal_outdoors.h"
#include "bn_regular_bg_tiles_item.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_bg_palette_ptr.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_ptr.h"
#include "pk_core.h"
#include "bn_point.h"
#include "bn_fixed_point.h"
#include "pk_transitions.h"
#include "pk_sw_kbd.h"
#include "bn_sprite_tiles_items_player0.h"
#include "bn_sprite_tiles_items_player1.h"
#include "bn_sprite_tiles_items_player2.h"
#include "bn_sprite_tiles_items_player3.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_shape_size.h"
#include "bn_sprite_palette_items_playerpal.h"
#include "bn_sprite_palette_ptr.h"

#include "math.h"

#include "save_sel.h"

#define WALK_SPEED 8.0f / 9.0f
#define RUN_SPEED (2 * WALK_SPEED)

bool running = false;

bool moveUp(int i) {
    if (i == 0) running = bn::keypad::b_held();
    if (i < 20 /* tile size / walk speed */ >> (running ? 1 : 0)) {
        pk::common::playerpos.set_y(pk::common::playerpos.y() + (running ? RUN_SPEED : WALK_SPEED));
        pk::common::playersprite->set_tiles(bn::sprite_tiles_items::player0.create_tiles((i << 2) / 19));
        return false; 
    }
    // pk::common::playerpos.set_y((pk::common::playerpos.y().integer() >> 4) << 4);
    return true;
}
bool moveRight(int i) {
    if (i == 0) running = bn::keypad::b_held();
    if (i < 20 /* tile size / walk speed */ >> (running ? 1 : 0)) { 
        pk::common::playerpos.set_x(pk::common::playerpos.x() - (running ? RUN_SPEED : WALK_SPEED));
        pk::common::playersprite->set_tiles(bn::sprite_tiles_items::player1.create_tiles((i << 2) / 19));
        return false; 
    }
    // pk::common::playerpos.set_x((pk::common::playerpos.x().integer() >> 4) << 4);
    return true;
}
bool moveDown(int i) {
    if (i == 0) running = bn::keypad::b_held();
    if (i < 20 /* tile size / walk speed */ >> (running ? 1 : 0)) { 
        pk::common::playerpos.set_y(pk::common::playerpos.y() - (running ? RUN_SPEED : WALK_SPEED));
        pk::common::playersprite->set_tiles(bn::sprite_tiles_items::player2.create_tiles((i << 2) / 19));
        return false;
    }
    // pk::common::playerpos.set_y((pk::common::playerpos.y().integer() >> 4) << 4);
    return true;
}
bool moveLeft(int i) {
    if (i == 0) running = bn::keypad::b_held();
    if (i < 20 /* tile size / walk speed */ >> (running ? 1 : 0)) { 
        pk::common::playerpos.set_x(pk::common::playerpos.x() + (running ? RUN_SPEED : WALK_SPEED));
        pk::common::playersprite->set_tiles(bn::sprite_tiles_items::player3.create_tiles(((i << 2) / 19)));
        return false;
    }
    // pk::common::playerpos.set_x((pk::common::playerpos.x().integer() >> 4) << 4);
    return true;
}

pk::scenes::NEWPINE_TOWN::NEWPINE_TOWN() : 
    pk::Scene("Newpine Town", bn::array<bn::regular_bg_ptr, 4>{
        bn::regular_bg_ptr::create(pk::common::bgpos, bn::regular_bg_map_item(pk::maps::NEWPINE_TOWN::layout0[0], pk::maps::NEWPINE_TOWN::map_size).create_map(bn::regular_bg_tiles_ptr::create(bn::regular_bg_tiles_items::outdoors), bn::bg_palette_items::gpal_outdoors.create_palette()) /*bn::regular_bg_map_ptr::create(map)*/),
        bn::regular_bg_ptr::create(pk::common::bgpos, bn::regular_bg_map_item(pk::maps::NEWPINE_TOWN::layout0[0], pk::maps::NEWPINE_TOWN::map_size).create_map(bn::regular_bg_tiles_ptr::create(bn::regular_bg_tiles_items::outdoors), bn::bg_palette_items::gpal_outdoors.create_palette()) /*bn::regular_bg_map_ptr::create(map)*/),
        bn::regular_bg_ptr::create(pk::common::bgpos, bn::regular_bg_map_item(pk::maps::NEWPINE_TOWN::layout0[0], pk::maps::NEWPINE_TOWN::map_size).create_map(bn::regular_bg_tiles_ptr::create(bn::regular_bg_tiles_items::outdoors), bn::bg_palette_items::gpal_outdoors.create_palette()) /*bn::regular_bg_map_ptr::create(map)*/),
        bn::regular_bg_ptr::create(pk::common::bgpos, bn::regular_bg_map_item(pk::maps::NEWPINE_TOWN::layout1[0], pk::maps::NEWPINE_TOWN::map_size).create_map(bn::regular_bg_tiles_ptr::create(bn::regular_bg_tiles_items::outdoors), bn::bg_palette_items::gpal_outdoors.create_palette()) /*bn::regular_bg_map_ptr::create(map)*/),
    }),
    map ({
        bn::regular_bg_map_item(pk::maps::NEWPINE_TOWN::layout0[0], pk::maps::NEWPINE_TOWN::map_size), 
        bn::regular_bg_map_item(pk::maps::NEWPINE_TOWN::layout1[0], pk::maps::NEWPINE_TOWN::map_size),
        bn::regular_bg_map_item(pk::maps::NEWPINE_TOWN::layout0[0], pk::maps::NEWPINE_TOWN::map_size), 
        bn::regular_bg_map_item(pk::maps::NEWPINE_TOWN::layout0[0], pk::maps::NEWPINE_TOWN::map_size), 
    }),
    tiles(bn::regular_bg_tiles_ptr::create(bn::regular_bg_tiles_items::outdoors)), 
    palette(bn::bg_palette_items::gpal_outdoors.create_palette()),
    movePlayerRight(moveRight),
    movePlayerUp(moveUp),
    movePlayerLeft(moveLeft),
    movePlayerDown(moveDown)
    // playerSprite(0, 0, bn::sprite_shape_size(16, 32), bn::sprite_tiles_items::player0.create_tiles(), bn::sprite_palette_items::playerpal.create_palette())
{
    pk::maps::NEWPINE_TOWN::music.play(bn::fixed(0.5));
    for (int i = 0; i < 4; i++) bg[i].set_position(pk::common::playerpos + bn::point(-7, 0));
    movePlayerUp.id = movePlayerRight.id;
    movePlayerLeft.id = movePlayerRight.id;
    movePlayerDown.id = movePlayerRight.id;
    pk::common::playersprite = bn::sprite_ptr::create(0, 0, bn::sprite_shape_size(16, 32), bn::sprite_tiles_items::player0.create_tiles(), bn::sprite_palette_items::playerpal.create_palette());
    pk::transitions::TRANSITION_FADE(18, true);
};

pk::scenes::NEWPINE_TOWN::~NEWPINE_TOWN() {
    pk::transitions::TRANSITION_FADE(18, false);
}

void pk::scenes::NEWPINE_TOWN::update() {
    if (bn::keypad::a_pressed()) pk::SceneManager::load<pk::scenes::SaveSel>();
    if (bn::keypad::up_held()) pk::TaskManager::add(movePlayerUp);
    if (bn::keypad::right_held()) pk::TaskManager::add(movePlayerRight);
    if (bn::keypad::down_held()) pk::TaskManager::add(movePlayerDown);
    if (bn::keypad::left_held()) pk::TaskManager::add(movePlayerLeft);
    for (int i = 0; i < 4; i++) bg[i].set_position(pk::common::playerpos + bn::point(-7, 0));
}

#undef WALK_SPEED