	.syntax unified

	thumb_func_start sub_08020248
sub_08020248: @ 0x08020248
	push {r4, lr}
	ldr r4, _08020274 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xb7
	ldrb r0, [r0]
	cmp r0, #3
	bne _08020278
	bl sub_0803713C
	movs r0, #0xa
	movs r1, #1
	bl clear_battle_sprite_slot
	adds r1, r4, #0
	adds r1, #0xab
	movs r0, #1
	strb r0, [r1]
	subs r1, #1
	ldrb r0, [r1]
	adds r0, #1
	b _0802027E
	.align 2, 0
_08020274: .4byte 0x03001800
_08020278:
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #6
_0802027E:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
