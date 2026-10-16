	.syntax unified

	thumb_func_start sub_08026AF4
sub_08026AF4: @ 0x08026AF4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r7, #0
	ldr r0, _08026B24 @ =0x084CCE48
	ldr r1, _08026B28 @ =0x06010800
	bl lz_decompress_dispatch
	ldr r0, _08026B2C @ =0x0850E358
	ldr r1, _08026B30 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r3, _08026B34 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08026B38
	movs r1, #0xac
	lsls r1, r1, #1
	b _08026B3C
	.align 2, 0
_08026B24: .4byte 0x084CCE48
_08026B28: .4byte 0x06010800
_08026B2C: .4byte 0x0850E358
_08026B30: .4byte 0x050003C0
_08026B34: .4byte 0x03001800
_08026B38:
	movs r1, #0xaa
	lsls r1, r1, #1
_08026B3C:
	adds r0, r3, r1
	ldrh r6, [r0]
	adds r1, #2
	adds r0, r3, r1
	ldrh r5, [r0]
	ldr r4, _08026BE0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xd2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08026B68
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0xa
	movs r1, #0
	bl sub_08036C20
	movs r7, #1
_08026B68:
	adds r0, r4, #0
	adds r0, #0xd3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08026B88
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0xb
	movs r1, #1
	bl sub_08036C20
	movs r7, #1
_08026B88:
	adds r0, r4, #0
	adds r0, #0xd4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08026BA8
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0xc
	movs r1, #2
	bl sub_08036C20
	movs r7, #1
_08026BA8:
	adds r0, r4, #0
	adds r0, #0xd5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08026BC8
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0xd
	movs r1, #3
	bl sub_08036C20
	movs r7, #1
_08026BC8:
	cmp r7, #0
	beq _08026BE4
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	bl sub_08035194
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0xd
	b _08026BEC
	.align 2, 0
_08026BE0: .4byte 0x03001800
_08026BE4:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_08026BEC:
	strb r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
