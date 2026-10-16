	.syntax unified

	thumb_func_start sprite_animation_dispatch
	.global sprite_animation_dispatch
sprite_animation_dispatch: @ 0x0806B39C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r7, r4, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	cmp r4, #0
	bne _0806B3D4
	ldr r1, _0806B3D0 @ =0x03002C30
	lsls r0, r0, #6
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x20
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldrh r0, [r1, #0x30]
	strh r0, [r1, #6]
	strh r4, [r1, #0x1a]
	b _0806B57C
	.align 2, 0
_0806B3D0: .4byte 0x03002C30
_0806B3D4:
	ldr r1, _0806B3FC @ =0x03002C30
	lsls r2, r0, #6
	adds r0, r2, r1
	adds r0, #0x20
	ldrb r0, [r0]
	adds r6, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	beq _0806B3E8
	b _0806B57C
_0806B3E8:
	subs r0, r7, #1
	cmp r0, #9
	bls _0806B3F0
	b _0806B576
_0806B3F0:
	lsls r0, r0, #2
	ldr r1, _0806B400 @ =_0806B404
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B3FC: .4byte 0x03002C30
_0806B400: .4byte _0806B404
_0806B404: @ jump table
	.4byte _0806B42C @ case 0
	.4byte _0806B454 @ case 1
	.4byte _0806B478 @ case 2
	.4byte _0806B49C @ case 3
	.4byte _0806B4C4 @ case 4
	.4byte _0806B4F0 @ case 5
	.4byte _0806B510 @ case 6
	.syntax divided
