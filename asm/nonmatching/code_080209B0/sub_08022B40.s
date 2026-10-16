	.syntax unified

	thumb_func_start sub_08022B40
sub_08022B40: @ 0x08022B40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08022C10 @ =0x083B5F80
	adds r0, #0xfc
	ldr r0, [r0]
	movs r1, #0x25
	bl process_sprite_anim_commands
	movs r6, #0
	ldr r0, _08022C14 @ =0x03002C30
	mov r8, r0
	ldr r7, _08022C18 @ =0x00000842
	add r7, r8
	ldr r4, _08022C1C @ =0x0000086B
	add r4, r8
_08022B64:
	movs r1, #0x21
	adds r1, r1, r6
	mov sb, r1
	cmp r6, #3
	bhi _08022BA2
	ldrb r1, [r4, #1]
	ldrb r2, [r4]
	ldr r0, _08022C20 @ =0x03001800
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r0, r0, r3
	add r0, r8
	movs r5, #2
	ldrsh r3, [r0, r5]
	movs r5, #4
	ldrsh r0, [r0, r5]
	subs r0, #4
	str r0, [sp]
	add r0, sp, #4
	bl calc_polar_to_screen_coords
	ldr r0, [sp, #4]
	strh r0, [r7]
	asrs r0, r0, #0x10
	strh r0, [r7, #2]
	ldrb r0, [r4, #1]
	adds r0, #4
	strb r0, [r4, #1]
_08022BA2:
	mov r1, sb
	lsls r0, r1, #6
	mov r5, r8
	adds r3, r0, r5
	adds r2, r3, #0
	adds r2, #0x2d
	ldrb r0, [r2]
	adds r1, r0, #1
	strb r1, [r2]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08022C14 @ =0x03002C30
	cmp r0, #0x5a
	bls _08022BDC
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _08022BD0
	adds r1, r3, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08022BD0:
	ldrb r0, [r3, #8]
	subs r0, #2
	strb r0, [r3, #8]
	ldrb r0, [r3, #9]
	subs r0, #2
	strb r0, [r3, #9]
_08022BDC:
	adds r7, #0x40
	adds r4, #0x40
	adds r6, #1
	cmp r6, #4
	bls _08022B64
	ldr r1, _08022C24 @ =0x00000849
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08022C02
	movs r0, #0x21
	movs r1, #5
	bl clear_battle_sprite_slot
	ldr r1, _08022C20 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08022C02:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022C10: .4byte 0x083B5F80
_08022C14: .4byte 0x03002C30
_08022C18: .4byte 0x00000842
_08022C1C: .4byte 0x0000086B
_08022C20: .4byte 0x03001800
_08022C24: .4byte 0x00000849
	.syntax divided
