	.syntax unified

	thumb_func_start sub_080220A0
sub_080220A0: @ 0x080220A0
	push {r4, r5, r6, lr}
	ldr r4, _0802212C @ =0x03002C30
	ldr r6, _08022130 @ =0x03001800
	adds r5, r6, #0
	adds r5, #0x88
	ldrb r0, [r5]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #0x47
	lsls r1, r1, #6
	adds r2, r1, r4
	ldrb r0, [r2, #8]
	cmp r0, #4
	beq _080220EC
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x47
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrb r1, [r0, #9]
	adds r1, #4
	strb r1, [r0, #9]
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x47
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrb r1, [r0, #8]
	subs r1, #4
	strb r1, [r0, #8]
_080220EC:
	ldr r0, _08022134 @ =0x083B5F80
	adds r0, #0xf0
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r1, _08022138 @ =0x00000862
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08022126
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x47
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08022126:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802212C: .4byte 0x03002C30
_08022130: .4byte 0x03001800
_08022134: .4byte 0x083B5F80
_08022138: .4byte 0x00000862
_0802213C:
	.byte 0x04, 0x49, 0x0A, 0x1C
	.byte 0xA6, 0x32, 0x23, 0x20, 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47
	.byte 0x00, 0x18, 0x00, 0x03
	.syntax divided
