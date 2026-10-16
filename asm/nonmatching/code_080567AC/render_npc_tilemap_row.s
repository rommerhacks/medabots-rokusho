	.syntax unified

	thumb_func_start render_npc_tilemap_row
render_npc_tilemap_row: @ 0x080580D0
	push {lr}
	sub sp, #0x14
	adds r2, r0, #0
	ldr r0, _0805810C @ =0x03006D14
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r1, r3
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r1, r3
	lsls r2, r2, #1
	adds r2, #1
	movs r3, #8
	str r3, [sp]
	movs r3, #2
	str r3, [sp, #4]
	movs r3, #0x84
	lsls r3, r3, #1
	str r3, [sp, #8]
	movs r3, #0xe
	str r3, [sp, #0xc]
	movs r3, #0
	str r3, [sp, #0x10]
	movs r3, #6
	bl copy_tilemap_region
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_0805810C: .4byte 0x03006D14
	.syntax divided
