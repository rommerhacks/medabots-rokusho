	.syntax unified

	thumb_func_start sub_08024BCC
sub_08024BCC: @ 0x08024BCC
	push {lr}
	movs r0, #0x22
	movs r1, #0
	bl advance_sprite_anim_frame
	cmp r0, #0
	beq _08024BEC
	ldr r0, _08024BF0 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _08024BF4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08024BEC:
	pop {r0}
	bx r0
	.align 2, 0
_08024BF0: .4byte 0x03000440
_08024BF4: .4byte 0x03001800
	.syntax divided
