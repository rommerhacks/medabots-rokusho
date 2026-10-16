	.syntax unified

	thumb_func_start battle_check_medal_level_up
battle_check_medal_level_up: @ 0x080127DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0801283C @ =0x0300196E
	movs r1, #0x18
	movs r2, #0
	bl sub_0803F624
	movs r0, #0
	mov sb, r0
	movs r1, #1
	mov sl, r1
_080127FA:
	ldr r0, _08012840 @ =0x03000590
	mov r2, sb
	lsls r1, r2, #8
	adds r1, r1, r0
	adds r0, r1, #0
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801280E
	b _0801293C
_0801280E:
	ldrb r0, [r1, #1]
	bl find_medal_slot_by_id
	subs r0, #1
	ldr r1, _08012844 @ =0x03000BE0
	lsls r0, r0, #6
	adds r5, r0, r1
	ldrb r2, [r5, #5]
	cmp r2, #0x64
	bne _08012824
	b _0801293C
_08012824:
	ldr r7, _08012848 @ =0x03001800
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r5, #2]
	ldrh r0, [r0]
	cmp r1, r0
	bls _0801284C
	subs r0, r1, r0
	strh r0, [r5, #2]
	b _0801293C
	.align 2, 0
_0801283C: .4byte 0x0300196E
_08012840: .4byte 0x03000590
_08012844: .4byte 0x03000BE0
_08012848: .4byte 0x03001800
_0801284C:
	adds r0, r2, #1
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #1
	movs r1, #0x64
	muls r0, r1, r0
	strh r0, [r5, #2]
	mov r4, sb
	lsls r6, r4, #3
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r1, r7, r0
	adds r1, r6, r1
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r1]
	ldrb r0, [r5, #1]
	lsls r0, r0, #4
	ldr r1, _08012958 @ =0x083B6158
	adds r0, r0, r1
	ldr r1, _0801295C @ =0x0300052E
	mov r8, r1
	movs r2, #0x10
	bl memcpy_bytes_08041D04
	ldrb r0, [r5, #5]
	mov r2, r8
	ldrb r1, [r2, #3]
	ldrb r2, [r2, #4]
	mov r4, r8
	ldrb r3, [r4, #5]
	ldrb r4, [r4, #6]
	str r4, [sp]
	bl sub_080420C4
	adds r2, r0, #0
	ldrb r0, [r5, #8]
	cmp r2, r0
	beq _080128D0
	ldr r1, _08012960 @ =0x0000016F
	adds r0, r7, r1
	adds r0, r6, r0
	mov r3, sl
	strb r3, [r0]
	movs r4, #0xb8
	lsls r4, r4, #1
	adds r0, r7, r4
	adds r0, r6, r0
	ldrb r1, [r5, #1]
	strb r1, [r0]
	ldr r1, _08012964 @ =0x00000171
	adds r0, r7, r1
	adds r0, r6, r0
	ldrb r1, [r5, #8]
	strb r1, [r0]
	movs r3, #0xb9
	lsls r3, r3, #1
	adds r0, r7, r3
	adds r0, r6, r0
	ldrb r1, [r5, #1]
	strb r1, [r0]
	adds r4, #3
	adds r0, r7, r4
	adds r0, r6, r0
	strb r2, [r0]
	strb r2, [r5, #8]
_080128D0:
	ldrb r1, [r5, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08012968 @ =0x083B7E0C
	adds r0, r0, r1
	mov r1, r8
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r0, [r5, #5]
	cmp r0, #0xa
	bne _08012900
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r0, r6, r0
	mov r2, sl
	strb r2, [r0]
	ldr r3, _0801296C @ =0x00000175
	adds r0, r7, r3
	adds r0, r6, r0
	mov r4, r8
	ldrb r1, [r4]
	strb r1, [r0]
_08012900:
	ldrb r0, [r5, #5]
	cmp r0, #0x1e
	bne _0801291E
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r0, r6, r0
	mov r2, sl
	strb r2, [r0]
	ldr r3, _0801296C @ =0x00000175
	adds r0, r7, r3
	adds r0, r6, r0
	mov r4, r8
	ldrb r1, [r4, #1]
	strb r1, [r0]
_0801291E:
	ldrb r0, [r5, #5]
	cmp r0, #0x3c
	bne _0801293C
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r0, r6, r0
	mov r2, sl
	strb r2, [r0]
	ldr r3, _0801296C @ =0x00000175
	adds r0, r7, r3
	adds r0, r6, r0
	mov r4, r8
	ldrb r1, [r4, #2]
	strb r1, [r0]
_0801293C:
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #2
	bhi _08012948
	b _080127FA
_08012948:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012958: .4byte 0x083B6158
_0801295C: .4byte 0x0300052E
_08012960: .4byte 0x0000016F
_08012964: .4byte 0x00000171
_08012968: .4byte 0x083B7E0C
_0801296C: .4byte 0x00000175
	.syntax divided
