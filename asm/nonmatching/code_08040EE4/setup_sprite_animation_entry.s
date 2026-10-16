	.syntax unified

	thumb_func_start setup_sprite_animation_entry
	.global setup_sprite_animation_entry
setup_sprite_animation_entry: @ 0x08044934
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov ip, r0
	ldr r0, [sp, #0x40]
	ldr r7, [sp, #0x44]
	ldr r4, [sp, #0x48]
	ldr r5, [sp, #0x4c]
	ldr r6, [sp, #0x50]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x18]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sl, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov sb, r4
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	str r6, [sp, #0x1c]
	cmp r7, #1
	beq _08044988
	cmp r7, #1
	blo _08044984
	cmp r7, #2
	beq _0804498C
	cmp r7, #3
	beq _08044992
	b _08044996
_08044984:
	movs r7, #0x64
	b _08044996
_08044988:
	movs r7, #0xc8
	b _08044996
_0804498C:
	movs r7, #0x96
	lsls r7, r7, #1
	b _08044996
_08044992:
	movs r7, #0xc8
	lsls r7, r7, #1
_08044996:
	cmp r5, #0
	bne _0804499E
	movs r5, #1
	b _080449A0
_0804499E:
	movs r5, #2
_080449A0:
	movs r3, #0
	ldr r0, [sp, #0x1c]
	cmp r0, #1
	bne _080449AA
	movs r3, #4
_080449AA:
	ldr r1, _08044A20 @ =0x02026000
	mov r4, ip
	lsls r0, r4, #6
	add r0, ip
	lsls r0, r0, #4
	ldr r6, _08044A24 @ =0x020260D0
	adds r0, r0, r6
	str r0, [r1, #8]
	ldr r4, _08044A28 @ =0x03002414
	ldr r0, [r4]
	ldr r6, _08044A2C @ =0x00000B84
	adds r0, r0, r6
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	str r2, [sp]
	mov r6, r8
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	str r2, [sp, #4]
	str r7, [sp, #8]
	mov r2, sb
	str r2, [sp, #0xc]
	orrs r5, r3
	str r5, [sp, #0x10]
	ldr r2, [sp, #0x18]
	mov r3, sl
	bl load_sprite_animation_by_type
	ldr r6, [sp, #0x1c]
	cmp r6, #2
	bne _08044A0E
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x14]
	ldr r1, [r4]
	ldr r0, _08044A2C @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _08044A30 @ =0x01000100
	add r0, sp, #0x14
	bl CpuFastSet
	ldr r0, [r4]
	ldr r1, _08044A34 @ =0x00001094
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _08044A38 @ =0x00001095
	adds r0, r0, r2
	strb r1, [r0]
_08044A0E:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044A20: .4byte 0x02026000
_08044A24: .4byte 0x020260D0
_08044A28: .4byte 0x03002414
_08044A2C: .4byte 0x00000B84
_08044A30: .4byte 0x01000100
_08044A34: .4byte 0x00001094
_08044A38: .4byte 0x00001095
	.syntax divided
