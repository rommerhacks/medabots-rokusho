	.syntax unified

	thumb_func_start sub_08074548
sub_08074548: @ 0x08074548
	push {lr}
	ldr r0, _08074564 @ =0x03007014
	ldr r1, [r0]
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08074560
	adds r0, r1, #0
	bl sound_channel1_update
_08074560:
	pop {r0}
	bx r0
	.align 2, 0
_08074564: .4byte 0x03007014
	.syntax divided
