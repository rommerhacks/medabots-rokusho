	.syntax unified

	thumb_func_start sub_08021C94
sub_08021C94: @ 0x08021C94
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _08021D88 @ =0x03000440
	adds r0, #0x86
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r0, [r0]
	bl sub_080353AC
	movs r4, #0
	movs r0, #0x5d
	mov r8, r0
	movs r7, #0x5c
	movs r6, #0x5b
	movs r5, #0x5a
_08021CB8:
	ldr r1, _08021D8C @ =0x03000590
	mov sb, r1
	lsls r0, r4, #8
	add r0, sb
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08021CE8
	adds r0, r5, #0
	movs r1, #0
	bl advance_sprite_anim_frame
	adds r0, r6, #0
	movs r1, #0
	bl advance_sprite_anim_frame
	adds r0, r7, #0
	movs r1, #0
	bl advance_sprite_anim_frame
	mov r0, r8
	movs r1, #0
	bl advance_sprite_anim_frame
_08021CE8:
	movs r2, #4
	add r8, r2
	adds r7, #4
	adds r6, #4
	adds r5, #4
	adds r4, #1
	cmp r4, #5
	bls _08021CB8
	ldr r4, _08021D90 @ =0x083B5F80
	adds r4, #0x8c
	ldr r0, [r4]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, [r4]
	movs r1, #0x22
	bl process_sprite_anim_commands
	ldr r0, [r4]
	movs r1, #0x23
	bl process_sprite_anim_commands
	ldr r1, _08021D94 @ =0x03002C30
	ldr r2, _08021D98 @ =0x00000862
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08021D7A
	movs r4, #0
	ldr r0, _08021D9C @ =0x03001C04
	mov r8, r0
	movs r2, #0
	ldr r0, _08021DA0 @ =0x00001763
	adds r0, r0, r1
	mov ip, r0
	ldr r0, _08021DA4 @ =0x00001723
	adds r7, r1, r0
	subs r0, #0x40
	adds r6, r1, r0
	subs r0, #0x40
	adds r5, r1, r0
	mov r3, sb
	adds r3, #0x40
	movs r1, #0x80
	lsls r1, r1, #1
_08021D42:
	ldrb r0, [r3]
	cmp r0, #0
	beq _08021D52
	strb r2, [r5]
	strb r2, [r6]
	strb r2, [r7]
	mov r0, ip
	strb r2, [r0]
_08021D52:
	add ip, r1
	adds r7, r7, r1
	adds r6, r6, r1
	adds r5, r5, r1
	adds r3, r3, r1
	adds r4, #1
	cmp r4, #5
	bls _08021D42
	movs r0, #0
	mov r1, r8
	strh r0, [r1, #2]
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r1, _08021DA8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08021D7A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021D88: .4byte 0x03000440
_08021D8C: .4byte 0x03000590
_08021D90: .4byte 0x083B5F80
_08021D94: .4byte 0x03002C30
_08021D98: .4byte 0x00000862
_08021D9C: .4byte 0x03001C04
_08021DA0: .4byte 0x00001763
_08021DA4: .4byte 0x00001723
_08021DA8: .4byte 0x03001800
_08021DAC:
	.byte 0x0E, 0x49, 0x0B, 0x1C
	.byte 0x89, 0x33, 0x18, 0x78, 0xC0, 0x00, 0x40, 0x18, 0x2A, 0x30, 0x00, 0x22, 0x02, 0x70, 0x18, 0x78
	.byte 0xC0, 0x00, 0x40, 0x18, 0x2B, 0x30, 0x02, 0x70, 0x18, 0x78, 0xC0, 0x00, 0x40, 0x18, 0x2C, 0x30
	.byte 0x02, 0x70, 0x18, 0x78, 0xC0, 0x00, 0x40, 0x18, 0x2D, 0x30, 0x02, 0x70, 0xAA, 0x31, 0x08, 0x78
	.byte 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03, 0x04, 0x49, 0x0A, 0x1C
	.byte 0xA6, 0x32, 0x25, 0x20, 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47
	.byte 0x00, 0x18, 0x00, 0x03
	.syntax divided
