	.syntax unified

	thumb_func_start sub_08047F50
	.global sub_08047F50
sub_08047F50: @ 0x08047F50
	movs r3, #0
	ldr r2, _08047F6C @ =0x030017A0
	movs r1, #8
_08047F56:
	ldrb r0, [r2]
	cmp r0, #3
	bne _08047F5E
	adds r3, #1
_08047F5E:
	adds r2, #8
	subs r1, #1
	cmp r1, #0
	bge _08047F56
	adds r0, r3, #0
	bx lr
	.align 2, 0
_08047F6C: .4byte 0x030017A0
	.syntax divided
