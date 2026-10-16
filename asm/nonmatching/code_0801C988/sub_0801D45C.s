	.syntax unified

	thumb_func_start sub_0801D45C
sub_0801D45C: @ 0x0801D45C
	push {r4, r5, r6, lr}
	movs r0, #9
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r2, _0801D508 @ =0x03002C30
	movs r0, #0x90
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _0801D50C @ =0x0000C404
	strh r0, [r1]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r3, [r0]
	ldr r5, _0801D510 @ =0x03001800
	adds r3, r5, #0
	adds r3, #0x87
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r4, #0xba
	lsls r4, r4, #5
	adds r0, r0, r4
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	movs r6, #0x91
	lsls r6, r6, #2
	adds r1, r2, r6
	strh r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r3, _0801D514 @ =0x00000242
	adds r0, r2, r3
	strh r1, [r0]
	ldr r4, _0801D518 @ =0x0000024A
	adds r0, r2, r4
	movs r4, #6
	strb r4, [r0]
	adds r6, #7
	adds r1, r2, r6
	movs r0, #0xf0
	strb r0, [r1]
	adds r3, r5, #0
	adds r3, #0x88
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	adds r6, #0x25
	adds r0, r2, r6
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _0801D51C @ =0x00000272
	adds r1, r2, r3
	strh r0, [r1]
	subs r6, #0xc
	adds r2, r2, r6
	strb r4, [r2]
	ldr r0, _0801D520 @ =0x083B5F80
	ldr r0, [r0, #0x6c]
	movs r1, #9
	bl init_battle_sprite_entry_08040B90
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801D508: .4byte 0x03002C30
_0801D50C: .4byte 0x0000C404
_0801D510: .4byte 0x03001800
_0801D514: .4byte 0x00000242
_0801D518: .4byte 0x0000024A
_0801D51C: .4byte 0x00000272
_0801D520: .4byte 0x083B5F80
	.syntax divided
