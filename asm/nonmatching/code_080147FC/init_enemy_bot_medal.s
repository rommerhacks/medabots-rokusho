	.syntax unified

	thumb_func_start init_enemy_bot_medal
init_enemy_bot_medal: @ 0x080150FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _080151D0 @ =0x03001800
	mov sb, r0
	lsls r2, r4, #1
	mov r8, r2
	add r8, r4
	mov r0, r8
	lsls r0, r0, #2
	mov r8, r0
	mov r3, r8
	add r3, sb
	ldrb r0, [r3, #8]
	lsls r0, r0, #4
	ldr r1, _080151D4 @ =0x083B6158
	adds r0, r0, r1
	ldr r5, _080151D8 @ =0x0300052E
	adds r1, r5, #0
	movs r2, #0x10
	str r3, [sp]
	bl memcpy_bytes_08041D04
	ldr r6, _080151DC @ =0x03000590
	adds r7, r4, #3
	lsls r2, r7, #8
	mov sl, r2
	adds r1, r2, r6
	movs r0, #0x80
	strb r0, [r1]
	ldrb r0, [r5]
	strb r0, [r1, #1]
	ldrb r0, [r5, #1]
	strb r0, [r1, #4]
	ldr r3, [sp]
	ldrb r0, [r3, #9]
	strb r0, [r1, #5]
	ldrb r0, [r5, #2]
	strb r0, [r1, #6]
	ldrb r0, [r5, #7]
	strb r0, [r1, #7]
	ldrb r0, [r3, #0xe]
	strb r0, [r1, #9]
	ldr r1, _080151E0 @ =0x083BA4D8
	ldrb r0, [r3, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r4, r4, #8
	ldr r2, _080151E4 @ =0x0000030A
	adds r1, r6, r2
	adds r4, r4, r1
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_08041D04
	movs r5, #0
	movs r0, #0xa
	add sb, r0
	mov r3, r8
	add r3, sb
	adds r6, #0x18
	mov r0, sl
	adds r2, r0, r6
	movs r6, #0xf
	adds r4, r7, #0
_0801518C:
	ldrb r0, [r3]
	lsrs r0, r0, #4
	strb r0, [r2]
	ldrb r1, [r3]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r2, #1]
	adds r3, #1
	adds r2, #2
	adds r5, #1
	cmp r5, #3
	bls _0801518C
	movs r5, #0
	ldr r6, _080151E8 @ =0x083AD200
	ldr r0, _080151DC @ =0x03000590
	lsls r1, r4, #8
	adds r3, r1, r0
	adds r0, #0x20
	adds r1, r1, r0
_080151B2:
	ldrb r0, [r3, #4]
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, r0, r6
	ldrb r2, [r0]
	ldrb r0, [r3, #5]
	lsrs r0, r0, #1
	cmp r0, #0
	beq _080151C6
	muls r2, r0, r2
_080151C6:
	cmp r2, #0
	bne _080151EC
	movs r2, #1
	b _080151F2
	.align 2, 0
_080151D0: .4byte 0x03001800
_080151D4: .4byte 0x083B6158
_080151D8: .4byte 0x0300052E
_080151DC: .4byte 0x03000590
_080151E0: .4byte 0x083BA4D8
_080151E4: .4byte 0x0000030A
_080151E8: .4byte 0x083AD200
_080151EC:
	cmp r2, #0x64
	bls _080151F2
	movs r2, #0x64
_080151F2:
	strb r2, [r1]
	adds r1, #1
	adds r5, #1
	cmp r5, #7
	bls _080151B2
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
