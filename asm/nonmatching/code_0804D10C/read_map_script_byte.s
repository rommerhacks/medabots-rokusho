	.syntax unified

	thumb_func_start read_map_script_byte
	.global read_map_script_byte
read_map_script_byte: @ 0x0804D7F0
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r0, _0804D86C @ =0x03005590
	ldr r5, [r0]
	ldrb r1, [r5]
	ldrb r0, [r5, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldr r0, _0804D870 @ =0xFFFFC000
	mov r8, r0
	add r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrb r3, [r5, #2]
	ldrb r0, [r5, #3]
	lsls r0, r0, #8
	orrs r3, r0
	add r3, r8
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r6, _0804D874 @ =0x030057E0
	ldr r2, _0804D878 @ =0x00000C8E
	adds r0, r6, r2
	ldrh r0, [r0]
	mov sb, r0
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #7
	adds r4, r5, r0
	adds r0, r4, r1
	ldrb r2, [r0]
	adds r1, #1
	adds r1, r4, r1
	ldrb r0, [r1]
	lsls r0, r0, #8
	orrs r2, r0
	add r2, r8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sb
	adds r4, r4, r3
	ldrb r0, [r4]
	ldr r1, _0804D87C @ =0x00000C8A
	adds r6, r6, r1
	ldrh r1, [r6]
	adds r2, r2, r1
	lsls r0, r0, #0xe
	adds r2, r2, r0
	adds r5, r5, r2
	ldrb r0, [r5]
	adds r1, #1
	strh r1, [r6]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0804D86C: .4byte 0x03005590
_0804D870: .4byte 0xFFFFC000
_0804D874: .4byte 0x030057E0
_0804D878: .4byte 0x00000C8E
_0804D87C: .4byte 0x00000C8A
	.syntax divided
