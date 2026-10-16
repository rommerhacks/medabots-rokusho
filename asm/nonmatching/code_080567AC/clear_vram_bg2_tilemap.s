	.syntax unified

	thumb_func_start clear_vram_bg2_tilemap
clear_vram_bg2_tilemap: @ 0x08059D1C
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, _08059D5C @ =0x06008000
	ldr r2, _08059D60 @ =0x01001000
	mov r0, sp
	bl CpuFastSet
	ldr r0, _08059D64 @ =0x08784CB0
	ldr r1, _08059D68 @ =0x06008020
	bl lz_decompress_dispatch
	ldr r0, _08059D6C @ =0x08483AA0
	ldr r1, _08059D70 @ =0x05000020
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08059D74 @ =0x0400000C
	ldr r0, _08059D78 @ =0x00001608
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08059D5C: .4byte 0x06008000
_08059D60: .4byte 0x01001000
_08059D64: .4byte 0x08784CB0
_08059D68: .4byte 0x06008020
_08059D6C: .4byte 0x08483AA0
_08059D70: .4byte 0x05000020
_08059D74: .4byte 0x0400000C
_08059D78: .4byte 0x00001608
	.syntax divided
