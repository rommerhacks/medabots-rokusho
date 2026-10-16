	.syntax unified

	thumb_func_start load_medal_sprite
	.global load_medal_sprite
load_medal_sprite: @ 0x08009750
	push {lr}
	ldr r2, _080097BC @ =0x03000440
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
	ldr r2, _080097C0 @ =0x03000BE0
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r3, r0, r2
	ldrb r1, [r3]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080097D4
	ldr r2, _080097C4 @ =0x083AC494
	ldrb r1, [r3, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrb r3, [r3, #8]
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r1, _080097C8 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r1, _080097CC @ =0x03002C30
	movs r2, #0
	ldr r0, _080097D0 @ =0x0000C804
	strh r0, [r1]
	movs r0, #0xc0
	strh r0, [r1, #2]
	movs r0, #0x50
	strh r0, [r1, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1, #6]
	movs r0, #0xd
	strb r0, [r1, #0xa]
	strb r2, [r1, #0x1c]
	movs r0, #0x40
	strb r0, [r1, #0xb]
	b _080097DC
	.align 2, 0
_080097BC: .4byte 0x03000440
_080097C0: .4byte 0x03000BE0
_080097C4: .4byte 0x083AC494
_080097C8: .4byte 0x06010000
_080097CC: .4byte 0x03002C30
_080097D0: .4byte 0x0000C804
_080097D4:
	movs r0, #0
	movs r1, #1
	bl clear_sprite_table_mask
_080097DC:
	pop {r0}
	bx r0
	.syntax divided
