	.syntax unified

	thumb_func_start load_bg_tilemaps_and_palette
load_bg_tilemaps_and_palette: @ 0x0806977C
	push {r4, lr}
	ldr r4, _08069830 @ =0xFFFFF7FC
	add sp, r4
	ldr r0, _08069834 @ =0x087B2CCC
	ldr r1, _08069838 @ =0x0600C000
	bl LZ77UnCompVram
	movs r1, #0x80
	lsls r1, r1, #4
	add r1, sp
	movs r0, #0
	str r0, [r1]
	ldr r0, _0806983C @ =0x040000D4
	str r1, [r0]
	mov r1, sp
	str r1, [r0, #4]
	ldr r1, _08069840 @ =0x85000200
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r0, _08069844 @ =0x087B3710
	mov r1, sp
	bl LZ77UnCompVram
	movs r2, #0xc0
	lsls r2, r2, #8
	adds r3, r2, #0
	mov r1, sp
	movs r2, #0xa0
	lsls r2, r2, #2
_080697B6:
	ldrh r4, [r1]
	adds r0, r3, r4
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _080697B6
	ldr r1, _0806983C @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _08069848 @ =0x0600E800
	str r0, [r1, #4]
	ldr r0, _0806984C @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08069850 @ =0x087B384C
	mov r1, sp
	bl LZ77UnCompVram
	movs r1, #0xc0
	lsls r1, r1, #8
	adds r3, r1, #0
	mov r1, sp
	movs r2, #0x80
	lsls r2, r2, #3
_080697E8:
	ldrh r4, [r1]
	adds r0, r3, r4
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _080697E8
	ldr r0, _0806983C @ =0x040000D4
	mov r1, sp
	str r1, [r0]
	ldr r1, _08069854 @ =0x0600F800
	str r1, [r0, #4]
	ldr r1, _0806984C @ =0x80000400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08069858 @ =0x087B3AF0
	str r1, [r0]
	ldr r1, _0806985C @ =0x05000180
	str r1, [r0, #4]
	ldr r1, _08069860 @ =0x80000020
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _08069864 @ =0x0400000A
	ldr r2, _08069868 @ =0x00001D0D
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	ldr r4, _0806986C @ =0x00001F0F
	adds r0, r4, #0
	strh r0, [r1]
	ldr r3, _08069870 @ =0x00000804
	add sp, r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08069830: .4byte 0xFFFFF7FC
_08069834: .4byte 0x087B2CCC
_08069838: .4byte 0x0600C000
_0806983C: .4byte 0x040000D4
_08069840: .4byte 0x85000200
_08069844: .4byte 0x087B3710
_08069848: .4byte 0x0600E800
_0806984C: .4byte 0x80000400
_08069850: .4byte 0x087B384C
_08069854: .4byte 0x0600F800
_08069858: .4byte 0x087B3AF0
_0806985C: .4byte 0x05000180
_08069860: .4byte 0x80000020
_08069864: .4byte 0x0400000A
_08069868: .4byte 0x00001D0D
_0806986C: .4byte 0x00001F0F
_08069870: .4byte 0x00000804
	.syntax divided
