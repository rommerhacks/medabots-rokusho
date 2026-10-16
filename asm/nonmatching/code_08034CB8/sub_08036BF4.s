	.syntax unified

	thumb_func_start sub_08036BF4
	.global sub_08036BF4
sub_08036BF4: @ 0x08036BF4
	push {lr}
	sub sp, #8
	movs r2, #2
	cmp r0, #0
	bne _08036C00
	movs r2, #0x10
_08036C00:
	ldr r0, _08036C1C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #0xd
	movs r3, #0
	bl vram_fill_tilemap_rect
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08036C1C: .4byte 0x0400000A
	.syntax divided
