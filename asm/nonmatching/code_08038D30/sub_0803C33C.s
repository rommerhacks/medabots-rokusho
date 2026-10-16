	.syntax unified

	thumb_func_start sub_0803C33C
sub_0803C33C: @ 0x0803C33C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0803C368 @ =0x03002C30
	mov r8, r0
	ldr r0, _0803C36C @ =0x03000440
	ldr r1, _0803C370 @ =0x0000012F
	adds r7, r0, r1
	ldrb r3, [r7]
	lsls r0, r3, #6
	mov r6, r8
	adds r2, r0, r6
	adds r1, r2, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803C374
	subs r0, #1
	strb r0, [r1]
	b _0803C5E0
	.align 2, 0
_0803C368: .4byte 0x03002C30
_0803C36C: .4byte 0x03000440
_0803C370: .4byte 0x0000012F
_0803C374:
	ldr r1, _0803C3E0 @ =0x083AFAAC
	ldr r5, _0803C3E4 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0x38
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov sb, r0
	adds r0, r2, #0
	adds r0, #0x25
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bhi _0803C484
	movs r0, #2
	ldrsh r4, [r2, r0]
	adds r0, r3, #0
	bl update_sprite_animation_position
	ldrb r1, [r7]
	lsls r1, r1, #6
	add r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	subs r4, r0, r4
	ldrh r0, [r1, #0x30]
	adds r0, r0, r4
	strh r0, [r1, #0x30]
	ldrb r0, [r7]
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	ldrh r0, [r2, #0x30]
	cmp r0, #0x78
	bhi _0803C3C0
	b _0803C5E0
_0803C3C0:
	movs r3, #0xc4
	lsls r3, r3, #1
	cmp r0, r3
	bhi _0803C3E8
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r4, r0, #0
	subs r4, #0x78
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, r0, r4
	adds r3, #0x77
	b _0803C402
	.align 2, 0
_0803C3E0: .4byte 0x083AFAAC
_0803C3E4: .4byte 0x03001800
_0803C3E8:
	ldrh r1, [r2, #0x30]
	ldr r6, _0803C454 @ =0xFFFFFE78
	adds r0, r1, r6
	cmp r0, r4
	bhs _0803C46C
	adds r0, r4, r3
	subs r4, r0, r1
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, r0, r4
	ldr r3, _0803C458 @ =0x000001FF
_0803C402:
	adds r2, r3, #0
	ands r0, r2
	strh r0, [r1]
	movs r6, #0xac
	lsls r6, r6, #1
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, r0, r4
	ands r0, r2
	strh r0, [r1]
	ldrb r1, [r7]
	lsls r1, r1, #6
	add r1, r8
	ldrh r0, [r1, #2]
	subs r0, r0, r4
	ands r0, r2
	strh r0, [r1, #2]
	movs r0, #1
	adds r1, r4, #0
	bl battle_sprite_rotate_angles
	ldr r1, _0803C45C @ =0x03005000
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C460 @ =0x03004C30
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C464 @ =0x0300057C
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C468 @ =0x03001C04
	mov r0, sb
	lsrs r4, r0
	ldrh r2, [r1]
	adds r0, r4, r2
	strh r0, [r1]
	b _0803C5E0
	.align 2, 0
_0803C454: .4byte 0xFFFFFE78
_0803C458: .4byte 0x000001FF
_0803C45C: .4byte 0x03005000
_0803C460: .4byte 0x03004C30
_0803C464: .4byte 0x0300057C
_0803C468: .4byte 0x03001C04
_0803C46C:
	ldr r0, _0803C480 @ =0x0000018F
	cmp r1, r0
	bhi _0803C474
	b _0803C5E0
_0803C474:
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	b _0803C5E0
	.align 2, 0
_0803C480: .4byte 0x0000018F
_0803C484:
	adds r0, r1, #0
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bls _0803C492
	b _0803C5E0
_0803C492:
	movs r6, #2
	ldrsh r4, [r2, r6]
	adds r0, r3, #0
	bl update_sprite_animation_position
	ldrb r1, [r7]
	lsls r1, r1, #6
	add r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	ldrh r0, [r1, #0x30]
	subs r0, r0, r4
	ldr r3, _0803C52C @ =0x000001FF
	adds r6, r3, #0
	ands r0, r6
	strh r0, [r1, #0x30]
	ldrb r0, [r7]
	lsls r0, r0, #6
	mov r1, r8
	adds r3, r0, r1
	ldrh r1, [r3, #0x30]
	adds r2, r1, #0
	subs r2, #0x78
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x78
	bhi _0803C4CC
	b _0803C5E0
_0803C4CC:
	cmp r2, #0xef
	bls _0803C540
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r0, #0x78
	subs r4, r0, r1
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, r0, r4
	ands r0, r6
	strh r0, [r1]
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	ands r0, r6
	strh r0, [r1]
	ldrb r1, [r7]
	lsls r1, r1, #6
	add r1, r8
	ldrh r0, [r1, #2]
	adds r0, r0, r4
	ands r0, r6
	strh r0, [r1, #2]
	movs r0, #0
	adds r1, r4, #0
	bl battle_sprite_rotate_angles
	ldr r1, _0803C530 @ =0x03005000
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C534 @ =0x03004C30
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C538 @ =0x0300057C
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C53C @ =0x03001C04
	mov r2, sb
	lsrs r4, r2
	b _0803C5A4
	.align 2, 0
_0803C52C: .4byte 0x000001FF
_0803C530: .4byte 0x03005000
_0803C534: .4byte 0x03004C30
_0803C538: .4byte 0x0300057C
_0803C53C: .4byte 0x03001C04
_0803C540:
	ldr r0, _0803C5AC @ =0x00000167
	cmp r1, r0
	bhi _0803C5C4
	adds r0, #1
	subs r0, r0, r1
	cmp r0, r4
	bhs _0803C5C4
	ldr r3, _0803C5B0 @ =0xFFFFFE98
	adds r0, r4, r3
	adds r4, r0, r1
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	ands r0, r6
	strh r0, [r1]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, r0, r4
	ands r0, r6
	strh r0, [r1]
	ldrb r1, [r7]
	lsls r1, r1, #6
	add r1, r8
	ldrh r0, [r1, #2]
	adds r0, r0, r4
	ands r0, r6
	strh r0, [r1, #2]
	movs r0, #0
	adds r1, r4, #0
	bl battle_sprite_rotate_angles
	ldr r1, _0803C5B4 @ =0x03005000
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C5B8 @ =0x03004C30
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C5BC @ =0x0300057C
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C5C0 @ =0x03001C04
	mov r3, sb
	lsrs r4, r3
_0803C5A4:
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	b _0803C5E0
	.align 2, 0
_0803C5AC: .4byte 0x00000167
_0803C5B0: .4byte 0xFFFFFE98
_0803C5B4: .4byte 0x03005000
_0803C5B8: .4byte 0x03004C30
_0803C5BC: .4byte 0x0300057C
_0803C5C0: .4byte 0x03001C04
_0803C5C4:
	movs r0, #0xb0
	lsls r0, r0, #1
	cmp r1, r0
	bhi _0803C5E0
	ldr r1, _0803C5EC @ =0x03002C30
	ldr r0, _0803C5F0 @ =0x03000440
	ldr r6, _0803C5F4 @ =0x0000012F
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
_0803C5E0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C5EC: .4byte 0x03002C30
_0803C5F0: .4byte 0x03000440
_0803C5F4: .4byte 0x0000012F
	.syntax divided
