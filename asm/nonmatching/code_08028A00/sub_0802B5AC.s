	.syntax unified

	thumb_func_start sub_0802B5AC
sub_0802B5AC: @ 0x0802B5AC
	push {r4, r5, r6, r7, lr}
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	movs r7, #0
_0802B5B8:
	ldr r1, _0802B5E0 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xd2
	adds r0, r7, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802B5C8
	b _0802B78C
_0802B5C8:
	lsls r0, r7, #1
	adds r1, #0xd6
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #7
	bls _0802B5D6
	b _0802B78C
_0802B5D6:
	lsls r0, r0, #2
	ldr r1, _0802B5E4 @ =_0802B5E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B5E0: .4byte 0x03001800
_0802B5E4: .4byte _0802B5E8
_0802B5E8: @ jump table
	.4byte _0802B608 @ case 0
	.4byte _0802B62C @ case 1
	.4byte _0802B650 @ case 2
	.4byte _0802B674 @ case 3
	.4byte _0802B698 @ case 4
	.4byte _0802B6F8 @ case 5
	.4byte _0802B718 @ case 6
	.4byte _0802B738 @ case 7
_0802B608:
	ldr r3, _0802B628 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x60
	ldrb r0, [r0]
	adds r0, r0, r7
	adds r1, r3, #0
	adds r1, #0xe8
	movs r4, #0
	ldrsh r2, [r1, r4]
	adds r1, #4
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0xd
	bl battle_set_action_params
	b _0802B78C
	.align 2, 0
_0802B628: .4byte 0x03001800
_0802B62C:
	ldr r3, _0802B64C @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x60
	ldrb r0, [r0]
	adds r0, r0, r7
	adds r1, r3, #0
	adds r1, #0xe8
	movs r4, #0
	ldrsh r2, [r1, r4]
	adds r1, #4
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0x11
	bl battle_set_action_params
	b _0802B78C
	.align 2, 0
_0802B64C: .4byte 0x03001800
_0802B650:
	ldr r3, _0802B670 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x60
	ldrb r0, [r0]
	adds r0, r0, r7
	adds r1, r3, #0
	adds r1, #0xe8
	movs r4, #0
	ldrsh r2, [r1, r4]
	adds r1, #4
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0x13
	bl battle_set_action_params
	b _0802B78C
	.align 2, 0
_0802B670: .4byte 0x03001800
_0802B674:
	ldr r3, _0802B694 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x60
	ldrb r0, [r0]
	adds r0, r0, r7
	adds r1, r3, #0
	adds r1, #0xe8
	movs r4, #0
	ldrsh r2, [r1, r4]
	adds r1, #4
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0x10
	bl battle_set_action_params
	b _0802B78C
	.align 2, 0
_0802B694: .4byte 0x03001800
_0802B698:
	ldr r5, _0802B6F0 @ =0x03000590
	ldr r6, _0802B6F4 @ =0x03001800
	adds r4, r6, #0
	adds r4, #0x60
	ldrb r0, [r4]
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xc9
	movs r1, #0x2b
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r4]
	adds r1, r1, r7
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r1, #0xcb
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xec
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r4]
	adds r1, r1, r7
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r1, #0xcc
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xca
	movs r1, #1
	strb r1, [r0]
	b _0802B78C
	.align 2, 0
_0802B6F0: .4byte 0x03000590
_0802B6F4: .4byte 0x03001800
_0802B6F8:
	ldr r5, _0802B710 @ =0x03000590
	ldr r6, _0802B714 @ =0x03001800
	adds r4, r6, #0
	adds r4, #0x60
	ldrb r0, [r4]
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xc9
	movs r2, #0
	movs r1, #0x2c
	b _0802B74E
	.align 2, 0
_0802B710: .4byte 0x03000590
_0802B714: .4byte 0x03001800
_0802B718:
	ldr r5, _0802B730 @ =0x03000590
	ldr r6, _0802B734 @ =0x03001800
	adds r4, r6, #0
	adds r4, #0x60
	ldrb r0, [r4]
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xc9
	movs r2, #0
	movs r1, #0x2e
	b _0802B74E
	.align 2, 0
_0802B730: .4byte 0x03000590
_0802B734: .4byte 0x03001800
_0802B738:
	ldr r5, _0802B7A4 @ =0x03000590
	ldr r6, _0802B7A8 @ =0x03001800
	adds r4, r6, #0
	adds r4, #0x60
	ldrb r0, [r4]
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xc9
	movs r2, #0
	movs r1, #0x2f
_0802B74E:
	strb r1, [r0]
	ldrb r0, [r4]
	adds r0, r0, r7
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xca
	strb r2, [r0]
	adds r0, r6, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r4]
	adds r1, r1, r7
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r1, #0xcb
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xec
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r4]
	adds r1, r1, r7
	lsls r1, r1, #8
	adds r1, r1, r5
	adds r1, #0xcc
	strb r0, [r1]
_0802B78C:
	adds r7, #1
	cmp r7, #2
	bhi _0802B794
	b _0802B5B8
_0802B794:
	ldr r1, _0802B7A8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802B7A4: .4byte 0x03000590
_0802B7A8: .4byte 0x03001800
_0802B7AC:
	.byte 0x07, 0x48, 0x08, 0x4A
	.byte 0x11, 0x1C, 0x87, 0x31, 0x09, 0x78, 0x09, 0x02, 0x09, 0x18, 0xA8, 0x31, 0x08, 0x78, 0x11, 0x1C
	.byte 0x1E, 0x28, 0x07, 0xD1, 0xA6, 0x32, 0x4D, 0x20, 0x07, 0xE0, 0x00, 0x00, 0x90, 0x05, 0x00, 0x03
	.byte 0x00, 0x18, 0x00, 0x03, 0x0A, 0x1C, 0xA6, 0x32, 0x4E, 0x20, 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78
	.byte 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x00
	.syntax divided
