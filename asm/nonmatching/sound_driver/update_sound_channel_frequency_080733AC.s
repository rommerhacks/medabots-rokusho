	.syntax unified

	thumb_func_start update_sound_channel_frequency_080733AC
update_sound_channel_frequency_080733AC: @ 0x080733AC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	bl sub_080740AC
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r2, r4, #0
	adds r2, #0x6c
	ldrb r0, [r2]
	cmp r0, r1
	beq _08073482
	strb r1, [r2]
	adds r7, r4, #0
	adds r7, #0x64
	cmp r1, #0xff
	beq _08073464
	adds r0, r1, #0
	bl sub_08073140
	adds r1, r4, #0
	adds r1, #0x55
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080733EE
	movs r3, #0
	b _080733F6
_080733EE:
	ldr r1, _08073430 @ =0x000007FF
	cmp r0, r1
	ble _080733F6
	adds r3, r1, #0
_080733F6:
	ldrb r0, [r7]
	adds r1, r4, #0
	adds r1, #0x40
	cmp r0, #2
	bne _0807343C
	ldr r2, _08073434 @ =0x083ABA62
	ldrh r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #0xc
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #8
	strh r0, [r6]
	mov r2, sp
	ldr r0, _08073438 @ =0x04000084
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	movs r1, #0
	cmp r0, #0
	bne _08073428
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r0, #0
_08073428:
	strh r1, [r2]
	mov r0, sp
	ldrh r0, [r0]
	b _08073458
	.align 2, 0
_08073430: .4byte 0x000007FF
_08073434: .4byte 0x083ABA62
_08073438: .4byte 0x04000084
_0807343C:
	ldrh r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r2, _08073460 @ =0xFFFFF000
	adds r0, r2, #0
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0x67
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
_08073458:
	orrs r3, r0
	strh r3, [r5]
	b _08073482
	.align 2, 0
_08073460: .4byte 0xFFFFF000
_08073464:
	ldrb r0, [r7]
	cmp r0, #2
	bne _0807346E
	movs r0, #0
	b _08073474
_0807346E:
	adds r0, r4, #0
	adds r0, #0x67
	ldrb r0, [r0]
_08073474:
	strh r0, [r6]
	ldrh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
_08073482:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
