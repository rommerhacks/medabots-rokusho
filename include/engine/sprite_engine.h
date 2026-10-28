#ifndef GUARD_ENGINE_SPRITE_ENGINE_H
#define GUARD_ENGINE_SPRITE_ENGINE_H

// Sprite engine: DMA/LZ tile loads, OAM shapes, sprite trees and scene layers

// kind: 0 head, 1 right arm, 2 left arm, 3 legs; mode bit 2 = second side (mirrored), bit 4 clear = first call (queue
// the load)
void draw_medapart_sprite(struct OamData *oam, struct SpriteTree *obj, u32 id, u32 kind, u32 x, u32 y, u32 tile,
                          u32 pal, u32 mode);
void init_sprite_tree(struct SpriteTree *obj, u8 *buf, struct SpriteNodeDesc **nodes, struct SpriteNodeOam *oams);
u8 build_medabot_sprite(struct SpriteWork *work, u16 *affine, u32 side, struct OamData *oam, u16 tile, u8 *parts,
                        u8 pal, u8 x, u8 y, u32 alt);
void setup_medabot_part_sprites(void *oam, struct SpriteTree *obj, u32 head, u32 right_arm, u32 left_arm, u32 legs,
                                u32 x, u32 y, u32 depth, u32 pal, u32 mode, u32 side);
void goto_link_scene(u32 scene);
void medabot_sprite_slots_update(void);
void copy_oam_affine_params(struct OamData *oam, u16 *affine);
u32 dma3_copy_or_decompress(const u32 *src, void *dst);
u32 oam_shape_size_dims(s32 shape, s32 size); // OAM attr0 shape / attr1 size bits -> height << 16 | width
void part_layers_toggle_mirror(s32 head, s32 right_arm, s32 left_arm, s32 legs);
u32 setup_oam_sprite_entries(struct OamData *oams, void *tiles, void *pal, const struct SpriteDesc *desc,
                             const struct SpriteAnchor *anchor, u8 palNum, u16 tile);
u32 init_sprite_object_entry(struct SpriteOamList *obj, struct OamData *oams, void *tiles, void *pal,
                             const struct SpriteDesc *desc, const struct SpriteAnchor *anchor, u8 pal_num, u16 tile);
u16 render_sprite_if_visible_rotated(struct SpriteOamList *list, void *dst, u16 slot, s16 y, s16 x, u16 depth, u8 pal,
                                     u16 angle, u16 *affine, u32 k); // + rotation affine matrix k
u16 init_oam_sprite_entry(struct OamFull *oam, struct SpriteNodeDesc *desc, u8 pal, u16 tile);
u32 load_sprite_tree_recursive(struct SpriteNodeDesc **nodes, struct SpriteTileRef *list, u8 node, u8 pal,
                               struct SpriteNodeOam *oams, u16 *tile, u32 alt); // returns the bytes of tiles loaded
void render_sprite_node_recursive(struct SpriteTree *obj, struct SpriteTileRef *list, u8 node, s32 y, s32 x, s16 depth,
                                  s16 angle, u8 flip);
u16 copy_oam_entries_with_priority(struct SpriteOamList *list, struct OamData *dst, u16 slot, u16 end);
u16 batch_copy_oam_entries(struct SpriteOamBatch *batch, struct OamData *dst, u16 end);

#endif // GUARD_ENGINE_SPRITE_ENGINE_H
