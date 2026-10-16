	.syntax unified

	thumb_func_start sub_0801F4AC
sub_0801F4AC: @ 0x0801F4AC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _0801F548 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xb7
	ldrb r1, [r0]
	movs r0, #1
	mov sb, r0
	ands r0, r1
	cmp r0, #0
	bne _0801F594
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r1, [r0]
	movs r0, #2
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	bne _0801F594
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0801F594
	ldr r6, _0801F54C @ =0x03000590
	adds r5, r4, #0
	adds r5, #0x88
	ldrb r1, [r5]
	lsls r0, r1, #8
	adds r0, r0, r6
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801F594
	adds r0, r1, #0
	bl sub_080331F8
	cmp r0, #0
	beq _0801F594
	ldrb r0, [r5]
	adds r7, r4, #0
	adds r7, #0xa7
	ldrb r2, [r7]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r2, [r5]
	lsls r2, r2, #8
	adds r1, r1, r2
	adds r1, r1, r6
	adds r1, #0x49
	ldrb r1, [r1]
	bl sub_08036D64
	adds r2, r0, #0
	cmp r2, #0
	bne _0801F594
	ldrb r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, r1, r6
	adds r1, #0x49
	ldrb r0, [r1]
	cmp r0, #0xd
	beq _0801F540
	cmp r0, #0xe
	bne _0801F550
_0801F540:
	adds r0, r4, #0
	adds r0, #0x51
	strb r2, [r0]
	b _0801F560
	.align 2, 0
_0801F548: .4byte 0x03001800
_0801F54C: .4byte 0x03000590
_0801F550:
	cmp r0, #0xf
	beq _0801F558
	cmp r0, #0x10
	bne _0801F568
_0801F558:
	adds r0, r4, #0
	adds r0, #0x51
	mov r1, sb
	strb r1, [r0]
_0801F560:
	adds r0, #0x59
	mov r1, r8
	strb r1, [r0]
	b _0801F59E
_0801F568:
	cmp r0, #0x11
	beq _0801F570
	cmp r0, #0x12
	bne _0801F57E
_0801F570:
	adds r0, r4, #0
	adds r0, #0x51
	movs r1, #2
	strb r1, [r0]
	adds r0, #0x59
	strb r1, [r0]
	b _0801F59E
_0801F57E:
	cmp r0, #0x13
	beq _0801F586
	cmp r0, #0x14
	bne _0801F594
_0801F586:
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #3
	strb r0, [r1]
	adds r1, #0x59
	movs r0, #2
	b _0801F59C
_0801F594:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_0801F59C:
	strb r0, [r1]
_0801F59E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F5AC:
	.byte 0x02, 0x48, 0xB5, 0x30
	.byte 0x01, 0x21, 0x01, 0x70, 0x70, 0x47, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03
	.syntax divided
