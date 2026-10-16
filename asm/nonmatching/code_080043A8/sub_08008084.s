	.syntax unified

	thumb_func_start sub_08008084
sub_08008084: @ 0x08008084
	push {r4, lr}
	bl sub_080093F8
	bl sub_0800A180
	ldr r0, _080080BC @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #8
	bl sub_08041C14
	ldr r4, _080080C0 @ =0x083B7C00
	bl sub_0800A960
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _080080B6
	ldr r1, _080080C4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080080B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080080BC: .4byte 0x03001780
_080080C0: .4byte 0x083B7C00
_080080C4: .4byte 0x0300137C
	.syntax divided
