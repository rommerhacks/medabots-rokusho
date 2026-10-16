	.syntax unified

	thumb_func_start sub_0800CE90
sub_0800CE90: @ 0x0800CE90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _0800CED0 @ =0x0300058C
	ldr r0, [r0]
	lsls r1, r0, #0x19
	lsrs r1, r1, #0x1f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1f
	orrs r1, r0
	ldr r4, _0800CED4 @ =0x03000440
	cmp r1, #0
	beq _0800CEBC
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
_0800CEBC:
	adds r2, r4, #0
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r6, [r0]
	cmp r6, #0
	beq _0800CED8
	cmp r6, #1
	beq _0800CF54
	b _0800CFC0
	.align 2, 0
_0800CED0: .4byte 0x0300058C
_0800CED4: .4byte 0x03000440
_0800CED8:
	ldr r0, _0800CEF0 @ =0x03001780
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800CEF4
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800CF1E
	.align 2, 0
_0800CEF0: .4byte 0x03001780
_0800CEF4:
	ldr r0, _0800CF4C @ =0x083ACAF8
	ldr r0, [r0]
	adds r4, r2, #0
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #2
	movs r3, #2
	bl render_text_sprites_08040DB8
_0800CF1E:
	ldr r0, _0800CF4C @ =0x083ACAF8
	ldr r0, [r0, #4]
	ldr r4, _0800CF50 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #4
	bl render_text_sprites_08040DB8
	b _0800CFC0
	.align 2, 0
_0800CF4C: .4byte 0x083ACAF8
_0800CF50: .4byte 0x030004DE
_0800CF54:
	ldr r0, _0800CF6C @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800CF70
	movs r0, #0x10
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800CF96
	.align 2, 0
_0800CF6C: .4byte 0x03001780
_0800CF70:
	ldr r0, _0800CFE8 @ =0x083ACAF8
	ldr r0, [r0, #4]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #4
	bl render_text_sprites_08040DB8
_0800CF96:
	ldr r0, _0800CFE8 @ =0x083ACAF8
	ldr r0, [r0]
	ldr r4, _0800CFEC @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #2
	movs r3, #2
	bl render_text_sprites_08040DB8
_0800CFC0:
	ldr r2, _0800CFF0 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D00C
	ldr r0, _0800CFF4 @ =0x03000440
	adds r3, r0, #0
	adds r3, #0x34
	ldrb r4, [r3]
	cmp r4, #0
	bne _0800CFF8
	adds r0, #0x35
	ldrb r3, [r3]
	adds r3, r0, r3
	ldrb r0, [r3]
	cmp r0, #0x1d
	bne _0800D008
	strb r4, [r3]
	b _0800D00C
	.align 2, 0
_0800CFE8: .4byte 0x083ACAF8
_0800CFEC: .4byte 0x030004DE
_0800CFF0: .4byte 0x03001798
_0800CFF4: .4byte 0x03000440
_0800CFF8:
	adds r0, #0x35
	ldrb r3, [r3]
	adds r3, r0, r3
	ldrb r0, [r3]
	cmp r0, #4
	bne _0800D008
	movs r0, #0
	b _0800D00A
_0800D008:
	adds r0, #1
_0800D00A:
	strb r0, [r3]
_0800D00C:
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D04E
	ldr r2, _0800D034 @ =0x03000440
	adds r1, r2, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D038
	adds r0, r2, #0
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D04A
	movs r0, #0x1d
	b _0800D04C
	.align 2, 0
_0800D034: .4byte 0x03000440
_0800D038:
	adds r0, r2, #0
	adds r0, #0x35
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D04A
	movs r0, #4
	b _0800D04C
_0800D04A:
	subs r0, #1
_0800D04C:
	strb r0, [r1]
_0800D04E:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r4, _0800D0D8 @ =0x030004DE
	movs r0, #0x69
	rsbs r0, r0, #0
	adds r0, r0, r4
	mov sl, r0
	ldrb r1, [r0]
	adds r0, r4, #0
	bl divide_by_100000_08041370
	movs r6, #3
	str r6, [sp]
	movs r1, #0xf
	mov r8, r1
	str r1, [sp, #4]
	movs r7, #1
	str r7, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x20
	movs r2, #8
	movs r3, #2
	bl render_text_sprites_08040DB8
	movs r0, #0x23
	movs r1, #3
	bl clear_battle_sprite_slot
	movs r3, #0x68
	rsbs r3, r3, #0
	adds r3, r3, r4
	mov sb, r3
	ldrb r1, [r3]
	adds r0, r4, #0
	bl divide_by_100000_08041370
	str r6, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x23
	movs r2, #8
	movs r3, #4
	bl render_text_sprites_08040DB8
	ldr r0, _0800D0DC @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D0E4
	movs r0, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800D0E0 @ =0x0300137C
	str r7, [r0]
	b _0800D138
	.align 2, 0
_0800D0D8: .4byte 0x030004DE
_0800D0DC: .4byte 0x0300058C
_0800D0E0: .4byte 0x0300137C
_0800D0E4:
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0800D138
	ldr r1, _0800D148 @ =0x040000D4
	ldr r0, _0800D14C @ =0x084E2E98
	str r0, [r1]
	ldr r0, _0800D150 @ =0x050003E0
	str r0, [r1, #4]
	ldr r0, _0800D154 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0800D158 @ =0x083AC494
	mov r3, sl
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	mov r1, sb
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r1, _0800D15C @ =0x06010000
	bl lz_decompress_dispatch
	ldr r1, _0800D160 @ =0x03002C30
	movs r2, #0
	ldr r0, _0800D164 @ =0x0000C004
	strh r0, [r1]
	movs r0, #0x40
	strh r0, [r1, #2]
	movs r0, #0x50
	strh r0, [r1, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1, #6]
	mov r3, r8
	strb r3, [r1, #0xa]
	strb r2, [r1, #0x1c]
	movs r0, #0xc0
	strb r0, [r1, #0xb]
_0800D138:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D148: .4byte 0x040000D4
_0800D14C: .4byte 0x084E2E98
_0800D150: .4byte 0x050003E0
_0800D154: .4byte 0x84000008
_0800D158: .4byte 0x083AC494
_0800D15C: .4byte 0x06010000
_0800D160: .4byte 0x03002C30
_0800D164: .4byte 0x0000C004
	.syntax divided
