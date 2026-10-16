	.syntax unified

	thumb_func_start sub_080081BC
sub_080081BC: @ 0x080081BC
	push {r4, lr}
	bl sub_080093F8
	bl sub_0800A180
	ldr r0, _080081F4 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #8
	bl sub_08041C14
	ldr r4, _080081F8 @ =0x083B7C00
	bl sub_0800A960
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _080081EE
	ldr r1, _080081FC @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
_080081EE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080081F4: .4byte 0x03001780
_080081F8: .4byte 0x083B7C00
_080081FC: .4byte 0x0300137C
	.syntax divided
