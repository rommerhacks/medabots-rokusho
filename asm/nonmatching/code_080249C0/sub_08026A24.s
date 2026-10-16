	.syntax unified

	thumb_func_start sub_08026A24
sub_08026A24: @ 0x08026A24
	push {r4, lr}
	ldr r4, _08026A6C @ =0x030004DE
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_08036B50
	adds r0, r4, #0
	adds r0, #0x14
	movs r1, #0xe
	bl sub_08036B50
	adds r0, r4, #0
	adds r0, #0x28
	movs r1, #0x12
	bl sub_08036B50
	adds r0, r4, #0
	adds r0, #0x3c
	movs r1, #0x16
	bl sub_08036B50
	cmp r0, #0
	beq _08026A64
	adds r1, r4, #0
	subs r1, #0x18
	movs r0, #0x3c
	strh r0, [r1]
	ldr r1, _08026A70 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08026A64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08026A6C: .4byte 0x030004DE
_08026A70: .4byte 0x03001800
	.syntax divided
