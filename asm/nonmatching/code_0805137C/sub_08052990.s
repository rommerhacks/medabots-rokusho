	.syntax unified

	thumb_func_start sub_08052990
	.global sub_08052990
sub_08052990: @ 0x08052990
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r2, #0
	cmp r1, #0
	beq _080529A0
	cmp r1, #1
	beq _080529B0
	b _080529BC
_080529A0:
	ldr r0, _080529AC @ =0x03006D14
	ldr r0, [r0]
	ldrh r2, [r0]
	ldrh r0, [r0, #2]
	b _080529B8
	.align 2, 0
_080529AC: .4byte 0x03006D14
_080529B0:
	ldr r0, _080529C0 @ =0x03006D14
	ldr r0, [r0]
	ldrh r2, [r0, #4]
	ldrh r0, [r0, #6]
_080529B8:
	lsls r0, r0, #0x10
	orrs r2, r0
_080529BC:
	adds r0, r2, #0
	bx lr
	.align 2, 0
_080529C0: .4byte 0x03006D14
	.syntax divided
