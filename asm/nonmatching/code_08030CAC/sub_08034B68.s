	.syntax unified

	thumb_func_start sub_08034B68
sub_08034B68: @ 0x08034B68
	push {r4, r5, lr}
	ldr r4, _08034B9C @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	ldrb r0, [r1]
	ldrb r1, [r5]
	bl battle_select_random_target
	cmp r0, #0xff
	bne _08034B90
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0xa
	strh r0, [r1]
_08034B90:
	bl sub_08034F08
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034B9C: .4byte 0x03001800
	.syntax divided
