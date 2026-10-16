	.syntax unified

	thumb_func_start sub_0804E878
sub_0804E878: @ 0x0804E878
	push {r4, r5, lr}
	ldr r5, _0804E88C @ =0x030057E0
	ldr r0, _0804E890 @ =0x00000C93
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804E894
	cmp r0, #1
	beq _0804E8A0
	b _0804E8C4
	.align 2, 0
_0804E88C: .4byte 0x030057E0
_0804E890: .4byte 0x00000C93
_0804E894:
	bl sub_08050C74
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804E8C4
_0804E8A0:
	movs r0, #0x20
	movs r1, #0
	bl scene_state_dispatch
	cmp r0, #0
	beq _0804E8C4
	ldr r1, _0804E8CC @ =0x00000C4F
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #1
	beq _0804E8BA
	cmp r1, #2
	bne _0804E8C0
_0804E8BA:
	ldr r0, _0804E8D0 @ =0x03005310
	adds r0, #0x39
	strb r1, [r0]
_0804E8C0:
	bl map_script_command_done
_0804E8C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E8CC: .4byte 0x00000C4F
_0804E8D0: .4byte 0x03005310

	.syntax divided
