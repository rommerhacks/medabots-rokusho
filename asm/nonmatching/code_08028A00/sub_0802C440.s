	.syntax unified

	thumb_func_start sub_0802C440
sub_0802C440: @ 0x0802C440
	push {r4, r5, r6, r7, lr}
	ldr r4, _0802C4E0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	adds r7, r4, #0
	adds r7, #0xd2
	ldr r6, _0802C4E4 @ =0x083B6080
	movs r4, #0x84
	lsls r4, r4, #0x16
_0802C460:
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C470
	ldr r0, [r6]
	lsrs r1, r4, #0x18
	bl process_sprite_anim_commands
_0802C470:
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	bls _0802C460
	ldr r4, _0802C4E0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r7, _0802C4E8 @ =0x083B6084
	movs r6, #0x90
	lsls r6, r6, #0x16
	adds r4, #0xd6
_0802C498:
	ldrh r0, [r4]
	cmp r0, #0
	beq _0802C4A6
	ldr r0, [r7]
	lsrs r1, r6, #0x18
	bl process_sprite_anim_commands
_0802C4A6:
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r6, r6, r1
	adds r4, #2
	adds r5, #1
	cmp r5, #2
	bls _0802C498
	ldr r0, _0802C4EC @ =0x03002C30
	ldr r1, _0802C4F0 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0802C4DA
	movs r0, #0x21
	movs r1, #6
	bl clear_battle_sprite_slot
	ldr r0, _0802C4F4 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0802C4E0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802C4DA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C4E0: .4byte 0x03001800
_0802C4E4: .4byte 0x083B6080
_0802C4E8: .4byte 0x083B6084
_0802C4EC: .4byte 0x03002C30
_0802C4F0: .4byte 0x00000862
_0802C4F4: .4byte 0x03000440
	.syntax divided
