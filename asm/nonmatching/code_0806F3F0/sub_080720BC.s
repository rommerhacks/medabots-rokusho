	.syntax unified

	thumb_func_start sub_080720BC
sub_080720BC: @ 0x080720BC
	push {r4, lr}
	sub sp, #0x24
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x20]
	ldr r1, _08072124 @ =0x040000D4
	add r0, sp, #0x20
	str r0, [r1]
	ldr r0, _08072128 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0807212C @ =0x00000B84
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _08072130 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0x2a
	str r0, [sp]
	movs r0, #0x40
	str r0, [sp, #4]
	movs r0, #0x42
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #8
	str r0, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	movs r0, #0
	movs r1, #0x2a
	movs r2, #0x2a
	movs r3, #0x2a
	bl setup_scene_with_bg_and_sprites
	movs r0, #0
	movs r1, #0x2d
	movs r2, #0
	bl advance_text_display
	ldr r1, _08072134 @ =0x03001800
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
	strb r4, [r1, #0x11]
	movs r0, #0
	add sp, #0x24
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08072124: .4byte 0x040000D4
_08072128: .4byte 0x03002414
_0807212C: .4byte 0x00000B84
_08072130: .4byte 0x85000100
_08072134: .4byte 0x03001800
	.syntax divided
