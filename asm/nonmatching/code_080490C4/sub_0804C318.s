	.syntax unified

	thumb_func_start sub_0804C318
sub_0804C318: @ 0x0804C318
	push {lr}
	bl read_map_script_byte
	ldr r2, _0804C340 @ =0x030057E0
	ldr r3, _0804C344 @ =0x00000C94
	adds r1, r2, r3
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0804C34C
	ldr r0, _0804C348 @ =0x00000C5D
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #0xef
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	b _0804C356
	.align 2, 0
_0804C340: .4byte 0x030057E0
_0804C344: .4byte 0x00000C94
_0804C348: .4byte 0x00000C5D
_0804C34C:
	ldr r3, _0804C35C @ =0x00000C5D
	adds r2, r2, r3
	ldrb r1, [r2]
	movs r0, #0xef
	ands r0, r1
_0804C356:
	strb r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0804C35C: .4byte 0x00000C5D
	.syntax divided
