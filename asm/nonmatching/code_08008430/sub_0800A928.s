	.syntax unified

	thumb_func_start sub_0800A928
	.global sub_0800A928
sub_0800A928: @ 0x0800A928
	push {lr}
	ldr r0, _0800A93C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	bne _0800A940
	movs r0, #0
	b _0800A95A
	.align 2, 0
_0800A93C: .4byte 0x03001798
_0800A940:
	bl sub_08009E4C
	bl sub_08009EF4
	bl sub_08009F50
	bl sub_08009F90
	bl sub_0800A2E8
	bl sub_0800A594
	movs r0, #1
_0800A95A:
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
