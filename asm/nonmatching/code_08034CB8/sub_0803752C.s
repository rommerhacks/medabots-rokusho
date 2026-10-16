	.syntax unified

	thumb_func_start sub_0803752C
	.global sub_0803752C
sub_0803752C: @ 0x0803752C
	push {r4, lr}
	adds r4, r2, #0
	subs r1, r1, r0
	cmp r1, r4
	bls _08037554
	ldr r3, _08037550 @ =0x03001800
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
	b _0803756E
	.align 2, 0
_08037550: .4byte 0x03001800
_08037554:
	ldr r3, _08037574 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xc8
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	subs r0, r4, r1
	adds r1, r3, #0
	adds r1, #0xca
	strh r0, [r1]
	adds r1, #7
	movs r0, #1
	strb r0, [r1]
_0803756E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037574: .4byte 0x03001800
	.syntax divided
