	.syntax unified

	thumb_func_start init_battle_medaforce_sprite
	.global init_battle_medaforce_sprite
init_battle_medaforce_sprite: @ 0x08052F18
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r7, _0805300C @ =0x030057E0
	ldr r1, _08053010 @ =0x00000C76
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08052FFE
	ldr r1, _08053014 @ =0x0000C804
	ldr r2, _08053018 @ =0x00000C84
	adds r6, r7, r2
	ldrb r3, [r6]
	lsls r2, r3, #1
	adds r2, r2, r3
	ldr r0, _0805301C @ =0x00000C83
	adds r5, r7, r0
	lsls r2, r2, #2
	ldrb r0, [r5]
	adds r2, r2, r0
	movs r0, #1
	mov sb, r0
	str r0, [sp]
	movs r0, #0x30
	bl init_battle_sprite_entry_08048818
	ldr r4, _08053020 @ =0x03002C30
	ldr r2, _08053024 @ =0x00000C0B
	adds r1, r4, r2
	movs r0, #0x40
	strb r0, [r1]
	ldrb r0, [r6]
	ldr r1, _08053028 @ =0x00000C2B
	adds r6, r4, r1
	strb r0, [r6]
	ldrb r0, [r5]
	bl set_battle_state_byte_c83
	ldrb r1, [r5]
	movs r0, #0x30
	bl sub_080502B4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080493D4
	ldr r2, _0805302C @ =0x00000C6E
	adds r2, r2, r7
	mov r8, r2
	ldrh r0, [r2]
	bl sub_080526F0
	ldr r2, _08053030 @ =0x00000C72
	adds r1, r7, r2
	strb r0, [r1]
	movs r0, #0xc7
	lsls r0, r0, #4
	adds r5, r7, r0
	ldrh r0, [r5]
	bl sub_08052714
	ldr r2, _08053034 @ =0x00000C73
	adds r1, r7, r2
	strb r0, [r1]
	ldrb r0, [r6]
	bl resolve_tile_from_battle_state
	movs r2, #0xc3
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x30
	bl sub_0804877C
	ldr r1, _08053038 @ =0x0000CC0C
	mov r0, sb
	str r0, [sp]
	movs r0, #0x5a
	movs r2, #0x90
	movs r3, #0xe
	bl init_battle_sprite_entry_08048818
	mov r2, r8
	ldrh r1, [r2]
	ldr r0, _0805303C @ =0x0000168C
	adds r2, r4, r0
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldrh r1, [r5]
	subs r1, #5
	ldr r0, _08053040 @ =0x00001690
	adds r2, r4, r0
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08053044 @ =0x00000C02
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _08053048 @ =0x00001682
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, _0805304C @ =0x00000C04
	adds r0, r4, r1
	ldrh r0, [r0]
	subs r0, #5
	adds r2, #2
	adds r4, r4, r2
	strh r0, [r4]
_08052FFE:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805300C: .4byte 0x030057E0
_08053010: .4byte 0x00000C76
_08053014: .4byte 0x0000C804
_08053018: .4byte 0x00000C84
_0805301C: .4byte 0x00000C83
_08053020: .4byte 0x03002C30
_08053024: .4byte 0x00000C0B
_08053028: .4byte 0x00000C2B
_0805302C: .4byte 0x00000C6E
_08053030: .4byte 0x00000C72
_08053034: .4byte 0x00000C73
_08053038: .4byte 0x0000CC0C
_0805303C: .4byte 0x0000168C
_08053040: .4byte 0x00001690
_08053044: .4byte 0x00000C02
_08053048: .4byte 0x00001682
_0805304C: .4byte 0x00000C04
	.syntax divided
