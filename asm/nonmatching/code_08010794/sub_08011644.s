	.syntax unified

	thumb_func_start sub_08011644
sub_08011644: @ 0x08011644
	push {lr}
	ldr r1, _08011690 @ =0x040000D4
	ldr r0, _08011694 @ =0x06002800
	str r0, [r1]
	ldr r0, _08011698 @ =0x02020800
	str r0, [r1, #4]
	ldr r0, _0801169C @ =0x84000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080116A0 @ =0x06000280
	str r0, [r1]
	ldr r0, _080116A4 @ =0x02021000
	str r0, [r1, #4]
	ldr r0, _080116A8 @ =0x84000380
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080116AC @ =0x03002C30
	str r0, [r1]
	ldr r0, _080116B0 @ =0x02028000
	str r0, [r1, #4]
	ldr r0, _080116B4 @ =0x84000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _080116B8 @ =0x030017F0
	ldr r0, _080116BC @ =0x08000841
	str r0, [r1]
	ldr r1, _080116C0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08011690: .4byte 0x040000D4
_08011694: .4byte 0x06002800
_08011698: .4byte 0x02020800
_0801169C: .4byte 0x84000200
_080116A0: .4byte 0x06000280
_080116A4: .4byte 0x02021000
_080116A8: .4byte 0x84000380
_080116AC: .4byte 0x03002C30
_080116B0: .4byte 0x02028000
_080116B4: .4byte 0x84000800
_080116B8: .4byte 0x030017F0
_080116BC: .4byte 0x08000841
_080116C0: .4byte 0x0300137C
	.syntax divided
