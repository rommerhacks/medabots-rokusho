	.syntax unified

	thumb_func_start sub_0802CA5C
sub_0802CA5C: @ 0x0802CA5C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	movs r4, #0
	ldr r0, _0802CAC0 @ =0x030018D2
	mov sb, r0
	ldr r1, _0802CAC4 @ =0x083B608C
	mov r8, r1
	ldr r0, _0802CAC8 @ =0x03002C30
	ldr r1, _0802CACC @ =0x00000862
	adds r6, r0, r1
	movs r5, #0x84
	lsls r5, r5, #0x16
_0802CA7A:
	mov r1, sb
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CA96
	mov r1, r8
	ldr r0, [r1]
	lsrs r1, r5, #0x18
	bl process_sprite_anim_commands
	ldrb r0, [r6]
	cmp r0, #0xff
	bne _0802CA96
	movs r7, #1
_0802CA96:
	adds r6, #0x40
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #2
	bls _0802CA7A
	cmp r7, #0
	beq _0802CAB2
	ldr r1, _0802CAD0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802CAB2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CAC0: .4byte 0x030018D2
_0802CAC4: .4byte 0x083B608C
_0802CAC8: .4byte 0x03002C30
_0802CACC: .4byte 0x00000862
_0802CAD0: .4byte 0x03001800
	.syntax divided
