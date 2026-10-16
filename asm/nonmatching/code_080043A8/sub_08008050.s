	.syntax unified

	thumb_func_start sub_08008050
sub_08008050: @ 0x08008050
	push {lr}
	bl sub_080093F8
	bl sub_0800A180
	ldr r0, _0800807C @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #8
	bl sub_08041C14
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _08008080 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800807C: .4byte 0x03001780
_08008080: .4byte 0x0300137C
	.syntax divided
