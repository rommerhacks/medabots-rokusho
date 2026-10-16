	.syntax unified

	thumb_func_start sub_08011FEC
	.global sub_08011FEC
sub_08011FEC: @ 0x08011FEC
	push {r4, r5, r6, lr}
	sub sp, #4
	movs r5, #0
	ldr r0, _08012020 @ =0x03001800
	ldrb r1, [r0, #2]
	cmp r5, r1
	bhs _08012016
	adds r6, r0, #0
	adds r4, r6, #4
_08011FFE:
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	str r5, [sp]
	bl decompress_sprite_to_vram_08042D94
	adds r4, #0xc
	adds r5, #1
	ldrb r0, [r6, #2]
	cmp r5, r0
	blo _08011FFE
_08012016:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08012020: .4byte 0x03001800
	.syntax divided
