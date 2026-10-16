	.syntax unified

	thumb_func_start battle_find_entity_by_id
	.global battle_find_entity_by_id
battle_find_entity_by_id: @ 0x0804D8EC
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r3, #0
	ldr r1, _0804D910 @ =0x030057E0
	ldr r7, _0804D914 @ =0x00000FFF
	ldr r2, _0804D918 @ =0x000005DE
	adds r5, r1, r2
	subs r2, #2
	adds r4, r1, r2
_0804D902:
	ldrh r2, [r5]
	adds r1, r7, #0
	ands r1, r2
	cmp r1, r6
	bne _0804D91C
	adds r0, r4, #0
	b _0804D92C
	.align 2, 0
_0804D910: .4byte 0x030057E0
_0804D914: .4byte 0x00000FFF
_0804D918: .4byte 0x000005DE
_0804D91C:
	adds r5, #8
	adds r4, #8
	adds r3, #1
	cmp r3, #0x3f
	ble _0804D902
	cmp r3, #0x40
	bne _0804D92C
	movs r0, #0
_0804D92C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
