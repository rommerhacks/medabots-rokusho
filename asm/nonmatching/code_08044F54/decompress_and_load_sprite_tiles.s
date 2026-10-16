	.syntax unified

	thumb_func_start decompress_and_load_sprite_tiles
decompress_and_load_sprite_tiles: @ 0x08045084
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	mov sl, r1
	str r2, [sp, #0xc]
	mov r8, r3
	ldr r0, [sp, #0x38]
	ldr r6, [sp, #0x40]
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov sb, r7
	cmp r4, #0
	beq _08045106
	adds r0, r4, #0
	adds r1, r6, #0
	bl dma3_copy_or_decompress
	adds r5, r0, #0
	adds r4, r6, r5
	mov r0, r8
	str r0, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sl
	ldr r3, [sp, #0xc]
	bl copy_sprite_tiles_to_vram
	ldr r0, [sp, #0x44]
	cmp r0, #0
	beq _080450EC
	lsls r1, r7, #5
	ldr r0, _080450E8 @ =0x06010000
	adds r1, r1, r0
	lsls r2, r5, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r4, #0
	bl CpuSet
	b _08045106
	.align 2, 0
_080450E8: .4byte 0x06010000
_080450EC:
	ldr r2, _08045118 @ =0x040000B0
	str r4, [r2]
	mov r1, sb
	lsls r0, r1, #5
	ldr r1, _0804511C @ =0x06010000
	adds r0, r0, r1
	str r0, [r2, #4]
	lsrs r0, r5, #2
	movs r1, #0x94
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_08045106:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045118: .4byte 0x040000B0
_0804511C: .4byte 0x06010000
	.syntax divided
