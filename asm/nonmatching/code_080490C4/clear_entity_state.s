	.syntax unified

	thumb_func_start clear_entity_state
	.global clear_entity_state
clear_entity_state: @ 0x080492F8
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r4, #2
	ldr r1, _08049320 @ =0x030055A0
	adds r0, r0, r1
	movs r1, #4
	bl sub_080496C8
	lsls r4, r4, #6
	ldr r0, _08049324 @ =0x03002C30
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x40
	bl sub_080496C8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08049320: .4byte 0x030055A0
_08049324: .4byte 0x03002C30
	.syntax divided
