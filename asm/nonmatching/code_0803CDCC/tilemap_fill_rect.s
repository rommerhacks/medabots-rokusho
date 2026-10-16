	.syntax unified

	thumb_func_start tilemap_fill_rect
	.global tilemap_fill_rect
tilemap_fill_rect: @ 0x0803EFD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	mov sb, r1
	mov ip, r2
	ldr r1, [sp, #0x20]
	ldr r0, [sp, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r2, #0x1f
	bhi _0803F0B4
	cmp r3, #0x1f
	bhi _0803F05A
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	lsls r0, r2, #1
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r0, r0, r2
	adds r1, r1, r0
	lsls r0, r3, #6
	adds r5, r1, r0
	movs r0, #0x20
	subs r4, r0, r3
	movs r3, #0
	cmp r3, sb
	blo _0803F01C
	b _0803F14C
_0803F01C:
	movs r0, #0x20
	mov r7, ip
	subs r2, r0, r7
	lsls r0, r3, #6
	adds r0, r5, r0
	movs r1, #0
	subs r4, #1
	adds r3, #1
	cmp r1, r6
	bhs _0803F04A
	movs r7, #0xf8
	lsls r7, r7, #3
	mov sl, r7
_0803F036:
	mov r7, r8
	strh r7, [r0]
	adds r0, #2
	subs r2, #1
	cmp r2, #0
	bne _0803F044
	add r0, sl
_0803F044:
	adds r1, #1
	cmp r1, r6
	blo _0803F036
_0803F04A:
	cmp r4, #0
	bne _0803F054
	movs r0, #0x80
	lsls r0, r0, #4
	adds r5, r5, r0
_0803F054:
	cmp r3, sb
	blo _0803F01C
	b _0803F14C
_0803F05A:
	subs r3, #0x20
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	mov r2, ip
	lsls r0, r2, #1
	movs r7, #0xc0
	lsls r7, r7, #0x13
	adds r0, r0, r7
	adds r1, r1, r0
	lsls r0, r3, #6
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #5
	adds r5, r1, r0
	movs r3, #0
	cmp r3, sb
	bhs _0803F14C
	movs r1, #0x20
	mov sl, r1
_0803F084:
	mov r7, sl
	mov r0, ip
	subs r2, r7, r0
	lsls r0, r3, #6
	adds r0, r5, r0
	movs r1, #0
	adds r3, #1
	cmp r1, r6
	bhs _0803F0AE
	movs r4, #0xf8
	lsls r4, r4, #3
_0803F09A:
	mov r7, r8
	strh r7, [r0]
	adds r0, #2
	subs r2, #1
	cmp r2, #0
	bne _0803F0A8
	adds r0, r0, r4
_0803F0A8:
	adds r1, #1
	cmp r1, r6
	blo _0803F09A
_0803F0AE:
	cmp r3, sb
	blo _0803F084
	b _0803F14C
_0803F0B4:
	cmp r3, #0x1f
	bhi _0803F108
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	mov r2, ip
	lsls r0, r2, #1
	ldr r7, _0803F104 @ =0x05FFFFC0
	adds r0, r0, r7
	adds r1, r1, r0
	lsls r0, r3, #6
	adds r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r5, r1, r2
	movs r0, #0x20
	subs r4, r0, r3
	movs r3, #0
	cmp r3, sb
	bhs _0803F14C
_0803F0DE:
	lsls r0, r3, #6
	adds r0, r5, r0
	movs r1, #0
	subs r4, #1
	adds r3, #1
	cmp r1, r6
	bhs _0803F0F8
_0803F0EC:
	mov r7, r8
	strh r7, [r0]
	adds r0, #2
	adds r1, #1
	cmp r1, r6
	blo _0803F0EC
_0803F0F8:
	cmp r4, #0
	bne _0803F0FE
	adds r5, r5, r2
_0803F0FE:
	cmp r3, sb
	blo _0803F0DE
	b _0803F14C
	.align 2, 0
_0803F104: .4byte 0x05FFFFC0
_0803F108:
	subs r3, #0x20
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	mov r2, ip
	lsls r0, r2, #1
	ldr r7, _0803F148 @ =0x05FFFFC0
	adds r0, r0, r7
	adds r1, r1, r0
	lsls r0, r3, #6
	adds r1, r1, r0
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r5, r1, r0
	movs r3, #0
_0803F128:
	cmp r3, sb
	bhs _0803F14C
	lsls r0, r3, #6
	adds r0, r5, r0
	movs r1, #0
	adds r3, #1
	cmp r1, r6
	bhs _0803F128
_0803F138:
	mov r2, r8
	strh r2, [r0]
	adds r0, #2
	adds r1, #1
	cmp r1, r6
	blo _0803F138
	b _0803F128
	.align 2, 0
_0803F148: .4byte 0x05FFFFC0
_0803F14C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
