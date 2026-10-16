	.syntax unified

	thumb_func_start sub_08018900
	.global sub_08018900
sub_08018900: @ 0x08018900
	push {r4, r5, r6, lr}
	cmp r0, #2
	bhi _080189DA
	ldr r6, _0801892C @ =0x03000590
	lsls r5, r0, #8
	adds r2, r5, r6
	adds r0, r2, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	cmp r1, #0
	beq _080189DA
	cmp r1, #3
	bhi _08018930
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r5
	adds r0, r0, r6
	adds r0, #0x4a
	ldrb r1, [r0]
	b _080189CC
	.align 2, 0
_0801892C: .4byte 0x03000590
_08018930:
	ldrb r0, [r0]
	subs r0, #4
	cmp r0, #1
	beq _08018970
	cmp r0, #1
	bgt _08018942
	cmp r0, #0
	beq _08018948
	b _080189DA
_08018942:
	cmp r0, #2
	beq _08018998
	b _080189DA
_08018948:
	ldrb r0, [r2, #5]
	cmp r0, #9
	bls _080189DA
	ldrb r1, [r2, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08018968 @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _0801896C @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r1, [r4]
	b _080189B4
	.align 2, 0
_08018968: .4byte 0x083B7E0C
_0801896C: .4byte 0x0300052E
_08018970:
	ldrb r0, [r2, #5]
	cmp r0, #0x1d
	bls _080189DA
	ldrb r1, [r2, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _08018990 @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _08018994 @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r1, [r4, #1]
	b _080189B4
	.align 2, 0
_08018990: .4byte 0x083B7E0C
_08018994: .4byte 0x0300052E
_08018998:
	ldrb r0, [r2, #5]
	cmp r0, #0x3b
	bls _080189DA
	ldrb r1, [r2, #1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r1, _080189E0 @ =0x083B7E0C
	adds r0, r0, r1
	ldr r4, _080189E4 @ =0x0300052E
	adds r1, r4, #0
	movs r2, #3
	bl memcpy_bytes_08041D04
	ldrb r1, [r4, #2]
_080189B4:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _080189E8 @ =0x083B7CD4
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x20
	movs r2, #6
	bl memcpy_bytes_08041D04
	adds r4, #0x21
	ldrb r1, [r4]
_080189CC:
	adds r1, r1, r5
	adds r0, r6, #0
	adds r0, #0xb0
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080189DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080189E0: .4byte 0x083B7E0C
_080189E4: .4byte 0x0300052E
_080189E8: .4byte 0x083B7CD4
	.syntax divided
