	.syntax unified

	thumb_func_start sub_08057B68
sub_08057B68: @ 0x08057B68
	push {r4, lr}
	ldr r1, _08057BA0 @ =0x08414968
	ldr r0, _08057BA4 @ =0x030064A0
	adds r4, r0, #0
	adds r4, #0x70
	ldrb r0, [r4]
	adds r0, #0x82
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #1
	movs r1, #1
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _08057BB2
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi _08057BAC
	ldr r1, _08057BA8 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	b _08057BB0
	.align 2, 0
_08057BA0: .4byte 0x08414968
_08057BA4: .4byte 0x030064A0
_08057BA8: .4byte 0x0300137C
_08057BAC:
	ldr r1, _08057BB8 @ =0x0300137C
	movs r0, #2
_08057BB0:
	str r0, [r1]
_08057BB2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08057BB8: .4byte 0x0300137C
	.syntax divided
