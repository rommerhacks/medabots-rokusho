	.syntax unified

	thumb_func_start sub_0804C598
sub_0804C598: @ 0x0804C598
	push {r4, r5, r6, r7, lr}
	bl read_map_script_byte
	ldr r1, _0804C5F0 @ =0x030057E0
	ldr r2, _0804C5F4 @ =0x00000C94
	adds r1, r1, r2
	strb r0, [r1]
	movs r5, #0
	ldr r7, _0804C5F8 @ =0x030055A0
	adds r6, r1, #0
_0804C5AC:
	lsls r0, r5, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	bl sub_0804DBA4
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _0804C5E2
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #0
	beq _0804C5E2
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	bl set_sprite_animation_state
_0804C5E2:
	adds r5, #1
	cmp r5, #3
	ble _0804C5AC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C5F0: .4byte 0x030057E0
_0804C5F4: .4byte 0x00000C94
_0804C5F8: .4byte 0x030055A0
	.syntax divided
