#ifndef GUARD_ENGINE_SPRITE_ENGINE_H
#define GUARD_ENGINE_SPRITE_ENGINE_H

// Sprite engine: DMA/LZ tile loads, OAM shapes, sprite trees and scene layers

void load_sprite_animation_by_type(struct OamData *oam, struct Unk_08047414 *obj, u32 id, u32 kind, u32 x, u32 y,
                                   u32 tile, u32 pal, u32 e);
void sub_08047414(struct Unk_08047414 *obj, u8 *buf, struct SpriteNodeDesc **nodes, struct SpriteNodeOam *oams);
u8 sub_080460B0(struct Unk_03002414 *work, u16 *affine, u32 side, struct OamData *oam, u16 tile, u8 *parts, u8 pal,
                u8 x, u8 y, u32 alt);
void setup_scene_bg_layers_and_sprites(void *oam, struct Unk_08047414 *obj, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f,
                                       u32 g, u32 h, u32 i, u32 j);
void sub_08044CDC(u32 a);
void update_anim_object_flags(void);
void copy_oam_affine_params(struct OamData *oam, u16 *affine);
u32 dma3_copy_or_decompress(const u32 *src, void *dst);
u32 sub_08044E64(s32 shape, s32 size); // OAM attr0 shape / attr1 size bits -> height << 16 | width
void toggle_bg_layer_visibility(s32 a, s32 b, s32 c, s32 d);
u32 setup_oam_sprite_entries(struct OamData *oams, void *b, void *c, const struct SpriteDesc *desc,
                             const struct SpriteAnchor *e, u8 f, u16 g);
u32 init_sprite_object_entry(struct SpriteOamList *obj, struct OamData *oams, void *b, void *c,
                             const struct SpriteDesc *desc, const struct SpriteAnchor *e, u8 f, u16 g);
u16 sub_08045C30(struct SpriteOamList *list, void *dst, u16 slot, s16 y, s16 x, u16 depth, u8 pal, u16 angle,
                 u16 *affine, u32 k); // + rotation affine matrix k
u16 init_oam_sprite_entry(struct OamFull *oam, struct SpriteNodeDesc *desc, u8 pal, u16 tile);
u32 load_sprite_tree_recursive(struct SpriteNodeDesc **nodes, struct SpriteTileRef *list, u8 node, u8 pal,
                               struct SpriteNodeOam *oams, u16 *tile, u32 alt); // returns the bytes of tiles loaded
void render_sprite_node_recursive(struct Unk_08047414 *obj, struct SpriteTileRef *list, u8 node, s32 y, s32 x,
                                  s16 depth, s16 angle, u8 flip);
u16 copy_oam_entries_with_priority(struct SpriteOamList *list, struct OamData *dst, u16 slot, u16 end);
u16 batch_copy_oam_entries(struct SpriteOamBatch *batch, struct OamData *dst, u16 end);

#endif // GUARD_ENGINE_SPRITE_ENGINE_H
