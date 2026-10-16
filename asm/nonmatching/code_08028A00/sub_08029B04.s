	.syntax unified

	thumb_func_start sub_08029B04
sub_08029B04: @ 0x08029B04
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	movs r4, #0
	ldr r0, _08029B70 @ =0x030018D2
	mov sb, r0
	ldr r1, _08029B74 @ =0x083B6100
	mov r8, r1
	ldr r0, _08029B78 @ =0x03002C30
	ldr r1, _08029B7C @ =0x00000862
	adds r6, r0, r1
	movs r5, #0x84
	lsls r5, r5, #0x16
_08029B22:
	mov r1, sb
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029B3E
	mov r1, r8
	ldr r0, [r1]
	lsrs r1, r5, #0x18
	bl process_sprite_anim_commands
	ldrb r0, [r6]
	cmp r0, #0xff
	bne _08029B3E
	movs r7, #1
_08029B3E:
	adds r6, #0x40
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #2
	bls _08029B22
	cmp r7, #0
	beq _08029B62
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r1, _08029B80 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08029B62:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029B70: .4byte 0x030018D2
_08029B74: .4byte 0x083B6100
_08029B78: .4byte 0x03002C30
_08029B7C: .4byte 0x00000862
_08029B80: .4byte 0x03001800
	.syntax divided
