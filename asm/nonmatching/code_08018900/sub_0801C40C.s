	.syntax unified

	thumb_func_start sub_0801C40C
sub_0801C40C: @ 0x0801C40C
	push {r4, r5, lr}
	ldr r0, _0801C438 @ =0x084E2F18
	ldr r1, _0801C43C @ =0x05000320
	movs r2, #8
	bl CpuFastSet
	ldr r4, _0801C440 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	bl animate_battle_sprites
	ldrb r0, [r5]
	bl sub_0801AD48
	adds r4, #0x9c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C438: .4byte 0x084E2F18
_0801C43C: .4byte 0x05000320
_0801C440: .4byte 0x03001800
	.syntax divided
