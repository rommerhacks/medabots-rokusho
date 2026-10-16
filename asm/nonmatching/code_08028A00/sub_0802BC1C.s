	.syntax unified

	thumb_func_start sub_0802BC1C
sub_0802BC1C: @ 0x0802BC1C
	push {r4, r5, lr}
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	movs r2, #0
	ldr r0, _0802BC5C @ =0x03001800
	adds r5, r0, #0
	adds r5, #0xd2
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0xec
	adds r1, r3, #0
	adds r1, #0xd6
_0802BC38:
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BC44
	ldrh r0, [r4]
	strh r0, [r1]
_0802BC44:
	adds r1, #2
	adds r2, #1
	cmp r2, #2
	bls _0802BC38
	adds r1, r3, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802BC5C: .4byte 0x03001800
	.syntax divided
