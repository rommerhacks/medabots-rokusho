	.syntax unified

	thumb_func_start irq_init
	.global irq_init
irq_init: @ 0x08000458
	push {r4, r5, lr}
	ldr r0, _080004A8 @ =0x0807E6F0
	ldr r1, _080004AC @ =0x03000BA0
	ldr r2, _080004B0 @ =0x0400000E
	bl CpuSet
	ldr r0, _080004B4 @ =irq_dispatch_arm
	ldr r4, _080004B8 @ =0x03001C10
	ldr r5, _080004BC @ =0x04000200
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuSet
	ldr r0, _080004C0 @ =0x03007FFC
	str r4, [r0]
	ldr r0, _080004C4 @ =0x03000B98
	ldr r1, _080004C8 @ =0x08000841
	str r1, [r0]
	ldr r0, _080004CC @ =0x030017F0
	str r1, [r0]
	ldr r0, _080004D0 @ =0x03002C20
	str r1, [r0]
	ldr r1, _080004D4 @ =0x00002601
	adds r0, r1, #0
	strh r0, [r5]
	ldr r1, _080004D8 @ =0x04000004
	movs r0, #8
	strh r0, [r1]
	ldr r1, _080004DC @ =0x04000208
	movs r0, #1
	strh r0, [r1]
	movs r0, #0x40
	bl sub_0807C740
	bl get_medal_count_or_status
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080004A8: .4byte 0x0807E6F0
_080004AC: .4byte 0x03000BA0
_080004B0: .4byte 0x0400000E
_080004B4: .4byte irq_dispatch_arm
_080004B8: .4byte 0x03001C10
_080004BC: .4byte 0x04000200
_080004C0: .4byte 0x03007FFC
_080004C4: .4byte 0x03000B98
_080004C8: .4byte 0x08000841
_080004CC: .4byte 0x030017F0
_080004D0: .4byte 0x03002C20
_080004D4: .4byte 0x00002601
_080004D8: .4byte 0x04000004
_080004DC: .4byte 0x04000208
	.syntax divided
