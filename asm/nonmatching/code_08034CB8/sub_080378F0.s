	.syntax unified

	thumb_func_start sub_080378F0
sub_080378F0: @ 0x080378F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	ldr r0, _0803790C @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #5
	bhi _08037932
	lsls r0, r0, #2
	ldr r1, _08037910 @ =_08037914
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803790C: .4byte 0x03001800
_08037910: .4byte _08037914
_08037914: @ jump table
	.4byte _0803792C @ case 0
	.4byte _08037930 @ case 1
	.4byte _08037930 @ case 2
	.4byte _08037930 @ case 3
	.4byte _08037930 @ case 4
	.4byte _08037930 @ case 5
_0803792C:
	movs r1, #0xf
	b _08037932
_08037930:
	movs r1, #7
_08037932:
	ldr r5, _080379C4 @ =0x03002C30
	lsls r0, r2, #6
	adds r6, r0, r5
	adds r0, r6, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08037946
	b _08037A80
_08037946:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x14
	bl find_next_free_sprite_slot
	adds r7, r0, #0
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	lsls r4, r7, #6
	adds r4, r4, r5
	movs r1, #0
	ldr r0, _080379C8 @ =0x0000C604
	strh r0, [r4]
	strb r1, [r4, #0x1c]
	bl rng_next_080424B8
	ldr r1, _080379CC @ =0x083AF520
	mov r8, r1
	movs r5, #3
	ands r0, r5
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	ldr r2, _080379D0 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r4, #2]
	bl rng_next_080424B8
	ands r0, r5
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldrh r6, [r6, #4]
	adds r0, r0, r6
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #4]
	movs r0, #0x40
	strb r0, [r4, #8]
	strb r0, [r4, #9]
	movs r0, #6
	strb r0, [r4, #0xa]
	movs r0, #0xe0
	strb r0, [r4, #0xb]
	ldr r0, _080379D4 @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #5
	bhi _08037A80
	lsls r0, r0, #2
	ldr r1, _080379D8 @ =_080379DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080379C4: .4byte 0x03002C30
_080379C8: .4byte 0x0000C604
_080379CC: .4byte 0x083AF520
_080379D0: .4byte 0x000001FF
_080379D4: .4byte 0x03001800
_080379D8: .4byte _080379DC
_080379DC: @ jump table
	.4byte _080379F4 @ case 0
	.4byte _08037A18 @ case 1
	.4byte _08037A30 @ case 2
	.4byte _08037A48 @ case 3
	.4byte _08037A70 @ case 4
	.4byte _08037A80 @ case 5
_080379F4:
	bl rng_next_080424B8
	ldr r1, _08037A10 @ =0x03002C30
	lsls r2, r7, #6
	adds r2, r2, r1
	movs r1, #3
	ands r0, r1
	ldr r1, _08037A14 @ =0x00006B01
	adds r0, r0, r1
	strh r0, [r2, #6]
	adds r2, #0x29
	movs r0, #0x10
	strb r0, [r2]
	b _08037A80
	.align 2, 0
_08037A10: .4byte 0x03002C30
_08037A14: .4byte 0x00006B01
_08037A18:
	ldr r1, _08037A28 @ =0x03002C30
	lsls r0, r7, #6
	adds r0, r0, r1
	ldr r1, _08037A2C @ =0x00006C01
	strh r1, [r0, #6]
	adds r0, #0x29
	movs r1, #0x14
	b _08037A7E
	.align 2, 0
_08037A28: .4byte 0x03002C30
_08037A2C: .4byte 0x00006C01
_08037A30:
	ldr r1, _08037A40 @ =0x03002C30
	lsls r0, r7, #6
	adds r0, r0, r1
	ldr r1, _08037A44 @ =0x00006D01
	strh r1, [r0, #6]
	adds r0, #0x29
	movs r1, #0x18
	b _08037A7E
	.align 2, 0
_08037A40: .4byte 0x03002C30
_08037A44: .4byte 0x00006D01
_08037A48:
	ldr r0, _08037A68 @ =0x083B5F80
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r7, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	ldr r1, _08037A6C @ =0x03002C30
	lsls r0, r7, #6
	adds r0, r0, r1
	adds r0, #0x29
	movs r1, #0x1c
	b _08037A7E
	.align 2, 0
_08037A68: .4byte 0x083B5F80
_08037A6C: .4byte 0x03002C30
_08037A70:
	ldr r1, _08037A8C @ =0x03002C30
	lsls r0, r7, #6
	adds r0, r0, r1
	ldr r1, _08037A90 @ =0x00007001
	strh r1, [r0, #6]
	adds r0, #0x29
	movs r1, #0x20
_08037A7E:
	strb r1, [r0]
_08037A80:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037A8C: .4byte 0x03002C30
_08037A90: .4byte 0x00007001
	.syntax divided
