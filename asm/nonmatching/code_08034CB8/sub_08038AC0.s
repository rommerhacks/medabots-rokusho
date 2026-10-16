	.syntax unified

	thumb_func_start sub_08038AC0
sub_08038AC0: @ 0x08038AC0
	push {r4, r5, r6, r7, lr}
	ldr r4, _08038B10 @ =0x03002C30
	ldr r2, _08038B14 @ =0x03000440
	ldr r0, _08038B18 @ =0x0000012F
	adds r3, r2, r0
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x28
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r3, [r3]
	lsls r0, r3, #6
	adds r0, r0, r4
	adds r0, #0x28
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _08038B20
	ldr r2, _08038B1C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x60
	ldrb r0, [r0]
	subs r0, #0x24
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r4
	adds r0, r0, r2
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r0, #2
	b _08038B42
	.align 2, 0
_08038B10: .4byte 0x03002C30
_08038B14: .4byte 0x03000440
_08038B18: .4byte 0x0000012F
_08038B1C: .4byte 0x03001800
_08038B20:
	ldr r2, _08038BB0 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x60
	ldrb r0, [r0]
	subs r0, #0x24
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r4
	adds r0, r0, r2
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	subs r0, #2
_08038B42:
	strh r0, [r1, #2]
	adds r6, r2, #0
	adds r5, r6, #0
	adds r5, #0x60
	ldrb r0, [r5]
	ldr r1, _08038BB4 @ =0x0000012F
	adds r4, r7, r1
	subs r0, #0x24
	ldrb r2, [r4]
	adds r0, r0, r2
	bl sub_080350E0
	ldr r0, _08038BB8 @ =0x083B5F80
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	ldrb r1, [r4]
	bl process_sprite_anim_commands
	ldr r2, _08038BBC @ =0x03002C30
	ldrb r1, [r4]
	lsls r0, r1, #6
	adds r0, r0, r2
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08038BAA
	ldrb r0, [r5]
	subs r0, #0x24
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r2
	adds r0, r0, r6
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1, #2]
	ldrb r0, [r5]
	subs r0, #0x24
	ldrb r3, [r4]
	adds r0, r0, r3
	bl sub_080350E0
	ldrb r0, [r4]
	movs r1, #1
	bl clear_battle_sprite_slot
_08038BAA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038BB0: .4byte 0x03001800
_08038BB4: .4byte 0x0000012F
_08038BB8: .4byte 0x083B5F80
_08038BBC: .4byte 0x03002C30
	.syntax divided
