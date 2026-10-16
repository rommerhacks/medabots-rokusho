	.syntax unified

	thumb_func_start sub_08013824
sub_08013824: @ 0x08013824
	push {r4, r5, lr}
	ldr r4, _08013868 @ =0x0300047C
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r5, #2
	strb r5, [r4]
	ldr r1, _0801386C @ =0x03000590
	ldr r0, _08013870 @ =0x03001800
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	bl find_medal_slot_by_id
	subs r0, #1
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4, #5]
	strb r5, [r4, #6]
	bl sub_08043CA8
	ldr r1, _08013874 @ =0x03002B8C
	movs r0, #4
	str r0, [r1]
	ldr r1, _08013878 @ =0x0300137C
	movs r0, #0x28
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08013868: .4byte 0x0300047C
_0801386C: .4byte 0x03000590
_08013870: .4byte 0x03001800
_08013874: .4byte 0x03002B8C
_08013878: .4byte 0x0300137C
	.syntax divided
