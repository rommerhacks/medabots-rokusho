	.syntax unified

	thumb_func_start sub_0800EC44
sub_0800EC44: @ 0x0800EC44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r0, #0xa
	movs r1, #0x3c
	bl clear_sprite_table_mask
	movs r4, #0
	ldr r0, _0800ECC4 @ =0x03004C40
	mov sl, r0
	ldr r0, _0800ECC8 @ =0x03000440
	mov sb, r0
	mov r7, sb
	adds r7, #0x9e
	movs r0, #5
	mov r8, r0
	movs r6, #0xa0
	lsls r6, r6, #0x14
	movs r5, #1
_0800EC70:
	mov r0, sb
	adds r0, #0x3e
	ldrb r2, [r0]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #4
	adds r0, #1
	ldrb r0, [r0]
	lsls r3, r0, #2
	lsls r0, r0, #3
	adds r1, r1, r0
	lsls r0, r4, #1
	adds r1, r1, r0
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800ECD0
	ldr r1, _0800ECCC @ =0x083BB9CC
	adds r0, r3, r4
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r7, #0
	movs r2, #0xf
	bl memcpy_bytes_08041D04
	lsrs r1, r6, #0x18
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	movs r2, #0xb
	mov r3, r8
	bl render_text_sprites_08040DB8
	b _0800ECF0
	.align 2, 0
_0800ECC4: .4byte 0x03004C40
_0800ECC8: .4byte 0x03000440
_0800ECCC: .4byte 0x083BB9CC
_0800ECD0:
	adds r0, r7, #0
	movs r1, #0xd
	bl fill_text_blank
	lsrs r1, r6, #0x18
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	movs r2, #0xb
	mov r3, r8
	bl render_text_sprites_08040DB8
_0800ECF0:
	movs r0, #2
	add r8, r0
	movs r0, #0xf0
	lsls r0, r0, #0x14
	adds r6, r6, r0
	adds r4, #1
	cmp r4, #3
	bls _0800EC70
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
