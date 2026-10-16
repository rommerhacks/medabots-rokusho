	.syntax unified

	thumb_func_start decompress_active_medal_sprite
	.global decompress_active_medal_sprite
decompress_active_medal_sprite: @ 0x08009CDC
	push {r4, lr}
	sub sp, #4
	ldr r2, _08009D28 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x40
	lsls r0, r0, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x3d
	strb r0, [r1]
	ldrb r0, [r1]
	bl get_medal_active_slot
	adds r3, r0, #0
	cmp r3, #0xff
	beq _08009D1E
	ldr r0, _08009D2C @ =0x030017A0
	lsls r3, r3, #3
	adds r3, r3, r0
	ldrb r0, [r3, #3]
	ldrb r1, [r3, #4]
	ldrb r2, [r3, #5]
	ldrb r3, [r3, #6]
	movs r4, #2
	str r4, [sp]
	bl decompress_sprite_to_vram_08042D94
_08009D1E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08009D28: .4byte 0x03000440
_08009D2C: .4byte 0x030017A0
	.syntax divided
