	.syntax unified

	thumb_func_start update_battle_icon_blink_and_orbit
	.global update_battle_icon_blink_and_orbit
update_battle_icon_blink_and_orbit: @ 0x08005798
	push {r4, lr}
	ldr r0, _080057EC @ =0x03000440
	adds r0, #0x52
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08005858
	ldr r0, _080057F0 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080057F8
	ldr r3, _080057F4 @ =0x03002C30
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrh r0, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r3, r4
	ldrh r0, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrh r0, [r2]
	orrs r1, r0
	b _08005832
	.align 2, 0
_080057EC: .4byte 0x03000440
_080057F0: .4byte 0x03001780
_080057F4: .4byte 0x03002C30
_080057F8:
	ldr r4, _08005850 @ =0x03002C30
	mov ip, r4
	movs r3, #0x80
	lsls r3, r3, #1
	add r3, ip
	ldrh r2, [r3]
	ldr r1, _08005854 @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r3, #0xa0
	lsls r3, r3, #1
	add r3, ip
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r3, #0xc0
	lsls r3, r3, #1
	add r3, ip
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, ip
	ldrh r0, [r2]
	ands r1, r0
_08005832:
	strh r1, [r2]
	movs r0, #4
	bl update_battle_sprite_orbit_counterclockwise
	movs r0, #5
	bl update_battle_sprite_orbit_counterclockwise
	movs r0, #6
	bl update_battle_sprite_orbit_counterclockwise
	movs r0, #7
	bl update_battle_sprite_orbit_counterclockwise
	b _08005894
	.align 2, 0
_08005850: .4byte 0x03002C30
_08005854: .4byte 0x0000BFFF
_08005858:
	ldr r0, _0800589C @ =0x03002C30
	mov ip, r0
	movs r3, #0x80
	lsls r3, r3, #1
	add r3, ip
	ldrh r2, [r3]
	ldr r1, _080058A0 @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r3, #0xa0
	lsls r3, r3, #1
	add r3, ip
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r3, #0xc0
	lsls r3, r3, #1
	add r3, ip
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r2, #0xe0
	lsls r2, r2, #1
	add r2, ip
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
_08005894:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800589C: .4byte 0x03002C30
_080058A0: .4byte 0x0000BFFF
	.syntax divided
