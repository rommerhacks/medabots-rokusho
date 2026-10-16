	.syntax unified

	thumb_func_start sub_0800AED0
	.global sub_0800AED0
sub_0800AED0: @ 0x0800AED0
	push {r4, lr}
	sub sp, #4
	ldr r0, _0800AF04 @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	bl get_medal_active_slot
	adds r3, r0, #0
	cmp r3, #0xff
	beq _0800AEFA
	ldr r0, _0800AF08 @ =0x030017A0
	lsls r3, r3, #3
	adds r3, r3, r0
	ldrb r0, [r3, #3]
	ldrb r1, [r3, #4]
	ldrb r2, [r3, #5]
	ldrb r3, [r3, #6]
	movs r4, #2
	str r4, [sp]
	bl decompress_sprite_to_vram_08042D94
_0800AEFA:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800AF04: .4byte 0x03000440
_0800AF08: .4byte 0x030017A0
	.syntax divided
