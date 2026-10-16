	.syntax unified

	thumb_func_start sub_0803C8AC
sub_0803C8AC: @ 0x0803C8AC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, _0803C8CC @ =0x03002C30
	ldr r0, _0803C8D0 @ =0x03000440
	ldr r1, _0803C8D4 @ =0x0000012F
	adds r5, r0, r1
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r2, r0, r4
	ldrh r0, [r2, #0x30]
	cmp r0, #0
	beq _0803C8D8
	subs r0, #1
	strh r0, [r2, #0x30]
	b _0803C9C4
	.align 2, 0
_0803C8CC: .4byte 0x03002C30
_0803C8D0: .4byte 0x03000440
_0803C8D4: .4byte 0x0000012F
_0803C8D8:
	ldr r1, _0803C964 @ =0x083CEC74
	adds r0, r2, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #1
	bl process_animation_script
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x28
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803C9C4
	adds r0, r4, #0
	adds r0, #0x27
	ldrb r6, [r0]
	cmp r6, #0
	bne _0803C9C4
	ldr r0, _0803C968 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803C974
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	adds r3, r4, #0
	adds r3, #0x2d
	movs r5, #2
	ldrsh r2, [r4, r5]
	ldrb r3, [r3]
	adds r2, r2, r3
	movs r3, #0x3f
	ands r2, r3
	movs r5, #4
	ldrsh r3, [r4, r5]
	ldr r5, _0803C96C @ =0x083B4AE0
	adds r4, #0x2c
	ldrb r4, [r4]
	lsls r4, r4, #2
	adds r4, r4, r5
	ldr r4, [r4]
	str r4, [sp]
	ldr r4, _0803C970 @ =0x04000008
	ldrh r4, [r4]
	str r4, [sp, #4]
	str r6, [sp, #8]
	bl write_tilemap_to_vram_0803F1C8
	b _0803C9AE
	.align 2, 0
_0803C964: .4byte 0x083CEC74
_0803C968: .4byte 0x03001800
_0803C96C: .4byte 0x083B4AE0
_0803C970: .4byte 0x04000008
_0803C974:
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	movs r3, #2
	ldrsh r2, [r4, r3]
	adds r3, r4, #0
	adds r3, #0x2d
	ldrb r3, [r3]
	subs r2, r2, r3
	movs r3, #0x3f
	ands r2, r3
	movs r5, #4
	ldrsh r3, [r4, r5]
	ldr r5, _0803C9CC @ =0x083B4AE0
	adds r4, #0x2c
	ldrb r4, [r4]
	lsls r4, r4, #2
	adds r4, r4, r5
	ldr r4, [r4]
	str r4, [sp]
	ldr r4, _0803C9D0 @ =0x04000008
	ldrh r4, [r4]
	str r4, [sp, #4]
	str r6, [sp, #8]
	bl write_tilemap_to_vram_0803F1C8
_0803C9AE:
	ldr r1, _0803C9D4 @ =0x03002C30
	ldr r0, _0803C9D8 @ =0x03000440
	ldr r2, _0803C9DC @ =0x0000012F
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_0803C9C4:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803C9CC: .4byte 0x083B4AE0
_0803C9D0: .4byte 0x04000008
_0803C9D4: .4byte 0x03002C30
_0803C9D8: .4byte 0x03000440
_0803C9DC: .4byte 0x0000012F
	.syntax divided
