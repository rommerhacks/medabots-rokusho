	.syntax unified

	thumb_func_start sub_08036340
	.global sub_08036340
sub_08036340: @ 0x08036340
	push {lr}
	sub sp, #4
	movs r1, #4
	cmp r0, #0
	bne _0803634C
	movs r1, #0x12
_0803634C:
	ldr r2, _08036364 @ =0x084889B4
	ldr r0, _08036368 @ =0x0400000A
	ldrh r3, [r0]
	ldr r0, _0803636C @ =0x00000329
	str r0, [sp]
	adds r0, r1, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08036364: .4byte 0x084889B4
_08036368: .4byte 0x0400000A
_0803636C: .4byte 0x00000329
	.syntax divided
