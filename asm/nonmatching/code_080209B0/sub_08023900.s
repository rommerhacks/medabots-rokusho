	.syntax unified

	thumb_func_start sub_08023900
sub_08023900: @ 0x08023900
	push {lr}
	ldr r1, _08023930 @ =0x083B5F80
	ldr r0, _08023934 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _08023938 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08023944
	ldr r0, _0802393C @ =0x03002C30
	ldr r1, _08023940 @ =0x00000858
	adds r0, r0, r1
	ldrh r1, [r0]
	subs r1, #0x40
	b _0802394E
	.align 2, 0
_08023930: .4byte 0x083B5F80
_08023934: .4byte 0x03000440
_08023938: .4byte 0x03001800
_0802393C: .4byte 0x03002C30
_08023940: .4byte 0x00000858
_08023944:
	ldr r0, _08023978 @ =0x03002C30
	ldr r1, _0802397C @ =0x00000858
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #0x40
_0802394E:
	ldr r3, _08023980 @ =0x000003FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0]
	movs r0, #0x21
	bl move_sprite_toward_target
	cmp r0, #0
	beq _08023974
	ldr r0, _08023978 @ =0x03002C30
	ldr r1, _0802397C @ =0x00000858
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	ldr r1, _08023984 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08023974:
	pop {r0}
	bx r0
	.align 2, 0
_08023978: .4byte 0x03002C30
_0802397C: .4byte 0x00000858
_08023980: .4byte 0x000003FF
_08023984: .4byte 0x03001800
	.syntax divided
