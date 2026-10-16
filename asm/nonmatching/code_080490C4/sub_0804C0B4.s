	.syntax unified

	thumb_func_start sub_0804C0B4
sub_0804C0B4: @ 0x0804C0B4
	push {lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r1, _0804C0D8 @ =0x030057E0
	ldr r2, _0804C0DC @ =0x00000C94
	adds r0, r1, r2
	ldrb r2, [r0]
	movs r0, #0xf
	ands r0, r2
	ldr r2, _0804C0E0 @ =0x00000C95
	adds r1, r1, r2
	ldrb r1, [r1]
	bl set_battle_sprite_animation
	pop {r0}
	bx r0
	.align 2, 0
_0804C0D8: .4byte 0x030057E0
_0804C0DC: .4byte 0x00000C94
_0804C0E0: .4byte 0x00000C95
	.syntax divided
