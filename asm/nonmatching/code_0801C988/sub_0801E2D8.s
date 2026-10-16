	.syntax unified

	thumb_func_start sub_0801E2D8
	.global sub_0801E2D8
sub_0801E2D8: @ 0x0801E2D8
	push {lr}
	ldr r1, _0801E2F8 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _0801E2FC @ =0x083AD610
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0801E2F8: .4byte 0x03001800
_0801E2FC: .4byte 0x083AD610
	.syntax divided
