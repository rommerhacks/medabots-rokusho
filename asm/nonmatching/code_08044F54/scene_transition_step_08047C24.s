	.syntax unified

	thumb_func_start scene_transition_step_08047C24
	.global scene_transition_step_08047C24
scene_transition_step_08047C24: @ 0x08047C24
	push {r4, r5, r6, lr}
	adds r6, r3, #0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r5, #0
	ldr r4, _08047C44 @ =0x030064A0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08047C48
	cmp r0, #1
	beq _08047C68
	b _08047C7C
	.align 2, 0
_08047C44: .4byte 0x030064A0
_08047C48:
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _08047C56
	adds r0, r3, #0
	bl text_window_init
	b _08047C5A
_08047C56:
	bl sub_0803FB0C
_08047C5A:
	ldr r1, _08047C64 @ =0x030064A0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08047C7C
	.align 2, 0
_08047C64: .4byte 0x030064A0
_08047C68:
	adds r0, r6, #0
	bl run_message
	cmp r0, #0
	beq _08047C7C
	strb r5, [r4]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	movs r5, #1
_08047C7C:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
