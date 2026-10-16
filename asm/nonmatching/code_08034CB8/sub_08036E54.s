	.syntax unified

	thumb_func_start sub_08036E54
	.global sub_08036E54
sub_08036E54: @ 0x08036E54
	cmp r0, #0x63
	bls _08036E5C
	movs r0, #0x63
	b _08036E62
_08036E5C:
	cmp r0, #0
	bne _08036E62
	movs r0, #1
_08036E62:
	bx lr
	.syntax divided
