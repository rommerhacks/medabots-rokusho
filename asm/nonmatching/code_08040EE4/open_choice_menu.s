	.syntax unified

	thumb_func_start open_choice_menu
	.global open_choice_menu
open_choice_menu: @ 0x080415E8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	adds r3, r2, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r4, _08041620 @ =0x03000468
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0
	str r3, [sp]
	bl sub_0803F624
	strb r5, [r4, #2]
	movs r0, #0x7f
	strb r0, [r4, #3]
	strb r6, [r4, #4]
	ldr r3, [sp]
	strb r3, [r4, #5]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08041620: .4byte 0x03000468
	.syntax divided
