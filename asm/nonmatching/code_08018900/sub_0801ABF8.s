	.syntax unified

	thumb_func_start sub_0801ABF8
sub_0801ABF8: @ 0x0801ABF8
	push {lr}
	ldr r0, _0801AC1C @ =0x03001360
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801AC0C
	ldr r0, _0801AC20 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	bne _0801AC16
_0801AC0C:
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
_0801AC16:
	pop {r0}
	bx r0
	.align 2, 0
_0801AC1C: .4byte 0x03001360
_0801AC20: .4byte 0x03000440
	.syntax divided
