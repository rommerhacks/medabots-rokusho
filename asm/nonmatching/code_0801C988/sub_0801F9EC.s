	.syntax unified

	thumb_func_start sub_0801F9EC
sub_0801F9EC: @ 0x0801F9EC
	push {r4, r5, lr}
	ldr r4, _0801FA38 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	ldr r3, _0801FA3C @ =0x03000590
	adds r1, r4, #0
	adds r1, #0xa7
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r2, r4, #0
	adds r2, #0x87
	ldrb r2, [r2]
	lsls r2, r2, #8
	adds r1, r1, r2
	adds r1, r1, r3
	adds r1, #0x49
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0xe8
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r3, r4, #0
	adds r3, #0xec
	movs r5, #0
	ldrsh r3, [r3, r5]
	bl battle_set_action_params
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801FA38: .4byte 0x03001800
_0801FA3C: .4byte 0x03000590
	.syntax divided
