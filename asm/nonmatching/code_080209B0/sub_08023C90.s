	.syntax unified

	thumb_func_start sub_08023C90
	.global sub_08023C90
sub_08023C90: @ 0x08023C90
	push {lr}
	ldr r1, _08023CB0 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08023CB4 @ =0x083ADDE0
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08023CB0: .4byte 0x03001800
_08023CB4: .4byte 0x083ADDE0
	.syntax divided
