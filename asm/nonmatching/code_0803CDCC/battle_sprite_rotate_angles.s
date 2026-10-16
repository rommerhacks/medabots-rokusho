	.syntax unified

	thumb_func_start battle_sprite_rotate_angles
	.global battle_sprite_rotate_angles
battle_sprite_rotate_angles: @ 0x0803D4EC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r4, #0
	ldr r0, _0803D510 @ =0x03002C30
	ldr r2, _0803D514 @ =0x000001FF
	adds r5, r2, #0
	ldr r3, _0803D518 @ =0x00000282
	adds r2, r0, r3
	ldr r7, _0803D51C @ =0x000002A9
	adds r3, r0, r7
_0803D500:
	ldrb r0, [r3]
	cmp r0, #0
	beq _0803D528
	cmp r6, #0
	beq _0803D520
	ldrh r0, [r2]
	subs r0, r0, r1
	b _0803D524
	.align 2, 0
_0803D510: .4byte 0x03002C30
_0803D514: .4byte 0x000001FF
_0803D518: .4byte 0x00000282
_0803D51C: .4byte 0x000002A9
_0803D520:
	ldrh r0, [r2]
	adds r0, r0, r1
_0803D524:
	ands r0, r5
	strh r0, [r2]
_0803D528:
	adds r2, #0x40
	adds r3, #0x40
	adds r4, #1
	cmp r4, #0x13
	bls _0803D500
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
