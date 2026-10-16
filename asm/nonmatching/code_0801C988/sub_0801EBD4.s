	.syntax unified

	thumb_func_start sub_0801EBD4
sub_0801EBD4: @ 0x0801EBD4
	push {lr}
	bl setup_battle_medapart_scenes
	ldr r0, _0801EBF0 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _0801EBF4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0801EBF0: .4byte 0x03000440
_0801EBF4: .4byte 0x03001800
	.syntax divided
