	.syntax unified

	thumb_func_start sub_08047D24
	.global sub_08047D24
sub_08047D24: @ 0x08047D24
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r4, sp, #0xc
	adds r3, r4, #0
	ldr r2, _08047D48 @ =0x080ABBFC
	ldm r2!, {r5, r6, r7}
	stm r3!, {r5, r6, r7}
	ldr r2, [r2]
	str r2, [r3]
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r0, [r4]
	bl divide_by_10000_b
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08047D48: .4byte 0x080ABBFC
	.syntax divided
