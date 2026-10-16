	.syntax unified

	thumb_func_start load_npc_sprite_data
load_npc_sprite_data: @ 0x0800F6E4
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0xa
	movs r1, #0xf
	bl clear_sprite_table_mask
	ldr r4, _0800F734 @ =0x03000440
	adds r2, r4, #0
	adds r2, #0xef
	ldrb r0, [r2]
	cmp r0, #0x63
	bhi _0800F73C
	ldr r1, _0800F738 @ =0x083B6EC8
	adds r0, r4, #0
	adds r0, #0xf0
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #1
	movs r3, #9
	bl render_text_sprites_08040DB8
	b _0800F76E
	.align 2, 0
_0800F734: .4byte 0x03000440
_0800F738: .4byte 0x083B6EC8
_0800F73C:
	ldr r1, _0800F778 @ =0x083BE97C
	ldrb r0, [r2]
	subs r0, #0x64
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #1
	movs r3, #9
	bl render_text_sprites_08040DB8
_0800F76E:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F778: .4byte 0x083BE97C
	.syntax divided
