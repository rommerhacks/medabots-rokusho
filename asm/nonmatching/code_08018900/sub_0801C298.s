	.syntax unified

	thumb_func_start sub_0801C298
sub_0801C298: @ 0x0801C298
	push {r4, lr}
	ldr r1, _0801C2E4 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0x9d
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r0, _0801C2E8 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #0
	bne _0801C2C2
	ldr r0, _0801C2EC @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801C2C2
	movs r0, #0x3c
	strb r0, [r2]
_0801C2C2:
	adds r0, r4, #0
	adds r0, #0x9d
	ldrb r0, [r0]
	cmp r0, #0x3c
	bne _0801C2DE
	movs r0, #3
	movs r1, #1
	bl clear_battle_sprite_slot
	adds r1, r4, #0
	adds r1, #0x9c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801C2DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C2E4: .4byte 0x03001800
_0801C2E8: .4byte 0x03000440
_0801C2EC: .4byte 0x03001798
	.syntax divided
