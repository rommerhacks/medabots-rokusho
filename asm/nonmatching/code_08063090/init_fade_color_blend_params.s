	.syntax unified

	thumb_func_start init_fade_color_blend_params
	.global init_fade_color_blend_params
init_fade_color_blend_params: @ 0x08066880
	push {lr}
	sub sp, #0x40
	mov r0, sp
	movs r1, #0
	movs r2, #0x40
	bl custom_memset
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp]
	str r0, [sp, #0x14]
	str r0, [sp, #0x28]
	str r0, [sp, #0x3c]
	ldr r0, _080668B0 @ =0x03006F74
	ldr r0, [r0]
	movs r1, #0xf8
	lsls r1, r1, #1
	adds r0, r0, r1
	mov r1, sp
	bl copy_block_64bytes
	add sp, #0x40
	pop {r0}
	bx r0
	.align 2, 0
_080668B0: .4byte 0x03006F74
	.syntax divided
