	.syntax unified

	thumb_func_start sub_08030CAC
sub_08030CAC: @ 0x08030CAC
	push {lr}
	ldr r0, _08030CDC @ =0x084E2EF8
	ldr r1, _08030CE0 @ =0x05000300
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08030CE4 @ =0x084E2F18
	ldr r1, _08030CE8 @ =0x05000320
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08030CEC @ =0x084E2F38
	ldr r1, _08030CF0 @ =0x05000340
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08030CF4 @ =0x03002B8C
	movs r0, #7
	str r0, [r1]
	ldr r1, _08030CF8 @ =0x0300137C
	movs r0, #0x46
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08030CDC: .4byte 0x084E2EF8
_08030CE0: .4byte 0x05000300
_08030CE4: .4byte 0x084E2F18
_08030CE8: .4byte 0x05000320
_08030CEC: .4byte 0x084E2F38
_08030CF0: .4byte 0x05000340
_08030CF4: .4byte 0x03002B8C
_08030CF8: .4byte 0x0300137C
	.syntax divided
