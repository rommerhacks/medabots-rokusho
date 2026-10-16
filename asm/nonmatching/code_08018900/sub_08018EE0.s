	.syntax unified

	thumb_func_start sub_08018EE0
sub_08018EE0: @ 0x08018EE0
	movs r2, #0
	ldr r1, _08018EFC @ =0x03000590
	lsls r0, r0, #8
	adds r1, #0x4c
	adds r1, r0, r1
_08018EEA:
	ldrb r0, [r1, #0xd]
	cmp r0, #0
	beq _08018F00
	ldrb r0, [r1]
	ldrb r3, [r1, #0xd]
	cmp r0, r3
	beq _08018F00
	adds r0, r2, #1
	b _08018F0A
	.align 2, 0
_08018EFC: .4byte 0x03000590
_08018F00:
	adds r1, #0x18
	adds r2, #1
	cmp r2, #3
	bls _08018EEA
	movs r0, #0
_08018F0A:
	bx lr
	.syntax divided
