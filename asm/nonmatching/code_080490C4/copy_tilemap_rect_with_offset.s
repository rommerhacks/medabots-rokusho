	.syntax unified

	thumb_func_start copy_tilemap_rect_with_offset
	.global copy_tilemap_rect_with_offset
copy_tilemap_rect_with_offset: @ 0x0804925C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r0, [sp, #0x1c]
	mov ip, r0
	ldr r0, [sp, #0x20]
	mov sb, r0
	ldr r0, [sp, #0x2c]
	mov r8, r0
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0804927E
	cmp r0, #1
	beq _08049282
	b _08049284
_0804927E:
	movs r5, #0x20
	b _08049284
_08049282:
	movs r5, #0x40
_08049284:
	adds r0, r5, #0
	muls r0, r2, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #0
	cmp r0, sb
	bge _080492BE
	lsls r7, r5, #1
_08049296:
	adds r5, r4, #0
	adds r3, r1, #0
	adds r6, r0, #1
	mov r0, ip
	cmp r0, #0
	ble _080492B4
	mov r2, ip
_080492A4:
	ldrh r0, [r4]
	add r0, r8
	strh r0, [r1]
	adds r1, #2
	adds r4, #2
	subs r2, #1
	cmp r2, #0
	bne _080492A4
_080492B4:
	adds r1, r3, r7
	adds r4, r5, r7
	adds r0, r6, #0
	cmp r0, sb
	blt _08049296
_080492BE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
