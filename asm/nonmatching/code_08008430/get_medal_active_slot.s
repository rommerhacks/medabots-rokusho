	.syntax unified

	thumb_func_start get_medal_active_slot
get_medal_active_slot: @ 0x08009CAC
	push {lr}
	lsls r0, r0, #0x18
	ldr r1, _08009CD0 @ =0x03000BE0
	lsrs r0, r0, #0x12
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08009CD4
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08009CD4
	ldrb r0, [r2, #1]
	bl sub_0804384C
	b _08009CD6
	.align 2, 0
_08009CD0: .4byte 0x03000BE0
_08009CD4:
	movs r0, #0xff
_08009CD6:
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
