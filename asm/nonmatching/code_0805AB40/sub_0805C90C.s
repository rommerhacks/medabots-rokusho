	.syntax unified

	thumb_func_start sub_0805C90C
sub_0805C90C: @ 0x0805C90C
	push {lr}
	bl poll_choice_menu
	cmp r0, #0
	beq _0805C938
	ldr r0, _0805C928 @ =0x03000440
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805C930
	ldr r1, _0805C92C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _0805C936
	.align 2, 0
_0805C928: .4byte 0x03000440
_0805C92C: .4byte 0x0300137C
_0805C930:
	ldr r1, _0805C93C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #2
_0805C936:
	str r0, [r1]
_0805C938:
	pop {r0}
	bx r0
	.align 2, 0
_0805C93C: .4byte 0x0300137C
	.syntax divided
