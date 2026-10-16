	.syntax unified

	thumb_func_start update_battle_sprite_animations
	.global update_battle_sprite_animations
update_battle_sprite_animations: @ 0x0801A574
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r3, _0801A5BC @ =0x03002C30
	lsls r1, r1, #2
	adds r2, r2, r1
	ldr r6, _0801A5C0 @ =0x083AD3B3
	lsls r2, r2, #6
	adds r0, r3, #4
	adds r1, r2, r0
	adds r3, #0x20
	adds r2, r2, r3
_0801A58C:
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _0801A5D2
	ldrb r3, [r1, #0x1d]
	cmp r3, #0x1f
	bhi _0801A5C8
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	bne _0801A5C4
	ldrb r0, [r1, #0x1d]
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldrb r0, [r1, #5]
	adds r0, #2
	strb r0, [r1, #5]
	adds r0, r3, #1
	strb r0, [r1, #0x1d]
	b _0801A5C8
	.align 2, 0
_0801A5BC: .4byte 0x03002C30
_0801A5C0: .4byte 0x083AD3B3
_0801A5C4:
	subs r0, #1
	strb r0, [r2]
_0801A5C8:
	adds r1, #0x40
	adds r2, #0x40
	adds r4, #1
	cmp r4, #4
	bls _0801A58C
_0801A5D2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
