	.syntax unified

	thumb_func_start sub_08074B68
	.global sub_08074B68
sub_08074B68: @ 0x08074B68
	ldr r2, _08074BB4 @ =0x03007014
	ldr r1, [r2]
	ldr r0, [r1, #0x14]
	cmp r0, #0
	bne _08074BA8
	adds r0, r1, #0
	adds r0, #0x88
	ldr r0, [r0]
	cmp r0, #0
	bne _08074BA8
	adds r0, r1, #0
	adds r0, #0xe8
	ldr r0, [r0, #0x14]
	cmp r0, #0
	bne _08074BA8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r1, r3
	ldr r0, [r0, #0x14]
	cmp r0, #0
	bne _08074BA8
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r1, r3
	ldr r0, [r0, #0x14]
	cmp r0, #0
	bne _08074BA8
	adds r3, #0x74
	adds r0, r1, r3
	ldr r0, [r0, #0x14]
	cmp r0, #0
	beq _08074BBC
_08074BA8:
	ldr r0, [r2]
	ldr r1, _08074BB8 @ =0x0000072F
	adds r0, r0, r1
	ldrb r0, [r0]
	b _08074BC0
	.align 2, 0
_08074BB4: .4byte 0x03007014
_08074BB8: .4byte 0x0000072F
_08074BBC:
	movs r0, #1
	rsbs r0, r0, #0
_08074BC0:
	bx lr
	.align 2, 0
	.syntax divided
