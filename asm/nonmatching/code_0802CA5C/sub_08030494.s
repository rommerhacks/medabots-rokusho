	.syntax unified

	thumb_func_start sub_08030494
sub_08030494: @ 0x08030494
	push {r4, r5, r6, lr}
	ldr r0, _080304BC @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x86
	ldrh r2, [r5]
	adds r6, r0, #0
	cmp r2, #0x20
	bne _080304C4
	movs r0, #0x21
	movs r1, #4
	bl clear_battle_sprite_slot
	movs r0, #0
	strh r0, [r5]
	ldr r1, _080304C0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08030592
	.align 2, 0
_080304BC: .4byte 0x03000440
_080304C0: .4byte 0x03001800
_080304C4:
	movs r0, #3
	ands r0, r2
	ldr r4, _08030540 @ =0x03002C30
	cmp r0, #0
	bne _08030500
	ldr r0, _08030544 @ =0x00000844
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	movs r2, #0xff
	ands r0, r2
	strh r0, [r1]
	ldr r3, _08030548 @ =0x00000884
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	ands r0, r2
	strh r0, [r1]
	ldr r0, _0803054C @ =0x000008C4
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	ands r0, r2
	strh r0, [r1]
	adds r3, #0x80
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	ands r0, r2
	strh r0, [r1]
_08030500:
	ldrh r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08030550
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r4, r0
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x88
	lsls r0, r0, #4
	adds r2, r4, r0
	ldrh r0, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0x8c
	lsls r3, r3, #4
	adds r2, r4, r3
	ldrh r0, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x90
	lsls r0, r0, #4
	adds r2, r4, r0
	ldrh r0, [r2]
	orrs r1, r0
	b _08030586
	.align 2, 0
_08030540: .4byte 0x03002C30
_08030544: .4byte 0x00000844
_08030548: .4byte 0x00000884
_0803054C: .4byte 0x000008C4
_08030550:
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r4, r0
	ldrh r2, [r3]
	ldr r1, _08030598 @ =0x00007FFF
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r0, #0x88
	lsls r0, r0, #4
	adds r3, r4, r0
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r0, #0x8c
	lsls r0, r0, #4
	adds r3, r4, r0
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r3, #0x90
	lsls r3, r3, #4
	adds r2, r4, r3
	ldrh r0, [r2]
	ands r1, r0
_08030586:
	strh r1, [r2]
	adds r1, r6, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08030592:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08030598: .4byte 0x00007FFF
_0803059C:
	.byte 0x08, 0x48, 0x09, 0x4B
	.byte 0x19, 0x1C, 0x87, 0x31, 0x09, 0x78, 0x09, 0x02, 0x09, 0x18, 0xC0, 0x31, 0x0A, 0x78, 0x04, 0x20
	.byte 0x10, 0x43, 0x08, 0x70, 0xAA, 0x33, 0x18, 0x78, 0x01, 0x30, 0x18, 0x70, 0x70, 0x47, 0x00, 0x00
	.byte 0x90, 0x05, 0x00, 0x03, 0x00, 0x18, 0x00, 0x03, 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x6A, 0x20
	.byte 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
