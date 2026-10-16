	.syntax unified

	thumb_func_start update_sprite_animations_0806B334
	.global update_sprite_animations_0806B334
update_sprite_animations_0806B334: @ 0x0806B334
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r7, _0806B394 @ =0x03002C30
_0806B33A:
	lsls r0, r6, #6
	adds r4, r0, r7
	movs r0, #0x21
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806B384
	ldr r5, _0806B398 @ =0x08485D5C
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r5
	movs r1, #2
	ldrsh r2, [r0, r1]
	adds r3, r4, #0
	adds r3, #0x27
	ldrb r0, [r3]
	adds r1, r0, #1
	strb r1, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r2, r0
	bgt _0806B384
	movs r0, #0
	strb r0, [r3]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r0, [r0, #4]
	strb r0, [r1]
	ldrb r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r4, #6]
_0806B384:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x13
	bls _0806B33A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806B394: .4byte 0x03002C30
_0806B398: .4byte 0x08485D5C
	.syntax divided
