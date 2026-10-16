	.syntax unified

	thumb_func_start update_bg_scroll_offsets_a
	.global update_bg_scroll_offsets_a
update_bg_scroll_offsets_a: @ 0x08052B24
	push {r4, r5, lr}
	ldr r3, _08052B60 @ =0x03002C30
	ldr r1, _08052B64 @ =0x030057E0
	ldr r2, _08052B68 @ =0x00000C52
	adds r0, r1, r2
	ldr r4, _08052B6C @ =0x03004C30
	ldrh r2, [r0]
	ldrh r0, [r4]
	subs r2, r2, r0
	ldr r5, _08052B70 @ =0x00000BC2
	adds r0, r3, r5
	strh r2, [r0]
	ldr r0, _08052B74 @ =0x00000C54
	adds r1, r1, r0
	ldrh r1, [r1]
	ldrh r0, [r4, #2]
	subs r1, r1, r0
	ldr r4, _08052B78 @ =0x00000BC4
	adds r0, r3, r4
	strh r1, [r0]
	ldr r5, _08052B7C @ =0x00001642
	adds r0, r3, r5
	strh r2, [r0]
	subs r1, #5
	ldr r0, _08052B80 @ =0x00001644
	adds r3, r3, r0
	strh r1, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052B60: .4byte 0x03002C30
_08052B64: .4byte 0x030057E0
_08052B68: .4byte 0x00000C52
_08052B6C: .4byte 0x03004C30
_08052B70: .4byte 0x00000BC2
_08052B74: .4byte 0x00000C54
_08052B78: .4byte 0x00000BC4
_08052B7C: .4byte 0x00001642
_08052B80: .4byte 0x00001644
_08052B84:
	.byte 0x05, 0x48, 0xBC, 0x22, 0x12, 0x01, 0x81, 0x18, 0x00, 0x22, 0x0A, 0x80
	.byte 0xB2, 0x21, 0x49, 0x01, 0x40, 0x18, 0x02, 0x80, 0x70, 0x47, 0x00, 0x00, 0x30, 0x2C, 0x00, 0x03
	.syntax divided
