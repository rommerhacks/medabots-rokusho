	.syntax unified

	thumb_func_start toggle_bg_layer_visibility
toggle_bg_layer_visibility: @ 0x08046CC8
	push {r4, lr}
	adds r4, r1, #0
	cmp r0, #0
	blt _08046CDA
	ldr r1, _08046D0C @ =0x030052D0
	ldrb r0, [r1, #0xd]
	rsbs r0, r0, #0
	subs r0, #2
	strb r0, [r1, #0xd]
_08046CDA:
	cmp r4, #0
	blt _08046CE8
	ldr r1, _08046D10 @ =0x03005290
	ldrb r0, [r1, #0xd]
	rsbs r0, r0, #0
	subs r0, #2
	strb r0, [r1, #0xd]
_08046CE8:
	cmp r2, #0
	blt _08046CF6
	ldr r1, _08046D14 @ =0x030052B0
	ldrb r0, [r1, #0xd]
	rsbs r0, r0, #0
	subs r0, #2
	strb r0, [r1, #0xd]
_08046CF6:
	cmp r3, #0
	blt _08046D04
	ldr r1, _08046D18 @ =0x030052F0
	ldrb r0, [r1, #0xd]
	rsbs r0, r0, #0
	subs r0, #2
	strb r0, [r1, #0xd]
_08046D04:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08046D0C: .4byte 0x030052D0
_08046D10: .4byte 0x03005290
_08046D14: .4byte 0x030052B0
_08046D18: .4byte 0x030052F0
	.syntax divided
