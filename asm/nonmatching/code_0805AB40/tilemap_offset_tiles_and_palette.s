	.syntax unified

	thumb_func_start tilemap_offset_tiles_and_palette
	.global tilemap_offset_tiles_and_palette
tilemap_offset_tiles_and_palette: @ 0x0805B954
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0xd
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r3, r2, r0
	ldr r5, _0805B9B8 @ =0x000003FF
	movs r0, #0xfc
	lsls r0, r0, #8
	mov sb, r0
	movs r1, #0xf0
	lsls r1, r1, #8
	mov r8, r1
	adds r4, r5, #1
	ldr r2, _0805B9BC @ =0x00000FFF
	mov ip, r2
_0805B982:
	ldrh r1, [r3]
	adds r0, r1, #0
	ands r0, r5
	adds r0, r0, r7
	ands r0, r5
	mov r2, sb
	ands r1, r2
	orrs r0, r1
	adds r2, r0, #0
	mov r1, r8
	ands r2, r1
	lsls r1, r6, #0xc
	adds r2, r2, r1
	mov r1, ip
	ands r0, r1
	orrs r0, r2
	strh r0, [r3]
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bne _0805B982
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805B9B8: .4byte 0x000003FF
_0805B9BC: .4byte 0x00000FFF
	.syntax divided
