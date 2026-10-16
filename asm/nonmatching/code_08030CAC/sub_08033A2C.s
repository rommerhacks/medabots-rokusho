	.syntax unified

	thumb_func_start sub_08033A2C
sub_08033A2C: @ 0x08033A2C
	push {r4, r5, lr}
	ldr r5, _08033A70 @ =0x03000590
	ldr r0, _08033A74 @ =0x03001800
	adds r4, r0, #0
	adds r4, #0x87
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r5
	adds r0, #0xe0
	ldrb r0, [r0]
	cmp r0, #0
	bne _08033A4A
	adds r0, r1, #0
	bl sub_08035478
_08033A4A:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r5
	adds r0, #0xe1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08033A5E
	adds r0, r1, #0
	bl calc_bot_evasion_modifier
_08033A5E:
	ldrb r0, [r4]
	bl sub_080355C4
	bl sub_08034F08
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08033A70: .4byte 0x03000590
_08033A74: .4byte 0x03001800
	.syntax divided
