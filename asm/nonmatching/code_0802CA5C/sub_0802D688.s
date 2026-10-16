	.syntax unified

	thumb_func_start sub_0802D688
	.global sub_0802D688
sub_0802D688: @ 0x0802D688
	push {lr}
	ldr r1, _0802D6A8 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _0802D6AC @ =0x083AE8B0
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0802D6A8: .4byte 0x03001800
_0802D6AC: .4byte 0x083AE8B0
	.syntax divided
