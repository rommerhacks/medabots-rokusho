	.syntax unified

	thumb_func_start update_sprite_special_effects
update_sprite_special_effects: @ 0x0806DC80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
_0806DC88:
	ldr r0, _0806DCD4 @ =0x03002C30
	lsls r1, r7, #6
	adds r5, r1, r0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r6]
	cmp r0, #0
	beq _0806DCFA
	ldrh r0, [r5, #0x1a]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	strh r0, [r5, #0x1a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _0806DCD8 @ =0x08485F14
	ldrb r1, [r6]
	subs r4, r1, #1
	adds r2, r4, r2
	ldrb r1, [r2]
	bl sub_0807CC88
	cmp r0, #0
	bne _0806DCFA
	ldr r0, _0806DCDC @ =0x08485EF4
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r7, #0
	bl _call_via_r1
	cmp r0, #1
	beq _0806DCFA
	cmp r0, #1
	bgt _0806DCE0
	cmp r0, #0
	beq _0806DCE6
	b _0806DCFA
	.align 2, 0
_0806DCD4: .4byte 0x03002C30
_0806DCD8: .4byte 0x08485F14
_0806DCDC: .4byte 0x08485EF4
_0806DCE0:
	cmp r0, #0xff
	beq _0806DCF4
	b _0806DCFA
_0806DCE6:
	mov r0, r8
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0x22
	mov r1, r8
	strb r1, [r0]
	b _0806DCFA
_0806DCF4:
	adds r0, r7, #0
	bl sub_0806B584
_0806DCFA:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #4
	bls _0806DC88
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
