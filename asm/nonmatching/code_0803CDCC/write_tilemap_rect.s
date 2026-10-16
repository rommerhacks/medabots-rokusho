	.syntax unified

	thumb_func_start write_tilemap_rect
	.global write_tilemap_rect
write_tilemap_rect: @ 0x0803F15C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	mov sb, r1
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	ldr r5, _0803F1C4 @ =0x03000580
	strh r1, [r5]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	lsls r2, r2, #1
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r2, r2, r1
	adds r0, r0, r2
	lsls r3, r3, #6
	adds r0, r0, r3
	mov ip, r0
	ldr r4, [sp, #0x1c]
	movs r2, #0
	cmp r2, sb
	bhs _0803F1B8
	mov r8, r5
_0803F192:
	lsls r0, r2, #6
	mov r3, ip
	adds r1, r3, r0
	movs r3, #0
	adds r2, #1
	cmp r3, r6
	bhs _0803F1B4
	mov r5, r8
_0803F1A2:
	ldrh r0, [r5]
	ldrh r7, [r4]
	adds r0, r0, r7
	strh r0, [r1]
	adds r4, #2
	adds r1, #2
	adds r3, #1
	cmp r3, r6
	blo _0803F1A2
_0803F1B4:
	cmp r2, sb
	blo _0803F192
_0803F1B8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F1C4: .4byte 0x03000580
	.syntax divided
