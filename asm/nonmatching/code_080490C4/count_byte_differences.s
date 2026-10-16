	.syntax unified

	thumb_func_start count_byte_differences
count_byte_differences: @ 0x080496F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r5, #0
	cmp r5, r2
	bge _08049714
_08049700:
	ldrb r1, [r4]
	ldrb r0, [r3]
	adds r3, #1
	adds r4, #1
	cmp r1, r0
	beq _0804970E
	adds r5, #1
_0804970E:
	subs r2, #1
	cmp r2, #0
	bne _08049700
_08049714:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
_0804971C:
	.byte 0x02, 0x1C, 0x00, 0x23
	.byte 0x8B, 0x42, 0x05, 0xDA, 0x10, 0x78, 0x1B, 0x18, 0x01, 0x32, 0x01, 0x39, 0x00, 0x29, 0xF9, 0xD1
	.byte 0x18, 0x1C, 0x70, 0x47
	.syntax divided
