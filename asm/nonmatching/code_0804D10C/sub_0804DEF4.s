	.syntax unified

	thumb_func_start sub_0804DEF4
sub_0804DEF4: @ 0x0804DEF4
	push {r4, r5, r6, r7, lr}
	ldr r6, _0804DF08 @ =0x030057E0
	ldr r0, _0804DF0C @ =0x00000C93
	adds r7, r6, r0
	ldrb r5, [r7]
	cmp r5, #0
	beq _0804DF10
	cmp r5, #1
	beq _0804DFA0
	b _0804E0D8
	.align 2, 0
_0804DF08: .4byte 0x030057E0
_0804DF0C: .4byte 0x00000C93
_0804DF10:
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r4, r6, r1
	ldr r2, _0804DF84 @ =0x00000C18
	adds r1, r6, r2
	adds r0, r4, #0
	movs r2, #8
	bl memcpy_u8
	strb r5, [r4]
	ldr r1, _0804DF88 @ =0x00000C13
	adds r0, r6, r1
	strb r5, [r0]
	ldr r2, _0804DF8C @ =0x00000C17
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #0x81
	adds r0, r6, r1
	ldrb r0, [r0]
	bl field_set_player_facing
	ldr r4, _0804DF90 @ =0x030037F0
	adds r1, r4, #0
	subs r1, #0x40
	adds r0, r4, #0
	movs r2, #0x40
	bl memcpy_u8
	ldr r2, _0804DF94 @ =0x00000C5B
	adds r0, r6, r2
	strb r5, [r0]
	movs r0, #0
	bl sub_08052BA0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _0804DF98 @ =0x0000CC0C
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x40
	strh r5, [r0]
	adds r4, #0x28
	strb r2, [r4]
	ldr r2, _0804DF9C @ =0x00000C5F
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	bl sub_08050B50
	movs r0, #0x70
	bl sub_08047BA8
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	b _0804E0D8
	.align 2, 0
_0804DF84: .4byte 0x00000C18
_0804DF88: .4byte 0x00000C13
_0804DF8C: .4byte 0x00000C17
_0804DF90: .4byte 0x030037F0
_0804DF94: .4byte 0x00000C5B
_0804DF98: .4byte 0x0000CC0C
_0804DF9C: .4byte 0x00000C5F
_0804DFA0:
	bl sub_08050B50
	ldr r1, _0804DFB8 @ =0x00000C94
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804DFD4
	cmp r0, #1
	bgt _0804DFBC
	cmp r0, #0
	beq _0804DFC6
	b _0804DFF6
	.align 2, 0
_0804DFB8: .4byte 0x00000C94
_0804DFBC:
	cmp r0, #2
	beq _0804DFE0
	cmp r0, #3
	beq _0804DFEC
	b _0804DFF6
_0804DFC6:
	ldr r0, _0804DFD0 @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x40
	b _0804DFF2
	.align 2, 0
_0804DFD0: .4byte 0x03002B64
_0804DFD4:
	ldr r0, _0804DFDC @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x80
	b _0804DFF2
	.align 2, 0
_0804DFDC: .4byte 0x03002B64
_0804DFE0:
	ldr r0, _0804DFE8 @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x20
	b _0804DFF2
	.align 2, 0
_0804DFE8: .4byte 0x03002B64
_0804DFEC:
	ldr r0, _0804E07C @ =0x03002B64
	ldrb r1, [r0]
	movs r2, #0x10
_0804DFF2:
	orrs r1, r2
	strb r1, [r0]
_0804DFF6:
	ldr r5, _0804E080 @ =0x03002C30
	ldr r2, _0804E084 @ =0x00000BC2
	adds r0, r5, r2
	ldrh r1, [r0]
	subs r2, #0x40
	adds r0, r5, r2
	movs r7, #0
	strh r1, [r0]
	ldr r0, _0804E088 @ =0x00000BE8
	adds r6, r5, r0
	ldrb r4, [r6]
	movs r0, #0x2f
	bl sub_080518F4
	adds r1, r0, #0
	movs r0, #0x10
	bl sub_0807CBBC
	lsls r0, r0, #1
	cmp r4, r0
	bge _0804E0A4
	movs r0, #0x2f
	bl sub_080518F4
	ldr r1, _0804E08C @ =0x00000BC4
	adds r3, r5, r1
	ldr r2, _0804E090 @ =0x083D69A0
	ldrb r1, [r6]
	lsls r0, r0, #2
	muls r0, r1, r0
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bge _0804E040
	adds r1, #0xf
_0804E040:
	asrs r1, r1, #4
	ldrh r0, [r3]
	subs r0, r0, r1
	ldr r2, _0804E094 @ =0x00000B84
	adds r1, r5, r2
	strh r0, [r1]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0804E05C
	adds r0, #3
_0804E05C:
	asrs r2, r0, #2
	movs r0, #0
	ldrsh r1, [r3, r0]
	adds r0, r1, #0
	subs r0, #0x10
	cmp r0, #0
	bge _0804E06C
	adds r0, #3
_0804E06C:
	asrs r0, r0, #2
	cmp r2, r0
	bgt _0804E09C
	ldr r2, _0804E098 @ =0x00000B8B
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	b _0804E0D8
	.align 2, 0
_0804E07C: .4byte 0x03002B64
_0804E080: .4byte 0x03002C30
_0804E084: .4byte 0x00000BC2
_0804E088: .4byte 0x00000BE8
_0804E08C: .4byte 0x00000BC4
_0804E090: .4byte 0x083D69A0
_0804E094: .4byte 0x00000B84
_0804E098: .4byte 0x00000B8B
_0804E09C:
	movs r0, #0x2e
	bl sub_0804877C
	b _0804E0D8
_0804E0A4:
	ldr r0, _0804E0E0 @ =0x00000BE6
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	strb r7, [r6]
	ldr r4, _0804E0E4 @ =0x030063F8
	adds r1, r4, #0
	subs r1, #8
	adds r0, r4, #0
	movs r2, #8
	bl memcpy_u8
	movs r0, #0x2e
	bl clear_battle_sprite_entry
	adds r1, r4, #0
	adds r1, #0x43
	movs r0, #1
	strb r0, [r1]
	bl sub_08052BA0
	adds r4, #0x47
	strb r7, [r4]
	bl map_script_command_done
_0804E0D8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804E0E0: .4byte 0x00000BE6
_0804E0E4: .4byte 0x030063F8
	.syntax divided
