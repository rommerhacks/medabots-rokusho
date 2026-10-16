	.syntax unified

	thumb_func_start sub_080291E0
sub_080291E0: @ 0x080291E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _080292B0 @ =0x084DD45C
	ldr r1, _080292B4 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080292B8 @ =0x0850EC98
	ldr r1, _080292BC @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	bl sub_0803836C
	ldr r4, _080292C0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r0, _080292C4 @ =0x03000590
	mov sb, r0
	adds r6, r1, #0
	adds r4, #0xd2
	mov r8, r4
	ldr r7, _080292C8 @ =0x03002C30
	movs r2, #0x84
	lsls r2, r2, #4
	adds r4, r7, r2
_08029224:
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	mov r2, sb
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029292
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029292
	mov r0, r8
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x21
	movs r2, #0
	ldr r0, _080292CC @ =0x0000C404
	strh r0, [r4]
	strb r2, [r4, #0x1c]
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r7
	ldrh r0, [r0, #2]
	strh r0, [r4, #2]
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, r0, r7
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xf0
	strb r0, [r4, #0xb]
	ldr r0, _080292D0 @ =0x083B5F80
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_08029292:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _08029224
	ldr r1, _080292C0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080292B0: .4byte 0x084DD45C
_080292B4: .4byte 0x06014800
_080292B8: .4byte 0x0850EC98
_080292BC: .4byte 0x050002E0
_080292C0: .4byte 0x03001800
_080292C4: .4byte 0x03000590
_080292C8: .4byte 0x03002C30
_080292CC: .4byte 0x0000C404
_080292D0: .4byte 0x083B5F80
	.syntax divided
