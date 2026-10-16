	.syntax unified

	thumb_func_start sub_0803EE10
sub_0803EE10: @ 0x0803EE10
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0803EE94 @ =0x03000440
	adds r0, #0x9c
	ldrb r0, [r0]
	movs r1, #0
	mov sb, r1
	cmp r0, #1
	bne _0803EE2C
	movs r5, #3
	mov sb, r5
_0803EE2C:
	ldr r4, _0803EE98 @ =0x083AFCF8
	bl rng_next_080424B8
	movs r1, #0xf
	ands r1, r0
	adds r1, r1, r4
	ldrb r3, [r1]
	movs r7, #0
	ldr r0, _0803EE9C @ =0x03000590
	mov ip, r0
	ldr r1, _0803EEA0 @ =0x030019A4
	mov r8, r1
	lsls r2, r3, #8
	mov r5, sb
	lsls r1, r5, #8
	adds r0, #0x47
	adds r0, r1, r0
	adds r4, r2, r0
	mov r0, ip
	adds r0, #0xba
	adds r0, r1, r0
	adds r2, r2, r0
	movs r0, #0xa
	rsbs r0, r0, #0
	add r0, r8
	mov sl, r0
	movs r6, #0x80
	lsls r6, r6, #1
_0803EE64:
	mov r5, sb
	adds r0, r5, r3
	lsls r5, r0, #8
	ldrb r0, [r2]
	cmp r0, #0
	beq _0803EEAC
	ldrb r0, [r4]
	mov r1, r8
	strb r0, [r1]
	ldr r1, _0803EEA4 @ =0x030019A2
	ldrb r0, [r1]
	add r0, sl
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r5
	add r0, ip
	adds r0, #0x5f
	ldrb r0, [r0]
	ldr r5, _0803EEA8 @ =0x030019A5
	strb r0, [r5]
	b _0803EECA
	.align 2, 0
_0803EE94: .4byte 0x03000440
_0803EE98: .4byte 0x083AFCF8
_0803EE9C: .4byte 0x03000590
_0803EEA0: .4byte 0x030019A4
_0803EEA4: .4byte 0x030019A2
_0803EEA8: .4byte 0x030019A5
_0803EEAC:
	cmp r3, #2
	bne _0803EEBE
	mov r0, ip
	adds r0, #0x47
	adds r4, r1, r0
	adds r0, #0x73
	adds r2, r1, r0
	movs r3, #0
	b _0803EEC4
_0803EEBE:
	adds r4, r4, r6
	adds r2, r2, r6
	adds r3, #1
_0803EEC4:
	adds r7, #1
	cmp r7, #2
	bls _0803EE64
_0803EECA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
