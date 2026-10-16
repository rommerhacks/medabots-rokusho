	.syntax unified

	thumb_func_start check_soft_reset
check_soft_reset: @ 0x08000964
	push {lr}
	ldr r0, _0800098C @ =0x03002B64
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0xf
	bne _08000994
	ldr r0, _08000990 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08000994
	bl soft_reset
	bl read_keys
	movs r0, #1
	b _08000996
	.align 2, 0
_0800098C: .4byte 0x03002B64
_08000990: .4byte 0x0300058C
_08000994:
	movs r0, #0
_08000996:
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
