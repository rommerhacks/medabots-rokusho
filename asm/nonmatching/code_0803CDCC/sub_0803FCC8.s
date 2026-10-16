	.syntax unified

	thumb_func_start sub_0803FCC8
sub_0803FCC8: @ 0x0803FCC8
	push {r4, r5, lr}
	sub sp, #0xc
	movs r5, #0
	ldr r4, _0803FD14 @ =0x06000280
_0803FCD0:
	ldr r0, _0803FD18 @ =0x084C01C8
	adds r1, r4, #0
	movs r2, #0x10
	bl CpuFastSet
	adds r4, #0x40
	adds r5, #1
	cmp r5, #0x33
	bls _0803FCD0
	ldr r0, _0803FD1C @ =0x083B4AE0
	ldr r0, [r0, #0x48]
	str r0, [sp]
	ldr r0, _0803FD20 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x1a
	movs r1, #4
	movs r2, #2
	movs r3, #0xe
	bl write_tilemap_rect
	ldr r1, _0803FD24 @ =0x03000440
	ldrb r0, [r1, #4]
	adds r0, #1
	strb r0, [r1, #4]
	bl sub_0803FD28
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803FD14: .4byte 0x06000280
_0803FD18: .4byte 0x084C01C8
_0803FD1C: .4byte 0x083B4AE0
_0803FD20: .4byte 0x04000008
_0803FD24: .4byte 0x03000440
	.syntax divided
