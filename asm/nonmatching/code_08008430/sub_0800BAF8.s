	.syntax unified

	thumb_func_start sub_0800BAF8
sub_0800BAF8: @ 0x0800BAF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r2, _0800BB20 @ =0x0300058C
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	ldr r7, _0800BB24 @ =0x03000440
	cmp r0, #0
	beq _0800BB2C
	adds r3, r7, #0
	adds r3, #0x34
	ldrb r0, [r3]
	cmp r0, #0
	bne _0800BB28
	movs r0, #2
	b _0800BB2A
	.align 2, 0
_0800BB20: .4byte 0x0300058C
_0800BB24: .4byte 0x03000440
_0800BB28:
	subs r0, #1
_0800BB2A:
	strb r0, [r3]
_0800BB2C:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800BB48
	adds r1, r7, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #2
	bne _0800BB44
	movs r0, #0
	b _0800BB46
_0800BB44:
	adds r0, #1
_0800BB46:
	strb r0, [r1]
_0800BB48:
	adds r4, r7, #0
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r6, [r0]
	cmp r6, #0
	beq _0800BB74
	cmp r6, #1
	beq _0800BBF0
	ldr r0, _0800BB70 @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	bne _0800BB66
	b _0800BC90
_0800BB66:
	movs r0, #0x18
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800BCBA
	.align 2, 0
_0800BB70: .4byte 0x03001780
_0800BB74:
	ldr r0, _0800BB8C @ =0x03001780
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800BB90
	movs r0, #8
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800BBB8
	.align 2, 0
_0800BB8C: .4byte 0x03001780
_0800BB90:
	ldr r0, _0800BBE8 @ =0x083ACA64
	ldr r0, [r0]
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
_0800BBB8:
	ldr r0, _0800BBE8 @ =0x083ACA64
	mov sl, r0
	ldr r0, [r0, #4]
	ldr r4, _0800BBEC @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r1, #8
	mov sb, r1
	str r1, [sp]
	movs r2, #0xf
	mov r8, r2
	str r2, [sp, #4]
	movs r6, #1
	str r6, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #4
	b _0800BC5E
	.align 2, 0
_0800BBE8: .4byte 0x083ACA64
_0800BBEC: .4byte 0x030004DE
_0800BBF0:
	ldr r0, _0800BC08 @ =0x03001780
	ldr r5, [r0]
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800BC0C
	movs r0, #0x10
	movs r1, #8
	bl clear_battle_sprite_slot
	b _0800BC32
	.align 2, 0
_0800BC08: .4byte 0x03001780
_0800BC0C:
	ldr r0, _0800BC88 @ =0x083ACA64
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
_0800BC32:
	ldr r1, _0800BC88 @ =0x083ACA64
	mov sl, r1
	ldr r0, [r1]
	ldr r4, _0800BC8C @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r2, #8
	mov sb, r2
	str r2, [sp]
	movs r0, #0xf
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #1
	str r6, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #2
	movs r3, #2
_0800BC5E:
	bl render_text_sprites_08040DB8
	mov r1, sl
	ldr r0, [r1, #8]
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #2
	movs r3, #6
	bl render_text_sprites_08040DB8
	b _0800BD0E
	.align 2, 0
_0800BC88: .4byte 0x083ACA64
_0800BC8C: .4byte 0x030004DE
_0800BC90:
	ldr r0, _0800BDF0 @ =0x083ACA64
	ldr r0, [r0, #8]
	adds r4, r7, #0
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
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #2
	movs r3, #6
	bl render_text_sprites_08040DB8
_0800BCBA:
	ldr r1, _0800BDF0 @ =0x083ACA64
	mov sl, r1
	ldr r0, [r1, #4]
	ldr r4, _0800BDF4 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	movs r2, #8
	mov sb, r2
	str r2, [sp]
	movs r0, #0xf
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #1
	str r6, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #4
	bl render_text_sprites_08040DB8
	mov r1, sl
	ldr r0, [r1]
	adds r1, r4, #0
	movs r2, #8
	bl memcpy_bytes_0803F63C
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #2
	movs r3, #2
	bl render_text_sprites_08040DB8
_0800BD0E:
	ldr r2, _0800BDF8 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800BD2C
	ldr r0, _0800BDFC @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_0800BD2C:
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800BD48
	ldr r0, _0800BDFC @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x34
	adds r0, #0x35
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r1, [r0]
	subs r1, #1
	strb r1, [r0]
_0800BD48:
	movs r0, #0x20
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r4, _0800BDF4 @ =0x030004DE
	ldr r2, _0800BE00 @ =0x03000475
	ldrb r1, [r2]
	adds r0, r4, #0
	bl divide_by_100000_08041370
	movs r0, #3
	mov r8, r0
	str r0, [sp]
	movs r6, #0xf
	str r6, [sp, #4]
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
	movs r1, #0x68
	rsbs r1, r1, #0
	adds r1, r1, r4
	mov sl, r1
	ldrb r1, [r1]
	adds r0, r4, #0
	bl divide_by_100000_08041370
	mov r2, r8
	str r2, [sp]
	str r6, [sp, #4]
	str r7, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x23
	movs r2, #8
	movs r3, #4
	bl render_text_sprites_08040DB8
	movs r0, #0x26
	movs r1, #3
	bl clear_battle_sprite_slot
	movs r0, #0x67
	rsbs r0, r0, #0
	adds r0, r0, r4
	mov sb, r0
	ldrb r1, [r0]
	adds r0, r4, #0
	bl divide_by_100000_08041370
	mov r1, r8
	str r1, [sp]
	str r6, [sp, #4]
	str r7, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x26
	movs r2, #8
	movs r3, #6
	bl render_text_sprites_08040DB8
	ldr r0, _0800BE04 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800BE0C
	movs r0, #8
	movs r1, #0x21
	bl clear_battle_sprite_slot
	ldr r0, _0800BE08 @ =0x0300137C
	str r7, [r0]
	b _0800BE3C
	.align 2, 0
_0800BDF0: .4byte 0x083ACA64
_0800BDF4: .4byte 0x030004DE
_0800BDF8: .4byte 0x03001798
_0800BDFC: .4byte 0x03000440
_0800BE00: .4byte 0x03000475
_0800BE04: .4byte 0x0300058C
_0800BE08: .4byte 0x0300137C
_0800BE0C:
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0800BE3C
	ldr r1, _0800BE4C @ =0x040000D4
	ldr r0, _0800BE50 @ =0x02020800
	str r0, [r1]
	ldr r0, _0800BE54 @ =0x03002C30
	str r0, [r1, #4]
	ldr r0, _0800BE58 @ =0x84000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0800BE5C @ =0x0300178C
	ldr r2, _0800BE60 @ =0x03000475
	ldrb r0, [r2]
	str r0, [r1]
	ldr r1, _0800BE64 @ =0x03002B8C
	mov r2, sl
	ldrb r0, [r2]
	str r0, [r1]
	ldr r1, _0800BE68 @ =0x0300137C
	mov r2, sb
	ldrb r0, [r2]
	str r0, [r1]
_0800BE3C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BE4C: .4byte 0x040000D4
_0800BE50: .4byte 0x02020800
_0800BE54: .4byte 0x03002C30
_0800BE58: .4byte 0x84000400
_0800BE5C: .4byte 0x0300178C
_0800BE60: .4byte 0x03000475
_0800BE64: .4byte 0x03002B8C
_0800BE68: .4byte 0x0300137C
	.syntax divided
