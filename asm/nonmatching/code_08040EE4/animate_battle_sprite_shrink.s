	.syntax unified

	thumb_func_start animate_battle_sprite_shrink
animate_battle_sprite_shrink: @ 0x08041BA4
	push {r4, lr}
	ldr r2, _08041BEC @ =0x03002C30
	ldr r4, _08041BF0 @ =0x03000440
	adds r3, r4, #0
	adds r3, #0x2b
	ldrb r1, [r3]
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrb r0, [r1, #8]
	subs r0, #8
	strb r0, [r1, #8]
	ldrb r1, [r3]
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrb r0, [r1, #9]
	subs r0, #8
	strb r0, [r1, #9]
	ldrb r1, [r3]
	lsls r0, r1, #6
	adds r0, r0, r2
	ldrb r0, [r0, #8]
	cmp r0, #0
	bne _08041BE4
	adds r0, r1, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08041BE4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08041BEC: .4byte 0x03002C30
_08041BF0: .4byte 0x03000440
_08041BF4:
	.byte 0x06, 0x4A, 0x10, 0x1C, 0x2A, 0x30, 0x00, 0x78, 0x00, 0x01, 0x01, 0x30
	.byte 0x11, 0x1C, 0x28, 0x31, 0x08, 0x70, 0x01, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47
	.byte 0x40, 0x04, 0x00, 0x03
	.syntax divided
