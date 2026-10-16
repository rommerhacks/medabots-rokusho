	.syntax unified

	thumb_func_start sub_080337CC
sub_080337CC: @ 0x080337CC
	push {r4, r5, r6, r7, lr}
	ldr r4, _08033834 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r2, _08033838 @ =0x03000590
	ldrb r0, [r1]
	adds r7, r4, #0
	lsls r0, r0, #8
	adds r1, r2, #0
	adds r1, #0x40
	adds r4, r0, r1
	adds r6, r2, #0
	adds r6, #0x49
	movs r2, #0x80
	lsls r2, r2, #1
_080337F8:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803381E
	movs r3, #0
	ldr r0, _0803383C @ =0x03001860
	ldrb r0, [r0]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r1, r0, r6
_0803380A:
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	beq _08033816
	ldrb r0, [r1]
	cmp r0, #0x34
	beq _0803382E
_08033816:
	adds r1, #0x18
	adds r3, #1
	cmp r3, #2
	bls _0803380A
_0803381E:
	adds r4, r4, r2
	adds r5, #1
	cmp r5, #2
	bls _080337F8
	adds r1, r7, #0
	adds r1, #0x51
	movs r0, #1
	strb r0, [r1]
_0803382E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033834: .4byte 0x03001800
_08033838: .4byte 0x03000590
_0803383C: .4byte 0x03001860
	.syntax divided
