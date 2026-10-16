	.syntax unified

	thumb_func_start sub_080315B0
sub_080315B0: @ 0x080315B0
	push {r4, r5, lr}
	ldr r4, _080315FC @ =0x0300052E
	ldr r0, _08031600 @ =0x03001800
	adds r5, r0, #0
	adds r5, #0x87
	ldrb r1, [r5]
	adds r0, r4, #0
	movs r2, #0x23
	bl update_battle_sprite_animations
	subs r4, #0x6a
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x78
	bne _080315F6
	movs r0, #0x21
	movs r1, #2
	bl clear_battle_sprite_slot
	ldrb r0, [r5]
	lsls r0, r0, #0x1a
	movs r1, #0x8c
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #4
	bl clear_battle_sprite_slot
	ldr r1, _08031604 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080315F6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080315FC: .4byte 0x0300052E
_08031600: .4byte 0x03001800
_08031604: .4byte 0x0300137C
_08031608:
	.byte 0x01, 0x49, 0x4F, 0x20, 0x08, 0x60, 0x70, 0x47
	.byte 0x7C, 0x13, 0x00, 0x03
	.syntax divided
