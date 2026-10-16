	.syntax unified

	thumb_func_start handle_menu_cursor_updown
handle_menu_cursor_updown: @ 0x0800B6E8
	push {lr}
	ldr r2, _0800B708 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0800B714
	ldr r0, _0800B70C @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x4a
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800B710
	movs r0, #2
	b _0800B712
	.align 2, 0
_0800B708: .4byte 0x03001798
_0800B70C: .4byte 0x03000440
_0800B710:
	subs r0, #1
_0800B712:
	strb r0, [r1]
_0800B714:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800B738
	ldr r0, _0800B730 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x4a
	ldrb r0, [r1]
	cmp r0, #2
	bne _0800B734
	movs r0, #0
	b _0800B736
	.align 2, 0
_0800B730: .4byte 0x03000440
_0800B734:
	adds r0, #1
_0800B736:
	strb r0, [r1]
_0800B738:
	ldrb r1, [r2]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _0800B75C
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0800B760 @ =0x03002C30
	ldr r1, _0800B764 @ =0x03000440
	adds r1, #0x4a
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, #0x70
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r1, [r0]
_0800B75C:
	pop {r0}
	bx r0
	.align 2, 0
_0800B760: .4byte 0x03002C30
_0800B764: .4byte 0x03000440
	.syntax divided
