	.syntax unified

	thumb_func_start copy_tilemap_region
	.global copy_tilemap_region
copy_tilemap_region: @ 0x080491C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, [sp, #0x24]
	mov sl, r0
	ldr r0, [sp, #0x34]
	cmp r0, #0
	beq _080491E4
	cmp r0, #1
	beq _080491E8
	b _080491EA
_080491E4:
	movs r6, #0x20
	b _080491EA
_080491E8:
	movs r6, #0x40
_080491EA:
	adds r0, r6, #0
	muls r0, r2, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r4, r4, r0
	movs r0, #0
	ldr r1, [sp, #0x28]
	cmp r0, r1
	bge _08049248
	lsls r6, r6, #1
	mov sb, r6
_08049200:
	adds r6, r4, #0
	adds r0, #1
	str r0, [sp]
	mov r7, sl
	cmp r7, #0
	ble _0804923C
	ldr r0, _08049258 @ =0x000003FF
	mov r8, r0
	movs r1, #0xc0
	lsls r1, r1, #4
	mov ip, r1
	mov r2, sl
	ldr r7, [sp, #0x30]
	lsls r3, r7, #0xc
_0804921C:
	ldrh r1, [r5]
	adds r0, r1, #0
	mov r7, r8
	ands r0, r7
	ldr r7, [sp, #0x2c]
	adds r0, r0, r7
	mov r7, ip
	ands r1, r7
	orrs r1, r3
	orrs r0, r1
	strh r0, [r4]
	adds r4, #2
	adds r5, #2
	subs r2, #1
	cmp r2, #0
	bne _0804921C
_0804923C:
	mov r0, sb
	adds r4, r6, r0
	ldr r0, [sp]
	ldr r1, [sp, #0x28]
	cmp r0, r1
	blt _08049200
_08049248:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08049258: .4byte 0x000003FF
	.syntax divided
