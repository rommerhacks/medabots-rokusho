	.syntax unified

	thumb_func_start sub_08021BD8
sub_08021BD8: @ 0x08021BD8
	push {r4, r5, r6, r7, lr}
	ldr r0, _08021C6C @ =0x084CCE48
	ldr r1, _08021C70 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08021C74 @ =0x0850E358
	ldr r1, _08021C78 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _08021C7C @ =0x083B5F80
	adds r4, #0x8c
	ldr r0, [r4]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, [r4]
	movs r1, #0x22
	bl init_battle_sprite_entry_08040B90
	ldr r0, [r4]
	movs r1, #0x23
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x21
	movs r1, #3
	bl set_sprite_hidden_flags
	movs r0, #0
	mov ip, r0
	ldr r1, _08021C80 @ =0x03000590
	ldr r0, _08021C84 @ =0x03002C30
	movs r3, #0
	ldr r2, _08021C88 @ =0x00001763
	adds r7, r0, r2
	subs r2, #0x40
	adds r6, r0, r2
	subs r2, #0x40
	adds r5, r0, r2
	subs r2, #0x40
	adds r4, r0, r2
	adds r1, #0x40
	movs r2, #0x80
	lsls r2, r2, #1
_08021C30:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08021C3E
	strb r3, [r4]
	strb r3, [r5]
	strb r3, [r6]
	strb r3, [r7]
_08021C3E:
	adds r7, r7, r2
	adds r6, r6, r2
	adds r5, r5, r2
	adds r4, r4, r2
	adds r1, r1, r2
	movs r0, #1
	add ip, r0
	mov r0, ip
	cmp r0, #5
	bls _08021C30
	movs r1, #0
	ldr r0, _08021C8C @ =0x03000440
	adds r0, #0x86
	strh r1, [r0]
	ldr r1, _08021C90 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021C6C: .4byte 0x084CCE48
_08021C70: .4byte 0x06014800
_08021C74: .4byte 0x0850E358
_08021C78: .4byte 0x050002E0
_08021C7C: .4byte 0x083B5F80
_08021C80: .4byte 0x03000590
_08021C84: .4byte 0x03002C30
_08021C88: .4byte 0x00001763
_08021C8C: .4byte 0x03000440
_08021C90: .4byte 0x03001800
	.syntax divided
