	.syntax unified

	thumb_func_start sub_08032FFC
sub_08032FFC: @ 0x08032FFC
	movs r1, #0
	ldr r2, _0803300C @ =0x03001861
_08033000:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033010
	movs r0, #1
	b _08033018
	.align 2, 0
_0803300C: .4byte 0x03001861
_08033010:
	adds r1, #1
	cmp r1, #2
	bls _08033000
	movs r0, #0
_08033018:
	bx lr
	.align 2, 0
	.syntax divided
