	.syntax unified

	thumb_func_start clear_and_copy_tilemap_rows
clear_and_copy_tilemap_rows: @ 0x0804177C
	push {r4, r5, lr}
	ldr r3, _08041808 @ =0x03000440
	adds r0, r3, #0
	adds r0, #0x2d
	ldrb r2, [r0]
	lsls r2, r2, #6
	subs r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #1
	ldr r1, _0804180C @ =0x06002800
	adds r0, r0, r1
	adds r2, r2, r0
	adds r4, r2, #0
	movs r0, #0
	adds r5, r3, #0
	movs r3, #0
_0804179C:
	movs r1, #0
	adds r0, #1
_080417A0:
	strh r3, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #7
	bls _080417A0
	adds r4, #0x40
	adds r2, r4, #0
	cmp r0, #1
	bls _0804179C
	ldr r3, _08041810 @ =0x06002D40
	movs r1, #0
_080417B6:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	adds r1, #1
	cmp r1, #7
	bls _080417B6
	adds r4, #0x40
	adds r2, r4, #0
	ldr r3, _08041814 @ =0x06002E80
	movs r1, #0
_080417CC:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	adds r1, #1
	cmp r1, #7
	bls _080417CC
	adds r4, #0x40
	adds r2, r4, #0
	movs r0, #0
	movs r3, #0
_080417E2:
	movs r1, #0
	adds r4, #0x40
	adds r0, #1
_080417E8:
	strh r3, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #7
	bls _080417E8
	adds r2, r4, #0
	cmp r0, #1
	bls _080417E2
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08041808: .4byte 0x03000440
_0804180C: .4byte 0x06002800
_08041810: .4byte 0x06002D40
_08041814: .4byte 0x06002E80
	.syntax divided
