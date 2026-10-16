	.syntax unified

	thumb_func_start update_battle_sprite_visibility
	.global update_battle_sprite_visibility
update_battle_sprite_visibility: @ 0x08009AF8
	push {r4, r5, r6, lr}
	ldr r4, _08009B84 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08009BA8
	movs r6, #0x7f
	ands r6, r1
	adds r0, r6, #0
	movs r1, #6
	bl sub_0807CD58
	adds r1, r4, #0
	adds r1, #0x3f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bne _08009B98
	ldr r0, _08009B88 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08009BA8
	ldr r5, _08009B8C @ =0x03002C30
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r4, #0
	ldr r0, _08009B90 @ =0x0000C804
	strh r0, [r1]
	movs r2, #0xa1
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0x19
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #6
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	adds r0, #0x2a
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0xa3
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _08009B94 @ =0x00000307
	strh r0, [r1]
	adds r2, #6
	adds r1, r5, r2
	movs r0, #0xe
	strb r0, [r1]
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r4, [r0]
	adds r2, #1
	adds r1, r5, r2
	movs r0, #0x40
	strb r0, [r1]
	b _08009BB8
	.align 2, 0
_08009B84: .4byte 0x03000440
_08009B88: .4byte 0x03001780
_08009B8C: .4byte 0x03002C30
_08009B90: .4byte 0x0000C804
_08009B94: .4byte 0x00000307
_08009B98:
	ldr r0, _08009BA4 @ =0x03002C30
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r0, r2
	b _08009BB0
	.align 2, 0
_08009BA4: .4byte 0x03002C30
_08009BA8:
	ldr r0, _08009BC0 @ =0x03002C30
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r0, r1
_08009BB0:
	ldrh r2, [r0]
	ldr r1, _08009BC4 @ =0x0000BFFF
	ands r1, r2
	strh r1, [r0]
_08009BB8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08009BC0: .4byte 0x03002C30
_08009BC4: .4byte 0x0000BFFF
	.syntax divided
