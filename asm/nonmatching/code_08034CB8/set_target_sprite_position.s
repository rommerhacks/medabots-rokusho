	.syntax unified

	thumb_func_start set_target_sprite_position
	.global set_target_sprite_position
set_target_sprite_position: @ 0x08034FC8
	push {r4, lr}
	adds r3, r0, #0
	cmp r2, #0
	bne _08035054
	movs r0, #6
	ands r0, r1
	lsrs r0, r0, #1
	cmp r0, #1
	beq _08035004
	cmp r0, #3
	beq _0803502C
	ldr r0, _08034FFC @ =0x03002C30
	lsls r2, r3, #2
	adds r1, r2, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r0
	ldr r0, _08035000 @ =0x03001800
	adds r2, r2, r0
	movs r4, #0x9e
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1, #2]
	adds r4, #2
	b _080350C4
	.align 2, 0
_08034FFC: .4byte 0x03002C30
_08035000: .4byte 0x03001800
_08035004:
	ldr r0, _08035024 @ =0x03002C30
	lsls r2, r3, #2
	adds r1, r2, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r0
	ldr r0, _08035028 @ =0x03001800
	adds r2, r2, r0
	movs r4, #0x9e
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r0, [r0]
	adds r0, #1
	strh r0, [r1, #2]
	adds r4, #2
	b _080350C4
	.align 2, 0
_08035024: .4byte 0x03002C30
_08035028: .4byte 0x03001800
_0803502C:
	ldr r0, _0803504C @ =0x03002C30
	lsls r2, r3, #2
	adds r1, r2, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r0
	ldr r0, _08035050 @ =0x03001800
	adds r2, r2, r0
	movs r4, #0x9e
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r0, [r0]
	subs r0, #1
	strh r0, [r1, #2]
	adds r4, #2
	b _080350C4
	.align 2, 0
_0803504C: .4byte 0x03002C30
_08035050: .4byte 0x03001800
_08035054:
	movs r0, #6
	ands r0, r1
	lsrs r0, r0, #1
	cmp r0, #1
	beq _08035088
	cmp r0, #3
	beq _080350B0
	ldr r0, _08035080 @ =0x03002C30
	lsls r1, r3, #2
	adds r2, r1, #0
	adds r2, #0x5d
	lsls r2, r2, #6
	adds r2, r2, r0
	ldr r0, _08035084 @ =0x03001800
	adds r1, r1, r0
	movs r4, #0x9f
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrh r0, [r0]
	subs r0, #1
	strh r0, [r2, #4]
	b _080350CA
	.align 2, 0
_08035080: .4byte 0x03002C30
_08035084: .4byte 0x03001800
_08035088:
	ldr r0, _080350A8 @ =0x03002C30
	lsls r1, r3, #2
	adds r2, r1, #0
	adds r2, #0x5d
	lsls r2, r2, #6
	adds r2, r2, r0
	ldr r0, _080350AC @ =0x03001800
	adds r1, r1, r0
	movs r4, #0x9f
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrh r0, [r0]
	subs r0, #2
	strh r0, [r2, #4]
	b _080350CA
	.align 2, 0
_080350A8: .4byte 0x03002C30
_080350AC: .4byte 0x03001800
_080350B0:
	ldr r0, _080350D8 @ =0x03002C30
	lsls r2, r3, #2
	adds r1, r2, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r0
	ldr r0, _080350DC @ =0x03001800
	adds r2, r2, r0
	movs r4, #0x9f
	lsls r4, r4, #1
_080350C4:
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1, #4]
_080350CA:
	adds r0, r3, #0
	bl sub_080350E0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080350D8: .4byte 0x03002C30
_080350DC: .4byte 0x03001800
	.syntax divided
