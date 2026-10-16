	.syntax unified

	thumb_func_start battle_draw_tilemap_row_dma
	.global battle_draw_tilemap_row_dma
battle_draw_tilemap_row_dma: @ 0x0806FDA4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #0xd2
	add r0, sp, #4
	strh r1, [r0]
	ldr r3, _0806FDCC @ =0x03001800
	movs r0, #0xed
	adds r0, r0, r3
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #2
	bls _0806FDD0
	movs r0, #1
	b _0806FF2E
	.align 2, 0
_0806FDCC: .4byte 0x03001800
_0806FDD0:
	ldr r7, _0806FE20 @ =0x0848604C
	mov r1, sb
	ldrb r6, [r1]
	lsls r1, r6, #2
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	mov r8, r0
	adds r4, r1, r0
	adds r0, r4, #0
	adds r0, #0x32
	adds r0, r0, r7
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x30
	adds r0, r0, r7
	ldrb r5, [r0]
	adds r3, #0xec
	mov sl, r3
	ldrb r3, [r3]
	adds r0, r5, r3
	cmp r1, r0
	bgt _0806FE28
	ldr r0, _0806FE24 @ =0x03002C30
	adds r1, r6, #0
	adds r1, #0xb
	lsls r1, r1, #6
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x33
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #3
	movs r2, #0
	strh r0, [r1, #4]
	mov r3, sl
	strb r2, [r3]
	mov r1, sb
	b _0806FF26
	.align 2, 0
_0806FE20: .4byte 0x0848604C
_0806FE24: .4byte 0x03002C30
_0806FE28:
	cmp r3, #1
	bhi _0806FF00
	adds r0, r4, #0
	adds r0, #0x33
	adds r0, r0, r7
	ldrb r2, [r0]
	adds r1, r2, r3
	adds r0, r4, #0
	adds r0, #0x31
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r1, r0
	bge _0806FE9C
	lsls r1, r6, #1
	adds r0, r3, #0
	adds r0, #0xe
	adds r4, r1, r0
	movs r1, #0xc4
	lsls r1, r1, #8
	ldr r2, _0806FE94 @ =0x00000403
	movs r0, #3
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl init_battle_sprite_entry_08048818
	ldr r0, _0806FE98 @ =0x03002C30
	lsls r2, r4, #6
	adds r2, r2, r0
	mov r3, sb
	ldrb r0, [r3]
	lsls r0, r0, #2
	add r0, r8
	adds r0, #0x30
	adds r0, r0, r7
	ldrb r0, [r0]
	mov r3, sl
	ldrb r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #3
	strh r0, [r2, #2]
	mov r1, sb
	ldrb r0, [r1]
	lsls r0, r0, #2
	add r0, r8
	adds r0, #0x31
	adds r0, r0, r7
	ldrb r0, [r0]
	ldrb r1, [r3]
	subs r0, r0, r1
	lsls r0, r0, #3
	subs r0, #4
	strh r0, [r2, #4]
	b _0806FF22
	.align 2, 0
_0806FE94: .4byte 0x00000403
_0806FE98: .4byte 0x03002C30
_0806FE9C:
	adds r0, r0, r3
	cmp r0, r2
	bge _0806FEFC
	lsls r1, r6, #1
	adds r0, r3, #0
	adds r0, #0xe
	adds r4, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #8
	ldr r2, _0806FEF4 @ =0x00000403
	movs r0, #3
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl init_battle_sprite_entry_08048818
	ldr r0, _0806FEF8 @ =0x03002C30
	lsls r2, r4, #6
	adds r2, r2, r0
	mov r3, sb
	ldrb r0, [r3]
	lsls r0, r0, #2
	add r0, r8
	adds r0, #0x30
	adds r0, r0, r7
	ldrb r0, [r0]
	mov r3, sl
	ldrb r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #3
	strh r0, [r2, #2]
	mov r1, sb
	ldrb r0, [r1]
	lsls r0, r0, #2
	add r0, r8
	adds r0, #0x31
	adds r0, r0, r7
	ldrb r0, [r0]
	ldrb r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0xc
	strh r0, [r2, #4]
	b _0806FF22
	.align 2, 0
_0806FEF4: .4byte 0x00000403
_0806FEF8: .4byte 0x03002C30
_0806FEFC:
	lsls r0, r2, #5
	b _0806FF0A
_0806FF00:
	adds r0, r4, #0
	adds r0, #0x33
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #5
_0806FF0A:
	adds r0, r5, r0
	adds r0, r3, r0
	ldr r1, _0806FF40 @ =0x040000D4
	add r2, sp, #4
	str r2, [r1]
	lsls r0, r0, #1
	ldr r3, _0806FF44 @ =0x0600F800
	adds r0, r0, r3
	str r0, [r1, #4]
	ldr r0, _0806FF48 @ =0x80000001
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0806FF22:
	ldr r1, _0806FF4C @ =0x03001800
	adds r1, #0xec
_0806FF26:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0
_0806FF2E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806FF40: .4byte 0x040000D4
_0806FF44: .4byte 0x0600F800
_0806FF48: .4byte 0x80000001
_0806FF4C: .4byte 0x03001800
	.syntax divided
