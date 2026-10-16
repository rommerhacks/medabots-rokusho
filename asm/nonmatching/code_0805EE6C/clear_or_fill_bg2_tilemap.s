	.syntax unified

	thumb_func_start clear_or_fill_bg2_tilemap
clear_or_fill_bg2_tilemap: @ 0x0805F9E4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	adds r7, r0, #0
	cmp r7, #7
	bgt _0805FA50
	movs r0, #0
	str r0, [sp, #0x40]
	add r0, sp, #0x40
	ldr r2, _0805FA40 @ =0x01000010
	mov r1, sp
	bl CpuFastSet
	ldr r6, _0805FA44 @ =0x0400000C
	ldrh r0, [r6]
	lsrs r0, r0, #8
	movs r5, #0x1f
	ands r0, r5
	lsls r0, r0, #0xb
	movs r1, #7
	subs r1, r1, r7
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	adds r0, r0, r1
	adds r4, r7, #1
	ldr r1, _0805FA48 @ =0x001FFFFF
	ands r4, r1
	mov r1, sp
	adds r2, r4, #0
	bl CpuSet
	ldrh r0, [r6]
	lsrs r0, r0, #8
	ands r0, r5
	lsls r0, r0, #0xb
	ldr r1, _0805FA4C @ =0x0600002C
	adds r0, r0, r1
	movs r1, #0x1d
	subs r1, r1, r7
	lsls r1, r1, #1
	add r1, sp
	adds r2, r4, #0
	bl CpuSet
	b _0805FABE
	.align 2, 0
_0805FA40: .4byte 0x01000010
_0805FA44: .4byte 0x0400000C
_0805FA48: .4byte 0x001FFFFF
_0805FA4C: .4byte 0x0600002C
_0805FA50:
	subs r7, #8
	ldr r0, _0805FA88 @ =0x0400000C
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	mov r1, sp
	movs r2, #0x10
	bl CpuFastSet
	add r1, sp, #0x1c
	movs r0, #0xd
	subs r0, r0, r7
	lsls r0, r0, #1
	mov r3, sp
	adds r2, r3, r0
	movs r4, #0xd
	mov r5, sp
	adds r5, #0x1e
_0805FA7E:
	cmp r4, r7
	bgt _0805FA8C
	ldrh r0, [r3]
	strh r0, [r1]
	b _0805FA92
	.align 2, 0
_0805FA88: .4byte 0x0400000C
_0805FA8C:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r2, #2
_0805FA92:
	subs r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0805FA7E
	adds r1, r5, #0
	lsls r0, r7, #1
	adds r0, #0x20
	mov r3, sp
	adds r2, r3, r0
	movs r4, #0xd
_0805FAA6:
	cmp r4, r7
	bgt _0805FAB0
	ldrh r0, [r3, #0x3a]
	strh r0, [r1]
	b _0805FAB6
_0805FAB0:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
_0805FAB6:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0805FAA6
_0805FABE:
	movs r5, #0xc0
	lsls r5, r5, #0x13
	movs r4, #0x13
_0805FAC4:
	ldr r0, _0805FAEC @ =0x0400000A
	ldrh r1, [r0]
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	adds r1, r1, r5
	mov r0, sp
	movs r2, #0x10
	bl CpuFastSet
	adds r5, #0x40
	subs r4, #1
	cmp r4, #0
	bge _0805FAC4
	add sp, #0x44
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805FAEC: .4byte 0x0400000A
	.syntax divided
