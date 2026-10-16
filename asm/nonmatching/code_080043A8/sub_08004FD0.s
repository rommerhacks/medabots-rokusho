	.syntax unified

	thumb_func_start sub_08004FD0
	.global sub_08004FD0
sub_08004FD0: @ 0x08004FD0
	push {r4, r5, lr}
	sub sp, #4
	movs r5, #0
	ldr r4, _08004FFC @ =0x030017A0
_08004FD8:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08004FEC
	ldrb r0, [r4, #3]
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #5]
	ldrb r3, [r4, #6]
	str r5, [sp]
	bl decompress_sprite_to_vram_08042D94
_08004FEC:
	adds r4, #8
	adds r5, #1
	cmp r5, #8
	bls _08004FD8
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08004FFC: .4byte 0x030017A0
	.syntax divided
