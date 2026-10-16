	.syntax unified

	thumb_func_start clear_vram_bg1_tilemap
clear_vram_bg1_tilemap: @ 0x08059D7C
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, _08059DB4 @ =0x06004000
	ldr r2, _08059DB8 @ =0x01001000
	mov r0, sp
	bl CpuFastSet
	ldr r0, _08059DBC @ =0x08784CB0
	ldr r1, _08059DC0 @ =0x06004020
	bl lz_decompress_dispatch
	ldr r1, _08059DC4 @ =0x0400000A
	ldr r0, _08059DC8 @ =0x00001E04
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08059DB4: .4byte 0x06004000
_08059DB8: .4byte 0x01001000
_08059DBC: .4byte 0x08784CB0
_08059DC0: .4byte 0x06004020
_08059DC4: .4byte 0x0400000A
_08059DC8: .4byte 0x00001E04
	.syntax divided
