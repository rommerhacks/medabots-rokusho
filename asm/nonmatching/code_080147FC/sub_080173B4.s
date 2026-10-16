	.syntax unified

	thumb_func_start sub_080173B4
	.global sub_080173B4
sub_080173B4: @ 0x080173B4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r5, #0
	movs r7, #0
	movs r0, #0x24
	movs r1, #0xd
	bl clear_sprite_table_mask
	ldr r2, _080173DC @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x82
	ldrb r0, [r0]
	cmp r0, #1
	beq _080173FC
	cmp r0, #1
	bgt _080173E0
	cmp r0, #0
	beq _080173EA
	b _0801756E
	.align 2, 0
_080173DC: .4byte 0x03001800
_080173E0:
	cmp r0, #2
	beq _08017460
	cmp r0, #3
	beq _080174C4
	b _0801756E
_080173EA:
	ldr r0, _080173F8 @ =0x030004DE
	movs r1, #0xd
	bl sub_08042678
	movs r7, #1
	b _0801756E
	.align 2, 0
_080173F8: .4byte 0x030004DE
_080173FC:
	ldr r1, _0801743C @ =0x03000590
	adds r0, r2, #0
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r0, r1
	ldrb r0, [r1, #5]
	cmp r0, #9
	bhi _08017410
	b _08017560
_08017410:
	adds r0, r2, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	bne _08017454
	adds r0, r1, #0
	adds r0, #0xc1
	ldrb r0, [r0]
	cmp r0, #0x50
	bne _08017448
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08017440 @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _08017444 @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r1, [r4]
	b _08017500
	.align 2, 0
_0801743C: .4byte 0x03000590
_08017440: .4byte 0x083B7E0C
_08017444: .4byte 0x0300052E
_08017448:
	ldr r0, _08017450 @ =0x083C4A10
	ldr r0, [r0, #0x10]
	b _08017564
	.align 2, 0
_08017450: .4byte 0x083C4A10
_08017454:
	ldr r0, _0801745C @ =0x083C4A10
	ldr r0, [r0, #4]
	b _08017564
	.align 2, 0
_0801745C: .4byte 0x083C4A10
_08017460:
	ldr r1, _080174A0 @ =0x03000590
	adds r0, r2, #0
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r0, r1
	ldrb r0, [r1, #5]
	cmp r0, #0x1d
	bls _08017560
	adds r0, r2, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	bne _080174B8
	adds r0, r1, #0
	adds r0, #0xc1
	ldrb r0, [r0]
	cmp r0, #0x50
	bne _080174AC
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _080174A4 @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _080174A8 @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r1, [r4, #1]
	b _08017500
	.align 2, 0
_080174A0: .4byte 0x03000590
_080174A4: .4byte 0x083B7E0C
_080174A8: .4byte 0x0300052E
_080174AC:
	ldr r0, _080174B4 @ =0x083C4A10
	ldr r0, [r0, #0x10]
	b _08017564
	.align 2, 0
_080174B4: .4byte 0x083C4A10
_080174B8:
	ldr r0, _080174C0 @ =0x083C4A10
	ldr r0, [r0, #4]
	b _08017564
	.align 2, 0
_080174C0: .4byte 0x083C4A10
_080174C4:
	ldr r1, _08017534 @ =0x03000590
	adds r0, r2, #0
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r0, r1
	ldrb r0, [r1, #5]
	cmp r0, #0x3b
	bls _08017560
	adds r0, r2, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	bne _08017554
	adds r0, r1, #0
	adds r0, #0xc1
	ldrb r0, [r0]
	cmp r0, #0x50
	bne _08017548
	ldrb r1, [r1, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08017538 @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _0801753C @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r1, [r4, #2]
_08017500:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08017540 @ =0x083B7CD4
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x20
	movs r2, #6
	bl memcpy_bytes_08041D04
	ldr r1, _08017544 @ =0x083B6EC8
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	subs r4, #0x50
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	movs r0, #0
	bl sub_08017734
	b _0801756E
	.align 2, 0
_08017534: .4byte 0x03000590
_08017538: .4byte 0x083B7E0C
_0801753C: .4byte 0x0300052E
_08017540: .4byte 0x083B7CD4
_08017544: .4byte 0x083B6EC8
_08017548:
	ldr r0, _08017550 @ =0x083C4A10
	ldr r0, [r0, #0x10]
	b _08017564
	.align 2, 0
_08017550: .4byte 0x083C4A10
_08017554:
	ldr r0, _0801755C @ =0x083C4A10
	ldr r0, [r0, #4]
	b _08017564
	.align 2, 0
_0801755C: .4byte 0x083C4A10
_08017560:
	ldr r0, _080175AC @ =0x083C4A10
	ldr r0, [r0, #0x14]
_08017564:
	ldr r1, _080175B0 @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_08041D04
	movs r5, #1
_0801756E:
	cmp r5, #1
	beq _08017576
	cmp r7, #1
	bne _0801757C
_08017576:
	movs r0, #1
	bl sub_08017734
_0801757C:
	cmp r6, #0
	beq _080175D8
	cmp r5, #0
	beq _080175B8
	ldr r3, _080175B4 @ =0x03000440
	adds r0, r3, #0
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080175F0
	adds r0, r3, #0
	adds r0, #0x9e
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xe
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	b _080175C6
	.align 2, 0
_080175AC: .4byte 0x083C4A10
_080175B0: .4byte 0x030004DE
_080175B4: .4byte 0x03000440
_080175B8:
	ldr r0, _080175D4 @ =0x030004DE
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xe
	str r1, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
_080175C6:
	movs r1, #0x24
	movs r2, #0x13
	movs r3, #0xe
	bl render_text_sprites_08040DB8
	b _080175F0
	.align 2, 0
_080175D4: .4byte 0x030004DE
_080175D8:
	ldr r0, _080175F8 @ =0x030004DE
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xe
	str r1, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r1, #0x24
	movs r2, #0x13
	movs r3, #0xe
	bl render_text_sprites_08040DB8
_080175F0:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080175F8: .4byte 0x030004DE
	.syntax divided
