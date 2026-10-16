	.syntax unified

	thumb_func_start sub_0804AF6C
sub_0804AF6C: @ 0x0804AF6C
	push {lr}
	ldr r0, _0804AF7C @ =0x030057A0
	ldrb r0, [r0, #0x14]
	bl sub_08058214
	pop {r0}
	bx r0
	.align 2, 0
_0804AF7C: .4byte 0x030057A0
	.syntax divided
