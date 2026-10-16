	.syntax unified

	thumb_func_start setup_menu_tilemap_by_state
setup_menu_tilemap_by_state: @ 0x0800F8D8
	push {r4, lr}
	sub sp, #8
	ldr r0, _0800F8F0 @ =0x03000440
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #2
	bgt _0800F8F4
	cmp r0, #1
	bge _0800F960
	cmp r0, #0
	beq _0800F8FA
	b _0800FA5C
	.align 2, 0
_0800F8F0: .4byte 0x03000440
_0800F8F4:
	cmp r0, #3
	beq _0800F9E0
	b _0800FA5C
_0800F8FA:
	ldr r4, _0800F950 @ =0x0400000A
	ldrh r0, [r4]
	str r0, [sp]
	movs r0, #0xa6
	lsls r0, r0, #7
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #6
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800F954 @ =0x0000530C
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #7
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800F958 @ =0x00005318
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #8
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800F95C @ =0x00005324
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #9
	bl fill_tilemap_rect_08042698
	b _0800FA5C
	.align 2, 0
_0800F950: .4byte 0x0400000A
_0800F954: .4byte 0x0000530C
_0800F958: .4byte 0x00005318
_0800F95C: .4byte 0x00005324
_0800F960:
	ldr r4, _0800F9CC @ =0x0400000A
	ldrh r0, [r4]
	str r0, [sp]
	movs r0, #0xa6
	lsls r0, r0, #7
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #6
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800F9D0 @ =0x0000530C
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #7
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800F9D4 @ =0x00005318
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #8
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800F9D8 @ =0x00005330
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #9
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800F9DC @ =0x0000533C
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #0xa
	bl fill_tilemap_rect_08042698
	b _0800FA5C
	.align 2, 0
_0800F9CC: .4byte 0x0400000A
_0800F9D0: .4byte 0x0000530C
_0800F9D4: .4byte 0x00005318
_0800F9D8: .4byte 0x00005330
_0800F9DC: .4byte 0x0000533C
_0800F9E0:
	ldr r4, _0800FA64 @ =0x0400000A
	ldrh r0, [r4]
	str r0, [sp]
	movs r0, #0xa6
	lsls r0, r0, #7
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #6
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800FA68 @ =0x00005348
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #7
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800FA6C @ =0x00005354
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #8
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800FA70 @ =0x00005360
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #9
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800FA74 @ =0x0000536C
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #0xa
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0800FA78 @ =0x00005378
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0xe
	movs r3, #0xb
	bl fill_tilemap_rect_08042698
_0800FA5C:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800FA64: .4byte 0x0400000A
_0800FA68: .4byte 0x00005348
_0800FA6C: .4byte 0x00005354
_0800FA70: .4byte 0x00005360
_0800FA74: .4byte 0x0000536C
_0800FA78: .4byte 0x00005378
	.syntax divided
