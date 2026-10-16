	.syntax unified

	thumb_func_start sub_08047574
sub_08047574: @ 0x08047574
	push {r4, lr}
	ldr r0, _080475FC @ =0x03005310
	movs r1, #0x3c
	bl sub_080496C8
	ldr r0, _08047600 @ =0x030057A0
	movs r1, #0x38
	bl sub_080496C8
	ldr r0, _08047604 @ =0x03006D14
	movs r1, #4
	bl sub_080496C8
	ldr r0, _08047608 @ =0x030057DC
	movs r1, #4
	bl sub_080496C8
	ldr r0, _0804760C @ =0x0300534C
	movs r1, #4
	bl sub_080496C8
	ldr r0, _08047610 @ =0x030055A0
	movs r4, #0x80
	lsls r4, r4, #2
	adds r1, r4, #0
	bl sub_080496C8
	ldr r0, _08047614 @ =0x03006D40
	adds r1, r4, #0
	bl sub_080496C8
	ldr r0, _08047618 @ =0x03006F40
	movs r1, #0x34
	bl sub_080496C8
	ldr r0, _0804761C @ =0x03006D38
	movs r1, #8
	bl sub_080496C8
	ldr r0, _08047620 @ =0x03006D20
	movs r1, #0x10
	bl sub_080496C8
	ldr r0, _08047624 @ =0x030057D8
	movs r1, #4
	bl sub_080496C8
	ldr r0, _08047628 @ =0x03005590
	movs r1, #4
	bl sub_080496C8
	ldr r0, _0804762C @ =0x03005350
	movs r1, #0x90
	lsls r1, r1, #2
	bl sub_080496C8
	ldr r0, _08047630 @ =0x03006D30
	movs r1, #4
	bl sub_080496C8
	ldr r0, _08047634 @ =0x030064A0
	ldr r1, _08047638 @ =0x00000874
	bl sub_080496C8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080475FC: .4byte 0x03005310
_08047600: .4byte 0x030057A0
_08047604: .4byte 0x03006D14
_08047608: .4byte 0x030057DC
_0804760C: .4byte 0x0300534C
_08047610: .4byte 0x030055A0
_08047614: .4byte 0x03006D40
_08047618: .4byte 0x03006F40
_0804761C: .4byte 0x03006D38
_08047620: .4byte 0x03006D20
_08047624: .4byte 0x030057D8
_08047628: .4byte 0x03005590
_0804762C: .4byte 0x03005350
_08047630: .4byte 0x03006D30
_08047634: .4byte 0x030064A0
_08047638: .4byte 0x00000874
	.syntax divided
