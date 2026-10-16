	.syntax unified

	thumb_func_start sub_080374E0
	.global sub_080374E0
sub_080374E0: @ 0x080374E0
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	cmp r3, r4
	bls _08037508
	ldr r3, _08037504 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xc8
	movs r2, #0
	movs r1, #0
	strh r4, [r0]
	adds r0, #4
	strh r4, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r0, #7
	strb r2, [r0]
	b _08037522
	.align 2, 0
_08037504: .4byte 0x03001800
_08037508:
	ldr r2, _08037528 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xc8
	strh r3, [r0]
	adds r0, #4
	strh r3, [r0]
	subs r0, r4, r3
	adds r1, r2, #0
	adds r1, #0xca
	strh r0, [r1]
	adds r1, #7
	movs r0, #1
	strb r0, [r1]
_08037522:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037528: .4byte 0x03001800
	.syntax divided
