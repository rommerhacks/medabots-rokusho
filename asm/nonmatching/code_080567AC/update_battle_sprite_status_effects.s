	.syntax unified

	thumb_func_start update_battle_sprite_status_effects
	.global update_battle_sprite_status_effects
update_battle_sprite_status_effects: @ 0x080567AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _08056830 @ =0x03005350
	adds r0, r1, #0
	adds r0, #0xf0
	ldr r0, [r0]
	mov ip, r1
	cmp r0, #0
	beq _0805688C
	movs r1, #0
	ldr r6, _08056834 @ =0x03002C30
	ldr r7, _08056838 @ =0x03006D30
	ldr r0, _0805683C @ =0x0000F3FF
	mov sb, r0
	movs r2, #0x86
	lsls r2, r2, #2
	add r2, ip
	mov sl, r2
_080567D6:
	movs r4, #0
	lsls r0, r1, #1
	adds r2, r1, #1
	mov r8, r2
	adds r0, r0, r1
	lsls r5, r0, #8
_080567E2:
	ldr r0, [r7]
	adds r0, r5, r0
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r2, _08056834 @ =0x03002C30
	adds r3, r0, r2
	ldr r0, [r3, #0x14]
	asrs r2, r0, #8
	ldr r0, _08056840 @ =0x030053EC
	ldr r1, [r0]
	cmp r2, r1
	ble _08056844
	mov r1, sl
	ldr r0, [r1]
	strb r0, [r3, #0xb]
	ldr r2, [r7]
	adds r2, r5, r2
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r2, r2, r4
	ldrb r1, [r2]
	lsls r1, r1, #6
	adds r1, r1, r6
	ldrh r3, [r1]
	mov r0, sb
	ands r0, r3
	strh r0, [r1]
	ldrb r0, [r2]
	lsls r0, r0, #6
	adds r0, r0, r6
	movs r1, #0x88
	lsls r1, r1, #2
	b _08056876
	.align 2, 0
_08056830: .4byte 0x03005350
_08056834: .4byte 0x03002C30
_08056838: .4byte 0x03006D30
_0805683C: .4byte 0x0000F3FF
_08056840: .4byte 0x030053EC
_08056844:
	movs r0, #0x85
	lsls r0, r0, #2
	add r0, ip
	ldr r0, [r0]
	subs r1, r1, r2
	adds r0, r0, r1
	strb r0, [r3, #0xb]
	ldr r2, [r7]
	adds r2, r5, r2
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r2, r2, r4
	ldrb r1, [r2]
	lsls r1, r1, #6
	adds r1, r1, r6
	ldrh r3, [r1]
	mov r0, sb
	ands r0, r3
	strh r0, [r1]
	ldrb r0, [r2]
	lsls r0, r0, #6
	adds r0, r0, r6
	movs r1, #0x87
	lsls r1, r1, #2
_08056876:
	add r1, ip
	ldr r1, [r1]
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	adds r4, #1
	cmp r4, #3
	ble _080567E2
	mov r1, r8
	cmp r1, #0xf
	ble _080567D6
_0805688C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
