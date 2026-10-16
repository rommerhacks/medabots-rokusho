	.syntax unified

	thumb_func_start sub_0800A594
	.global sub_0800A594
sub_0800A594: @ 0x0800A594
	push {r4, r5, r6, lr}
	sub sp, #0x10
	movs r0, #0x5a
	movs r1, #0xf
	bl clear_sprite_table_mask
	ldr r5, _0800A640 @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x46
	ldrb r6, [r0]
	cmp r6, #0
	beq _0800A660
	cmp r6, #1
	bne _0800A5B2
	b _0800A720
_0800A5B2:
	ldr r0, _0800A644 @ =0x03000BE0
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #0x3b
	bhi _0800A5C6
	b _0800A808
_0800A5C6:
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _0800A648 @ =0x083B7E0C
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xee
	movs r2, #3
	bl memcpy_bytes_08041D04
	adds r0, r5, #0
	adds r0, #0xf0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0800A64C @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _0800A650 @ =0x083B6EC8
	ldr r2, _0800A654 @ =0x0000010F
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, r5, #0
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xb
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x5a
	movs r2, #0x13
	movs r3, #7
	bl render_text_sprites_08040DB8
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _0800A658 @ =0x0400000A
	ldrh r1, [r1]
	str r1, [sp]
	ldr r1, _0800A65C @ =0x0000D334
	str r1, [sp, #4]
	b _0800A7F4
	.align 2, 0
_0800A640: .4byte 0x03000440
_0800A644: .4byte 0x03000BE0
_0800A648: .4byte 0x083B7E0C
_0800A64C: .4byte 0x083B7CD4
_0800A650: .4byte 0x083B6EC8
_0800A654: .4byte 0x0000010F
_0800A658: .4byte 0x0400000A
_0800A65C: .4byte 0x0000D334
_0800A660:
	ldr r0, _0800A6E8 @ =0x03000BE0
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #9
	bls _0800A704
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _0800A6EC @ =0x083B7E0C
	adds r0, r0, r1
	adds r4, r5, #0
	adds r4, #0xee
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0800A6F0 @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _0800A6F4 @ =0x083B6EC8
	ldr r2, _0800A6F8 @ =0x0000010F
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	subs r4, #0x50
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xb
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x5a
	movs r2, #0x13
	movs r3, #7
	bl render_text_sprites_08040DB8
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _0800A6FC @ =0x0400000A
	ldrh r1, [r1]
	str r1, [sp]
	ldr r1, _0800A700 @ =0x0000D334
	str r1, [sp, #4]
	b _0800A7F4
	.align 2, 0
_0800A6E8: .4byte 0x03000BE0
_0800A6EC: .4byte 0x083B7E0C
_0800A6F0: .4byte 0x083B7CD4
_0800A6F4: .4byte 0x083B6EC8
_0800A6F8: .4byte 0x0000010F
_0800A6FC: .4byte 0x0400000A
_0800A700: .4byte 0x0000D334
_0800A704:
	adds r4, r5, #0
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xd
	bl sub_08042678
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xb
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	b _0800A7DC
_0800A720:
	ldr r0, _0800A7A8 @ =0x03000BE0
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r0, [r1, #5]
	cmp r0, #0x1d
	bls _0800A7C4
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _0800A7AC @ =0x083B7E0C
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xee
	movs r2, #3
	bl memcpy_bytes_08041D04
	adds r0, r5, #0
	adds r0, #0xef
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0800A7B0 @ =0x083B7CD4
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _0800A7B4 @ =0x083B6EC8
	ldr r2, _0800A7B8 @ =0x0000010F
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, r5, #0
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xb
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x5a
	movs r2, #0x13
	movs r3, #7
	bl render_text_sprites_08040DB8
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _0800A7BC @ =0x0400000A
	ldrh r1, [r1]
	str r1, [sp]
	ldr r1, _0800A7C0 @ =0x0000D334
	str r1, [sp, #4]
	b _0800A7F4
	.align 2, 0
_0800A7A8: .4byte 0x03000BE0
_0800A7AC: .4byte 0x083B7E0C
_0800A7B0: .4byte 0x083B7CD4
_0800A7B4: .4byte 0x083B6EC8
_0800A7B8: .4byte 0x0000010F
_0800A7BC: .4byte 0x0400000A
_0800A7C0: .4byte 0x0000D334
_0800A7C4:
	adds r4, r5, #0
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xd
	bl sub_08042678
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xb
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
_0800A7DC:
	adds r0, r4, #0
	movs r1, #0x5a
	movs r2, #0x13
	movs r3, #7
	bl render_text_sprites_08040DB8
	ldr r0, _0800A800 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800A804 @ =0x0000D334
	str r0, [sp, #4]
	movs r0, #0
_0800A7F4:
	movs r1, #0x19
	movs r2, #0xa
	movs r3, #2
	bl divide_by_100000_08042838
	b _0800A844
	.align 2, 0
_0800A800: .4byte 0x0400000A
_0800A804: .4byte 0x0000D334
_0800A808:
	adds r4, r5, #0
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xd
	bl sub_08042678
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xb
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x5a
	movs r2, #0x13
	movs r3, #7
	bl render_text_sprites_08040DB8
	ldr r0, _0800A84C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800A850 @ =0x0000D334
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0x19
	movs r2, #0xa
	movs r3, #2
	bl divide_by_100000_08042838
_0800A844:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800A84C: .4byte 0x0400000A
_0800A850: .4byte 0x0000D334
	.syntax divided
