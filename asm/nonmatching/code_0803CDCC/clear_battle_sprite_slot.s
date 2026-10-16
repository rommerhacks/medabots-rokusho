	.syntax unified

	thumb_func_start clear_battle_sprite_slot
	.global clear_battle_sprite_slot
clear_battle_sprite_slot: @ 0x08040CD0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	movs r5, #0
	cmp r5, r6
	bhs _08040CFC
	lsls r4, r0, #6
	movs r7, #0
_08040CE6:
	str r7, [sp]
	ldr r1, _08040D04 @ =0x03002C30
	adds r1, r4, r1
	mov r0, sp
	ldr r2, _08040D08 @ =0x01000010
	bl CpuFastSet
	adds r4, #0x40
	adds r5, #1
	cmp r5, r6
	blo _08040CE6
_08040CFC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040D04: .4byte 0x03002C30
_08040D08: .4byte 0x01000010
	.syntax divided
