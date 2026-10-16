	.syntax unified

	thumb_func_start setup_random_encounter_enemies
setup_random_encounter_enemies: @ 0x08011E20
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _08011E58 @ =0x030057E0
	ldr r2, _08011E5C @ =0x00000C2D
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #0
	bne _08011E84
	ldr r1, _08011E60 @ =0x000007FE
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldr r1, _08011E64 @ =0x083BF090
	adds r0, r0, r1
	ldr r4, _08011E68 @ =0x0300052E
	adds r1, r4, #0
	movs r2, #4
	bl memcpy_bytes_08041D04
	bl sub_08043C94
	cmp r0, #0x27
	bhi _08011E6C
	ldrb r1, [r4]
	b _08011E7E
	.align 2, 0
_08011E58: .4byte 0x030057E0
_08011E5C: .4byte 0x00000C2D
_08011E60: .4byte 0x000007FE
_08011E64: .4byte 0x083BF090
_08011E68: .4byte 0x0300052E
_08011E6C:
	cmp r0, #0x45
	bhi _08011E74
	ldrb r1, [r4, #1]
	b _08011E7E
_08011E74:
	cmp r0, #0x59
	bhi _08011E7C
	ldrb r1, [r4, #2]
	b _08011E7E
_08011E7C:
	ldrb r1, [r4, #3]
_08011E7E:
	ldr r2, _08011F14 @ =0x00000C2A
	adds r0, r5, r2
	strb r1, [r0]
_08011E84:
	ldr r1, _08011F18 @ =0x083C1A00
	ldr r2, _08011F14 @ =0x00000C2A
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _08011F1C @ =0x03001800
	adds r1, r4, #0
	movs r2, #0x28
	bl memcpy_bytes_08041D04
	ldrb r0, [r4, #3]
	cmp r0, #0
	bne _08011F08
	movs r0, #0
	mov sb, r0
	movs r7, #0
_08011EA8:
	ldr r4, _08011F1C @ =0x03001800
	adds r4, r7, r4
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	bl sub_08011F20
	mov r8, r0
	mov r1, r8
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	bl sub_08011F20
	adds r6, r0, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	bl sub_08011F20
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	bl sub_08011F20
	mov r2, r8
	strb r2, [r4, #4]
	strb r6, [r4, #5]
	strb r5, [r4, #6]
	strb r0, [r4, #7]
	adds r7, #0xc
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #2
	bls _08011EA8
_08011F08:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011F14: .4byte 0x00000C2A
_08011F18: .4byte 0x083C1A00
_08011F1C: .4byte 0x03001800
	.syntax divided
