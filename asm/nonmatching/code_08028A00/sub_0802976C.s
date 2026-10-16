	.syntax unified

	thumb_func_start sub_0802976C
sub_0802976C: @ 0x0802976C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	movs r4, #0
	ldr r0, _080297DC @ =0x030018D2
	mov sb, r0
	movs r6, #0x84
	lsls r6, r6, #4
	movs r5, #0x84
	lsls r5, r5, #0x16
	ldr r1, _080297E0 @ =0x083B6070
	mov r8, r1
_08029788:
	mov r1, sb
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080297AA
	mov r1, r8
	ldr r0, [r1]
	lsrs r1, r5, #0x18
	bl process_sprite_anim_commands
	ldr r0, _080297E4 @ =0x03002C30
	adds r0, r6, r0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080297AA
	movs r7, #1
_080297AA:
	adds r6, #0x40
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #2
	bls _08029788
	cmp r7, #0
	beq _080297CE
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r1, _080297E8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080297CE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080297DC: .4byte 0x030018D2
_080297E0: .4byte 0x083B6070
_080297E4: .4byte 0x03002C30
_080297E8: .4byte 0x03001800
	.syntax divided
