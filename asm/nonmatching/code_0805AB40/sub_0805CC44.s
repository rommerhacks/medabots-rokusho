	.syntax unified

	thumb_func_start sub_0805CC44
sub_0805CC44: @ 0x0805CC44
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r4, _0805CD34 @ =0x03006F74
	ldr r0, [r4]
	movs r5, #0
	strb r5, [r0, #6]
	ldr r0, [r4]
	strb r5, [r0, #0xc]
	ldr r0, [r4]
	strb r5, [r0, #0x11]
	bl unpack_item_inventory_to_buffer
	bl update_battle_medapart_icons
	ldr r0, [r4]
	ldrb r0, [r0, #0x10]
	cmp r0, #0
	beq _0805CC80
	ldr r0, _0805CD38 @ =0x03002C30
	movs r1, #0xa6
	lsls r1, r1, #5
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
	bl calc_fade_sprite_position
_0805CC80:
	ldr r4, [r4]
	ldrb r0, [r4, #0x10]
	subs r0, #1
	movs r1, #5
	bl sub_0807CBBC
	cmp r0, #0
	beq _0805CCB0
	ldr r2, _0805CD38 @ =0x03002C30
	movs r6, #0xa2
	lsls r6, r6, #5
	adds r3, r2, r6
	ldrh r0, [r3]
	movs r6, #0x80
	lsls r6, r6, #7
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xa4
	lsls r0, r0, #5
	adds r2, r2, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
_0805CCB0:
	strb r5, [r4, #0x12]
	ldr r0, _0805CD3C @ =0x0850DCF8
	ldr r4, _0805CD40 @ =0x0202F800
	adds r1, r4, #0
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _0805CD44 @ =0x084E2E58
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0805CD48 @ =0x080AF7C0
	ldr r1, _0805CD4C @ =0x0202F9C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0805CD50 @ =0x0878AE78
	ldr r1, _0805CD54 @ =0x0202FA00
	movs r2, #0x80
	bl CpuFastSet
	str r5, [sp]
	ldr r1, _0805CD58 @ =0x050001A0
	ldr r2, _0805CD5C @ =0x01000008
	mov r0, sp
	bl CpuFastSet
	ldr r0, _0805CD60 @ =0x03000440
	adds r0, #0x84
	strb r5, [r0]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r6, #0x80
	lsls r6, r6, #3
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r6, #0x80
	lsls r6, r6, #5
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0805CD64 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805CD34: .4byte 0x03006F74
_0805CD38: .4byte 0x03002C30
_0805CD3C: .4byte 0x0850DCF8
_0805CD40: .4byte 0x0202F800
_0805CD44: .4byte 0x084E2E58
_0805CD48: .4byte 0x080AF7C0
_0805CD4C: .4byte 0x0202F9C0
_0805CD50: .4byte 0x0878AE78
_0805CD54: .4byte 0x0202FA00
_0805CD58: .4byte 0x050001A0
_0805CD5C: .4byte 0x01000008
_0805CD60: .4byte 0x03000440
_0805CD64: .4byte 0x0300137C
	.syntax divided
