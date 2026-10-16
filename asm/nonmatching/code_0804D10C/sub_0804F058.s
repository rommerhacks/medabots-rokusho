	.syntax unified

	thumb_func_start sub_0804F058
sub_0804F058: @ 0x0804F058
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
	movs r6, #0
	movs r5, #0
	ldr r0, _0804F0A0 @ =0x030055A0
	mov r8, r0
_0804F068:
	lsls r0, r5, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	bl sub_0804DBA4
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _0804F0A6
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	beq _0804F0A4
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_080507E0
	adds r6, r6, r0
	b _0804F0A6
	.align 2, 0
_0804F0A0: .4byte 0x030055A0
_0804F0A4:
	adds r7, #1
_0804F0A6:
	adds r5, #1
	cmp r5, #3
	ble _0804F068
	cmp r7, #4
	bne _0804F0B2
	movs r6, #1
_0804F0B2:
	cmp r6, #0
	beq _0804F0BA
	bl sub_08050244
_0804F0BA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
