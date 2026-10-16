	.syntax unified

	thumb_func_start read_map_script_bytes
	.global read_map_script_bytes
read_map_script_bytes: @ 0x0804D880
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #0
	cmp r4, r5
	bge _0804D89C
	ldr r6, _0804D8A4 @ =0x03006474
_0804D88E:
	bl read_map_script_byte
	adds r1, r4, r6
	strb r0, [r1]
	adds r4, #1
	cmp r4, r5
	blt _0804D88E
_0804D89C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D8A4: .4byte 0x03006474
	.syntax divided
