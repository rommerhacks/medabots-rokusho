	.syntax unified

	thumb_func_start sub_08062A74
	.global sub_08062A74
sub_08062A74: @ 0x08062A74
	lsls r0, r0, #0x10
	lsls r1, r1, #0x18
	ldr r2, _08062A8C @ =0x083BB9CC
	lsrs r0, r0, #0xe
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _08062A90 @ =0x030004DE
	cmp r1, #0
	beq _08062A88
	adds r3, #0x14
_08062A88:
	movs r1, #0
	b _08062A9A
	.align 2, 0
_08062A8C: .4byte 0x083BB9CC
_08062A90: .4byte 0x030004DE
_08062A94:
	adds r1, #1
	cmp r1, #0x13
	bhi _08062AA8
_08062A9A:
	ldrb r0, [r2]
	strb r0, [r3]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0xfe
	bne _08062A94
_08062AA8:
	movs r0, #0xfe
	strb r0, [r3]
	bx lr
	.align 2, 0
	.syntax divided
