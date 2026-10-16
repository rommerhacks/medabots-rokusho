	.syntax unified

	thumb_func_start draw_battle_ui_tiles_from_rom
draw_battle_ui_tiles_from_rom: @ 0x0803E83C
	push {r4, r5, lr}
	sub sp, #4
	movs r5, #0
	ldr r4, _0803E868 @ =0x083ACEEA
_0803E844:
	ldrb r1, [r4]
	ldrb r2, [r4, #1]
	ldr r0, _0803E86C @ =0x04000008
	ldrh r3, [r0]
	movs r0, #0x83
	lsls r0, r0, #8
	str r0, [sp]
	movs r0, #0xff
	bl draw_tilemap_with_offset
	adds r4, #2
	adds r5, #1
	cmp r5, #2
	bls _0803E844
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E868: .4byte 0x083ACEEA
_0803E86C: .4byte 0x04000008
	.syntax divided
