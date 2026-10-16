	.syntax unified

	thumb_func_start init_battle_sprite_vram
init_battle_sprite_vram: @ 0x0800B8B0
	push {r4, lr}
	sub sp, #4
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _0800B90C @ =0x040000D4
	ldr r1, _0800B910 @ =0x03002C30
	str r1, [r4]
	ldr r0, _0800B914 @ =0x02020800
	str r0, [r4, #4]
	ldr r0, _0800B918 @ =0x84000400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	str r0, [r4]
	str r1, [r4, #4]
	ldr r0, _0800B91C @ =0x85000400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800B920 @ =0x084C6A98
	ldr r1, _0800B924 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r0, _0800B928 @ =0x084E2E38
	str r0, [r4]
	ldr r0, _0800B92C @ =0x050003E0
	str r0, [r4, #4]
	ldr r0, _0800B930 @ =0x84000008
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _0800B934 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B90C: .4byte 0x040000D4
_0800B910: .4byte 0x03002C30
_0800B914: .4byte 0x02020800
_0800B918: .4byte 0x84000400
_0800B91C: .4byte 0x85000400
_0800B920: .4byte 0x084C6A98
_0800B924: .4byte 0x06017400
_0800B928: .4byte 0x084E2E38
_0800B92C: .4byte 0x050003E0
_0800B930: .4byte 0x84000008
_0800B934: .4byte 0x0300137C
	.syntax divided
