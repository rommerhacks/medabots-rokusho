	.syntax unified

	thumb_func_start sub_0802C1A4
sub_0802C1A4: @ 0x0802C1A4
	push {r4, lr}
	ldr r4, _0802C23C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r3, #0
	adds r4, #0xd2
	ldr r0, _0802C240 @ =0x03002C30
	ldr r2, _0802C244 @ =0x00000848
	adds r1, r0, r2
_0802C1C2:
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C1D6
	ldrb r0, [r1]
	subs r0, #8
	strb r0, [r1]
	ldrb r0, [r1, #1]
	adds r0, #8
	strb r0, [r1, #1]
_0802C1D6:
	adds r1, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802C1C2
	ldr r4, _0802C23C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r3, #0
	ldr r0, _0802C240 @ =0x03002C30
	ldr r1, _0802C248 @ =0x00000908
	adds r2, r0, r1
	adds r1, r4, #0
	adds r1, #0xd6
_0802C1FC:
	ldrh r0, [r1]
	ldr r4, _0802C240 @ =0x03002C30
	cmp r0, #0
	beq _0802C210
	ldrb r0, [r2]
	subs r0, #8
	strb r0, [r2]
	ldrb r0, [r2, #1]
	adds r0, #8
	strb r0, [r2, #1]
_0802C210:
	adds r2, #0x40
	adds r1, #2
	adds r3, #1
	cmp r3, #2
	bls _0802C1FC
	ldr r2, _0802C244 @ =0x00000848
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #8
	bne _0802C236
	movs r0, #0x21
	movs r1, #6
	bl clear_battle_sprite_slot
	ldr r1, _0802C23C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802C236:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802C23C: .4byte 0x03001800
_0802C240: .4byte 0x03002C30
_0802C244: .4byte 0x00000848
_0802C248: .4byte 0x00000908
	.syntax divided
