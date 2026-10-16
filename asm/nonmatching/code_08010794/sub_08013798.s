	.syntax unified

	thumb_func_start sub_08013798
sub_08013798: @ 0x08013798
	push {r4, lr}
	ldr r0, _080137F0 @ =0x06002800
	ldr r1, _080137F4 @ =0x02020800
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _080137F8 @ =0x0600C800
	ldr r1, _080137FC @ =0x02021000
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _08013800 @ =0x0600D000
	ldr r1, _08013804 @ =0x02021800
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _08013808 @ =0x0600D800
	ldr r1, _0801380C @ =0x02022000
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _08013810 @ =0x03002C30
	ldr r1, _08013814 @ =0x02028000
	movs r2, #0x80
	lsls r2, r2, #4
	bl CpuFastSet
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _08013818 @ =0x030017F0
	ldr r0, _0801381C @ =0x08000841
	str r0, [r1]
	ldr r1, _08013820 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080137F0: .4byte 0x06002800
_080137F4: .4byte 0x02020800
_080137F8: .4byte 0x0600C800
_080137FC: .4byte 0x02021000
_08013800: .4byte 0x0600D000
_08013804: .4byte 0x02021800
_08013808: .4byte 0x0600D800
_0801380C: .4byte 0x02022000
_08013810: .4byte 0x03002C30
_08013814: .4byte 0x02028000
_08013818: .4byte 0x030017F0
_0801381C: .4byte 0x08000841
_08013820: .4byte 0x0300137C
	.syntax divided
