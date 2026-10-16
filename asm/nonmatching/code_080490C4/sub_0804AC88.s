	.syntax unified

	thumb_func_start sub_0804AC88
sub_0804AC88: @ 0x0804AC88
	push {lr}
	sub sp, #4
	ldr r0, _0804ACF8 @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	ldr r0, _0804ACFC @ =0x030055A0
	movs r1, #0x80
	lsls r1, r1, #2
	bl sub_080496C8
	movs r0, #0
	str r0, [sp]
	ldr r1, _0804AD00 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0804AD04 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_0804B1FC
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xf2
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0804AD08 @ =0x030057E0
	ldr r1, _0804AD0C @ =0x00000CBA
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	bl update_battle_field_frame
	bl load_battlefield_data_to_buffer
	movs r0, #0xb
	movs r1, #0
	bl dispatch_jump_table_29
	ldr r1, _0804AD10 @ =0x42000000
	ldr r2, _0804AD14 @ =0x00000000
	ldr r3, _0804AD18 @ =0x41000000
	movs r0, #0
	bl setup_palette_fade_to_color
	bl sub_0804A1C4
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0804ACF8: .4byte 0x03002C30
_0804ACFC: .4byte 0x030055A0
_0804AD00: .4byte 0x040000D4
_0804AD04: .4byte 0x85000100
_0804AD08: .4byte 0x030057E0
_0804AD0C: .4byte 0x00000CBA
_0804AD10: .4byte 0x42000000
_0804AD14: .4byte 0x00000000
_0804AD18: .4byte 0x41000000
	.syntax divided
