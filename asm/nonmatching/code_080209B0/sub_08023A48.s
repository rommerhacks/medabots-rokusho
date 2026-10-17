	.syntax unified

	thumb_func_start sub_08023A48
sub_08023A48: @ 0x08023A48
	push {r4, r5, r6, lr}
	ldr r5, _08023AA8 @ =0x03000590
	ldr r6, _08023AAC @ =0x03001800
	adds r4, r6, #0
	adds r4, #0x88
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xc4
	movs r2, #0
	movs r1, #0x26
	strb r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xc5
	strb r2, [r0]
	adds r0, r6, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r4]
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r1, #0xc6
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xec
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r4]
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r1, #0xc7
	strb r0, [r1]
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08023AA8: .4byte 0x03000590
_08023AAC: .4byte 0x03001800
	.syntax divided
