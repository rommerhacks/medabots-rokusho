	.syntax unified

	thumb_func_start copy_transition_tiles_to_bg2
copy_transition_tiles_to_bg2: @ 0x080418C0
	push {r4, r5, r6, r7, lr}
	ldr r3, _08041914 @ =0x03000440
	adds r0, r3, #0
	adds r0, #0x2d
	ldrb r2, [r0]
	lsls r2, r2, #6
	subs r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #1
	ldr r1, _08041918 @ =0x06002800
	adds r0, r0, r1
	adds r2, r2, r0
	ldr r4, _0804191C @ =0x06002D40
	adds r6, r4, #0
	adds r0, r2, #0
	movs r5, #0
	adds r7, r3, #0
_080418E2:
	movs r1, #0
	adds r3, r0, #0
	adds r3, #0x40
	adds r6, #0x40
	adds r5, #1
_080418EC:
	ldrh r0, [r4]
	strh r0, [r2]
	adds r4, #2
	adds r2, #2
	adds r1, #1
	cmp r1, #7
	bls _080418EC
	adds r0, r3, #0
	adds r2, r0, #0
	adds r4, r6, #0
	cmp r5, #5
	bls _080418E2
	adds r1, r7, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08041914: .4byte 0x03000440
_08041918: .4byte 0x06002800
_0804191C: .4byte 0x06002D40
	.syntax divided
