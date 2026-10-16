	.syntax unified

	thumb_func_start sub_0804AA28
sub_0804AA28: @ 0x0804AA28
	push {lr}
	sub sp, #4
	ldr r0, _0804AA94 @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	ldr r0, _0804AA98 @ =0x030055A0
	movs r1, #0x80
	lsls r1, r1, #2
	bl sub_080496C8
	movs r0, #0
	str r0, [sp]
	ldr r1, _0804AA9C @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0804AAA0 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_0804B1FC
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xf2
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0804AAA4 @ =0x030057E0
	ldr r1, _0804AAA8 @ =0x00000CBA
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	bl update_battle_field_frame
	movs r0, #6
	movs r1, #0
	bl dispatch_jump_table_29
	ldr r1, _0804AAAC @ =0x42000000
	ldr r2, _0804AAB0 @ =0x00000000
	ldr r3, _0804AAB4 @ =0x41000000
	movs r0, #0
	bl setup_palette_fade_to_color
	bl sub_0804A1C4
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0804AA94: .4byte 0x03002C30
_0804AA98: .4byte 0x030055A0
_0804AA9C: .4byte 0x040000D4
_0804AAA0: .4byte 0x85000100
_0804AAA4: .4byte 0x030057E0
_0804AAA8: .4byte 0x00000CBA
_0804AAAC: .4byte 0x42000000
_0804AAB0: .4byte 0x00000000
_0804AAB4: .4byte 0x41000000
	.syntax divided
