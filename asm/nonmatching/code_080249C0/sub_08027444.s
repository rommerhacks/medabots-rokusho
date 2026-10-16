	.syntax unified

	thumb_func_start sub_08027444
sub_08027444: @ 0x08027444
	push {r4, lr}
	ldr r4, _08027474 @ =0x03000440
	adds r4, #0x86
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	bl sub_080378A8
	ldrh r0, [r4]
	cmp r0, #0x23
	bls _0802746C
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _08027478 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802746C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027474: .4byte 0x03000440
_08027478: .4byte 0x03001800
_0802747C:
	.byte 0x04, 0x49, 0x0A, 0x1C
	.byte 0xA6, 0x32, 0x3A, 0x20, 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47
	.byte 0x00, 0x18, 0x00, 0x03
	.syntax divided
