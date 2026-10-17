	.syntax unified

	thumb_func_start sub_0806C4CC
sub_0806C4CC: @ 0x0806C4CC
	push {lr}
	ldr r1, _0806C4F8 @ =0x03002C30
	movs r2, #0xe2
	lsls r2, r2, #4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _0806C4F4
	ldr r0, _0806C4FC @ =0x00000E1A
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _0806C4F4
	movs r0, #0x38
	bl clear_sprite_entry
_0806C4F4:
	pop {r0}
	bx r0
	.align 2, 0
_0806C4F8: .4byte 0x03002C30
_0806C4FC: .4byte 0x00000E1A
	.syntax divided
