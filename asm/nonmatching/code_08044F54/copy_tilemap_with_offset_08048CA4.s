	.syntax unified

	thumb_func_start copy_tilemap_with_offset_08048CA4
	.global copy_tilemap_with_offset_08048CA4
copy_tilemap_with_offset_08048CA4: @ 0x08048CA4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	mov ip, r1
	mov sb, r2
	adds r4, r3, #0
	ldr r0, [sp, #0x34]
	mov r8, r0
	movs r1, #0x20
	mov sl, r1
	cmp r2, #0x1f
	bgt _08048CC6
	mov sl, sb
_08048CC6:
	movs r5, #0
	cmp r5, sl
	bge _08048D3A
	movs r2, #0x80
	lsls r2, r2, #4
	add r2, ip
	str r2, [sp, #4]
_08048CD4:
	movs r1, #0x20
	cmp r4, #0x1f
	bgt _08048CDC
	adds r1, r4, #0
_08048CDC:
	adds r6, r5, #1
	cmp r1, #0
	ble _08048D02
	adds r0, r4, #0
	muls r0, r5, r0
	lsls r0, r0, #1
	ldr r7, [sp, #8]
	adds r3, r0, r7
	lsls r0, r5, #6
	mov r7, ip
	adds r2, r0, r7
_08048CF2:
	ldrh r0, [r3]
	add r0, r8
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne _08048CF2
_08048D02:
	cmp r4, #0x1f
	ble _08048D34
	adds r0, r4, #0
	subs r0, #0x20
	cmp r0, #0
	ble _08048D34
	adds r0, r4, #0
	muls r0, r5, r0
	lsls r0, r0, #1
	ldr r1, [sp, #8]
	adds r1, #0x40
	adds r3, r0, r1
	lsls r0, r5, #6
	ldr r1, [sp, #4]
	adds r2, r0, r1
	adds r1, r4, #0
	subs r1, #0x20
_08048D24:
	ldrh r0, [r3]
	add r0, r8
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne _08048D24
_08048D34:
	adds r5, r6, #0
	cmp r5, sl
	blt _08048CD4
_08048D3A:
	mov r2, sb
	cmp r2, #0x1f
	ble _08048DC6
	movs r5, #0
	movs r7, #0x20
	rsbs r7, r7, #0
	add sb, r7
	cmp r5, sb
	bge _08048DC6
	movs r0, #0x80
	lsls r0, r0, #5
	add r0, ip
	str r0, [sp]
	movs r1, #0xc0
	lsls r1, r1, #5
	add r1, ip
	mov sl, r1
_08048D5C:
	movs r1, #0x20
	cmp r4, #0x1f
	bgt _08048D64
	adds r1, r4, #0
_08048D64:
	adds r6, r5, #1
	cmp r1, #0
	ble _08048D8C
	adds r0, r5, #0
	adds r0, #0x20
	muls r0, r4, r0
	lsls r0, r0, #1
	ldr r2, [sp, #8]
	adds r3, r0, r2
	lsls r0, r5, #6
	ldr r7, [sp]
	adds r2, r0, r7
_08048D7C:
	ldrh r0, [r3]
	add r0, r8
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne _08048D7C
_08048D8C:
	cmp r4, #0x1f
	ble _08048DC0
	adds r0, r4, #0
	subs r0, #0x20
	cmp r0, #0
	ble _08048DC0
	adds r0, r5, #0
	adds r0, #0x20
	muls r0, r4, r0
	lsls r0, r0, #1
	ldr r1, [sp, #8]
	adds r1, #0x40
	adds r3, r0, r1
	lsls r0, r5, #6
	mov r1, sl
	adds r2, r0, r1
	adds r1, r4, #0
	subs r1, #0x20
_08048DB0:
	ldrh r0, [r3]
	add r0, r8
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne _08048DB0
_08048DC0:
	adds r5, r6, #0
	cmp r5, sb
	blt _08048D5C
_08048DC6:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
