	.syntax unified

	thumb_func_start advance_battle_animation_frame
advance_battle_animation_frame: @ 0x08043FEC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r4, _08044080 @ =0x03001800
	adds r1, r4, #0
	adds r1, #0x7d
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	mov sb, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08044074
	mov r0, sb
	strb r0, [r1]
	adds r6, r4, #0
	adds r6, #0x7c
	ldrb r0, [r6]
	adds r0, #1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r6]
	ldr r0, _08044084 @ =0x083C40B8
	adds r0, r5, r0
	movs r1, #0x7e
	adds r1, r1, r4
	mov r8, r1
	movs r2, #1
	bl memcpy_bytes_08041D04
	lsls r5, r5, #7
	ldrb r0, [r6]
	adds r0, r5, r0
	ldr r7, _08044088 @ =0x083C40C3
	adds r0, r0, r7
	adds r4, #0x7f
	adds r1, r4, #0
	movs r2, #1
	bl memcpy_bytes_08041D04
	ldrb r0, [r4]
	cmp r0, #0xff
	bne _08044058
	mov r2, sb
	strb r2, [r6]
	adds r0, r5, r7
	adds r1, r4, #0
	movs r2, #1
	bl memcpy_bytes_08041D04
_08044058:
	mov r0, r8
	ldrb r2, [r0]
	ldrb r0, [r4]
	muls r0, r2, r0
	lsls r0, r0, #5
	ldr r1, _0804408C @ =0x02027000
	adds r0, r0, r1
	ldr r1, _08044090 @ =0x06008020
	lsls r2, r2, #3
	movs r3, #0x80
	lsls r3, r3, #0x13
	orrs r2, r3
	bl CpuSet
_08044074:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044080: .4byte 0x03001800
_08044084: .4byte 0x083C40B8
_08044088: .4byte 0x083C40C3
_0804408C: .4byte 0x02027000
_08044090: .4byte 0x06008020
	.syntax divided
