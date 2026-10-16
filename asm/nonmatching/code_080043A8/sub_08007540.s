	.syntax unified

	thumb_func_start sub_08007540
sub_08007540: @ 0x08007540
	push {r4, r5, lr}
	movs r2, #0
	ldr r5, _0800757C @ =0x03001800
	ldr r0, _08007580 @ =0x03000590
	adds r3, r5, #0
	adds r3, #0x5b
	movs r4, #0xd0
	lsls r4, r4, #2
	adds r1, r0, r4
	movs r4, #0x80
	lsls r4, r4, #1
_08007556:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08007562
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_08007562:
	adds r1, r1, r4
	adds r2, #1
	cmp r2, #2
	bls _08007556
	adds r0, r5, #0
	adds r0, #0x5b
	ldrb r1, [r0]
	movs r0, #3
	bl setup_bot_render_label
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800757C: .4byte 0x03001800
_08007580: .4byte 0x03000590
	.syntax divided
