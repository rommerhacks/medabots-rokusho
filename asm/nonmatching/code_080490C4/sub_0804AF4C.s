	.syntax unified

	thumb_func_start sub_0804AF4C
sub_0804AF4C: @ 0x0804AF4C
	push {lr}
	ldr r1, _0804AF68 @ =0x030057A0
	ldrb r0, [r1, #0x11]
	cmp r0, #0
	bne _0804AF60
	movs r0, #1
	strb r0, [r1, #0x10]
	movs r0, #0
	bl sub_08058110
_0804AF60:
	bl sub_0804A1C4
	pop {r0}
	bx r0
	.align 2, 0
_0804AF68: .4byte 0x030057A0
	.syntax divided
