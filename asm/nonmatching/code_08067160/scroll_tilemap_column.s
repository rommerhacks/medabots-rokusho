	.syntax unified

	thumb_func_start scroll_tilemap_column
scroll_tilemap_column: @ 0x08067218
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x40
	adds r3, r0, #0
	ldr r2, _08067284 @ =0x080AFE96
	ldr r0, _08067288 @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	adds r0, r0, r2
	ldrb r7, [r0]
	cmp r1, #0xe
	bgt _08067294
	ldr r0, _0806728C @ =0x04000008
	mov sb, r0
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r6, #0x1f
	ands r0, r6
	lsls r0, r0, #0xb
	lsls r1, r7, #1
	movs r2, #0xc0
	lsls r2, r2, #0x13
	mov r8, r2
	add r1, r8
	adds r0, r0, r1
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r2, #0x1e
	subs r2, r2, r7
	ldr r4, _08067290 @ =0x001FFFFF
	ands r2, r4
	mov r1, sp
	bl CpuSet
	mov r3, sb
	ldrh r1, [r3]
	lsrs r1, r1, #8
	ands r1, r6
	lsls r1, r1, #0xb
	adds r0, r7, #1
	lsls r0, r0, #1
	add r0, r8
	adds r1, r1, r0
	adds r1, r1, r5
	movs r2, #0x1d
	subs r2, r2, r7
	ands r2, r4
	mov r0, sp
	bl CpuSet
	b _08067308
	.align 2, 0
_08067284: .4byte 0x080AFE96
_08067288: .4byte 0x03006F74
_0806728C: .4byte 0x04000008
_08067290: .4byte 0x001FFFFF
_08067294:
	ldr r0, _08067318 @ =0x0400000A
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	lsls r1, r3, #6
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	adds r0, r0, r1
	mov r1, sp
	movs r2, #0x10
	bl CpuFastSet
	mov r2, sp
	ldr r0, _0806731C @ =0x0600DD3E
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2, #0x3e]
	movs r3, #0
	lsls r5, r7, #1
	mov r4, sp
	add r1, sp, #0x14
	movs r2, #0x13
_080672CC:
	ldrh r0, [r1]
	cmp r0, #0
	beq _080672D4
	ldrh r3, [r4, #0x3e]
_080672D4:
	strh r3, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _080672CC
	mov r1, sp
	adds r0, r1, r5
	ldr r1, _08067320 @ =0x04000008
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	lsls r1, r1, #0xb
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r2, r5, r2
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
	movs r2, #0x1e
	subs r2, r2, r7
	ldr r3, _08067324 @ =0x001FFFFF
	ands r2, r3
	bl CpuSet
_08067308:
	add sp, #0x40
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067318: .4byte 0x0400000A
_0806731C: .4byte 0x0600DD3E
_08067320: .4byte 0x04000008
_08067324: .4byte 0x001FFFFF
	.syntax divided
