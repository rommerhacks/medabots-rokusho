	.syntax unified

	thumb_func_start battle_check_damage_threshold
battle_check_damage_threshold: @ 0x08038F34
	push {r4, lr}
	ldr r3, _08038F4C @ =0x03001800
	adds r4, r3, #0
	adds r4, #0xe8
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _08038F50
	movs r0, #0
	b _08038F78
	.align 2, 0
_08038F4C: .4byte 0x03001800
_08038F50:
	adds r1, r3, #0
	adds r1, #0xee
	movs r0, #0
	strh r0, [r1]
	ldr r2, _08038F80 @ =0x03000590
	adds r0, r3, #0
	adds r0, #0x88
	ldrb r1, [r0]
	lsls r1, r1, #8
	adds r1, r1, r2
	adds r1, #0xbc
	ldrb r2, [r1]
	movs r0, #0x4c
	orrs r0, r2
	strb r0, [r1]
	ldrh r1, [r4]
	adds r0, r3, #0
	adds r0, #0xf2
	strh r1, [r0]
	movs r0, #1
_08038F78:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08038F80: .4byte 0x03000590
	.syntax divided
