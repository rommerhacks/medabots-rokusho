	.syntax unified

	thumb_func_start sub_0802F628
	.global sub_0802F628
sub_0802F628: @ 0x0802F628
	push {lr}
	ldr r1, _0802F648 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _0802F64C @ =0x083AEA84
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0802F648: .4byte 0x03001800
_0802F64C: .4byte 0x083AEA84
	.syntax divided
