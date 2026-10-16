	.syntax unified

	thumb_func_start sub_080268D4
sub_080268D4: @ 0x080268D4
	push {r4, r5, r6, lr}
	ldr r6, _08026920 @ =0x03001800
	adds r5, r6, #0
	adds r5, #0x88
	ldrb r0, [r5]
	adds r4, r6, #0
	adds r4, #0xec
	movs r1, #0
	ldrsh r2, [r4, r1]
	movs r1, #0
	bl sub_08037728
	ldrb r0, [r5]
	movs r1, #0
	ldrsh r2, [r4, r1]
	movs r1, #1
	bl sub_08037728
	ldrb r0, [r5]
	movs r1, #0
	ldrsh r2, [r4, r1]
	movs r1, #2
	bl sub_08037728
	ldrb r0, [r5]
	movs r1, #0
	ldrsh r2, [r4, r1]
	movs r1, #3
	bl sub_08037728
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08026920: .4byte 0x03001800
	.syntax divided
