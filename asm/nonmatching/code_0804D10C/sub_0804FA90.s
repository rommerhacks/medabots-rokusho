	.syntax unified

	thumb_func_start sub_0804FA90
sub_0804FA90: @ 0x0804FA90
	push {r4, lr}
	ldr r0, _0804FAA4 @ =0x030057E0
	ldr r1, _0804FAA8 @ =0x00000C93
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FAAC
	cmp r0, #1
	beq _0804FAB8
	b _0804FAC8
	.align 2, 0
_0804FAA4: .4byte 0x030057E0
_0804FAA8: .4byte 0x00000C93
_0804FAAC:
	bl sub_08050C74
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804FAC8
_0804FAB8:
	movs r0, #8
	movs r1, #0
	bl scene_state_dispatch
	cmp r0, #0
	beq _0804FAC8
	bl map_script_command_done
_0804FAC8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
