	.syntax unified

	thumb_func_start sub_08031538
sub_08031538: @ 0x08031538
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _08031594 @ =0x084D6BFC
	ldr r1, _08031598 @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r5, _0803159C @ =0x0300052E
	ldr r4, _080315A0 @ =0x03001800
	ldr r1, _080315A4 @ =0x00000167
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	movs r2, #2
	bl set_display_digit_type
	adds r4, #0x87
	ldrb r1, [r4]
	ldr r2, _080315A8 @ =0x03002C30
	lsls r0, r1, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r0, r0, r3
	adds r0, r0, r2
	movs r2, #2
	ldrsh r3, [r0, r2]
	adds r3, #0x18
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0x23
	bl battle_setup_text_sprites_0801A4F4
	subs r5, #0x6a
	movs r0, #0
	strb r0, [r5]
	ldr r1, _080315AC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031594: .4byte 0x084D6BFC
_08031598: .4byte 0x06017E00
_0803159C: .4byte 0x0300052E
_080315A0: .4byte 0x03001800
_080315A4: .4byte 0x00000167
_080315A8: .4byte 0x03002C30
_080315AC: .4byte 0x0300137C
	.syntax divided
