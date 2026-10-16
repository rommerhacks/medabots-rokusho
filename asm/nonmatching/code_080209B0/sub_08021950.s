	.syntax unified

	thumb_func_start sub_08021950
sub_08021950: @ 0x08021950
	push {r4, lr}
	ldr r0, _080219A4 @ =0x084D54BC
	ldr r1, _080219A8 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080219AC @ =0x0850E698
	ldr r1, _080219B0 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _080219B4 @ =0x083B5F80
	adds r0, #0xe4
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r3, _080219B8 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021994
	ldr r0, _080219BC @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r4, #0x80
	lsls r4, r4, #5
	adds r1, r4, #0
	orrs r1, r2
	strh r1, [r0]
_08021994:
	adds r1, r3, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080219A4: .4byte 0x084D54BC
_080219A8: .4byte 0x06014800
_080219AC: .4byte 0x0850E698
_080219B0: .4byte 0x050002E0
_080219B4: .4byte 0x083B5F80
_080219B8: .4byte 0x03001800
_080219BC: .4byte 0x03002C30
	.syntax divided
