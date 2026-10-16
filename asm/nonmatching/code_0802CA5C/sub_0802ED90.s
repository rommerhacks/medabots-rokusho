	.syntax unified

	thumb_func_start sub_0802ED90
sub_0802ED90: @ 0x0802ED90
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r6, #0
	movs r5, #0
	ldr r0, _0802EDFC @ =0x030018D2
	mov sb, r0
	ldr r1, _0802EE00 @ =0x083B5F80
	mov r8, r1
	ldr r7, _0802EE04 @ =0x030004C4
_0802EDA6:
	mov r1, sb
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EDD4
	ldrb r0, [r7]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	adds r4, r5, #0
	adds r4, #0x21
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	ldr r0, _0802EE08 @ =0x03002C30
	lsls r4, r4, #6
	adds r4, r4, r0
	adds r4, #0x22
	ldrb r0, [r4]
	cmp r0, #0xff
	bne _0802EDD4
	movs r6, #1
_0802EDD4:
	adds r5, #1
	cmp r5, #2
	bls _0802EDA6
	cmp r6, #0
	beq _0802EDF0
	ldr r0, _0802EE0C @ =0x03000440
	adds r0, #0x86
	movs r1, #0x20
	strh r1, [r0]
	ldr r1, _0802EE10 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802EDF0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EDFC: .4byte 0x030018D2
_0802EE00: .4byte 0x083B5F80
_0802EE04: .4byte 0x030004C4
_0802EE08: .4byte 0x03002C30
_0802EE0C: .4byte 0x03000440
_0802EE10: .4byte 0x03001800
	.syntax divided
