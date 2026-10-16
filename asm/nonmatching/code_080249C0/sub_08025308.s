	.syntax unified

	thumb_func_start sub_08025308
sub_08025308: @ 0x08025308
	push {lr}
	movs r0, #0x21
	bl sub_08037424
	ldr r0, _08025338 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #0
	bne _08025326
	ldr r0, _0802533C @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08025340
_08025326:
	ldr r0, _08025338 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0
	beq _08025340
	subs r0, #1
	strh r0, [r1]
	b _0802534A
	.align 2, 0
_08025338: .4byte 0x03000440
_0802533C: .4byte 0x03001798
_08025340:
	ldr r1, _08025350 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802534A:
	pop {r0}
	bx r0
	.align 2, 0
_08025350: .4byte 0x03001800
	.syntax divided
