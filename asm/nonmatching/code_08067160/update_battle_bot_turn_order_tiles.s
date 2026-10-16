	.syntax unified

	thumb_func_start update_battle_bot_turn_order_tiles
update_battle_bot_turn_order_tiles: @ 0x0806A5B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r4, #0
_0806A5C2:
	ldr r1, _0806A5EC @ =0x03006F8C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _0806A62A
	ldr r1, _0806A5F0 @ =0x03006F94
	ldrb r0, [r1]
	adds r2, r4, #1
	mov r8, r2
	cmp r0, r8
	bne _0806A5F4
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #0x19
	movs r0, #0xa0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	lsrs r1, r1, #0x18
	movs r0, #5
	b _0806A622
	.align 2, 0
_0806A5EC: .4byte 0x03006F8C
_0806A5F0: .4byte 0x03006F94
_0806A5F4:
	ldrb r0, [r1, #1]
	cmp r0, r8
	bne _0806A60C
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #0x19
	movs r2, #0xa0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	lsrs r1, r1, #0x18
	movs r0, #6
	b _0806A622
_0806A60C:
	ldrb r0, [r1, #2]
	cmp r0, r8
	bne _0806A6B6
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #0x19
	movs r0, #0xa0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	lsrs r1, r1, #0x18
	movs r0, #7
_0806A622:
	movs r2, #0xf
	bl write_tilemap_tiles_dma
	b _0806A6B6
_0806A62A:
	movs r6, #0
	movs r5, #5
	adds r2, r4, #1
	mov r8, r2
	lsls r0, r4, #2
	str r0, [sp, #4]
	ldr r2, _0806A688 @ =0x03002C30
	mov sl, r2
	ldr r0, _0806A68C @ =0x08485CC4
	mov sb, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	str r0, [sp]
	movs r7, #0
	mov ip, r1
_0806A648:
	cmp r4, r6
	beq _0806A696
	mov r1, ip
	adds r2, r4, r1
	adds r3, r6, r1
	ldrb r1, [r2]
	ldrb r0, [r3]
	cmp r1, r0
	blo _0806A694
	cmp r1, r0
	bne _0806A696
	ldrb r0, [r2]
	ldr r2, [sp]
	adds r0, r0, r2
	add r0, sb
	ldrb r1, [r0]
	lsls r1, r1, #6
	add r1, sl
	ldrb r0, [r3]
	adds r0, r0, r7
	add r0, sb
	ldrb r0, [r0]
	lsls r0, r0, #6
	add r0, sl
	ldrh r1, [r1, #0x1a]
	ldrh r0, [r0, #0x1a]
	cmp r1, r0
	bne _0806A690
	cmp r6, r4
	bge _0806A696
	b _0806A694
	.align 2, 0
_0806A688: .4byte 0x03002C30
_0806A68C: .4byte 0x08485CC4
_0806A690:
	cmp r1, r0
	bhs _0806A696
_0806A694:
	adds r5, #1
_0806A696:
	adds r7, #3
	adds r6, #1
	cmp r6, #2
	ble _0806A648
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r2, [sp, #4]
	adds r1, r2, r4
	lsls r1, r1, #0x19
	movs r2, #0xa0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	lsrs r1, r1, #0x18
	movs r2, #0xf
	bl write_tilemap_tiles_dma
_0806A6B6:
	mov r4, r8
	cmp r4, #2
	ble _0806A5C2
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
