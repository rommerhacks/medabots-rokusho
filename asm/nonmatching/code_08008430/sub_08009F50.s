	.syntax unified

	thumb_func_start sub_08009F50
	.global sub_08009F50
sub_08009F50: @ 0x08009F50
	push {lr}
	sub sp, #0x10
	movs r0, #0x14
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r0, _08009F88 @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r1, _08009F8C @ =0x03000BEA
	adds r0, r0, r1
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #0x14
	movs r2, #0x12
	movs r3, #3
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_08009F88: .4byte 0x03000440
_08009F8C: .4byte 0x03000BEA
	.syntax divided
