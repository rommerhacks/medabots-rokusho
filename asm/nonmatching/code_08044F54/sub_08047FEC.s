	.syntax unified

	thumb_func_start sub_08047FEC
	.global sub_08047FEC
sub_08047FEC: @ 0x08047FEC
	push {r4, r5, lr}
	movs r5, #0
	ldr r0, _08048008 @ =0x030064A0
	adds r4, r0, #0
	adds r4, #0x64
	ldrb r0, [r4]
	cmp r0, #1
	beq _08048012
	cmp r0, #1
	bgt _0804800C
	cmp r0, #0
	beq _0804801A
	b _08048032
	.align 2, 0
_08048008: .4byte 0x030064A0
_0804800C:
	cmp r0, #2
	beq _0804802C
	b _08048032
_08048012:
	bl game_state_execute_handler_b
	cmp r0, #0
	beq _08048032
_0804801A:
	ldr r0, _08048028 @ =0x03000440
	strb r5, [r0, #0x1b]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08048032
	.align 2, 0
_08048028: .4byte 0x03000440
_0804802C:
	bl poll_choice_menu
	adds r5, r0, #0
_08048032:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
