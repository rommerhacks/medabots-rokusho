	.syntax unified

	thumb_func_start shell_sort_by_second_byte
shell_sort_by_second_byte: @ 0x08002060
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	mov ip, r2
	cmp r2, #1
	bls _080020BE
_08002072:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #0xd
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _08002080
	movs r2, #1
_08002080:
	movs r1, #0
	movs r5, #0
_08002084:
	adds r0, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r6, r0, #0
	lsls r0, r5, #2
	mov r3, r8
	adds r4, r0, r3
	lsls r0, r6, #2
	adds r3, r0, r3
	ldrb r0, [r4, #1]
	ldrb r7, [r3, #1]
	cmp r0, r7
	bhs _080020A8
	ldrh r1, [r4]
	ldrh r0, [r3]
	strh r0, [r4]
	strh r1, [r3]
	movs r1, #1
_080020A8:
	adds r0, r6, #1
	cmp r0, ip
	bge _080020B6
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b _08002084
_080020B6:
	cmp r1, #1
	beq _08002072
	cmp r2, #1
	bhi _08002072
_080020BE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
