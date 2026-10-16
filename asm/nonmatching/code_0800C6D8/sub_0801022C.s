	.syntax unified

	thumb_func_start sub_0801022C
sub_0801022C: @ 0x0801022C
	push {lr}
	sub sp, #8
	ldr r0, _08010258 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #8
	movs r2, #0x12
	movs r3, #5
	bl vram_fill_tilemap_rect
	ldr r0, _0801025C @ =0x03002C30
	ldr r2, _08010260 @ =0x00000129
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08010258: .4byte 0x04000008
_0801025C: .4byte 0x03002C30
_08010260: .4byte 0x00000129
	.syntax divided
