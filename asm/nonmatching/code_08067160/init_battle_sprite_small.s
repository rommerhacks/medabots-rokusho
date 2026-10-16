	.syntax unified

	thumb_func_start init_battle_sprite_small
init_battle_sprite_small: @ 0x08069C5C
	push {lr}
	sub sp, #4
	ldr r1, _08069C7C @ =0x0000C004
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	movs r2, #0x33
	movs r3, #0
	bl init_battle_sprite_entry_08048818
	ldr r1, _08069C80 @ =0x03002C30
	ldr r0, _08069C84 @ =0x0000FFF0
	strh r0, [r1, #2]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08069C7C: .4byte 0x0000C004
_08069C80: .4byte 0x03002C30
_08069C84: .4byte 0x0000FFF0
	.syntax divided
