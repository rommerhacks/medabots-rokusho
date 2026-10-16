	.syntax unified

	thumb_func_start sub_08004798
sub_08004798: @ 0x08004798
	push {r4, lr}
	bl sub_08004E74
	bl setup_overworld_scene_from_position
	bl sub_08007480
	ldr r4, _080047C4 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	cmp r0, #0x3c
	bls _080047E0
	adds r0, r4, #0
	adds r0, #0x50
	ldrb r0, [r0]
	cmp r0, #1
	bne _080047CC
	ldr r1, _080047C8 @ =0x0300137C
	movs r0, #0x30
	b _080047DE
	.align 2, 0
_080047C4: .4byte 0x03000440
_080047C8: .4byte 0x0300137C
_080047CC:
	bl copy_obj_palette_to_buffer
	adds r1, r4, #0
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080047E8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_080047DE:
	str r0, [r1]
_080047E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080047E8: .4byte 0x0300137C
	.syntax divided
