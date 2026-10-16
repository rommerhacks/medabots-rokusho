	.syntax unified

	thumb_func_start sub_08037798
	.global sub_08037798
sub_08037798: @ 0x08037798
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	bl rng_lookup_table_value
	adds r4, r0, #0
	bl rng_next_080424B8
	adds r6, r0, #0
	movs r0, #1
	ands r6, r0
	movs r7, #0
	ldr r0, _08037800 @ =0x03000590
	mov ip, r0
_080377B6:
	mov r0, r8
	adds r5, r0, r4
	lsls r3, r5, #8
	mov r0, ip
	adds r2, r3, r0
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08037804
	adds r0, r2, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080377E0
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08037804
_080377E0:
	adds r0, r2, #0
	adds r0, #0xde
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r3
	add r0, ip
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _08037804
	adds r0, r5, #0
	b _08037824
	.align 2, 0
_08037800: .4byte 0x03000590
_08037804:
	cmp r6, #0
	beq _08037812
	adds r4, #1
	cmp r4, #2
	bls _0803781C
	movs r4, #0
	b _0803781C
_08037812:
	cmp r4, #0
	bne _0803781A
	movs r4, #2
	b _0803781C
_0803781A:
	subs r4, #1
_0803781C:
	adds r7, #1
	cmp r7, #2
	bls _080377B6
	movs r0, #0xff
_08037824:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
