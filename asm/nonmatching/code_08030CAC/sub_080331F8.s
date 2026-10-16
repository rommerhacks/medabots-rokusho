	.syntax unified

	thumb_func_start sub_080331F8
	.global sub_080331F8
sub_080331F8: @ 0x080331F8
	movs r2, #0
	ldr r1, _08033214 @ =0x03000590
	lsls r0, r0, #8
	adds r1, #0x49
	adds r1, r0, r1
_08033202:
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	beq _08033218
	ldrb r0, [r1]
	cmp r0, #0x16
	bne _08033218
	movs r0, #0
	b _08033222
	.align 2, 0
_08033214: .4byte 0x03000590
_08033218:
	adds r1, #0x18
	adds r2, #1
	cmp r2, #2
	bls _08033202
	movs r0, #1
_08033222:
	bx lr
	.syntax divided
