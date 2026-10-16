	.syntax unified

	thumb_func_start sub_0804FAD0
sub_0804FAD0: @ 0x0804FAD0
	push {r4, lr}
	ldr r0, _0804FAE8 @ =0x030057E0
	ldr r1, _0804FAEC @ =0x00000C93
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #1
	beq _0804FB04
	cmp r0, #1
	bgt _0804FAF0
	cmp r0, #0
	beq _0804FAFA
	b _0804FB3A
	.align 2, 0
_0804FAE8: .4byte 0x030057E0
_0804FAEC: .4byte 0x00000C93
_0804FAF0:
	cmp r0, #2
	beq _0804FB1E
	cmp r0, #3
	beq _0804FB2A
	b _0804FB3A
_0804FAFA:
	movs r0, #4
	movs r1, #0
	bl sub_08047878
	b _0804FB22
_0804FB04:
	ldr r0, _0804FB14 @ =0x03006D20
	ldrb r0, [r0, #0xc]
	cmp r0, #7
	bne _0804FB18
	movs r0, #2
	strb r0, [r4]
	b _0804FB3A
	.align 2, 0
_0804FB14: .4byte 0x03006D20
_0804FB18:
	bl map_script_command_done
	b _0804FB3A
_0804FB1E:
	bl sub_08050C74
_0804FB22:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804FB3A
_0804FB2A:
	movs r0, #5
	movs r1, #0
	bl scene_state_dispatch
	cmp r0, #0
	beq _0804FB3A
	bl map_script_command_done
_0804FB3A:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
