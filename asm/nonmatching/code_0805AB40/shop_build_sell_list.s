	.syntax unified

	thumb_func_start shop_build_sell_list
	.global shop_build_sell_list
shop_build_sell_list: @ 0x0805AF8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0805B028 @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #0x19]
	mov r8, r0
	movs r1, #0
	movs r7, #0x77
	ldr r0, _0805B02C @ =0x020403B8
_0805AFA6:
	strb r1, [r0, #2]
	subs r0, #8
	subs r7, #1
	cmp r7, #0
	bge _0805AFA6
	mov r0, r8
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #4
	movs r7, #0
	movs r3, #0
	ldr r0, _0805B030 @ =0x0300052E
	mov sb, r0
	ldr r0, _0805B034 @ =0x02040004
	mov sl, r0
	ldr r0, _0805B038 @ =0x03004C40
	adds r6, r1, r0
_0805AFC8:
	ldrb r0, [r6]
	ldrb r1, [r6, #1]
	cmp r0, r1
	bls _0805B006
	lsls r5, r3, #3
	movs r0, #0x81
	lsls r0, r0, #0x12
	adds r4, r5, r0
	strh r7, [r4]
	ldrb r0, [r6]
	ldrb r1, [r6, #1]
	subs r0, r0, r1
	strb r0, [r4, #2]
	adds r0, r7, #0
	mov r1, r8
	mov r2, sb
	str r3, [sp]
	bl load_part_data
	mov r1, sb
	ldrb r0, [r1, #3]
	strb r0, [r4, #3]
	add r5, sl
	ldrb r1, [r1, #0xb]
	movs r0, #0x64
	muls r0, r1, r0
	str r0, [r5]
	ldr r3, [sp]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_0805B006:
	adds r6, #2
	adds r7, #1
	cmp r7, #0x77
	ble _0805AFC8
	ldr r0, _0805B028 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x20
	strb r3, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805B028: .4byte 0x03006F74
_0805B02C: .4byte 0x020403B8
_0805B030: .4byte 0x0300052E
_0805B034: .4byte 0x02040004
_0805B038: .4byte 0x03004C40
	.syntax divided
