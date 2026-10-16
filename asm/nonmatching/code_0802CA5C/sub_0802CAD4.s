	.syntax unified

	thumb_func_start sub_0802CAD4
sub_0802CAD4: @ 0x0802CAD4
	push {r4, r5, lr}
	movs r4, #0
	movs r3, #0
	ldr r5, _0802CB24 @ =0x030018D2
	ldr r0, _0802CB28 @ =0x03002C30
	ldr r1, _0802CB2C @ =0x00000848
	adds r2, r0, r1
_0802CAE2:
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CB00
	ldrb r1, [r2]
	subs r1, #4
	strb r1, [r2]
	ldrb r0, [r2, #1]
	subs r0, #4
	strb r0, [r2, #1]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #4
	bne _0802CB00
	movs r4, #1
_0802CB00:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802CAE2
	cmp r4, #0
	beq _0802CB1E
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r1, _0802CB30 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802CB1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CB24: .4byte 0x030018D2
_0802CB28: .4byte 0x03002C30
_0802CB2C: .4byte 0x00000848
_0802CB30: .4byte 0x03001800
	.syntax divided
