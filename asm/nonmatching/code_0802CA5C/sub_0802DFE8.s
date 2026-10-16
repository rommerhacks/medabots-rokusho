	.syntax unified

	thumb_func_start sub_0802DFE8
sub_0802DFE8: @ 0x0802DFE8
	push {lr}
	ldr r0, _0802E008 @ =0x083B5F80
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, _0802E00C @ =0x03001800
	adds r0, #0xaa
	movs r1, #4
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0802E008: .4byte 0x083B5F80
_0802E00C: .4byte 0x03001800
	.syntax divided
