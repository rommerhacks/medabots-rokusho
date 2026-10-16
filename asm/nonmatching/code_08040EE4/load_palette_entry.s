	.syntax unified

	thumb_func_start load_palette_entry
	.global load_palette_entry
load_palette_entry: @ 0x08041D70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r6, #4
	ldr r1, _08041E28 @ =0x083B6158
	adds r0, r0, r1
	ldr r4, _08041E2C @ =0x0300052E
	adds r1, r4, #0
	movs r2, #0x10
	bl memcpy_bytes_08041D04
	movs r0, #0
	mov sb, r0
	subs r4, #0xee
	movs r1, #0xf6
	adds r1, r1, r4
	mov sl, r1
	movs r7, #0
	movs r3, #0x64
	mov r8, r3
_08041DA2:
	ldr r0, _08041E30 @ =0x03000BE0
	adds r5, r7, r0
	ldrb r1, [r5]
	movs r2, #0x80
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08041DB4
	b _08041FC6
_08041DB4:
	adds r0, r2, #0
	orrs r0, r1
	strb r0, [r5]
	strb r6, [r5, #1]
	adds r0, r4, #0
	adds r0, #0xef
	ldrb r0, [r0]
	strb r0, [r5, #4]
	adds r0, r4, #0
	adds r0, #0xf0
	ldrb r0, [r0]
	strb r0, [r5, #6]
	adds r0, r4, #0
	adds r0, #0xf5
	ldrb r0, [r0]
	strb r0, [r5, #7]
	bl clear_ewram_buffer_02023000
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r1, r4, #0
	adds r1, #0xf1
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0xf2
	ldrb r2, [r2]
	adds r3, r4, #0
	adds r3, #0xf3
	ldrb r3, [r3]
	adds r4, #0xf4
	ldrb r4, [r4]
	str r4, [sp]
	bl sub_080420C4
	strb r0, [r5, #8]
	ldrb r0, [r5, #5]
	adds r0, #1
	movs r4, #0x64
	muls r0, r4, r0
	strh r0, [r5, #2]
	ldrb r0, [r5, #5]
	movs r1, #0xa
	bl sub_0807CD58
	adds r2, r0, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	mov r3, sl
	ldrb r1, [r3]
	muls r0, r1, r0
	adds r0, r0, r1
	cmp r0, #0x64
	ble _08041E34
	adds r0, r5, #0
	adds r0, #0x20
	strb r4, [r0]
	b _08041E40
	.align 2, 0
_08041E28: .4byte 0x083B6158
_08041E2C: .4byte 0x0300052E
_08041E30: .4byte 0x03000BE0
_08041E34:
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r1, r0
	adds r1, r5, #0
	adds r1, #0x20
	strb r0, [r1]
_08041E40:
	ldr r4, _08041E6C @ =0x03000BE0
	adds r5, r7, r4
	ldrb r0, [r5, #5]
	movs r1, #0xa
	bl sub_0807CD58
	adds r2, r0, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _08041E70 @ =0x03000537
	ldrb r1, [r3]
	muls r0, r1, r0
	adds r0, r0, r1
	ldr r6, _08041E74 @ =0x03000440
	cmp r0, #0x64
	ble _08041E78
	adds r0, r5, #0
	adds r0, #0x21
	mov r1, r8
	strb r1, [r0]
	b _08041E84
	.align 2, 0
_08041E6C: .4byte 0x03000BE0
_08041E70: .4byte 0x03000537
_08041E74: .4byte 0x03000440
_08041E78:
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r1, r0
	adds r1, r5, #0
	adds r1, #0x21
	strb r0, [r1]
_08041E84:
	adds r5, r7, r4
	ldrb r0, [r5, #5]
	movs r1, #0xa
	bl sub_0807CD58
	adds r3, r0, #0
	lsls r1, r3, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	adds r0, #0xf8
	ldrb r2, [r0]
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r0, r2
	cmp r0, #0x64
	ble _08041EAE
	adds r0, r5, #0
	adds r0, #0x22
	mov r3, r8
	strb r3, [r0]
	b _08041EBA
_08041EAE:
	adds r0, r2, #0
	muls r0, r3, r0
	adds r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x22
	strb r0, [r1]
_08041EBA:
	adds r5, r7, r4
	ldrb r0, [r5, #5]
	movs r1, #0xa
	bl sub_0807CD58
	adds r2, r0, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0xf9
	ldrb r1, [r1]
	muls r0, r1, r0
	adds r0, r0, r1
	cmp r0, #0x64
	ble _08041EE2
	adds r0, r5, #0
	adds r0, #0x23
	mov r1, r8
	strb r1, [r0]
	b _08041EEE
_08041EE2:
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r1, r0
	adds r1, r5, #0
	adds r1, #0x23
	strb r0, [r1]
_08041EEE:
	adds r5, r7, r4
	ldrb r0, [r5, #5]
	movs r1, #0xa
	bl sub_0807CD58
	adds r2, r0, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0xfa
	ldrb r1, [r1]
	muls r0, r1, r0
	adds r0, r0, r1
	cmp r0, #0x64
	ble _08041F16
	adds r0, r5, #0
	adds r0, #0x24
	mov r3, r8
	strb r3, [r0]
	b _08041F22
_08041F16:
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r1, r0
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
_08041F22:
	adds r5, r7, r4
	ldrb r0, [r5, #5]
	movs r1, #0xa
	bl sub_0807CD58
	adds r2, r0, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	adds r1, r6, #0
	adds r1, #0xfb
	ldrb r1, [r1]
	muls r0, r1, r0
	adds r0, r0, r1
	cmp r0, #0x64
	ble _08041F4A
	adds r0, r5, #0
	adds r0, #0x25
	mov r1, r8
	strb r1, [r0]
	b _08041F56
_08041F4A:
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r1, r0
	adds r1, r5, #0
	adds r1, #0x25
	strb r0, [r1]
_08041F56:
	adds r5, r7, r4
	ldrb r0, [r5, #5]
	movs r1, #0xa
	bl sub_0807CD58
	adds r3, r0, #0
	lsls r1, r3, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	adds r0, #0xfc
	ldrb r2, [r0]
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r0, r2
	cmp r0, #0x64
	ble _08041F80
	adds r0, r5, #0
	adds r0, #0x26
	mov r3, r8
	strb r3, [r0]
	b _08041F8C
_08041F80:
	adds r0, r2, #0
	muls r0, r3, r0
	adds r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x26
	strb r0, [r1]
_08041F8C:
	adds r4, r7, r4
	ldrb r0, [r4, #5]
	movs r1, #0xa
	bl sub_0807CD58
	adds r3, r0, #0
	lsls r1, r3, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	adds r0, #0xfd
	ldrb r2, [r0]
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r0, r2
	cmp r0, #0x64
	ble _08041FB6
	adds r0, r4, #0
	adds r0, #0x27
	mov r1, r8
	strb r1, [r0]
	b _08041FC2
_08041FB6:
	adds r0, r2, #0
	muls r0, r3, r0
	adds r0, r2, r0
	adds r1, r4, #0
	adds r1, #0x27
	strb r0, [r1]
_08041FC2:
	mov r0, sb
	b _08041FD4
_08041FC6:
	adds r7, #0x40
	movs r3, #1
	add sb, r3
	mov r0, sb
	cmp r0, #0x1d
	bhi _08041FD4
	b _08041DA2
_08041FD4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
