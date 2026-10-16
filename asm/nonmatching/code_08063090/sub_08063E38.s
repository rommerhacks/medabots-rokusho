	.syntax unified

	thumb_func_start sub_08063E38
sub_08063E38: @ 0x08063E38
	push {r4, r5, r6, r7, lr}
	ldr r0, _08063EBC @ =0x08485BD8
	ldr r0, [r0, #0x64]
	bl run_message
	ldr r7, _08063EC0 @ =0x03006F74
	ldr r2, [r7]
	movs r0, #0x8c
	lsls r0, r0, #2
	adds r6, r2, r0
	ldr r1, _08063EC4 @ =0x03005010
	ldr r0, _08063EC8 @ =0x03000B90
	ldrb r0, [r0]
	movs r3, #0
	cmp r0, #0
	bne _08063E5A
	movs r3, #4
_08063E5A:
	adds r0, r1, #0
	adds r0, #0xa
	adds r0, r3, r0
	ldrh r4, [r0]
	adds r0, r2, #0
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08063EE4
	adds r0, r2, #0
	adds r0, #0x48
	ldrb r3, [r0]
	adds r5, r6, r3
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r4
	movs r1, #0xc0
	lsls r1, r1, #8
	cmp r0, r1
	bne _08063EA0
	movs r0, #0xf
	lsrs r1, r4, #8
	movs r2, #0xf
	ands r3, r0
	ands r1, r2
	cmp r3, r1
	bne _08063EA0
	strb r4, [r5]
	ldr r1, [r7]
	adds r1, #0x48
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08063EA0:
	ldr r0, _08063EC0 @ =0x03006F74
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x48
	ldrb r0, [r1]
	cmp r0, #0x3f
	bls _08063ECC
	ldr r1, _08063EC4 @ =0x03005010
	movs r0, #0xff
	lsls r0, r0, #8
	strh r0, [r1, #6]
	adds r3, r1, #0
	b _08063F14
	.align 2, 0
_08063EBC: .4byte 0x08485BD8
_08063EC0: .4byte 0x03006F74
_08063EC4: .4byte 0x03005010
_08063EC8: .4byte 0x03000B90
_08063ECC:
	ldr r0, _08063EE0 @ =0x03005010
	ldrb r1, [r1]
	movs r3, #0xfe
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0, #6]
	adds r3, r0, #0
	b _08063F14
	.align 2, 0
_08063EE0: .4byte 0x03005010
_08063EE4:
	movs r0, #0xff
	lsls r0, r0, #8
	adds r2, r4, #0
	ands r2, r0
	cmp r2, r0
	bne _08063EF2
	strh r2, [r1, #6]
_08063EF2:
	movs r0, #0xfe
	lsls r0, r0, #8
	adds r3, r1, #0
	cmp r2, r0
	bne _08063F14
	movs r0, #0xff
	ands r0, r4
	adds r5, r6, r0
	ldrb r2, [r5]
	movs r0, #0xf
	ands r4, r0
	lsls r0, r4, #8
	ldr r4, _08063F44 @ =0xFFFFC000
	adds r1, r4, #0
	orrs r0, r1
	orrs r2, r0
	strh r2, [r3, #6]
_08063F14:
	ldrh r1, [r3, #0xa]
	movs r0, #0xff
	lsls r0, r0, #8
	cmp r1, r0
	bne _08063F5A
	ldrh r0, [r3, #0xe]
	cmp r0, r1
	bne _08063F5A
	ldr r0, _08063F48 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08063F4C
	adds r0, r6, #0
	bl export_medals_to_buffer
	ldrb r0, [r6, #1]
	ldrb r1, [r6, #8]
	bl sub_08062AB0
	b _08063F52
	.align 2, 0
_08063F44: .4byte 0xFFFFC000
_08063F48: .4byte 0x03006F74
_08063F4C:
	ldrb r0, [r6, #1]
	bl medal_remove_by_id
_08063F52:
	ldr r1, _08063F60 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08063F5A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063F60: .4byte 0x0300137C
_08063F64:
	.byte 0x02, 0x49, 0x08, 0x68, 0x01, 0x30, 0x08, 0x60, 0x70, 0x47, 0x00, 0x00
	.byte 0x7C, 0x13, 0x00, 0x03
	.syntax divided
