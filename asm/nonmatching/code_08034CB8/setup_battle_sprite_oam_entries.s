	.syntax unified

	thumb_func_start setup_battle_sprite_oam_entries
	.global setup_battle_sprite_oam_entries
setup_battle_sprite_oam_entries: @ 0x080369C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	movs r0, #0
	mov ip, r0
	movs r7, #0
	mov r8, r7
	ldr r4, _08036A68 @ =0x083AF480
	lsls r0, r2, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	mov sb, r0
	movs r6, #0
	ldr r5, [sp, #4]
	ldr r3, _08036A6C @ =0x03002C30
	lsls r2, r2, #2
	adds r2, r2, r4
	lsls r1, r1, #6
	adds r0, r3, #0
	adds r0, #0x23
	adds r4, r1, r0
	adds r3, r1, r3
_08036A0C:
	ldrb r0, [r5]
	cmp r0, #0xfe
	beq _08036AAE
	ldr r0, _08036A70 @ =0xFFFFC404
	strh r0, [r3]
	mov r1, r8
	strb r1, [r3, #0x1c]
	ldr r7, [sp]
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r2]
	adds r0, r0, r1
	ldr r7, _08036A74 @ =0x000001FF
	adds r1, r7, #0
	ands r0, r1
	strh r0, [r3, #2]
	mov r1, sl
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov r7, sb
	ldrh r7, [r7]
	adds r0, r0, r7
	movs r1, #0xff
	ands r0, r1
	strh r0, [r3, #4]
	movs r0, #0x80
	strb r0, [r3, #0xb]
	ldrb r0, [r5]
	movs r7, #0xb4
	lsls r7, r7, #6
	adds r1, r7, #0
	adds r0, r0, r1
	strh r0, [r3, #6]
	mov r0, r8
	strb r0, [r4]
	movs r0, #0xe
	strb r0, [r3, #0xa]
	ldr r1, [sp, #4]
	ldrb r0, [r1, #6]
	cmp r0, #3
	beq _08036A88
	cmp r0, #3
	bgt _08036A78
	cmp r0, #2
	beq _08036A7E
	b _08036A9C
	.align 2, 0
_08036A68: .4byte 0x083AF480
_08036A6C: .4byte 0x03002C30
_08036A70: .4byte 0xFFFFC404
_08036A74: .4byte 0x000001FF
_08036A78:
	cmp r0, #4
	beq _08036A90
	b _08036A9C
_08036A7E:
	ldr r7, _08036A84 @ =0x0000FFFC
	b _08036A92
	.align 2, 0
_08036A84: .4byte 0x0000FFFC
_08036A88:
	ldr r7, _08036A8C @ =0x0000FFF8
	b _08036A92
	.align 2, 0
_08036A8C: .4byte 0x0000FFF8
_08036A90:
	ldr r7, _08036AC0 @ =0x0000FFF4
_08036A92:
	adds r0, r7, #0
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	adds r0, r0, r6
	strh r0, [r3, #2]
_08036A9C:
	adds r6, #8
	adds r5, #1
	adds r4, #0x40
	adds r3, #0x40
	movs r7, #1
	add ip, r7
	mov r0, ip
	cmp r0, #4
	bls _08036A0C
_08036AAE:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036AC0: .4byte 0x0000FFF4
	.syntax divided
