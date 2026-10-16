	.syntax unified

	thumb_func_start load_battle_scene_graphics
load_battle_scene_graphics: @ 0x0806EB7C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r4, _0806EC9C @ =0xFFFFFBE0
	add sp, r4
	ldr r0, _0806ECA0 @ =0x087BA86C
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UnCompVram
	ldr r0, _0806ECA4 @ =0x087C8368
	ldr r1, _0806ECA8 @ =0x06008020
	bl LZ77UnCompVram
	ldr r0, _0806ECAC @ =0x08485FB8
	ldr r0, [r0, #4]
	ldr r1, _0806ECB0 @ =0x06008C80
	bl LZ77UnCompVram
	ldr r4, _0806ECB4 @ =0x040000D4
	ldr r0, _0806ECB8 @ =0x087BDC10
	str r0, [r4]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r4, #4]
	ldr r0, _0806ECBC @ =0x84000080
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806ECC0 @ =0x087C8818
	str r0, [r4]
	str r1, [r4, #4]
	ldr r1, _0806ECC4 @ =0x84000008
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806ECC8 @ =0x08485FC8
	ldr r0, [r0, #4]
	str r0, [r4]
	ldr r0, _0806ECCC @ =0x05000020
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806ECD0 @ =0x087BDE10
	ldr r1, _0806ECD4 @ =0x06007000
	bl LZ77UnCompVram
	ldr r0, _0806ECD8 @ =0x087BE18C
	ldr r1, _0806ECDC @ =0x06007800
	bl LZ77UnCompVram
	ldr r0, _0806ECE0 @ =0x087C8838
	add r1, sp, #0x10
	bl LZ77UnCompVram
	movs r6, #0
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #1
	mov r8, r0
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0x1f
	movs r2, #0xa
	movs r3, #0xc
	bl copy_tilemap_rect_to_vram
	ldr r0, _0806ECE4 @ =0x08485FC0
	ldr r0, [r0, #4]
	add r5, sp, #0x100
	adds r1, r5, #0
	bl LZ77UnCompVram
	movs r0, #0xa
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #0x64
	str r0, [sp, #8]
	mov r2, r8
	str r2, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #0x1e
	movs r2, #0x14
	movs r3, #0x14
	bl copy_tilemap_rect_to_vram
	ldr r1, _0806ECE8 @ =0x0400000A
	ldr r2, _0806ECEC @ =0x00000E01
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	ldr r2, _0806ECF0 @ =0x00000F03
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #6
	ldr r2, _0806ECF4 @ =0x00001E08
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	ldr r2, _0806ECF8 @ =0x00001F0A
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0806ECFC @ =0x08485FD8
	ldr r0, [r0, #4]
	str r0, [r4]
	ldr r0, _0806ED00 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _0806ED04 @ =0x80000050
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r1, #0xc0
	lsls r1, r1, #8
	ldr r2, _0806ED08 @ =0x0000040D
	movs r4, #3
	str r4, [sp]
	movs r0, #0
	movs r3, #4
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806ED0C @ =0x03002C30
	movs r0, #0x98
	strh r0, [r1, #2]
	movs r0, #0x40
	strh r0, [r1, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	ldr r0, _0806ED10 @ =0x03000430
	str r6, [r0]
	ldr r1, _0806ED14 @ =0x03001800
	ldrh r0, [r1, #0xc]
	strh r0, [r1, #4]
	ldr r0, _0806ED18 @ =0x0300137C
	str r4, [r0]
	movs r3, #0x84
	lsls r3, r3, #3
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806EC9C: .4byte 0xFFFFFBE0
_0806ECA0: .4byte 0x087BA86C
_0806ECA4: .4byte 0x087C8368
_0806ECA8: .4byte 0x06008020
_0806ECAC: .4byte 0x08485FB8
_0806ECB0: .4byte 0x06008C80
_0806ECB4: .4byte 0x040000D4
_0806ECB8: .4byte 0x087BDC10
_0806ECBC: .4byte 0x84000080
_0806ECC0: .4byte 0x087C8818
_0806ECC4: .4byte 0x84000008
_0806ECC8: .4byte 0x08485FC8
_0806ECCC: .4byte 0x05000020
_0806ECD0: .4byte 0x087BDE10
_0806ECD4: .4byte 0x06007000
_0806ECD8: .4byte 0x087BE18C
_0806ECDC: .4byte 0x06007800
_0806ECE0: .4byte 0x087C8838
_0806ECE4: .4byte 0x08485FC0
_0806ECE8: .4byte 0x0400000A
_0806ECEC: .4byte 0x00000E01
_0806ECF0: .4byte 0x00000F03
_0806ECF4: .4byte 0x00001E08
_0806ECF8: .4byte 0x00001F0A
_0806ECFC: .4byte 0x08485FD8
_0806ED00: .4byte 0x05000200
_0806ED04: .4byte 0x80000050
_0806ED08: .4byte 0x0000040D
_0806ED0C: .4byte 0x03002C30
_0806ED10: .4byte 0x03000430
_0806ED14: .4byte 0x03001800
_0806ED18: .4byte 0x0300137C
	.syntax divided
