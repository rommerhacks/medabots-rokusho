	.syntax unified

	thumb_func_start sub_0805CDF0
sub_0805CDF0: @ 0x0805CDF0
	push {r4, lr}
	ldr r4, _0805CE1C @ =0x03001780
	ldr r0, [r4]
	bl sub_0805CA28
	ldrb r1, [r4]
	movs r0, #0x53
	movs r2, #0x54
	bl sub_08041C14
	ldr r0, _0805CE20 @ =0x03006F74
	ldr r2, [r0]
	ldrb r0, [r2, #0x10]
	cmp r0, #0
	beq _0805CE24
	movs r1, #0x81
	lsls r1, r1, #0x12
	ldrb r0, [r2, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	b _0805CE26
	.align 2, 0
_0805CE1C: .4byte 0x03001780
_0805CE20: .4byte 0x03006F74
_0805CE24:
	movs r0, #0x3f
_0805CE26:
	ldr r1, _0805CE44 @ =0x084851CC
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _0805CE3E
	ldr r1, _0805CE48 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805CE3E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805CE44: .4byte 0x084851CC
_0805CE48: .4byte 0x0300137C
	.syntax divided
