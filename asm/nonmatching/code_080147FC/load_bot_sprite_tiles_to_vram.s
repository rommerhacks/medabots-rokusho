	.syntax unified

	thumb_func_start load_bot_sprite_tiles_to_vram
	.global load_bot_sprite_tiles_to_vram
load_bot_sprite_tiles_to_vram: @ 0x08017D50
	push {lr}
	ldr r2, _08017D80 @ =0x03000590
	ldr r0, _08017D84 @ =0x03000440
	adds r3, r0, #0
	adds r3, #0x3d
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r3, [r3]
	adds r0, r0, r3
	lsls r0, r0, #8
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	lsls r0, r0, #7
	ldr r1, _08017D88 @ =0x084C21BC
	adds r0, r0, r1
	ldr r1, _08017D8C @ =0x06007800
	movs r2, #0x20
	bl CpuFastSet
	pop {r0}
	bx r0
	.align 2, 0
_08017D80: .4byte 0x03000590
_08017D84: .4byte 0x03000440
_08017D88: .4byte 0x084C21BC
_08017D8C: .4byte 0x06007800
	.syntax divided
