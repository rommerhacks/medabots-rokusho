	.syntax unified

	thumb_func_start sub_08026EF8
sub_08026EF8: @ 0x08026EF8
	push {r4, lr}
	ldr r4, _08026F20 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl clear_ewram_buffer_02023000_b
	cmp r0, #0
	beq _08026F24
	subs r1, r0, #1
	adds r0, r4, #0
	adds r0, #0xd0
	strb r1, [r0]
	subs r0, #0x45
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #2
	b _08026F2C
	.align 2, 0
_08026F20: .4byte 0x03001800
_08026F24:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_08026F2C:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
