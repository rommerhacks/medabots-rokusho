	.syntax unified

	thumb_func_start sub_08024C94
sub_08024C94: @ 0x08024C94
	push {lr}
	ldr r0, _08024CB8 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0x3c
	bne _08024CC0
	movs r0, #0x21
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r1, _08024CBC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08024D08
	.align 2, 0
_08024CB8: .4byte 0x03000440
_08024CBC: .4byte 0x03001800
_08024CC0:
	adds r0, #1
	strh r0, [r1]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08024CEC
	ldr r1, _08024CE4 @ =0x03002C30
	ldr r0, _08024CE8 @ =0x03001800
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	subs r0, #2
	b _08024D02
	.align 2, 0
_08024CE4: .4byte 0x03002C30
_08024CE8: .4byte 0x03001800
_08024CEC:
	ldr r1, _08024D0C @ =0x03002C30
	ldr r0, _08024D10 @ =0x03001800
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	adds r0, #2
_08024D02:
	ldr r2, _08024D14 @ =0x00000842
	adds r1, r1, r2
	strh r0, [r1]
_08024D08:
	pop {r0}
	bx r0
	.align 2, 0
_08024D0C: .4byte 0x03002C30
_08024D10: .4byte 0x03001800
_08024D14: .4byte 0x00000842
	.syntax divided
