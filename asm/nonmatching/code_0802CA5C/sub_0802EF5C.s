	.syntax unified

	thumb_func_start sub_0802EF5C
sub_0802EF5C: @ 0x0802EF5C
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r3, #0
	ldr r7, _0802EF84 @ =0x030018D2
	movs r5, #0x90
	lsls r5, r5, #4
	movs r4, #0x84
	lsls r4, r4, #4
_0802EF6C:
	adds r0, r3, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EFA4
	ldr r2, _0802EF88 @ =0x03002C30
	adds r1, r4, r2
	ldrb r0, [r1, #8]
	cmp r0, #4
	bne _0802EF8C
	movs r6, #1
	b _0802EFA4
	.align 2, 0
_0802EF84: .4byte 0x030018D2
_0802EF88: .4byte 0x03002C30
_0802EF8C:
	subs r0, #4
	strb r0, [r1, #8]
	ldrb r0, [r1, #9]
	subs r0, #4
	strb r0, [r1, #9]
	adds r1, r5, r2
	ldrb r0, [r1, #8]
	subs r0, #4
	strb r0, [r1, #8]
	ldrb r0, [r1, #9]
	subs r0, #4
	strb r0, [r1, #9]
_0802EFA4:
	adds r5, #0x40
	adds r4, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802EF6C
	cmp r6, #0
	beq _0802EFC4
	movs r0, #0x21
	movs r1, #6
	bl clear_battle_sprite_slot
	ldr r1, _0802EFCC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802EFC4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EFCC: .4byte 0x03001800
	.syntax divided
