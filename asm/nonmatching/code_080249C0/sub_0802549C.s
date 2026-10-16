	.syntax unified

	thumb_func_start sub_0802549C
sub_0802549C: @ 0x0802549C
	push {lr}
	movs r0, #0x21
	bl sub_08037424
	ldr r2, _080254D0 @ =0x03002C30
	ldr r0, _080254D4 @ =0x00000888
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0x40
	bne _080254E8
	ldr r1, _080254D8 @ =0x00000842
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r3, _080254DC @ =0x00000882
	adds r0, r2, r3
	strh r1, [r0]
	ldr r1, _080254E0 @ =0x00000844
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	ldr r1, _080254E4 @ =0x03001800
	adds r1, #0xaa
	b _080254F0
	.align 2, 0
_080254D0: .4byte 0x03002C30
_080254D4: .4byte 0x00000888
_080254D8: .4byte 0x00000842
_080254DC: .4byte 0x00000882
_080254E0: .4byte 0x00000844
_080254E4: .4byte 0x03001800
_080254E8:
	adds r0, #1
	strb r0, [r1]
	ldr r0, _080254FC @ =0x00000889
	adds r1, r2, r0
_080254F0:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080254FC: .4byte 0x00000889
	.syntax divided
