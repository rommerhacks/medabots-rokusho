	.syntax unified

	thumb_func_start load_battle_entity_palette
	.global load_battle_entity_palette
load_battle_entity_palette: @ 0x0801BCE4
	push {lr}
	ldr r3, _0801BD14 @ =0x083CE480
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r3, _0801BD18 @ =0x083B2584
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1, #2]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	lsls r2, r2, #5
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r2, r2, r1
	adds r1, r2, #0
	movs r2, #8
	bl CpuFastSet
	pop {r0}
	bx r0
	.align 2, 0
_0801BD14: .4byte 0x083CE480
_0801BD18: .4byte 0x083B2584
	.syntax divided
