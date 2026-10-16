	.syntax unified

	thumb_func_start sub_0804FE20
sub_0804FE20: @ 0x0804FE20
	push {lr}
	ldr r2, _0804FE44 @ =0x030057E0
	ldr r1, _0804FE48 @ =0x00000C36
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804FE3E
	ldr r3, _0804FE4C @ =0x00000C94
	adds r0, r2, r3
	ldrb r1, [r0]
	subs r3, #0x60
	adds r0, r2, r3
	strb r1, [r0]
	bl sub_08050244
_0804FE3E:
	pop {r0}
	bx r0
	.align 2, 0
_0804FE44: .4byte 0x030057E0
_0804FE48: .4byte 0x00000C36
_0804FE4C: .4byte 0x00000C94
	.syntax divided
