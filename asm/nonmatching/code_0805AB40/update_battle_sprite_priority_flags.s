	.syntax unified

	thumb_func_start update_battle_sprite_priority_flags
	.global update_battle_sprite_priority_flags
update_battle_sprite_priority_flags: @ 0x0805B838
	push {r4, r5, lr}
	ldr r0, _0805B870 @ =0x03006F74
	ldr r1, [r0]
	adds r1, #0x20
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #4
	bls _0805B8DE
	ldr r0, _0805B874 @ =0x02023078
	ldrb r0, [r0]
	cmp r0, #0
	beq _0805B880
	ldr r0, _0805B878 @ =0x03001780
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0805B880
	ldr r3, _0805B87C @ =0x03002C30
	movs r5, #0xd0
	lsls r5, r5, #5
	adds r2, r3, r5
	ldrh r1, [r2]
	movs r5, #0x80
	lsls r5, r5, #7
	adds r0, r5, #0
	orrs r0, r1
	b _0805B88E
	.align 2, 0
_0805B870: .4byte 0x03006F74
_0805B874: .4byte 0x02023078
_0805B878: .4byte 0x03001780
_0805B87C: .4byte 0x03002C30
_0805B880:
	ldr r3, _0805B8C0 @ =0x03002C30
	movs r0, #0xd0
	lsls r0, r0, #5
	adds r2, r3, r0
	ldrh r1, [r2]
	ldr r0, _0805B8C4 @ =0x0000BFFF
	ands r0, r1
_0805B88E:
	strh r0, [r2]
	ldr r0, _0805B8C8 @ =0x02023078
	ldrb r1, [r0]
	adds r1, #3
	ldr r0, [r4]
	adds r0, #0x20
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	beq _0805B8D0
	ldr r0, _0805B8CC @ =0x03001780
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0805B8D0
	movs r0, #0xd2
	lsls r0, r0, #5
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r1
	b _0805B8DC
	.align 2, 0
_0805B8C0: .4byte 0x03002C30
_0805B8C4: .4byte 0x0000BFFF
_0805B8C8: .4byte 0x02023078
_0805B8CC: .4byte 0x03001780
_0805B8D0:
	movs r5, #0xd2
	lsls r5, r5, #5
	adds r2, r3, r5
	ldrh r1, [r2]
	ldr r0, _0805B8E4 @ =0x0000BFFF
	ands r0, r1
_0805B8DC:
	strh r0, [r2]
_0805B8DE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805B8E4: .4byte 0x0000BFFF
	.syntax divided
