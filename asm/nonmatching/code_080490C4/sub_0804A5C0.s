	.syntax unified

	thumb_func_start sub_0804A5C0
sub_0804A5C0: @ 0x0804A5C0
	push {r4, lr}
	sub sp, #4
	ldr r0, _0804A624 @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	ldr r0, _0804A628 @ =0x030055A0
	movs r1, #0x80
	lsls r1, r1, #2
	bl sub_080496C8
	movs r4, #0
	str r4, [sp]
	ldr r1, _0804A62C @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0804A630 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_080492CC
	bl sub_08048B6C
	ldr r1, _0804A634 @ =0x030057E0
	ldr r2, _0804A638 @ =0x00000C8A
	adds r0, r1, r2
	movs r2, #0
	strh r4, [r0]
	ldr r3, _0804A63C @ =0x00000C88
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, _0804A640 @ =0x00000C89
	adds r1, r1, r0
	strb r2, [r1]
	ldr r0, _0804A644 @ =0x00007FFF
	ldr r1, _0804A648 @ =0x42000000
	ldr r2, _0804A64C @ =0x00000000
	ldr r3, _0804A650 @ =0x41000000
	bl setup_palette_fade_to_color
	bl sub_0804A1C4
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A624: .4byte 0x03002C30
_0804A628: .4byte 0x030055A0
_0804A62C: .4byte 0x040000D4
_0804A630: .4byte 0x85000100
_0804A634: .4byte 0x030057E0
_0804A638: .4byte 0x00000C8A
_0804A63C: .4byte 0x00000C88
_0804A640: .4byte 0x00000C89
_0804A644: .4byte 0x00007FFF
_0804A648: .4byte 0x42000000
_0804A64C: .4byte 0x00000000
_0804A650: .4byte 0x41000000
	.syntax divided
