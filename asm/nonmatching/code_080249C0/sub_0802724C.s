	.syntax unified

	thumb_func_start sub_0802724C
sub_0802724C: @ 0x0802724C
	push {r4, r5, lr}
	movs r0, #0x21
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r2, _080272C8 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r4, r2, r0
	ldr r3, _080272CC @ =0x0000C404
	strh r3, [r4]
	ldr r5, _080272D0 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802727E
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r0, #0
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r4]
_0802727E:
	ldr r0, _080272D4 @ =0x0000085C
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080272D8 @ =0x00000842
	adds r1, r2, r0
	movs r0, #0x78
	strh r0, [r1]
	ldr r0, _080272DC @ =0x00000844
	adds r1, r2, r0
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080272E0 @ =0x0000084A
	adds r1, r2, r0
	movs r0, #7
	strb r0, [r1]
	ldr r0, _080272E4 @ =0x0000084B
	adds r1, r2, r0
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, _080272E8 @ =0x083B5F80
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080272C8: .4byte 0x03002C30
_080272CC: .4byte 0x0000C404
_080272D0: .4byte 0x03001800
_080272D4: .4byte 0x0000085C
_080272D8: .4byte 0x00000842
_080272DC: .4byte 0x00000844
_080272E0: .4byte 0x0000084A
_080272E4: .4byte 0x0000084B
_080272E8: .4byte 0x083B5F80
	.syntax divided
