	.syntax unified

	thumb_func_start update_battle_icon_rotation
update_battle_icon_rotation: @ 0x0806A6CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0806A7E0 @ =0x03006F8C
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #2
	bhi _0806A716
	ldr r0, _0806A7E4 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806A716
	ldr r1, _0806A7E8 @ =0x03006FEC
	ldrb r0, [r1]
	subs r0, #4
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0806A700
	movs r0, #4
	strb r0, [r1]
_0806A700:
	ldr r2, _0806A7EC @ =0x03002C30
	ldr r1, _0806A7F0 @ =0x08485CC4
	mov r3, sb
	ldrb r0, [r3]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrh r0, [r1, #0x1a]
	adds r0, #3
	strh r0, [r1, #0x1a]
_0806A716:
	movs r4, #1
	movs r6, #0xff
	mov r8, r6
	movs r0, #3
	mov ip, r0
	movs r7, #0
	ldr r1, _0806A7F0 @ =0x08485CC4
	mov sl, r1
_0806A726:
	mov r3, sb
	adds r5, r4, r3
	ldrb r0, [r5]
	cmp r0, #2
	bhi _0806A7A2
	ldr r2, _0806A7F4 @ =0x03006F84
	subs r1, r4, #1
	movs r0, #0xb
	muls r0, r1, r0
	ldrb r2, [r2]
	adds r0, r0, r2
	ldr r6, _0806A7F8 @ =0x08485CCD
	adds r0, r0, r6
	ldrb r0, [r0]
	ldr r1, _0806A7FC @ =0x03007000
	adds r3, r7, r1
	ldr r1, [r3]
	adds r0, r0, r1
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	ldr r6, _0806A800 @ =0x083D69A0
	adds r0, r0, r6
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x15
	movs r0, #7
	ands r1, r0
	adds r1, #6
	ldr r0, _0806A804 @ =0x03006FF8
	adds r2, r7, r0
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	cmp r1, r0
	bgt _0806A7A2
	ldr r0, _0806A7E8 @ =0x03006FEC
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #4
	strb r0, [r1]
	mov r6, r8
	ands r0, r6
	cmp r0, #3
	bhi _0806A784
	movs r0, #4
	strb r0, [r1]
_0806A784:
	ldrb r0, [r5]
	add r0, ip
	add r0, sl
	ldrb r1, [r0]
	lsls r1, r1, #6
	ldr r0, _0806A7EC @ =0x03002C30
	adds r1, r1, r0
	ldrh r0, [r1, #0x1a]
	adds r0, #3
	strh r0, [r1, #0x1a]
	movs r1, #0
	str r1, [r2]
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
_0806A7A2:
	movs r3, #3
	add ip, r3
	adds r7, #4
	adds r4, #1
	cmp r4, #2
	ble _0806A726
	movs r4, #0
	movs r6, #0
_0806A7B2:
	ldr r0, _0806A7E0 @ =0x03006F8C
	adds r0, r4, r0
	ldrb r0, [r0]
	adds r5, r4, #1
	cmp r0, #2
	bhi _0806A834
	ldr r0, _0806A7E8 @ =0x03006FEC
	adds r0, r4, r0
	ldrb r1, [r0]
	cmp r1, #0x20
	bne _0806A80C
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	movs r1, #0xa
	movs r3, #0
	bl sprite_animation_dispatch
	ldr r0, _0806A808 @ =0x03006FF0
	adds r0, r4, r0
	strb r6, [r0]
	b _0806A834
	.align 2, 0
_0806A7E0: .4byte 0x03006F8C
_0806A7E4: .4byte 0x0300058C
_0806A7E8: .4byte 0x03006FEC
_0806A7EC: .4byte 0x03002C30
_0806A7F0: .4byte 0x08485CC4
_0806A7F4: .4byte 0x03006F84
_0806A7F8: .4byte 0x08485CCD
_0806A7FC: .4byte 0x03007000
_0806A800: .4byte 0x083D69A0
_0806A804: .4byte 0x03006FF8
_0806A808: .4byte 0x03006FF0
_0806A80C:
	ldr r0, _0806A828 @ =0x03006FF0
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r1, r0
	bhi _0806A830
	ldr r0, _0806A82C @ =0x03002C30
	lsls r1, r5, #6
	adds r1, r1, r0
	adds r1, #0x27
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	strb r6, [r2]
	b _0806A834
	.align 2, 0
_0806A828: .4byte 0x03006FF0
_0806A82C: .4byte 0x03002C30
_0806A830:
	adds r0, #1
	strb r0, [r2]
_0806A834:
	adds r4, r5, #0
	cmp r4, #2
	ble _0806A7B2
	ldr r0, _0806A874 @ =0x03001780
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0806A864
	movs r3, #0xff
	movs r2, #0x20
	ldr r1, _0806A878 @ =0x03006FEC
	movs r4, #2
_0806A84E:
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	ands r0, r3
	cmp r0, #0x20
	bls _0806A85C
	strb r2, [r1]
_0806A85C:
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _0806A84E
_0806A864:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A874: .4byte 0x03001780
_0806A878: .4byte 0x03006FEC
	.syntax divided
