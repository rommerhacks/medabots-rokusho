	.syntax unified

	thumb_func_start battle_setup_part_sprite
battle_setup_part_sprite: @ 0x08019D9C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	mov ip, r2
	ldr r5, _08019E0C @ =0x03002C30
	lsls r0, r7, #1
	adds r0, r0, r7
	adds r1, #0x46
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r6, r0, r5
	ldr r0, _08019E10 @ =0x03001800
	adds r0, #0x3c
	ldrb r2, [r0]
	adds r2, #2
	lsls r2, r2, #0xa
	ldr r1, _08019E14 @ =0xFFFFC004
	adds r0, r1, #0
	movs r1, #0
	orrs r2, r0
	strh r2, [r6]
	strb r1, [r6, #0x1c]
	ldr r4, _08019E18 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0xf0
	ldrb r0, [r0]
	adds r0, #0xb
	strb r0, [r6, #0xa]
	strb r3, [r6, #0xb]
	lsls r0, r7, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r5
	adds r3, r4, #0
	adds r3, #0xef
	ldr r5, _08019E1C @ =0x0000FFFC
	adds r1, r5, #0
	ldrb r3, [r3]
	adds r1, r1, r3
	ldrh r0, [r0, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, _08019E20 @ =0x0000EFFF
	ands r2, r0
	strh r2, [r6]
	mov r0, ip
	cmp r0, #1
	beq _08019E34
	cmp r0, #1
	blo _08019E24
	cmp r0, #2
	beq _08019E44
	b _08019E54
	.align 2, 0
_08019E0C: .4byte 0x03002C30
_08019E10: .4byte 0x03001800
_08019E14: .4byte 0xFFFFC004
_08019E18: .4byte 0x03000440
_08019E1C: .4byte 0x0000FFFC
_08019E20: .4byte 0x0000EFFF
_08019E24:
	ldr r1, _08019E30 @ =0x03000590
	lsls r0, r7, #8
	adds r0, r0, r1
	adds r0, #0xc4
	b _08019E4C
	.align 2, 0
_08019E30: .4byte 0x03000590
_08019E34:
	ldr r1, _08019E40 @ =0x03000590
	lsls r0, r7, #8
	adds r0, r0, r1
	adds r0, #0xc9
	b _08019E4C
	.align 2, 0
_08019E40: .4byte 0x03000590
_08019E44:
	ldr r1, _08019EB0 @ =0x03000590
	lsls r0, r7, #8
	adds r0, r0, r1
	adds r0, #0xdf
_08019E4C:
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x23
	strb r1, [r0]
_08019E54:
	adds r0, r4, #0
	adds r0, #0xee
	ldrb r5, [r0]
	adds r1, r5, #0
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08019E6E
	ldr r2, _08019EB4 @ =0xFFFFFF00
	adds r0, r2, #0
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_08019E6E:
	adds r0, r7, #0
	bl sub_08015924
	cmp r0, #0
	beq _08019EBC
	ldr r2, _08019EB8 @ =0x03002C30
	lsls r0, r7, #1
	adds r0, r0, r7
	mov r1, r8
	adds r1, #0x46
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r3, r0, r2
	lsls r0, r7, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	subs r0, r0, r5
	strh r0, [r3, #2]
	adds r0, r4, #0
	adds r0, #0xf1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08019EE0
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	b _08019EE0
	.align 2, 0
_08019EB0: .4byte 0x03000590
_08019EB4: .4byte 0xFFFFFF00
_08019EB8: .4byte 0x03002C30
_08019EBC:
	ldr r3, _08019EEC @ =0x03002C30
	lsls r1, r7, #1
	adds r1, r1, r7
	mov r0, r8
	adds r0, #0x46
	adds r1, r1, r0
	lsls r1, r1, #6
	adds r1, r1, r3
	lsls r2, r7, #8
	movs r0, #0xba
	lsls r0, r0, #5
	adds r2, r2, r0
	adds r2, r2, r3
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r2, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
_08019EE0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08019EEC: .4byte 0x03002C30
	.syntax divided
