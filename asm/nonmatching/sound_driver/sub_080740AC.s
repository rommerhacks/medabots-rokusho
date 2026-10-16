	.syntax unified

	thumb_func_start sub_080740AC
sub_080740AC: @ 0x080740AC
	adds r3, r0, #0
	ldr r2, [r3, #8]
	cmp r2, #0
	bne _080740B8
	movs r0, #0xff
	b _080740D0
_080740B8:
	adds r0, r2, #0
	adds r0, #0x30
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x6b
	ldrb r0, [r0]
	subs r0, r1, r0
	cmp r0, #0
	bge _080740CC
	adds r0, #0x30
_080740CC:
	adds r0, r2, r0
	ldrb r0, [r0]
_080740D0:
	bx lr
	.align 2, 0
	.syntax divided
