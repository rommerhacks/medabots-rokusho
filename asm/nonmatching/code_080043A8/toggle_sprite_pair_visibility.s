	.syntax unified

	thumb_func_start toggle_sprite_pair_visibility
toggle_sprite_pair_visibility: @ 0x08006514
	push {r4, lr}
	ldr r0, _0800653C @ =0x03001780
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08006548
	ldr r2, _08006540 @ =0x03002C30
	adds r4, r2, #0
	adds r4, #0x40
	ldrh r3, [r4]
	ldr r1, _08006544 @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r3
	strh r0, [r4]
	adds r2, #0x80
	ldrh r0, [r2]
	ands r1, r0
	b _08006560
	.align 2, 0
_0800653C: .4byte 0x03001780
_08006540: .4byte 0x03002C30
_08006544: .4byte 0x0000BFFF
_08006548:
	ldr r2, _08006568 @ =0x03002C30
	adds r3, r2, #0
	adds r3, #0x40
	ldrh r0, [r3]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r3]
	adds r2, #0x80
	ldrh r0, [r2]
	orrs r1, r0
_08006560:
	strh r1, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08006568: .4byte 0x03002C30
	.syntax divided
