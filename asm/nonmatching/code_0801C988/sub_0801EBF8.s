	.syntax unified

	thumb_func_start sub_0801EBF8
sub_0801EBF8: @ 0x0801EBF8
	push {r4, lr}
	ldr r1, _0801EC1C @ =0x03000590
	ldr r4, _0801EC20 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r2, [r0]
	lsls r0, r2, #8
	adds r0, r0, r1
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801EC24
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #3
	b _0801EC32
	.align 2, 0
_0801EC1C: .4byte 0x03000590
_0801EC20: .4byte 0x03001800
_0801EC24:
	adds r0, r2, #0
	bl add_bot_to_defeated_list
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_0801EC32:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
