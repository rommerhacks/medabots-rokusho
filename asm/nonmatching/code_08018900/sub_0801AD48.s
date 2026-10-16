	.syntax unified

	thumb_func_start sub_0801AD48
sub_0801AD48: @ 0x0801AD48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r0, #0x78
	movs r1, #8
	bl clear_battle_sprite_slot
	movs r4, #0
	ldr r0, _0801ADB4 @ =0x03002C30
	movs r5, #0
	ldr r1, _0801ADB8 @ =0x0000C404
	mov r8, r1
	ldr r7, _0801ADBC @ =0x0000EFFF
	mov ip, r7
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r2, r0, r1
	ldr r7, _0801ADC0 @ =0x00001E21
	adds r3, r0, r7
_0801AD70:
	mov r0, r8
	strh r0, [r2]
	strb r5, [r2, #0x1c]
	movs r0, #0x78
	strh r0, [r2, #4]
	movs r0, #9
	strb r0, [r2, #0xa]
	movs r0, #0x80
	strb r0, [r2, #0xb]
	movs r0, #3
	adds r1, r4, #0
	ands r1, r0
	ldr r7, _0801ADC4 @ =0x00000616
	adds r0, r1, r7
	strh r0, [r2, #6]
	strb r5, [r3, #3]
	movs r0, #7
	subs r0, r0, r4
	strb r0, [r3, #5]
	strb r5, [r3, #7]
	lsls r0, r4, #1
	strb r0, [r3, #6]
	strb r5, [r3]
	strb r1, [r3, #1]
	cmp r6, #2
	bhi _0801ADC8
	ldrh r0, [r2]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x5c
	b _0801ADD2
	.align 2, 0
_0801ADB4: .4byte 0x03002C30
_0801ADB8: .4byte 0x0000C404
_0801ADBC: .4byte 0x0000EFFF
_0801ADC0: .4byte 0x00001E21
_0801ADC4: .4byte 0x00000616
_0801ADC8:
	ldrh r0, [r2]
	mov r1, ip
	ands r1, r0
	strh r1, [r2]
	movs r0, #0x94
_0801ADD2:
	strh r0, [r2, #2]
	adds r2, #0x40
	adds r3, #0x40
	adds r4, #1
	cmp r4, #7
	bls _0801AD70
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
