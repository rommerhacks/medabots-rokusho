	.syntax unified

	thumb_func_start sub_0800E78C
sub_0800E78C: @ 0x0800E78C
	push {r4, lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	ldr r0, _0800E7AC @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x3e
	ldrb r1, [r1]
	cmp r1, #2
	bgt _0800E7B0
	cmp r1, #1
	bge _0800E86C
	cmp r1, #0
	beq _0800E7B8
	b _0800E9D4
	.align 2, 0
_0800E7AC: .4byte 0x03000440
_0800E7B0:
	cmp r1, #3
	bne _0800E7B6
	b _0800E930
_0800E7B6:
	b _0800E9D4
_0800E7B8:
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #6
	bls _0800E7C2
	b _0800E9D4
_0800E7C2:
	lsls r0, r0, #2
	ldr r1, _0800E7CC @ =_0800E7D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800E7CC: .4byte _0800E7D0
_0800E7D0: @ jump table
	.4byte _0800E7EC @ case 0
	.4byte _0800E804 @ case 1
	.4byte _0800E81C @ case 2
	.4byte _0800E83C @ case 3
	.4byte _0800E848 @ case 4
	.4byte _0800E854 @ case 5
	.4byte _0800E860 @ case 6
_0800E7EC:
	ldr r1, _0800E7FC @ =0x083B8170
	ldr r0, _0800E800 @ =0x03000440
	adds r0, #0xf0
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _0800E9CC
	.align 2, 0
_0800E7FC: .4byte 0x083B8170
_0800E800: .4byte 0x03000440
_0800E804:
	ldr r1, _0800E814 @ =0x083B6E24
	ldr r0, _0800E818 @ =0x03000440
	adds r0, #0xee
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _0800E9CC
	.align 2, 0
_0800E814: .4byte 0x083B6E24
_0800E818: .4byte 0x03000440
_0800E81C:
	ldr r4, _0800E834 @ =0x083B53F8
	ldr r0, _0800E838 @ =0x03000440
	adds r0, #0xf0
	ldrb r0, [r0]
	bl sub_08042B80
	adds r0, #0x11
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	b _0800E9CC
	.align 2, 0
_0800E834: .4byte 0x083B53F8
_0800E838: .4byte 0x03000440
_0800E83C:
	ldr r0, _0800E844 @ =0x083BD884
	ldr r0, [r0]
	b _0800E9CC
	.align 2, 0
_0800E844: .4byte 0x083BD884
_0800E848:
	ldr r0, _0800E850 @ =0x083BD884
	ldr r0, [r0, #4]
	b _0800E9CC
	.align 2, 0
_0800E850: .4byte 0x083BD884
_0800E854:
	ldr r0, _0800E85C @ =0x083BD884
	ldr r0, [r0, #8]
	b _0800E9CC
	.align 2, 0
_0800E85C: .4byte 0x083BD884
_0800E860:
	ldr r0, _0800E868 @ =0x083BD884
	ldr r0, [r0, #0xc]
	b _0800E9CC
	.align 2, 0
_0800E868: .4byte 0x083BD884
_0800E86C:
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #7
	bls _0800E876
	b _0800E9D4
_0800E876:
	lsls r0, r0, #2
	ldr r1, _0800E880 @ =_0800E884
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800E880: .4byte _0800E884
_0800E884: @ jump table
	.4byte _0800E8A4 @ case 0
	.4byte _0800E8BC @ case 1
	.4byte _0800E8D4 @ case 2
	.4byte _0800E8F4 @ case 3
	.4byte _0800E900 @ case 4
	.4byte _0800E90C @ case 5
	.4byte _0800E918 @ case 6
	.4byte _0800E924 @ case 7
_0800E8A4:
	ldr r1, _0800E8B4 @ =0x083B8170
	ldr r0, _0800E8B8 @ =0x03000440
	adds r0, #0xf0
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _0800E9CC
	.align 2, 0
_0800E8B4: .4byte 0x083B8170
_0800E8B8: .4byte 0x03000440
_0800E8BC:
	ldr r1, _0800E8CC @ =0x083B6E24
	ldr r0, _0800E8D0 @ =0x03000440
	adds r0, #0xee
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _0800E9CC
	.align 2, 0
_0800E8CC: .4byte 0x083B6E24
_0800E8D0: .4byte 0x03000440
_0800E8D4:
	ldr r4, _0800E8EC @ =0x083B53F8
	ldr r0, _0800E8F0 @ =0x03000440
	adds r0, #0xf0
	ldrb r0, [r0]
	bl sub_08042B80
	adds r0, #0x11
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	b _0800E9CC
	.align 2, 0
_0800E8EC: .4byte 0x083B53F8
_0800E8F0: .4byte 0x03000440
_0800E8F4:
	ldr r0, _0800E8FC @ =0x083BD884
	ldr r0, [r0]
	b _0800E9CC
	.align 2, 0
_0800E8FC: .4byte 0x083BD884
_0800E900:
	ldr r0, _0800E908 @ =0x083BD884
	ldr r0, [r0, #4]
	b _0800E9CC
	.align 2, 0
_0800E908: .4byte 0x083BD884
_0800E90C:
	ldr r0, _0800E914 @ =0x083BD884
	ldr r0, [r0, #8]
	b _0800E9CC
	.align 2, 0
_0800E914: .4byte 0x083BD884
_0800E918:
	ldr r0, _0800E920 @ =0x083BD884
	ldr r0, [r0, #0x10]
	b _0800E9CC
	.align 2, 0
_0800E920: .4byte 0x083BD884
_0800E924:
	ldr r0, _0800E92C @ =0x083BD884
	ldr r0, [r0, #0x14]
	b _0800E9CC
	.align 2, 0
_0800E92C: .4byte 0x083BD884
_0800E930:
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #7
	bhi _0800E9D4
	lsls r0, r0, #2
	ldr r1, _0800E944 @ =_0800E948
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800E944: .4byte _0800E948
_0800E948: @ jump table
	.4byte _0800E968 @ case 0
	.4byte _0800E980 @ case 1
	.4byte _0800E98C @ case 2
	.4byte _0800E998 @ case 3
	.4byte _0800E9A4 @ case 4
	.4byte _0800E9B0 @ case 5
	.4byte _0800E9BC @ case 6
	.4byte _0800E9C8 @ case 7
_0800E968:
	ldr r1, _0800E978 @ =0x083B6E24
	ldr r0, _0800E97C @ =0x03000440
	adds r0, #0xee
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _0800E9CC
	.align 2, 0
_0800E978: .4byte 0x083B6E24
_0800E97C: .4byte 0x03000440
_0800E980:
	ldr r0, _0800E988 @ =0x083B53F8
	ldr r0, [r0, #0x4c]
	b _0800E9CC
	.align 2, 0
_0800E988: .4byte 0x083B53F8
_0800E98C:
	ldr r0, _0800E994 @ =0x083BD884
	ldr r0, [r0]
	b _0800E9CC
	.align 2, 0
_0800E994: .4byte 0x083BD884
_0800E998:
	ldr r0, _0800E9A0 @ =0x083BD884
	ldr r0, [r0, #0x18]
	b _0800E9CC
	.align 2, 0
_0800E9A0: .4byte 0x083BD884
_0800E9A4:
	ldr r0, _0800E9AC @ =0x083BD884
	ldr r0, [r0, #0x1c]
	b _0800E9CC
	.align 2, 0
_0800E9AC: .4byte 0x083BD884
_0800E9B0:
	ldr r0, _0800E9B8 @ =0x083BD884
	ldr r0, [r0, #0x20]
	b _0800E9CC
	.align 2, 0
_0800E9B8: .4byte 0x083BD884
_0800E9BC:
	ldr r0, _0800E9C4 @ =0x083BD884
	ldr r0, [r0, #0x24]
	b _0800E9CC
	.align 2, 0
_0800E9C4: .4byte 0x083BD884
_0800E9C8:
	ldr r0, _0800E9E8 @ =0x083BD884
	ldr r0, [r0, #0x28]
_0800E9CC:
	bl run_message
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0800E9D4:
	cmp r4, #0
	beq _0800E9E2
	bl sub_0803FB0C
	ldr r1, _0800E9EC @ =0x0300137C
	movs r0, #0x21
	str r0, [r1]
_0800E9E2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800E9E8: .4byte 0x083BD884
_0800E9EC: .4byte 0x0300137C
	.syntax divided
