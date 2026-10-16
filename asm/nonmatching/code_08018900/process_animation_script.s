	.syntax unified

	thumb_func_start process_animation_script
	.global process_animation_script
process_animation_script: @ 0x0801BD58
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _0801BD9C @ =0x03000440
	lsls r1, r1, #3
	adds r1, r1, r0
	adds r2, r1, #0
	adds r2, #0x66
	ldrb r0, [r2]
	cmp r0, #0xff
	beq _0801BE32
	mov r8, r1
	str r2, [sp]
	movs r0, #0x64
	add r0, r8
	mov sb, r0
	mov r6, r8
	adds r5, r6, #0
	adds r5, #0x65
	movs r1, #0x67
	adds r1, r1, r6
	mov sl, r1
_0801BD8C:
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #0
	beq _0801BDA0
	subs r0, #1
	strb r0, [r3]
	b _0801BE32
	.align 2, 0
_0801BD9C: .4byte 0x03000440
_0801BDA0:
	mov r4, r8
	adds r4, #0x65
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrb r1, [r0]
	cmp r1, #0xfe
	beq _0801BDCE
	cmp r1, #0xfe
	bgt _0801BDBA
	cmp r1, #0xfd
	beq _0801BDC0
	b _0801BDDE
_0801BDBA:
	cmp r1, #0xff
	beq _0801BDD6
	b _0801BDDE
_0801BDC0:
	ldrh r0, [r0, #2]
	bl play_sound_effect
	ldrb r0, [r4]
	adds r0, #2
	strb r0, [r4]
	b _0801BE2C
_0801BDCE:
	ldrh r0, [r0, #2]
	lsls r0, r0, #1
	strb r0, [r4]
	b _0801BE2C
_0801BDD6:
	movs r0, #0xff
	ldr r1, [sp]
	strb r0, [r1]
	b _0801BE32
_0801BDDE:
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x64
	strb r1, [r0]
	adds r0, #4
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r1, r6, #0
	adds r1, #0x6a
	ldrh r2, [r1]
	ldrb r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r1, [r1, #2]
	lsls r1, r1, #5
	muls r1, r2, r1
	movs r3, #0x80
	lsls r3, r3, #0x12
	adds r1, r1, r3
	adds r0, r0, r1
	mov r1, sl
	ldrb r3, [r1]
	lsls r1, r3, #3
	adds r1, r1, r3
	lsls r1, r1, #9
	ldr r3, _0801BE44 @ =0x06004000
	adds r1, r1, r3
	lsls r2, r2, #3
	movs r3, #0x80
	lsls r3, r3, #0x13
	orrs r2, r3
	bl CpuSet
	ldrb r0, [r5]
	adds r0, #2
	strb r0, [r5]
_0801BE2C:
	movs r0, #1
	cmp r0, #0
	bne _0801BD8C
_0801BE32:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801BE44: .4byte 0x06004000
	.syntax divided
