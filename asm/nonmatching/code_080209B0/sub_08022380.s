	.syntax unified

	thumb_func_start sub_08022380
sub_08022380: @ 0x08022380
	push {r4, lr}
	ldr r1, _0802239C @ =0x03001800
	adds r4, r1, #0
	adds r4, #0x58
	ldrb r0, [r4]
	adds r2, r1, #0
	cmp r0, #0
	bne _080223A0
	adds r1, #0xa6
	movs r0, #0x72
	strb r0, [r1]
	movs r0, #1
	strb r0, [r4]
	b _080223AC
	.align 2, 0
_0802239C: .4byte 0x03001800
_080223A0:
	adds r3, r2, #0
	adds r3, #0xa6
	movs r1, #0
	movs r0, #0x73
	strb r0, [r3]
	strb r1, [r4]
_080223AC:
	adds r1, r2, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
