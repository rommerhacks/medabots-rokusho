	.syntax unified

	thumb_func_start sub_0801C988
sub_0801C988: @ 0x0801C988
	push {r4, lr}
	ldr r1, _0801C9BC @ =0x03002C30
	ldr r0, _0801C9C0 @ =0x00000848
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bne _0801C9B6
	ldr r0, _0801C9C4 @ =0x03001800
	adds r4, r0, #0
	adds r4, #0xaa
	ldrb r0, [r4]
	cmp r0, #0x1f
	bhi _0801C9B0
	movs r0, #0x3f
	bl play_sound_effect
_0801C9B0:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0801C9B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C9BC: .4byte 0x03002C30
_0801C9C0: .4byte 0x00000848
_0801C9C4: .4byte 0x03001800
	.syntax divided
