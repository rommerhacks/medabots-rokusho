	.syntax unified

	thumb_func_start sub_0802E8D4
sub_0802E8D4: @ 0x0802E8D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
	movs r5, #0
	ldr r0, _0802E90C @ =0x030018D2
	mov r8, r0
	ldr r0, _0802E910 @ =0x03002C30
	movs r6, #0xa0
	lsls r6, r6, #0x14
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r4, r0, r1
_0802E8EE:
	mov r1, r8
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E91E
	ldrb r0, [r4, #8]
	cmp r0, #2
	bne _0802E914
	movs r7, #1
	lsrs r0, r6, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	b _0802E91E
	.align 2, 0
_0802E90C: .4byte 0x030018D2
_0802E910: .4byte 0x03002C30
_0802E914:
	subs r0, #2
	strb r0, [r4, #8]
	ldrb r0, [r4, #9]
	subs r0, #2
	strb r0, [r4, #9]
_0802E91E:
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r6, r6, r0
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802E8EE
	cmp r7, #0
	beq _0802E93A
	ldr r1, _0802E944 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802E93A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E944: .4byte 0x03001800
	.syntax divided
