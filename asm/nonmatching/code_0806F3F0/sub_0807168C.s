	.syntax unified

	thumb_func_start sub_0807168C
sub_0807168C: @ 0x0807168C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r1, _08071714 @ =0x080AFF90
	mov r0, sp
	movs r2, #4
	bl memcpy_optimized
	movs r0, #0
	mov r8, r0
	movs r7, #1
	movs r6, #0x16
_080716A6:
	ldr r0, _08071718 @ =0x03007010
	ldrb r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _080716F6
	ldr r4, _0807171C @ =0x03002C30
	lsls r0, r6, #6
	adds r5, r0, r4
	ldrh r0, [r5, #0x32]
	adds r1, r5, #0
	adds r1, #0x23
	ldrb r1, [r1]
	bl sub_0807CC88
	adds r2, r0, #0
	adds r3, r6, #0
	cmp r2, #0
	bne _080716EC
	adds r1, r5, #0
	adds r1, #0x21
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080716DE
	strb r2, [r1]
_080716DE:
	ldrb r0, [r1]
	mov r2, sp
	adds r1, r2, r0
	ldrh r0, [r5, #0x30]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #6]
_080716EC:
	lsls r1, r3, #6
	adds r1, r1, r4
	ldrh r0, [r1, #0x32]
	adds r0, #1
	strh r0, [r1, #0x32]
_080716F6:
	adds r6, #1
	movs r0, #1
	add r8, r0
	lsls r0, r7, #0x19
	lsrs r7, r0, #0x18
	mov r2, r8
	cmp r2, #3
	ble _080716A6
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08071714: .4byte 0x080AFF90
_08071718: .4byte 0x03007010
_0807171C: .4byte 0x03002C30
	.syntax divided
