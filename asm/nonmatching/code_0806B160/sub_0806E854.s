	.syntax unified

	thumb_func_start sub_0806E854
sub_0806E854: @ 0x0806E854
	push {lr}
	sub sp, #0x24
	ldr r0, _0806E8B4 @ =0x03000430
	ldr r2, [r0]
	cmp r2, #2
	bne _0806E8AE
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x20]
	ldr r1, _0806E8B8 @ =0x040000D4
	add r0, sp, #0x20
	str r0, [r1]
	ldr r0, _0806E8BC @ =0x03002414
	ldr r0, [r0]
	ldr r3, _0806E8C0 @ =0x00000B84
	adds r0, r0, r3
	str r0, [r1, #4]
	ldr r0, _0806E8C4 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0x2a
	str r0, [sp]
	movs r0, #0x70
	str r0, [sp, #4]
	movs r0, #0x50
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0xc
	str r0, [sp, #0x10]
	movs r1, #0
	str r1, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #0
	movs r1, #0x2a
	movs r2, #0x2a
	movs r3, #0x2a
	bl setup_scene_with_bg_and_sprites
	movs r0, #0
	movs r1, #0x2d
	movs r2, #0x2a
	bl advance_text_display
_0806E8AE:
	add sp, #0x24
	pop {r0}
	bx r0
	.align 2, 0
_0806E8B4: .4byte 0x03000430
_0806E8B8: .4byte 0x040000D4
_0806E8BC: .4byte 0x03002414
_0806E8C0: .4byte 0x00000B84
_0806E8C4: .4byte 0x85000100
	.syntax divided
