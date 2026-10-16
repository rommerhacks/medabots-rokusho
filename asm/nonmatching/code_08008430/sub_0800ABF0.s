	.syntax unified

	thumb_func_start sub_0800ABF0
sub_0800ABF0: @ 0x0800ABF0
	push {lr}
	ldr r0, _0800AC28 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0800AC22
	bl sub_08009E4C
	bl sub_08009EF4
	bl sub_08009F50
	bl sub_08009F90
	bl sub_0800AB0C
	bl sub_0800ABA4
	bl sub_0800AED0
	bl sub_0800AF0C
	bl sub_0800AF64
_0800AC22:
	pop {r0}
	bx r0
	.align 2, 0
_0800AC28: .4byte 0x03001798
	.syntax divided
