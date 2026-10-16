	.syntax unified

	thumb_func_start sub_080223BC
	.global sub_080223BC
sub_080223BC: @ 0x080223BC
	push {lr}
	ldr r1, _080223DC @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xb5
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080223E0 @ =0x083ADB6C
	adds r1, #0xaa
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080223DC: .4byte 0x03001800
_080223E0: .4byte 0x083ADB6C
	.syntax divided
