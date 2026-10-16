	.syntax unified

	thumb_func_start sub_08017268
	.global sub_08017268
sub_08017268: @ 0x08017268
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x14
	movs r1, #0x10
	bl clear_sprite_table_mask
	ldr r0, _0801728C @ =0x03001800
	adds r1, r0, #0
	adds r1, #0x82
	ldrb r1, [r1]
	cmp r1, #1
	beq _080172B0
	cmp r1, #1
	bgt _08017290
	cmp r1, #0
	beq _0801729A
	b _0801738C
	.align 2, 0
_0801728C: .4byte 0x03001800
_08017290:
	cmp r1, #2
	beq _080172EC
	cmp r1, #3
	beq _08017338
	b _0801738C
_0801729A:
	ldr r0, _080172A8 @ =0x083C4A10
	ldr r0, [r0, #0xc]
	ldr r1, _080172AC @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_08041D04
	b _0801738C
	.align 2, 0
_080172A8: .4byte 0x083C4A10
_080172AC: .4byte 0x030004DE
_080172B0:
	ldr r1, _080172DC @ =0x03000590
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r0, r1
	ldrb r0, [r1, #5]
	cmp r0, #9
	bls _08017328
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _080172E0 @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _080172E4 @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldr r1, _080172E8 @ =0x083B7338
	ldrb r0, [r4]
	b _08017360
	.align 2, 0
_080172DC: .4byte 0x03000590
_080172E0: .4byte 0x083B7E0C
_080172E4: .4byte 0x0300052E
_080172E8: .4byte 0x083B7338
_080172EC:
	ldr r1, _08017318 @ =0x03000590
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r0, r1
	ldrb r0, [r1, #5]
	cmp r0, #0x1d
	bls _08017328
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _0801731C @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _08017320 @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldr r1, _08017324 @ =0x083B7338
	ldrb r0, [r4, #1]
	b _08017360
	.align 2, 0
_08017318: .4byte 0x03000590
_0801731C: .4byte 0x083B7E0C
_08017320: .4byte 0x0300052E
_08017324: .4byte 0x083B7338
_08017328:
	ldr r0, _08017334 @ =0x030004DE
	movs r1, #0xd
	bl fill_text_blank
	b _0801738C
	.align 2, 0
_08017334: .4byte 0x030004DE
_08017338:
	ldr r1, _08017374 @ =0x03000590
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r0, r1
	ldrb r0, [r1, #5]
	cmp r0, #0x3b
	bls _08017384
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08017378 @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _0801737C @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldr r1, _08017380 @ =0x083B7338
	ldrb r0, [r4, #2]
_08017360:
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	subs r4, #0x50
	adds r1, r4, #0
	movs r2, #0x11
	bl memcpy_bytes_0803F63C
	b _0801738C
	.align 2, 0
_08017374: .4byte 0x03000590
_08017378: .4byte 0x083B7E0C
_0801737C: .4byte 0x0300052E
_08017380: .4byte 0x083B7338
_08017384:
	ldr r0, _080173B0 @ =0x030004DE
	movs r1, #0xd
	bl fill_text_blank
_0801738C:
	ldr r0, _080173B0 @ =0x030004DE
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #0x14
	movs r2, #0xa
	movs r3, #0x11
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080173B0: .4byte 0x030004DE
	.syntax divided
