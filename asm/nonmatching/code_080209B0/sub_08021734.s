	.syntax unified

	thumb_func_start sub_08021734
sub_08021734: @ 0x08021734
	push {r4, lr}
	movs r0, #0x21
	bl move_sprite_toward_target
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r4, r1, #0x1f
	movs r0, #0x22
	bl move_sprite_toward_target
	cmp r0, #0
	beq _0802174E
	adds r4, #1
_0802174E:
	movs r0, #0x23
	bl move_sprite_toward_target
	cmp r0, #0
	beq _0802175A
	adds r4, #1
_0802175A:
	cmp r4, #3
	bne _08021768
	ldr r1, _08021770 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08021768:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021770: .4byte 0x03001800
	.syntax divided
