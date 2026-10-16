	.syntax unified

	thumb_func_start sub_08004CA4
sub_08004CA4: @ 0x08004CA4
	push {lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	ldr r3, _08004CC4 @ =0x03001800
	adds r1, r3, #0
	adds r1, #0x51
	ldrb r0, [r1]
	cmp r0, #1
	bhi _08004D02
	cmp r0, #0
	beq _08004CC8
	cmp r0, #1
	beq _08004CE4
	b _08004CF8
	.align 2, 0
_08004CC4: .4byte 0x03001800
_08004CC8:
	ldr r1, _08004CE0 @ =0x03005010
	movs r0, #0xd3
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r1, #6]
	b _08004CF8
	.align 2, 0
_08004CE0: .4byte 0x03005010
_08004CE4:
	ldr r2, _08004D34 @ =0x03005010
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #6]
_08004CF8:
	ldr r1, _08004D38 @ =0x03001800
	adds r1, #0x51
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08004D02:
	ldr r1, _08004D34 @ =0x03005010
	ldr r0, _08004D3C @ =0x03000B90
	ldrb r2, [r0]
	movs r0, #1
	eors r0, r2
	lsls r0, r0, #2
	adds r1, #0xa
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08004DAA
	ldr r0, _08004D38 @ =0x03001800
	adds r2, r0, #0
	adds r2, #0x52
	ldrb r2, [r2]
	adds r3, r0, #0
	cmp r2, #0
	beq _08004D40
	cmp r2, #1
	beq _08004D50
	b _08004D5C
	.align 2, 0
_08004D34: .4byte 0x03005010
_08004D38: .4byte 0x03001800
_08004D3C: .4byte 0x03000B90
_08004D40:
	ldr r0, _08004D4C @ =0x00007FFF
	ands r1, r0
	movs r2, #0xd5
	lsls r2, r2, #1
	b _08004D58
	.align 2, 0
_08004D4C: .4byte 0x00007FFF
_08004D50:
	ldr r0, _08004D9C @ =0x00007FFF
	ands r1, r0
	movs r2, #0xd6
	lsls r2, r2, #1
_08004D58:
	adds r0, r3, r2
	strh r1, [r0]
_08004D5C:
	adds r1, r3, #0
	adds r1, #0x52
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _08004DAA
	movs r1, #0xd3
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08004DA4
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r3, r1
	subs r2, #2
	adds r1, r3, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08004DA4
	ldr r1, _08004DA0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08004DA8
	.align 2, 0
_08004D9C: .4byte 0x00007FFF
_08004DA0: .4byte 0x0300137C
_08004DA4:
	ldr r1, _08004DB0 @ =0x0300137C
	movs r0, #0x32
_08004DA8:
	str r0, [r1]
_08004DAA:
	pop {r0}
	bx r0
	.align 2, 0
_08004DB0: .4byte 0x0300137C
	.syntax divided
