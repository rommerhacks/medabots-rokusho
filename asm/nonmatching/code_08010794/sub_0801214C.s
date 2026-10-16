	.syntax unified

	thumb_func_start sub_0801214C
	.global sub_0801214C
sub_0801214C: @ 0x0801214C
	push {lr}
	ldr r0, _08012194 @ =0x03000440
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801218E
	movs r0, #0x32
	bl get_item_quantity_by_id
	cmp r0, #0
	beq _0801218E
	ldr r0, _08012198 @ =0x030057E0
	ldr r1, _0801219C @ =0x00000C2D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801218E
	ldr r1, _080121A0 @ =0x03002C30
	ldr r0, _080121A4 @ =0x0000C404
	strh r0, [r1]
	movs r0, #8
	strh r0, [r1, #2]
	movs r0, #0x50
	strh r0, [r1, #4]
	movs r0, #0xb
	strb r0, [r1, #0xa]
	movs r0, #0xc0
	strb r0, [r1, #0xb]
	movs r0, #0xe0
	lsls r0, r0, #3
	strh r0, [r1, #6]
_0801218E:
	pop {r0}
	bx r0
	.align 2, 0
_08012194: .4byte 0x03000440
_08012198: .4byte 0x030057E0
_0801219C: .4byte 0x00000C2D
_080121A0: .4byte 0x03002C30
_080121A4: .4byte 0x0000C404
	.syntax divided
