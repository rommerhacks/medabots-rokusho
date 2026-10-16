	.syntax unified

	thumb_func_start sub_08026CBC
sub_08026CBC: @ 0x08026CBC
	push {r4, lr}
	ldr r1, _08026CEC @ =0x03000590
	ldr r4, _08026CF0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r2, [r0]
	lsls r0, r2, #8
	adds r0, r0, r1
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	bne _08026CDA
	adds r0, r2, #0
	bl add_bot_to_defeated_list
_08026CDA:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08026CEC: .4byte 0x03000590
_08026CF0: .4byte 0x03001800
	.syntax divided
