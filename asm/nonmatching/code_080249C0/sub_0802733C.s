	.syntax unified

	thumb_func_start sub_0802733C
sub_0802733C: @ 0x0802733C
	push {r4, r5, lr}
	ldr r5, _08027370 @ =0x03000440
	adds r4, r5, #0
	adds r4, #0x86
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	bl sub_080378A8
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _0802736A
	bl copy_obj_palette_to_buffer
	adds r1, r5, #0
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08027374 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802736A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08027370: .4byte 0x03000440
_08027374: .4byte 0x03001800
	.syntax divided
