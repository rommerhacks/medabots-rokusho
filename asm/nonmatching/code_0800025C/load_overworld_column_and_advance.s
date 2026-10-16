	.syntax unified

	thumb_func_start load_overworld_column_and_advance
load_overworld_column_and_advance: @ 0x080026A4
	push {lr}
	sub sp, #8
	ldr r0, _080026D8 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x88
	ldrb r1, [r1]
	str r1, [sp]
	adds r0, #0x85
	ldrb r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #1
	movs r2, #8
	movs r3, #4
	bl load_overworld_map_column
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	bne _080026D0
	ldr r0, _080026DC @ =0x0300137C
	str r1, [r0]
_080026D0:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_080026D8: .4byte 0x03000440
_080026DC: .4byte 0x0300137C
	.syntax divided
