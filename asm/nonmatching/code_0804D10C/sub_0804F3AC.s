	.syntax unified

	thumb_func_start sub_0804F3AC
sub_0804F3AC: @ 0x0804F3AC
	push {r4, r5, lr}
	ldr r4, _0804F3C4 @ =0x030057E0
	ldr r1, _0804F3C8 @ =0x00000C93
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r2, r4, #0
	cmp r0, #0
	beq _0804F3CC
	cmp r0, #1
	beq _0804F428
	b _0804F568
	.align 2, 0
_0804F3C4: .4byte 0x030057E0
_0804F3C8: .4byte 0x00000C93
_0804F3CC:
	ldr r3, _0804F3E0 @ =0x00000C94
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804F3EC
	ldr r0, _0804F3E4 @ =0x03005310
	ldr r1, _0804F3E8 @ =0x03004C30
	ldrh r1, [r1]
	strh r1, [r0, #0x1e]
	b _0804F3F4
	.align 2, 0
_0804F3E0: .4byte 0x00000C94
_0804F3E4: .4byte 0x03005310
_0804F3E8: .4byte 0x03004C30
_0804F3EC:
	ldr r0, _0804F410 @ =0x03005310
	ldr r1, _0804F414 @ =0x03004C30
	ldrh r1, [r1, #2]
	strh r1, [r0, #0x26]
_0804F3F4:
	ldr r0, _0804F418 @ =0x00000C96
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0804F41C @ =0x00000C95
	adds r0, r2, r1
	ldrb r1, [r0]
	ldr r3, _0804F420 @ =0x00000C98
	adds r0, r2, r3
	strb r1, [r0]
	ldr r0, _0804F424 @ =0x00000C93
	adds r1, r2, r0
	b _0804F512
	.align 2, 0
_0804F410: .4byte 0x03005310
_0804F414: .4byte 0x03004C30
_0804F418: .4byte 0x00000C96
_0804F41C: .4byte 0x00000C95
_0804F420: .4byte 0x00000C98
_0804F424: .4byte 0x00000C93
_0804F428:
	ldr r2, _0804F488 @ =0x00000C95
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804F434
	b _0804F52C
_0804F434:
	subs r0, #1
	strb r0, [r1]
	ldr r3, _0804F48C @ =0x00000C98
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	ldrb r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl sub_0807CBBC
	muls r0, r5, r0
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r2, r0, #1
	ldr r3, _0804F490 @ =0x00000C94
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804F4B0
	ldr r1, _0804F494 @ =0x083D69A0
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r4, #3
	ands r4, r5
	adds r2, r4, #1
	lsls r2, r2, #4
	movs r1, #0x80
	subs r1, r1, r2
	bl sub_0807CBBC
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r4, #1
	bhi _0804F49C
	ldr r0, _0804F498 @ =0x03005310
	ldrh r0, [r0, #0x1e]
	subs r0, r0, r1
	b _0804F4A2
	.align 2, 0
_0804F488: .4byte 0x00000C95
_0804F48C: .4byte 0x00000C98
_0804F490: .4byte 0x00000C94
_0804F494: .4byte 0x083D69A0
_0804F498: .4byte 0x03005310
_0804F49C:
	ldr r0, _0804F4AC @ =0x03005310
	ldrh r0, [r0, #0x1e]
	adds r0, r1, r0
_0804F4A2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080529C4
	b _0804F4FA
	.align 2, 0
_0804F4AC: .4byte 0x03005310
_0804F4B0:
	ldr r1, _0804F4E4 @ =0x083D69A0
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r4, #3
	ands r4, r5
	adds r2, r4, #1
	lsls r2, r2, #4
	movs r1, #0x80
	subs r1, r1, r2
	bl sub_0807CBBC
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r4, #1
	bhi _0804F4EC
	ldr r0, _0804F4E8 @ =0x03005310
	ldrh r0, [r0, #0x26]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080529E4
	b _0804F4FA
	.align 2, 0
_0804F4E4: .4byte 0x083D69A0
_0804F4E8: .4byte 0x03005310
_0804F4EC:
	ldr r0, _0804F51C @ =0x03005310
	ldrh r0, [r0, #0x26]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080529E4
_0804F4FA:
	bl update_bg_scroll_offsets_a
	ldr r4, _0804F520 @ =0x030057E0
	ldr r3, _0804F524 @ =0x00000C76
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804F50E
	bl update_bg_scroll_offsets_b
_0804F50E:
	ldr r0, _0804F528 @ =0x00000C96
	adds r1, r4, r0
_0804F512:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0804F568
	.align 2, 0
_0804F51C: .4byte 0x03005310
_0804F520: .4byte 0x030057E0
_0804F524: .4byte 0x00000C76
_0804F528: .4byte 0x00000C96
_0804F52C:
	ldr r1, _0804F540 @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804F548
	ldr r0, _0804F544 @ =0x03005310
	ldrh r0, [r0, #0x1e]
	bl sub_080529C4
	b _0804F550
	.align 2, 0
_0804F540: .4byte 0x00000C94
_0804F544: .4byte 0x03005310
_0804F548:
	ldr r0, _0804F570 @ =0x03005310
	ldrh r0, [r0, #0x26]
	bl sub_080529E4
_0804F550:
	bl update_bg_scroll_offsets_a
	ldr r0, _0804F574 @ =0x030057E0
	ldr r2, _0804F578 @ =0x00000C76
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804F564
	bl update_bg_scroll_offsets_b
_0804F564:
	bl map_script_command_done
_0804F568:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804F570: .4byte 0x03005310
_0804F574: .4byte 0x030057E0
_0804F578: .4byte 0x00000C76

	.syntax divided
