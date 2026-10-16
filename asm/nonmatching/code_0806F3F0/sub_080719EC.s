	.syntax unified

	thumb_func_start sub_080719EC
sub_080719EC: @ 0x080719EC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _08071A58 @ =0x080AFF9C
	add r0, sp, #4
	movs r2, #0xc
	bl memcpy_optimized
	ldr r6, _08071A5C @ =0x03002C30
	lsls r0, r5, #6
	adds r4, r0, r6
	adds r2, r4, #0
	adds r2, #0x21
	ldrb r0, [r2]
	cmp r0, #0xb
	bhi _08071AA8
	ldrh r1, [r4, #0x1a]
	add r0, sp
	adds r0, #4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _08071AE4
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _08071AE4
	adds r0, r4, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08071AE4
	cmp r5, #0xb
	bne _08071A64
	movs r1, #0xcc
	lsls r1, r1, #8
	ldr r2, _08071A60 @ =0x0000050E
	movs r0, #3
	str r0, [sp]
	movs r0, #0xc
	movs r3, #4
	bl init_battle_sprite_entry_08048818
	movs r4, #0xc
	b _08071A78
	.align 2, 0
_08071A58: .4byte 0x080AFF9C
_08071A5C: .4byte 0x03002C30
_08071A60: .4byte 0x0000050E
_08071A64:
	adds r4, r5, #1
	movs r1, #0xc8
	lsls r1, r1, #8
	ldr r2, _08071AA0 @ =0x0000050E
	movs r0, #3
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #4
	bl init_battle_sprite_entry_08048818
_08071A78:
	ldr r2, _08071AA4 @ =0x03002C30
	lsls r1, r4, #6
	adds r1, r1, r2
	lsls r0, r5, #6
	adds r0, r0, r2
	ldrh r2, [r0, #2]
	movs r3, #0
	strh r2, [r1, #2]
	strh r3, [r1, #4]
	ldrb r0, [r0, #0xb]
	subs r0, #1
	strb r0, [r1, #0xb]
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	movs r0, #4
	movs r2, #0
	bl sub_08071C40
	b _08071AE4
	.align 2, 0
_08071AA0: .4byte 0x0000050E
_08071AA4: .4byte 0x03002C30
_08071AA8:
	cmp r5, #0xb
	bne _08071ACC
	ldrh r2, [r4]
	ldr r1, _08071AE0 @ =0x0000F3FF
	adds r0, r1, #0
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #4
	adds r3, r2, #0
	orrs r0, r3
	strh r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrh r0, [r2]
	ands r1, r0
	orrs r1, r3
	strh r1, [r2]
_08071ACC:
	adds r2, r4, #0
	adds r2, #0x22
	ldrb r0, [r2]
	cmp r0, #0xff
	beq _08071ADA
	movs r0, #0
	strb r0, [r2]
_08071ADA:
	movs r0, #0
	b _08071AE6
	.align 2, 0
_08071AE0: .4byte 0x0000F3FF
_08071AE4:
	movs r0, #1
_08071AE6:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
