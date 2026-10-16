	.syntax unified

	thumb_func_start sub_0804D9AC
	.global sub_0804D9AC
sub_0804D9AC: @ 0x0804D9AC
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x30
	bl clear_battle_sprite_entry
	movs r0, #0x5a
	bl clear_battle_sprite_entry
	lsls r0, r4, #6
	ldr r5, _0804DAE4 @ =0x03002C30
	adds r0, r0, r5
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r2, #0x40
	bl memcpy_u8
	lsls r4, r4, #2
	ldr r1, _0804DAE8 @ =0x030055A0
	adds r4, r4, r1
	adds r1, #0xc0
	adds r0, r4, #0
	movs r2, #4
	bl memcpy_u8
	ldr r6, _0804DAEC @ =0x030057E0
	ldr r3, _0804DAF0 @ =0x00000C76
	adds r0, r6, r3
	movs r1, #1
	mov r8, r1
	mov r2, r8
	strb r2, [r0]
	subs r3, #0x74
	adds r3, r3, r5
	mov sl, r3
	ldr r1, _0804DAF4 @ =0x03004C30
	ldrh r0, [r1]
	ldrh r2, [r3]
	adds r0, r0, r2
	ldr r3, _0804DAF8 @ =0x00000C6E
	adds r2, r6, r3
	strh r0, [r2]
	ldr r0, _0804DAFC @ =0x00000C04
	adds r0, r0, r5
	mov sb, r0
	ldrh r0, [r1, #2]
	mov r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r3, #2
	adds r4, r6, r3
	strh r0, [r4]
	ldrh r0, [r2]
	bl sub_080526F0
	ldr r2, _0804DB00 @ =0x00000C72
	adds r1, r6, r2
	strb r0, [r1]
	ldrh r0, [r4]
	bl sub_08052714
	ldr r3, _0804DB04 @ =0x00000C73
	adds r1, r6, r3
	strb r0, [r1]
	ldr r0, _0804DB08 @ =0x00000C2B
	adds r4, r5, r0
	ldrb r1, [r4]
	ldr r2, _0804DB0C @ =0x00000C84
	adds r0, r6, r2
	strb r1, [r0]
	bl sub_08051E8C
	ldrb r1, [r4]
	ldr r3, _0804DB10 @ =0x00000C21
	adds r0, r5, r3
	lsls r1, r1, #2
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080502B4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x30
	bl sub_080493D4
	ldr r1, _0804DB14 @ =0x0000CC0C
	mov r0, r8
	str r0, [sp]
	movs r0, #0x5a
	movs r2, #0x90
	movs r3, #0xe
	bl init_battle_sprite_entry_08048818
	mov r2, sl
	ldrh r1, [r2]
	ldr r3, _0804DB18 @ =0x00001682
	adds r0, r5, r3
	strh r1, [r0]
	mov r1, sb
	ldrh r0, [r1]
	subs r0, #5
	ldr r2, _0804DB1C @ =0x00001684
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _0804DB20 @ =0x00000C0C
	adds r0, r5, r3
	ldr r1, [r0]
	asrs r1, r1, #8
	ldr r0, _0804DB24 @ =0x0000168C
	adds r2, r5, r0
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r0, #5
	ldr r2, _0804DB28 @ =0x00001690
	adds r5, r5, r2
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r1, r0
	str r1, [r5]
	movs r0, #1
	bl update_battle_direction_indicator
	ldr r3, _0804DB2C @ =0x00000C5D
	adds r1, r6, r3
	ldrb r0, [r1]
	ldr r2, _0804DB30 @ =0x00000C5E
	adds r6, r6, r2
	strb r0, [r6]
	movs r0, #0xdf
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804DAE4: .4byte 0x03002C30
_0804DAE8: .4byte 0x030055A0
_0804DAEC: .4byte 0x030057E0
_0804DAF0: .4byte 0x00000C76
_0804DAF4: .4byte 0x03004C30
_0804DAF8: .4byte 0x00000C6E
_0804DAFC: .4byte 0x00000C04
_0804DB00: .4byte 0x00000C72
_0804DB04: .4byte 0x00000C73
_0804DB08: .4byte 0x00000C2B
_0804DB0C: .4byte 0x00000C84
_0804DB10: .4byte 0x00000C21
_0804DB14: .4byte 0x0000CC0C
_0804DB18: .4byte 0x00001682
_0804DB1C: .4byte 0x00001684
_0804DB20: .4byte 0x00000C0C
_0804DB24: .4byte 0x0000168C
_0804DB28: .4byte 0x00001690
_0804DB2C: .4byte 0x00000C5D
_0804DB30: .4byte 0x00000C5E
	.syntax divided
