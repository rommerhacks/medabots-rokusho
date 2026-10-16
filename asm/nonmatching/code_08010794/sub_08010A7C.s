	.syntax unified

	thumb_func_start sub_08010A7C
sub_08010A7C: @ 0x08010A7C
	push {r4, lr}
	sub sp, #0x14
	bl update_battle_field_frame
	bl sub_080487E4
	movs r1, #0xbc
	lsls r1, r1, #6
	movs r0, #0x10
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	movs r0, #0xa
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp, #0x10]
	movs r0, #0x40
	movs r2, #5
	movs r3, #0x10
	bl setup_blend_effect
	ldr r0, _08010AC0 @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	ldr r1, _08010AC4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010AC0: .4byte 0x03000440
_08010AC4: .4byte 0x0300137C
	.syntax divided
