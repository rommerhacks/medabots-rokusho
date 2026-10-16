	.syntax unified

	thumb_func_start accumulate_alive_bot_score
accumulate_alive_bot_score: @ 0x08012608
	push {r4, r5, lr}
	movs r4, #0
	movs r3, #0
	ldr r5, _08012640 @ =0x03001800
	ldr r0, _08012644 @ =0x03000590
	ldr r1, _08012648 @ =0x000003BA
	adds r2, r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
_0801261A:
	ldrb r0, [r2]
	cmp r0, #0
	beq _08012622
	adds r4, #1
_08012622:
	adds r2, r2, r1
	adds r3, #1
	cmp r3, #2
	bls _0801261A
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r5, r2
	lsls r0, r4, #3
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08012640: .4byte 0x03001800
_08012644: .4byte 0x03000590
_08012648: .4byte 0x000003BA
	.syntax divided
