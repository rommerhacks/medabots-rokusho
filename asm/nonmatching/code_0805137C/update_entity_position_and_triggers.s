	.syntax unified

	thumb_func_start update_entity_position_and_triggers
update_entity_position_and_triggers: @ 0x08053D94
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r2, _08053F5C @ =0x03005404
	mov sb, r2
	mov r3, sb
	adds r3, #4
	bl get_state_float_as_int
	ldr r3, _08053F60 @ =0x03002C30
	mov r8, r3
	movs r4, #0x8c
	lsls r4, r4, #1
	add r4, sb
	mov ip, r4
	ldr r2, [r4]
	ldr r0, _08053F64 @ =0x03006D30
	ldr r7, [r0]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #8
	adds r1, r1, r7
	movs r6, #0x83
	lsls r6, r6, #2
	adds r2, r1, r6
	movs r5, #0xb7
	lsls r5, r5, #2
	adds r0, r1, r5
	ldr r4, [r2]
	adds r0, r0, r4
	ldrb r2, [r0]
	lsls r2, r2, #6
	add r2, r8
	mov r0, sb
	ldr r3, [r0]
	lsls r4, r4, #1
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r3, r3, r0
	strh r3, [r2, #2]
	mov r2, ip
	ldr r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r6, r0, r6
	adds r5, r0, r5
	ldr r3, [r6]
	adds r5, r5, r3
	ldrb r2, [r5]
	lsls r2, r2, #6
	add r2, r8
	mov r4, sb
	ldr r1, [r4, #4]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r0, r4
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r1, r1, r0
	strh r1, [r2, #4]
	mov r0, ip
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r1, r0, r7
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08053E60
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r1, r3
	mov r4, sb
	ldrb r2, [r4, #4]
	ldrb r0, [r0]
	cmp r2, r0
	blo _08053E60
	adds r3, #4
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	bhi _08053E60
	movs r0, #2
	str r0, [r1]
	mov r4, ip
	ldr r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, #0xac
	movs r1, #0
	str r1, [r0]
_08053E60:
	ldr r4, _08053F68 @ =0x03005350
	movs r0, #0xe6
	lsls r0, r0, #1
	adds r6, r4, r0
	ldr r1, [r6]
	ldr r2, _08053F64 @ =0x03006D30
	ldr r5, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r3, r0, r5
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r0, [r0]
	mov r8, r2
	cmp r0, #0
	beq _08053EC2
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldr r0, _08053F6C @ =0x000001FF
	ands r1, r0
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _08053EC2
	adds r2, #4
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08053EC2
	movs r0, #2
	str r0, [r3]
	ldr r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r5
	movs r2, #0
	str r2, [r0, #0x64]
	ldr r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r5
	str r2, [r0, #0x1c]
_08053EC2:
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r7, r4, r3
	ldr r1, [r7]
	mov r4, r8
	ldr r6, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r5, r0, r6
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08053F50
	adds r4, r5, #0
	adds r4, #0xa0
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	bl int_to_softfloat
	adds r1, r0, #0
	ldr r0, [r4]
	bl soft_float_gt
	cmp r0, #0
	bgt _08053F12
	movs r0, #2
	str r0, [r5]
	ldr r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xac
	movs r1, #0
	str r1, [r0]
_08053F12:
	ldr r1, [r7]
	mov r3, r8
	ldr r6, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r5, r0, r6
	adds r4, r5, #0
	adds r4, #0xa0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl int_to_softfloat
	adds r1, r0, #0
	ldr r0, [r4]
	bl softfloat_compare_ge
	cmp r0, #0
	blt _08053F50
	movs r0, #2
	str r0, [r5]
	ldr r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xac
	movs r1, #0
	str r1, [r0]
_08053F50:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053F5C: .4byte 0x03005404
_08053F60: .4byte 0x03002C30
_08053F64: .4byte 0x03006D30
_08053F68: .4byte 0x03005350
_08053F6C: .4byte 0x000001FF
	.syntax divided
