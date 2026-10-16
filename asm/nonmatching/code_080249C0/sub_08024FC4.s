	.syntax unified

	thumb_func_start sub_08024FC4
sub_08024FC4: @ 0x08024FC4
	push {r4, r5, lr}
	ldr r2, _08024FE4 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	bne _08024FF0
	ldr r3, _08024FE8 @ =0x03002C30
	ldr r0, _08024FEC @ =0x00000858
	adds r2, r3, r0
	ldrh r0, [r2]
	subs r0, #0x80
	b _08024FFA
	.align 2, 0
_08024FE4: .4byte 0x03001800
_08024FE8: .4byte 0x03002C30
_08024FEC: .4byte 0x00000858
_08024FF0:
	ldr r3, _08025014 @ =0x03002C30
	ldr r0, _08025018 @ =0x00000858
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #0x80
_08024FFA:
	ldr r5, _0802501C @ =0x000003FF
	adds r1, r5, #0
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08025020 @ =0x00000848
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, #0x80
	bne _08025024
	adds r1, r4, #0
	adds r1, #0xaa
	b _0802502C
	.align 2, 0
_08025014: .4byte 0x03002C30
_08025018: .4byte 0x00000858
_0802501C: .4byte 0x000003FF
_08025020: .4byte 0x00000848
_08025024:
	adds r0, #1
	strb r0, [r2]
	ldr r5, _08025038 @ =0x00000849
	adds r1, r3, r5
_0802502C:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08025038: .4byte 0x00000849
	.syntax divided
