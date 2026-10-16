	.syntax unified

	thumb_func_start battle_scene_init_clear
battle_scene_init_clear: @ 0x0806EAA4
	push {r4, lr}
	sub sp, #4
	movs r3, #0
	str r3, [sp]
	ldr r0, _0806EB48 @ =0x040000D4
	mov r1, sp
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0806EB4C @ =0x85006000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [sp]
	mov r1, sp
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0806EB50 @ =0x85000100
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, _0806EB54 @ =0x03002C30
	str r1, [r0, #4]
	ldr r1, _0806EB58 @ =0x85000800
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r2, _0806EB5C @ =0x03001800
	str r2, [r0, #4]
	ldr r1, _0806EB60 @ =0x8500003E
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	movs r4, #0
	movs r0, #3
	strh r0, [r2]
	movs r1, #1
	strh r1, [r2, #2]
	str r3, [r2, #8]
	ldr r0, _0806EB64 @ =0x03005000
	strh r3, [r0]
	strh r3, [r0, #2]
	ldr r0, _0806EB68 @ =0x03004C30
	strh r3, [r0]
	strh r3, [r0, #2]
	ldr r0, _0806EB6C @ =0x0300057C
	strh r3, [r0]
	strh r3, [r0, #2]
	ldr r0, _0806EB70 @ =0x03001C04
	strh r3, [r0]
	strh r3, [r0, #2]
	movs r0, #0xb
	strh r0, [r2, #0xc]
	strh r0, [r2, #4]
	strh r1, [r2, #6]
	adds r1, r2, #0
	adds r1, #0xf4
	movs r0, #0xf8
	lsls r0, r0, #3
	strh r0, [r1]
	adds r2, #0xf6
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2]
	ldr r0, _0806EB74 @ =0x03007008
	strb r4, [r0]
	ldr r1, _0806EB78 @ =0x0300137C
	movs r0, #8
	str r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806EB48: .4byte 0x040000D4
_0806EB4C: .4byte 0x85006000
_0806EB50: .4byte 0x85000100
_0806EB54: .4byte 0x03002C30
_0806EB58: .4byte 0x85000800
_0806EB5C: .4byte 0x03001800
_0806EB60: .4byte 0x8500003E
_0806EB64: .4byte 0x03005000
_0806EB68: .4byte 0x03004C30
_0806EB6C: .4byte 0x0300057C
_0806EB70: .4byte 0x03001C04
_0806EB74: .4byte 0x03007008
_0806EB78: .4byte 0x0300137C
	.syntax divided
