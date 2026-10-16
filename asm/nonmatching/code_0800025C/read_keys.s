	.syntax unified
	thumb_func_start read_keys
read_keys: @ 0x08000844
	push {r4, r5, r6, lr}
	ldr r0, _08000894 @ =0x03001790
	ldr r5, _08000898 @ =0x03002B64
	ldrh r2, [r5]
	strh r2, [r0]
	ldr r0, _0800089C @ =0x04000130
	ldrh r1, [r0]
	ldr r3, _080008A0 @ =0x000003FF
	adds r0, r3, #0
	eors r1, r0
	strh r1, [r5]
	ldr r6, _080008A4 @ =0x0300058C
	adds r3, r1, #0
	bics r3, r2
	strh r3, [r6]
	ldr r0, _080008A8 @ =0x03001C00
	bics r2, r1
	strh r2, [r0]
	ldr r4, _080008AC @ =0x03001798
	movs r0, #0
	strh r0, [r4]
	cmp r3, #0
	beq _0800087A
	strh r3, [r4]
	ldr r1, _080008B0 @ =0x03002418
	movs r0, #0x10
	strb r0, [r1]
_0800087A:
	ldrh r2, [r5]
	cmp r2, #0
	beq _080008B8
	ldr r1, _080008B0 @ =0x03002418
	ldrb r0, [r1]
	cmp r0, #0
	bne _080008B4
	ldrh r0, [r6]
	orrs r0, r2
	strh r0, [r4]
	movs r0, #3
	b _080008B6
	.align 2, 0
_08000894: .4byte 0x03001790
_08000898: .4byte 0x03002B64
_0800089C: .4byte 0x04000130
_080008A0: .4byte 0x000003FF
_080008A4: .4byte 0x0300058C
_080008A8: .4byte 0x03001C00
_080008AC: .4byte 0x03001798
_080008B0: .4byte 0x03002418
_080008B4:
	subs r0, #1
_080008B6:
	strb r0, [r1]
_080008B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	.syntax divided
