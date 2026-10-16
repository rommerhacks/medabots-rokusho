	.syntax unified

	thumb_func_start sub_0800A2B4
	.global sub_0800A2B4
sub_0800A2B4: @ 0x0800A2B4
	push {lr}
	ldr r0, _0800A2E4 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0800A2DE
	bl sub_08009E4C
	bl sub_08009EF4
	bl sub_08009F50
	bl sub_08009F90
	bl sub_0800A000
	bl sub_0800A05C
	bl sub_0800A0B8
_0800A2DE:
	pop {r0}
	bx r0
	.align 2, 0
_0800A2E4: .4byte 0x03001798
	.syntax divided
