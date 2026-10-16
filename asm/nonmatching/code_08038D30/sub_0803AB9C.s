	.syntax unified

	thumb_func_start sub_0803AB9C
sub_0803AB9C: @ 0x0803AB9C
	push {lr}
	ldr r0, _0803ABD8 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803ABFC
	ldr r0, _0803ABDC @ =0x05000300
	ldr r1, _0803ABE0 @ =0x0202F900
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803ABE4 @ =0x05000320
	ldr r1, _0803ABE8 @ =0x0202F920
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803ABEC @ =0x05000340
	ldr r1, _0803ABF0 @ =0x0202F940
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803ABF4 @ =0x05000360
	ldr r1, _0803ABF8 @ =0x0202F960
	movs r2, #8
	bl CpuFastSet
	b _0803AC24
	.align 2, 0
_0803ABD8: .4byte 0x03001800
_0803ABDC: .4byte 0x05000300
_0803ABE0: .4byte 0x0202F900
_0803ABE4: .4byte 0x05000320
_0803ABE8: .4byte 0x0202F920
_0803ABEC: .4byte 0x05000340
_0803ABF0: .4byte 0x0202F940
_0803ABF4: .4byte 0x05000360
_0803ABF8: .4byte 0x0202F960
_0803ABFC:
	ldr r0, _0803AC2C @ =0x05000280
	ldr r1, _0803AC30 @ =0x0202F880
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803AC34 @ =0x050002A0
	ldr r1, _0803AC38 @ =0x0202F8A0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803AC3C @ =0x050002C0
	ldr r1, _0803AC40 @ =0x0202F8C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0803AC44 @ =0x050002E0
	ldr r1, _0803AC48 @ =0x0202F8E0
	movs r2, #8
	bl CpuFastSet
_0803AC24:
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
_0803AC2C: .4byte 0x05000280
_0803AC30: .4byte 0x0202F880
_0803AC34: .4byte 0x050002A0
_0803AC38: .4byte 0x0202F8A0
_0803AC3C: .4byte 0x050002C0
_0803AC40: .4byte 0x0202F8C0
_0803AC44: .4byte 0x050002E0
_0803AC48: .4byte 0x0202F8E0
	.syntax divided
