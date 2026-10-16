	.syntax unified

	thumb_func_start apply_blend_coefficients
apply_blend_coefficients: @ 0x08049C7C
	push {r4, r5, lr}
	ldr r5, _08049CA4 @ =0x04000052
	ldr r4, _08049CA8 @ =0x03006F40
	ldrb r0, [r4, #4]
	movs r2, #0x3f
	adds r1, r2, #0
	ands r1, r0
	lsls r1, r1, #8
	ldrb r3, [r4, #3]
	adds r0, r2, #0
	ands r0, r3
	orrs r0, r1
	strh r0, [r5]
	ldr r1, _08049CAC @ =0x04000054
	ldrb r0, [r4, #5]
	ands r2, r0
	strh r2, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08049CA4: .4byte 0x04000052
_08049CA8: .4byte 0x03006F40
_08049CAC: .4byte 0x04000054
	.syntax divided
