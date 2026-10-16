	.syntax unified

	thumb_func_start sub_0801C444
sub_0801C444: @ 0x0801C444
	push {r4, r5, lr}
	ldr r5, _0801C46C @ =0x03001800
	adds r4, r5, #0
	adds r4, #0x87
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r0, [r4]
	bl sub_0801ADE8
	cmp r0, #0
	beq _0801C466
	adds r1, r5, #0
	adds r1, #0x9c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801C466:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C46C: .4byte 0x03001800
	.syntax divided
