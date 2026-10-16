	.syntax unified

	thumb_func_start sub_080278B8
sub_080278B8: @ 0x080278B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	movs r6, #0
	ldr r0, _0802792C @ =0x030018D2
	mov sb, r0
	ldr r1, _08027930 @ =0x083B6008
	mov r8, r1
_080278CC:
	mov r1, sb
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08027904
	mov r1, r8
	ldr r0, [r1]
	adds r4, r6, #0
	adds r4, #0x21
	lsls r1, r4, #0x18
	lsrs r5, r1, #0x18
	adds r1, r5, #0
	bl process_sprite_anim_commands
	ldr r0, _08027934 @ =0x03002C30
	lsls r4, r4, #6
	adds r4, r4, r0
	adds r4, #0x22
	ldrb r0, [r4]
	cmp r0, #0xff
	bne _08027904
	adds r0, r5, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r7, #1
_08027904:
	adds r6, #1
	cmp r6, #2
	bls _080278CC
	cmp r7, #0
	beq _08027920
	bl load_all_bot_part_sprites
	bl iterate_bots_setup_battle_sprites
	ldr r1, _08027938 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08027920:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802792C: .4byte 0x030018D2
_08027930: .4byte 0x083B6008
_08027934: .4byte 0x03002C30
_08027938: .4byte 0x03001800
	.syntax divided
