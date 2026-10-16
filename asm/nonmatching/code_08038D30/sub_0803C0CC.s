	.syntax unified

	thumb_func_start sub_0803C0CC
sub_0803C0CC: @ 0x0803C0CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0803C0F8 @ =0x03002C30
	mov r8, r0
	ldr r0, _0803C0FC @ =0x03000440
	ldr r1, _0803C100 @ =0x0000012F
	adds r7, r0, r1
	ldrb r3, [r7]
	lsls r0, r3, #6
	mov r6, r8
	adds r2, r0, r6
	adds r1, r2, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803C104
	subs r0, #1
	strb r0, [r1]
	b _0803C324
	.align 2, 0
_0803C0F8: .4byte 0x03002C30
_0803C0FC: .4byte 0x03000440
_0803C100: .4byte 0x0000012F
_0803C104:
	ldr r1, _0803C170 @ =0x083AFAAC
	ldr r5, _0803C174 @ =0x03001800
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
	bhi _0803C1FC
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
	bhi _0803C150
	b _0803C324
_0803C150:
	movs r3, #0xc4
	lsls r3, r3, #1
	cmp r0, r3
	bhi _0803C178
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
	b _0803C192
	.align 2, 0
_0803C170: .4byte 0x083AFAAC
_0803C174: .4byte 0x03001800
_0803C178:
	ldrh r1, [r2, #0x30]
	ldr r6, _0803C1D4 @ =0xFFFFFE78
	adds r0, r1, r6
	cmp r0, r4
	bhs _0803C1E4
	adds r0, r4, r3
	subs r4, r0, r1
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, r0, r4
	ldr r3, _0803C1D8 @ =0x000001FF
_0803C192:
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
	ldr r1, _0803C1DC @ =0x0300057C
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C1E0 @ =0x03001C04
	mov r0, sb
	lsrs r4, r0
	ldrh r2, [r1]
	adds r0, r4, r2
	strh r0, [r1]
	b _0803C324
	.align 2, 0
_0803C1D4: .4byte 0xFFFFFE78
_0803C1D8: .4byte 0x000001FF
_0803C1DC: .4byte 0x0300057C
_0803C1E0: .4byte 0x03001C04
_0803C1E4:
	ldr r0, _0803C1F8 @ =0x0000018F
	cmp r1, r0
	bhi _0803C1EC
	b _0803C324
_0803C1EC:
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	b _0803C324
	.align 2, 0
_0803C1F8: .4byte 0x0000018F
_0803C1FC:
	adds r0, r1, #0
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bls _0803C20A
	b _0803C324
_0803C20A:
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
	ldr r3, _0803C290 @ =0x000001FF
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
	bls _0803C324
	cmp r2, #0xef
	bls _0803C29C
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
	ldr r1, _0803C294 @ =0x0300057C
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C298 @ =0x03001C04
	mov r2, sb
	lsrs r4, r2
	b _0803C2F0
	.align 2, 0
_0803C290: .4byte 0x000001FF
_0803C294: .4byte 0x0300057C
_0803C298: .4byte 0x03001C04
_0803C29C:
	ldr r0, _0803C2F8 @ =0x00000167
	cmp r1, r0
	bhi _0803C308
	adds r0, #1
	subs r0, r0, r1
	cmp r0, r4
	bhs _0803C308
	ldr r3, _0803C2FC @ =0xFFFFFE98
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
	ldr r1, _0803C300 @ =0x0300057C
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	ldr r1, _0803C304 @ =0x03001C04
	mov r3, sb
	lsrs r4, r3
_0803C2F0:
	ldrh r0, [r1]
	subs r0, r0, r4
	strh r0, [r1]
	b _0803C324
	.align 2, 0
_0803C2F8: .4byte 0x00000167
_0803C2FC: .4byte 0xFFFFFE98
_0803C300: .4byte 0x0300057C
_0803C304: .4byte 0x03001C04
_0803C308:
	movs r0, #0xb0
	lsls r0, r0, #1
	cmp r1, r0
	bhi _0803C324
	ldr r1, _0803C330 @ =0x03002C30
	ldr r0, _0803C334 @ =0x03000440
	ldr r6, _0803C338 @ =0x0000012F
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
_0803C324:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C330: .4byte 0x03002C30
_0803C334: .4byte 0x03000440
_0803C338: .4byte 0x0000012F
	.syntax divided
