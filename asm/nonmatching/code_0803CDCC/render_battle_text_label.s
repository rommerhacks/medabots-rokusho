	.syntax unified

	thumb_func_start render_battle_text_label
render_battle_text_label: @ 0x0803E7C0
	push {lr}
	sub sp, #0x18
	ldr r0, _0803E7EC @ =0x0300198A
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r2, #0
	str r2, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	subs r1, #5
	str r1, [sp, #0x14]
	movs r1, #0xa
	movs r2, #0x12
	movs r3, #3
	bl render_text_sprites_08040EE4
	add sp, #0x18
	pop {r0}
	bx r0
	.align 2, 0
_0803E7EC: .4byte 0x0300198A
	.syntax divided
