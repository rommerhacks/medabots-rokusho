	.syntax unified

	thumb_func_start copy_tilemap_rect_to_vram
	.global copy_tilemap_rect_to_vram
copy_tilemap_rect_to_vram: @ 0x0806FA30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0806FB24 @ =0xFFFFFAF0
	add sp, r4
	ldr r4, _0806FB28 @ =0x00000504
	add r4, sp
	str r0, [r4]
	movs r5, #0xa6
	lsls r5, r5, #3
	add r5, sp
	ldr r0, [r5]
	ldr r6, _0806FB2C @ =0x00000534
	add r6, sp
	ldr r4, [r6]
	movs r7, #0xa7
	lsls r7, r7, #3
	add r7, sp
	ldr r5, [r7]
	ldr r7, _0806FB30 @ =0x0000053C
	add r7, sp
	ldr r6, [r7]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r7, #0xa1
	lsls r7, r7, #3
	add r7, sp
	str r1, [r7]
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r8, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov sb, r4
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov ip, r5
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	ldr r0, _0806FB34 @ =0x0000050C
	add r0, sp
	str r6, [r0]
	movs r1, #0xa0
	lsls r1, r1, #3
	add r1, sp
	movs r0, #0
	str r0, [r1]
	ldr r0, _0806FB38 @ =0x040000D4
	str r1, [r0]
	mov r1, sp
	str r1, [r0, #4]
	ldr r1, _0806FB3C @ =0x85000140
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	movs r0, #0
	cmp r0, r8
	bge _0806FAF0
_0806FAB0:
	adds r5, r0, #1
	cmp r7, #0
	beq _0806FAEA
	mov r2, sb
	adds r1, r0, r2
	lsls r1, r1, #5
	muls r0, r7, r0
	ldr r3, _0806FB34 @ =0x0000050C
	add r3, sp
	ldr r3, [r3]
	lsls r4, r3, #0xc
	lsls r0, r0, #1
	ldr r6, _0806FB28 @ =0x00000504
	add r6, sp
	ldr r6, [r6]
	adds r2, r0, r6
	add r1, sl
	adds r3, r7, #0
	lsls r1, r1, #1
	add r1, sp
_0806FAD8:
	ldrh r0, [r2]
	adds r0, r0, r4
	add r0, ip
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bne _0806FAD8
_0806FAEA:
	adds r0, r5, #0
	cmp r0, r8
	blt _0806FAB0
_0806FAF0:
	ldr r2, _0806FB38 @ =0x040000D4
	mov r7, sp
	str r7, [r2]
	movs r1, #0xa1
	lsls r1, r1, #3
	add r1, sp
	ldr r1, [r1]
	lsls r0, r1, #0xb
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, _0806FB40 @ =0x80000280
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r3, #0xa2
	lsls r3, r3, #3
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806FB24: .4byte 0xFFFFFAF0
_0806FB28: .4byte 0x00000504
_0806FB2C: .4byte 0x00000534
_0806FB30: .4byte 0x0000053C
_0806FB34: .4byte 0x0000050C
_0806FB38: .4byte 0x040000D4
_0806FB3C: .4byte 0x85000140
_0806FB40: .4byte 0x80000280
	.syntax divided
