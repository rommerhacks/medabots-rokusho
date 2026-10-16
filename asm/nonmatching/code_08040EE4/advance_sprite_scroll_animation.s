	.syntax unified

	thumb_func_start advance_sprite_scroll_animation
advance_sprite_scroll_animation: @ 0x080419CC
	push {r4, lr}
	ldr r4, _08041A20 @ =0x03002C30
	ldr r2, _08041A24 @ =0x03000440
	adds r3, r2, #0
	adds r3, #0x2b
	ldrb r1, [r3]
	lsls r1, r1, #6
	adds r1, r1, r4
	ldrb r0, [r1, #8]
	adds r0, #8
	strb r0, [r1, #8]
	ldrb r1, [r3]
	lsls r1, r1, #6
	adds r1, r1, r4
	ldrb r0, [r1, #9]
	adds r0, #8
	strb r0, [r1, #9]
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r1, r0, r4
	ldrb r0, [r1, #8]
	cmp r0, #0x3f
	bls _08041A10
	movs r0, #0x40
	strb r0, [r1, #8]
	ldrb r1, [r3]
	lsls r1, r1, #6
	adds r1, r1, r4
	strb r0, [r1, #9]
	adds r1, r2, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08041A10:
	adds r1, r2, #0
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08041A20: .4byte 0x03002C30
_08041A24: .4byte 0x03000440
	.syntax divided
