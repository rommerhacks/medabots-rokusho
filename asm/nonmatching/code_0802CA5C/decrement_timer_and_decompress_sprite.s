	.syntax unified

	thumb_func_start decrement_timer_and_decompress_sprite
decrement_timer_and_decompress_sprite: @ 0x0802EE14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802EE30 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0
	beq _0802EE34
	subs r0, #1
	strh r0, [r1]
	b _0802EEDA
	.align 2, 0
_0802EE30: .4byte 0x03000440
_0802EE34:
	ldr r0, _0802EEE8 @ =0x084E17E0
	ldr r1, _0802EEEC @ =0x06015400
	bl lz_decompress_dispatch
	ldr r0, _0802EEF0 @ =0x084E30B8
	ldr r1, _0802EEF4 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	movs r2, #0
	ldr r3, _0802EEF8 @ =0x03001800
	ldr r5, _0802EEFC @ =0x03002C30
	movs r0, #0
	mov r8, r0
	movs r7, #0
	mov sl, r7
	ldr r0, _0802EF00 @ =0x0000C624
	mov sb, r0
	movs r7, #0x60
	adds r7, r7, r3
	mov ip, r7
	ldr r0, _0802EF04 @ =0x00000923
	adds r4, r5, r0
	movs r7, #0x90
	lsls r7, r7, #4
	adds r1, r5, r7
	movs r6, #0x40
_0802EE6A:
	ldr r7, _0802EF08 @ =0x030018D2
	adds r0, r2, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EEC0
	mov r0, sb
	strh r0, [r1]
	mov r7, r8
	strb r7, [r1, #0x1c]
	mov r7, ip
	ldrb r0, [r7]
	adds r0, r0, r2
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	mov r7, ip
	ldrb r0, [r7]
	adds r0, r0, r2
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r1, #4]
	strb r6, [r1, #8]
	strb r6, [r1, #9]
	mov r0, sl
	strh r0, [r1, #0x18]
	movs r0, #6
	strb r0, [r1, #0xa]
	movs r0, #0xf0
	strb r0, [r1, #0xb]
	mov r7, r8
	strb r7, [r4]
	movs r0, #0x81
	lsls r0, r0, #8
	strh r0, [r1, #6]
_0802EEC0:
	adds r4, #0x40
	adds r1, #0x40
	adds r2, #1
	cmp r2, #2
	bls _0802EE6A
	movs r0, #0x2a
	bl play_sound_effect
	ldr r1, _0802EF08 @ =0x030018D2
	subs r1, #0x28
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802EEDA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EEE8: .4byte 0x084E17E0
_0802EEEC: .4byte 0x06015400
_0802EEF0: .4byte 0x084E30B8
_0802EEF4: .4byte 0x050002C0
_0802EEF8: .4byte 0x03001800
_0802EEFC: .4byte 0x03002C30
_0802EF00: .4byte 0x0000C624
_0802EF04: .4byte 0x00000923
_0802EF08: .4byte 0x030018D2
	.syntax divided
