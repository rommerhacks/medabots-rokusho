	.syntax unified

	thumb_func_start write_tilemap_tiles_dma
write_tilemap_tiles_dma: @ 0x08069620
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x54]
	ldr r1, _080696E8 @ =0x080AFEE0
	mov r0, sp
	movs r2, #8
	bl memcpy_optimized
	add r5, sp, #8
	ldr r1, _080696EC @ =0x080AFEE8
	adds r0, r5, #0
	movs r2, #8
	bl memcpy_optimized
	add r0, sp, #0x10
	mov r8, r0
	ldr r1, _080696F0 @ =0x080AFEF0
	movs r2, #0x10
	bl memcpy_optimized
	add r4, sp, #0x20
	adds r1, r4, #0
	ldr r0, _080696F4 @ =0x080AFF00
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	add r6, sp, #0x40
	ldr r1, _080696F8 @ =0x080AFF20
	adds r0, r6, #0
	movs r2, #0x10
	bl memcpy_optimized
	movs r0, #7
	ands r7, r0
	lsls r0, r7, #2
	adds r4, r4, r0
	ldr r4, [r4]
	mov sb, r4
	movs r1, #0
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r1, r0
	bge _08069762
	mov r4, sp
	adds r4, r4, r7
	str r4, [sp, #0x58]
	mov r6, sl
	lsls r6, r6, #0x10
	str r6, [sp, #0x60]
_0806969E:
	movs r5, #0
	adds r0, r1, #1
	str r0, [sp, #0x5c]
	ldr r2, [sp, #0x58]
	ldrb r2, [r2]
	cmp r5, r2
	bge _08069754
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	mov sl, r0
	lsls r0, r7, #1
	mov r3, sp
	adds r3, r3, r0
	adds r3, #0x10
	mov ip, r3
	add r0, sp
	adds r0, #0x40
	mov r8, r0
	ldr r2, _080696FC @ =0x040000D4
	ldr r3, [sp, #0x60]
	mov r4, sp
	adds r4, #0x50
	str r4, [sp, #0x64]
	ldr r6, [sp, #0x54]
	adds r0, r1, r6
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xa
_080696D6:
	cmp r7, #4
	bls _08069700
	mov r0, sl
	adds r1, r0, r5
	mov r6, ip
	ldrh r6, [r6]
	adds r1, r1, r6
	b _0806970A
	.align 2, 0
_080696E8: .4byte 0x080AFEE0
_080696EC: .4byte 0x080AFEE8
_080696F0: .4byte 0x080AFEF0
_080696F4: .4byte 0x080AFF00
_080696F8: .4byte 0x080AFF20
_080696FC: .4byte 0x040000D4
_08069700:
	mov r6, ip
	ldrh r1, [r6]
	mov r0, sb
	ldrh r0, [r0]
	adds r1, r1, r0
_0806970A:
	mov r6, r8
	ldrh r0, [r6]
	adds r0, r0, r1
	ldr r1, [sp, #0x64]
	strh r0, [r1]
	add r0, sp, #0x50
	cmp r7, #3
	bhi _0806972C
	str r0, [r2]
	lsrs r0, r3, #0x10
	lsls r0, r0, #1
	ldr r6, _08069728 @ =0x0600F800
	adds r0, r0, r6
	b _08069736
	.align 2, 0
_08069728: .4byte 0x0600F800
_0806972C:
	str r0, [r2]
	lsrs r0, r3, #0x10
	lsls r0, r0, #1
	ldr r1, _08069774 @ =0x0600E800
	adds r0, r0, r1
_08069736:
	adds r0, r4, r0
	str r0, [r2, #4]
	ldr r0, _08069778 @ =0x80000001
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r6, #2
	add sb, r6
	movs r0, #0x80
	lsls r0, r0, #9
	adds r3, r3, r0
	adds r5, #1
	ldr r1, [sp, #0x58]
	ldrb r1, [r1]
	cmp r5, r1
	blt _080696D6
_08069754:
	ldr r1, [sp, #0x5c]
	mov r0, sp
	adds r0, r0, r7
	adds r0, #8
	ldrb r0, [r0]
	cmp r1, r0
	blt _0806969E
_08069762:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08069774: .4byte 0x0600E800
_08069778: .4byte 0x80000001
	.syntax divided
