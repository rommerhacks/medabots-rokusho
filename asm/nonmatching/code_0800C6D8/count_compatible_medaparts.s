	.syntax unified

	thumb_func_start count_compatible_medaparts
count_compatible_medaparts: @ 0x0800FC60
	push {r4, r5, r6, r7, lr}
	ldr r1, _0800FCE4 @ =0x03000440
	adds r2, r1, #0
	adds r2, #0x41
	movs r0, #0
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0800FCDE
	movs r5, #0
	adds r4, r1, #0
	adds r7, r4, #0
	adds r7, #0x3e
	adds r6, r2, #0
_0800FC86:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r7]
	bl sub_08042114
	lsls r1, r0, #0x10
	lsrs r2, r1, #0x10
	cmp r2, #0
	beq _0800FCD8
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #1
	bne _0800FCD2
	lsrs r1, r1, #0x18
	movs r0, #0xff
	ands r0, r2
	cmp r1, r0
	beq _0800FCD8
	ldrb r1, [r7]
	adds r0, r5, #0
	movs r3, #0x87
	lsls r3, r3, #1
	adds r2, r4, r3
	bl load_part_data
	ldr r1, _0800FCE8 @ =0x030017A0
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r2, _0800FCEC @ =0x00000111
	adds r1, r4, r2
	ldrb r0, [r0, #1]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0800FCD8
_0800FCD2:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_0800FCD8:
	adds r5, #1
	cmp r5, #0x77
	bls _0800FC86
_0800FCDE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FCE4: .4byte 0x03000440
_0800FCE8: .4byte 0x030017A0
_0800FCEC: .4byte 0x00000111
	.syntax divided
