	.syntax unified

	thumb_func_start sub_0805D488
sub_0805D488: @ 0x0805D488
	push {r4, lr}
	ldr r4, _0805D4A4 @ =0x03006F74
	ldr r2, [r4]
	ldrb r0, [r2]
	cmp r0, #8
	beq _0805D4AC
	ldr r1, _0805D4A8 @ =0x04000054
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	strh r0, [r1]
	b _0805D4DA
	.align 2, 0
_0805D4A4: .4byte 0x03006F74
_0805D4A8: .4byte 0x04000054
_0805D4AC:
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r2, [r1]
	ldr r0, _0805D4E0 @ =0x0000FDFF
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _0805D4E4 @ =0x0000FBFF
	ands r0, r2
	strh r0, [r1]
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r1, [r4]
	movs r2, #0
	movs r0, #1
	strb r0, [r1, #6]
	ldr r1, _0805D4E8 @ =0x03002B8C
	movs r0, #0xa
	str r0, [r1]
	ldr r0, _0805D4EC @ =0x0300137C
	str r2, [r0]
_0805D4DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805D4E0: .4byte 0x0000FDFF
_0805D4E4: .4byte 0x0000FBFF
_0805D4E8: .4byte 0x03002B8C
_0805D4EC: .4byte 0x0300137C
	.syntax divided
