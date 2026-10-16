	.syntax unified

	thumb_func_start unpack_item_inventory_to_buffer
unpack_item_inventory_to_buffer: @ 0x0805AD00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r7, #0
	movs r1, #0
	ldr r0, _0805AD54 @ =0x03002BA0
	mov r8, r0
	ldr r3, _0805AD58 @ =0x03006F74
	mov sl, r3
	mov sb, r8
	movs r0, #0x81
	lsls r0, r0, #0x12
	mov ip, r0
_0805AD1E:
	lsls r1, r1, #0x10
	asrs r2, r1, #0x10
	lsls r5, r2, #1
	mov r3, sb
	adds r0, r5, r3
	ldrb r4, [r0]
	movs r0, #0x80
	ands r0, r4
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r6, r1, #0
	cmp r3, #0
	beq _0805AD5C
	lsls r1, r2, #2
	add r1, ip
	movs r0, #0x7f
	ands r0, r4
	strh r0, [r1]
	adds r0, r5, #1
	add r0, r8
	ldrb r0, [r0]
	strh r0, [r1, #2]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	b _0805AD62
	.align 2, 0
_0805AD54: .4byte 0x03002BA0
_0805AD58: .4byte 0x03006F74
_0805AD5C:
	lsls r0, r2, #2
	add r0, ip
	strh r3, [r0, #2]
_0805AD62:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r6, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	ble _0805AD1E
	mov r3, sl
	ldr r0, [r3]
	strb r7, [r0, #0x10]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
