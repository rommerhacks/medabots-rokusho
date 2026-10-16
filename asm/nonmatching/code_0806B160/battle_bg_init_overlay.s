	.syntax unified

	thumb_func_start battle_bg_init_overlay
battle_bg_init_overlay: @ 0x0806E660
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0806E740 @ =0xFFFFF650
	add sp, r4
	ldr r0, _0806E744 @ =0x087F27F8
	ldr r1, _0806E748 @ =0x06008000
	bl LZ77UnCompVram
	ldr r0, _0806E74C @ =0x087F3070
	mov r1, sp
	bl LZ77UnCompVram
	movs r1, #0
	ldr r0, _0806E750 @ =0x087F3250
	mov sb, r0
	ldr r2, _0806E754 @ =0x03001800
	mov sl, r2
	movs r5, #0x96
	lsls r5, r5, #3
	add r5, sp
	movs r7, #0
	mov r8, r5
	movs r3, #0x80
	lsls r3, r3, #5
	mov ip, r3
_0806E698:
	lsls r4, r1, #5
	lsls r0, r1, #4
	adds r6, r1, #1
	subs r0, r0, r1
	lsls r0, r0, #2
	mov r3, sp
	adds r2, r0, r3
	lsls r0, r1, #6
	mov r3, r8
	adds r1, r0, r3
	movs r3, #0x1d
_0806E6AE:
	ldrh r0, [r2]
	add r0, ip
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _0806E6AE
	adds r0, r4, #0
	adds r0, #0x1e
	lsls r0, r0, #1
	adds r0, r5, r0
	strh r7, [r0]
	adds r0, r4, #0
	adds r0, #0x1f
	lsls r0, r0, #1
	adds r0, r5, r0
	strh r7, [r0]
	adds r1, r6, #0
	cmp r1, #0x13
	ble _0806E698
	ldr r0, _0806E758 @ =0x040000D4
	movs r1, #0x96
	lsls r1, r1, #3
	add r1, sp
	str r1, [r0]
	ldr r1, _0806E75C @ =0x0600F800
	str r1, [r0, #4]
	ldr r1, _0806E760 @ =0x84000140
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sb
	str r1, [r0]
	ldr r1, _0806E764 @ =0x05000020
	str r1, [r0, #4]
	ldr r1, _0806E768 @ =0x80000010
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _0806E76C @ =0x0400000A
	ldr r2, _0806E770 @ =0x00001F0B
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0806E774 @ =0x04000050
	ldr r2, _0806E778 @ =0x00000241
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x10
	strh r0, [r1]
	movs r0, #9
	mov r3, sl
	strh r0, [r3, #4]
	movs r0, #3
	ldr r1, _0806E77C @ =0x0300137C
	str r0, [r1]
	movs r3, #0x9b
	lsls r3, r3, #4
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806E740: .4byte 0xFFFFF650
_0806E744: .4byte 0x087F27F8
_0806E748: .4byte 0x06008000
_0806E74C: .4byte 0x087F3070
_0806E750: .4byte 0x087F3250
_0806E754: .4byte 0x03001800
_0806E758: .4byte 0x040000D4
_0806E75C: .4byte 0x0600F800
_0806E760: .4byte 0x84000140
_0806E764: .4byte 0x05000020
_0806E768: .4byte 0x80000010
_0806E76C: .4byte 0x0400000A
_0806E770: .4byte 0x00001F0B
_0806E774: .4byte 0x04000050
_0806E778: .4byte 0x00000241
_0806E77C: .4byte 0x0300137C
_0806E780:
	.byte 0x07, 0x48, 0x81, 0x68, 0x02, 0x1C, 0x00, 0x29, 0x0E, 0xD0, 0x3C, 0x29, 0x0C, 0xDD, 0x00, 0x20
	.byte 0x90, 0x60, 0x06, 0x20, 0x90, 0x80, 0x03, 0x49, 0x02, 0x20, 0x08, 0x60, 0x07, 0xE0, 0x00, 0x00
	.byte 0x00, 0x18, 0x00, 0x03, 0x7C, 0x13, 0x00, 0x03, 0x90, 0x68, 0x01, 0x30, 0x90, 0x60, 0x70, 0x47
	.byte 0x03, 0x48, 0x81, 0x68, 0x02, 0x1C, 0x00, 0x29, 0x04, 0xD1, 0x01, 0x20, 0x10, 0x73, 0x0B, 0xE0
	.byte 0x00, 0x18, 0x00, 0x03, 0x3C, 0x29, 0x07, 0xDD, 0x00, 0x20, 0x90, 0x60, 0x01, 0x49, 0x08, 0x20
	.byte 0x08, 0x60, 0x04, 0xE0, 0x7C, 0x13, 0x00, 0x03, 0x90, 0x68, 0x01, 0x30, 0x90, 0x60, 0x70, 0x47
	.syntax divided
