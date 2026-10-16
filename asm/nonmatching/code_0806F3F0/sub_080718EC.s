	.syntax unified

	thumb_func_start sub_080718EC
sub_080718EC: @ 0x080718EC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _08071958 @ =0x080AFF9C
	add r0, sp, #4
	movs r2, #0xc
	bl memcpy_optimized
	ldr r5, _0807195C @ =0x03002C30
	lsls r0, r6, #6
	adds r4, r0, r5
	adds r2, r4, #0
	adds r2, #0x21
	ldrb r0, [r2]
	cmp r0, #0xb
	bhi _080719A8
	ldrh r1, [r4, #0x1a]
	add r0, sp
	adds r0, #4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _080719E0
	ldrh r0, [r4, #2]
	subs r0, #1
	strh r0, [r4, #2]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _080719E0
	adds r0, r4, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _080719E0
	cmp r6, #0
	bne _08071964
	movs r1, #0xcc
	lsls r1, r1, #8
	ldr r2, _08071960 @ =0x0000050E
	movs r0, #3
	str r0, [sp]
	movs r0, #1
	movs r3, #4
	bl init_battle_sprite_entry_08048818
	movs r4, #1
	b _08071978
	.align 2, 0
_08071958: .4byte 0x080AFF9C
_0807195C: .4byte 0x03002C30
_08071960: .4byte 0x0000050E
_08071964:
	adds r4, r6, #1
	movs r1, #0xc8
	lsls r1, r1, #8
	ldr r2, _080719A0 @ =0x0000050E
	movs r0, #3
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #4
	bl init_battle_sprite_entry_08048818
_08071978:
	ldr r2, _080719A4 @ =0x03002C30
	lsls r1, r4, #6
	adds r1, r1, r2
	lsls r0, r6, #6
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
	movs r0, #3
	movs r2, #0
	bl sub_08071C40
	b _080719E0
	.align 2, 0
_080719A0: .4byte 0x0000050E
_080719A4: .4byte 0x03002C30
_080719A8:
	cmp r6, #0
	bne _080719CA
	ldrh r2, [r5]
	ldr r1, _080719DC @ =0x0000F3FF
	adds r0, r1, #0
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #4
	adds r3, r2, #0
	orrs r0, r3
	strh r0, [r5]
	adds r2, r5, #0
	adds r2, #0x40
	ldrh r0, [r2]
	ands r1, r0
	orrs r1, r3
	strh r1, [r2]
_080719CA:
	adds r1, r4, #0
	adds r1, #0x22
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080719D8
	movs r0, #0
	strb r0, [r1]
_080719D8:
	movs r0, #0
	b _080719E2
	.align 2, 0
_080719DC: .4byte 0x0000F3FF
_080719E0:
	movs r0, #1
_080719E2:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
