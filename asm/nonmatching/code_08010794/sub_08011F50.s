	.syntax unified

	thumb_func_start sub_08011F50
	.global sub_08011F50
sub_08011F50: @ 0x08011F50
	push {r4, lr}
	sub sp, #0x18
	ldr r1, _08011F94 @ =0x083C3F38
	ldr r0, _08011F98 @ =0x03001800
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _08011F9C @ =0x030004DE
	adds r1, r4, #0
	movs r2, #0x12
	bl memcpy_bytes_0803F63C
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	subs r0, #5
	str r0, [sp, #0x14]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0x12
	movs r3, #3
	bl render_text_sprites_08040EE4
	add sp, #0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08011F94: .4byte 0x083C3F38
_08011F98: .4byte 0x03001800
_08011F9C: .4byte 0x030004DE
	.syntax divided
