	.syntax unified

	thumb_func_start sub_0800EE34
sub_0800EE34: @ 0x0800EE34
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	movs r6, #0
	ldr r0, _0800EE90 @ =0x03004C40
	mov sb, r0
	ldr r4, _0800EE94 @ =0x03000440
	movs r1, #0xf1
	adds r1, r1, r4
	mov r8, r1
	movs r5, #5
	ldr r7, _0800EE98 @ =0x0400000A
_0800EE50:
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r2, [r0]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r1, r4, #0
	adds r1, #0x3f
	ldrb r1, [r1]
	lsls r3, r1, #2
	lsls r1, r1, #3
	adds r0, r0, r1
	lsls r1, r6, #1
	adds r0, r0, r1
	add r0, sb
	ldrb r1, [r0]
	cmp r1, #0
	beq _0800EEBC
	adds r0, r3, r6
	adds r1, r2, #0
	adds r2, r4, #0
	adds r2, #0xee
	bl load_part_data
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800EEA0
	ldrh r0, [r7]
	str r0, [sp]
	ldr r0, _0800EE9C @ =0x0000A354
	b _0800EEA6
	.align 2, 0
_0800EE90: .4byte 0x03004C40
_0800EE94: .4byte 0x03000440
_0800EE98: .4byte 0x0400000A
_0800EE9C: .4byte 0x0000A354
_0800EEA0:
	ldrh r0, [r7]
	str r0, [sp]
	ldr r0, _0800EEB8 @ =0x0000A350
_0800EEA6:
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x1b
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
	b _0800EECE
	.align 2, 0
_0800EEB8: .4byte 0x0000A350
_0800EEBC:
	ldrh r0, [r7]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x1b
	adds r3, r5, #0
	bl vram_fill_tilemap_rect
_0800EECE:
	adds r5, #2
	adds r6, #1
	cmp r6, #3
	bls _0800EE50
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
