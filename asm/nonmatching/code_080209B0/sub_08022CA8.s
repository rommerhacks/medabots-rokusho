	.syntax unified

	thumb_func_start sub_08022CA8
	.global sub_08022CA8
sub_08022CA8: @ 0x08022CA8
	push {lr}
	ldr r1, _08022CC8 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08022CCC @ =0x083ADC0C
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08022CC8: .4byte 0x03001800
_08022CCC: .4byte 0x083ADC0C
	.syntax divided
