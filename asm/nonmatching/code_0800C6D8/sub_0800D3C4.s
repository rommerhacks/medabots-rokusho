	.syntax unified

	thumb_func_start sub_0800D3C4
sub_0800D3C4: @ 0x0800D3C4
	push {lr}
	ldr r1, _0800D3DC @ =0x083AC9AC
	ldr r0, _0800D3E0 @ =0x03000440
	adds r0, #0x33
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800D3DC: .4byte 0x083AC9AC
_0800D3E0: .4byte 0x03000440
	.syntax divided
