	.syntax unified

	thumb_func_start sub_08025570
sub_08025570: @ 0x08025570
	push {lr}
	movs r0, #0x21
	bl sub_08037424
	ldr r2, _080255B0 @ =0x03002C30
	ldr r1, _080255B4 @ =0x00000842
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r3, _080255B8 @ =0x00000882
	adds r0, r2, r3
	strh r1, [r0]
	ldr r1, _080255BC @ =0x00000844
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	ldr r0, _080255C0 @ =0x00000848
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #1
	bne _080255C8
	movs r0, #0x21
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r1, _080255C4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _080255E8
	.align 2, 0
_080255B0: .4byte 0x03002C30
_080255B4: .4byte 0x00000842
_080255B8: .4byte 0x00000882
_080255BC: .4byte 0x00000844
_080255C0: .4byte 0x00000848
_080255C4: .4byte 0x03001800
_080255C8:
	subs r0, #1
	strb r0, [r1]
	ldr r3, _080255F0 @ =0x00000849
	adds r1, r2, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r0, _080255F4 @ =0x00000888
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r3, #0x40
	adds r1, r2, r3
	ldrb r0, [r1]
	subs r0, #1
_080255E8:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080255F0: .4byte 0x00000849
_080255F4: .4byte 0x00000888
	.syntax divided
