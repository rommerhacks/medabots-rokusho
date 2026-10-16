	.syntax unified

	thumb_func_start sub_0801AC6C
sub_0801AC6C: @ 0x0801AC6C
	push {lr}
	ldr r0, _0801AC88 @ =0x03001360
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801AC80
	ldr r0, _0801AC8C @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	bne _0801AC90
_0801AC80:
	bl game_state_execute_handler_a
	b _0801AC92
	.align 2, 0
_0801AC88: .4byte 0x03001360
_0801AC8C: .4byte 0x03000440
_0801AC90:
	movs r0, #1
_0801AC92:
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
