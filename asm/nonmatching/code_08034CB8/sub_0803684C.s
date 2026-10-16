	.syntax unified

	thumb_func_start sub_0803684C
	.global sub_0803684C
sub_0803684C: @ 0x0803684C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r7, #1
	movs r6, #0
_08036858:
	ldr r1, _080368A0 @ =0x03002C30
	mov r0, r8
	adds r3, r0, r6
	lsls r0, r3, #6
	adds r4, r0, r1
	ldrh r2, [r4]
	cmp r2, #0
	beq _080368B2
	adds r1, r4, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	bne _080368AC
	ldr r1, _080368A4 @ =0x00008004
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r4]
	movs r0, #0xe
	strb r0, [r4, #0xa]
	ldr r0, _080368A8 @ =0x083B5F80
	ldr r0, [r0, #0x74]
	lsls r1, r3, #0x18
	lsrs r5, r1, #0x18
	adds r1, r5, #0
	bl process_sprite_anim_commands
	adds r0, r4, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080368B0
	adds r0, r5, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	b _080368B2
	.align 2, 0
_080368A0: .4byte 0x03002C30
_080368A4: .4byte 0x00008004
_080368A8: .4byte 0x083B5F80
_080368AC:
	subs r0, #1
	strb r0, [r1]
_080368B0:
	movs r7, #0
_080368B2:
	adds r6, #1
	cmp r6, #3
	bls _08036858
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
