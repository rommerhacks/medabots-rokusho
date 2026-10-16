	.syntax unified

	thumb_func_start sub_08010040
sub_08010040: @ 0x08010040
	push {r4, lr}
	ldr r3, _080100AC @ =0x03002C30
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r2, #0
	ldr r0, _080100B0 @ =0x0000D204
	strh r0, [r1]
	movs r4, #0x81
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r0, #0xa8
	strh r0, [r1]
	ldr r0, _080100B4 @ =0x03000440
	adds r0, #0x4a
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #0x38
	adds r4, #2
	adds r1, r3, r4
	strh r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, _080100B8 @ =0x00000307
	strh r0, [r1]
	adds r4, #6
	adds r1, r3, r4
	movs r0, #0xe
	strb r0, [r1]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #0x40
	strb r1, [r0]
	subs r4, #1
	adds r0, r3, r4
	strb r1, [r0]
	adds r1, #0xdc
	adds r0, r3, r1
	strb r2, [r0]
	adds r4, #0x20
	adds r0, r3, r4
	strb r2, [r0]
	adds r1, #0xb
	adds r0, r3, r1
	strb r2, [r0]
	subs r4, #0x1e
	adds r1, r3, r4
	movs r0, #0xc1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080100AC: .4byte 0x03002C30
_080100B0: .4byte 0x0000D204
_080100B4: .4byte 0x03000440
_080100B8: .4byte 0x00000307
	.syntax divided
