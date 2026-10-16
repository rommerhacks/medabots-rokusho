	.syntax unified

	thumb_func_start update_battle_sprite_explosions
update_battle_sprite_explosions: @ 0x08067A70
	push {r4, r5, r6, r7, lr}
	movs r1, #0
	movs r7, #0
	movs r5, #0xff
_08067A78:
	ldr r2, _08067AC4 @ =0x03002C30
	adds r1, #1
	lsls r0, r1, #6
	adds r4, r0, r2
	ldrh r0, [r4, #0x1a]
	adds r6, r1, #0
	cmp r0, #0
	bne _08067ACC
	movs r1, #0x78
	strh r1, [r4, #2]
	movs r2, #0x28
	strh r2, [r4, #4]
	lsls r1, r1, #0x10
	ldr r0, [r4, #0xc]
	ands r0, r5
	orrs r0, r1
	str r0, [r4, #0xc]
	lsls r2, r2, #0x10
	ldr r0, [r4, #0x10]
	ands r0, r5
	orrs r0, r2
	str r0, [r4, #0x10]
	bl rng_next_080424B8
	strb r0, [r4, #0xc]
	bl rng_next_080424B8
	strb r0, [r4, #0x10]
	movs r0, #0x3f
	strh r0, [r4, #0x1a]
	strb r7, [r4, #8]
	strb r7, [r4, #9]
	ldrh r0, [r4]
	ldr r2, _08067AC8 @ =0x0000FFF7
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r4]
	b _08067B20
	.align 2, 0
_08067AC4: .4byte 0x03002C30
_08067AC8: .4byte 0x0000FFF7
_08067ACC:
	subs r0, #1
	movs r1, #0
	strh r0, [r4, #0x1a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08067AE2
	ldrh r0, [r4]
	movs r1, #8
	orrs r0, r1
	strh r0, [r4]
_08067AE2:
	ldr r3, [r4, #0xc]
	asrs r1, r3, #8
	movs r0, #0xc
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #8
	adds r2, r5, #0
	ands r2, r3
	orrs r2, r1
	str r2, [r4, #0xc]
	ldr r3, [r4, #0x10]
	asrs r1, r3, #8
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #8
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	str r0, [r4, #0x10]
	asrs r2, r2, #0x10
	strh r2, [r4, #2]
	asrs r0, r0, #0x10
	strh r0, [r4, #4]
	ldrb r1, [r4, #0x1a]
	movs r0, #0x40
	subs r0, r0, r1
	strb r0, [r4, #8]
	strb r0, [r4, #9]
_08067B20:
	adds r1, r6, #0
	cmp r1, #0xf
	ble _08067A78
	ldr r1, _08067B5C @ =0x04000050
	movs r2, #0xc4
	lsls r2, r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _08067B60 @ =0x04000052
	ldr r0, _08067B64 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x48
	ldrb r2, [r0]
	adds r1, r2, #0
	adds r1, #0xff
	strb r1, [r0]
	movs r0, #0xf
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r1, _08067B68 @ =0x04000054
	movs r0, #8
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067B5C: .4byte 0x04000050
_08067B60: .4byte 0x04000052
_08067B64: .4byte 0x03006F74
_08067B68: .4byte 0x04000054
	.syntax divided
