	.syntax unified

	thumb_func_start sub_080241F0
sub_080241F0: @ 0x080241F0
	push {lr}
	movs r0, #0x21
	bl move_sprite_toward_target
	cmp r0, #0
	beq _08024206
	ldr r1, _0802420C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08024206:
	pop {r0}
	bx r0
	.align 2, 0
_0802420C: .4byte 0x03001800
	.syntax divided
