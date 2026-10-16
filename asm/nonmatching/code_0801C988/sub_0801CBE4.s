	.syntax unified

	thumb_func_start sub_0801CBE4
sub_0801CBE4: @ 0x0801CBE4
	push {r4, lr}
	ldr r0, _0801CC0C @ =0x03000590
	ldr r4, _0801CC10 @ =0x03001800
	adds r1, r4, #0
	adds r1, #0x87
	ldrb r2, [r1]
	lsls r1, r2, #8
	adds r1, r1, r0
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801CC14
	adds r0, r2, #0
	bl add_bot_to_defeated_list
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x2f
	b _0801CC1A
	.align 2, 0
_0801CC0C: .4byte 0x03000590
_0801CC10: .4byte 0x03001800
_0801CC14:
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x20
_0801CC1A:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
