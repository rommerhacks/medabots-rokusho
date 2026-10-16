	.syntax unified

	thumb_func_start load_battle_bg_tilemaps
load_battle_bg_tilemaps: @ 0x0807085C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _08070A0C @ =0x087C11C4
	ldr r1, _08070A10 @ =0x06004000
	bl LZ77UnCompVram
	ldr r0, _08070A14 @ =0x087C2598
	ldr r1, _08070A18 @ =0x06008000
	bl LZ77UnCompVram
	ldr r0, _08070A1C @ =0x087C3928
	ldr r1, _08070A20 @ =0x06006800
	bl LZ77UnCompVram
	ldr r0, _08070A24 @ =0x087C3AF4
	ldr r1, _08070A28 @ =0x06007000
	bl LZ77UnCompVram
	ldr r0, _08070A2C @ =0x087C3D40
	ldr r1, _08070A30 @ =0x06007800
	bl LZ77UnCompVram
	ldr r0, _08070A34 @ =0x087C40B0
	ldr r1, _08070A38 @ =0x0600A800
	bl LZ77UnCompVram
	ldr r0, _08070A3C @ =0x087C4210
	ldr r1, _08070A40 @ =0x0600B000
	bl LZ77UnCompVram
	ldr r0, _08070A44 @ =0x087C4498
	ldr r1, _08070A48 @ =0x0600B800
	bl LZ77UnCompVram
	ldr r0, _08070A4C @ =0x087B1CEC
	ldr r1, _08070A50 @ =0x06010000
	bl LZ77UnCompVram
	movs r7, #0
	ldr r0, _08070A54 @ =0x03002C30
	mov sl, r0
	movs r1, #0
	mov sb, r1
_080708BA:
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	movs r2, #3
	str r2, [sp]
	movs r1, #0xc8
	lsls r1, r1, #8
	ldr r2, _08070A58 @ =0x0000050E
	movs r3, #4
	bl init_battle_sprite_entry_08048818
	lsls r1, r7, #6
	add r1, sl
	lsls r6, r7, #3
	adds r0, r6, #0
	adds r0, #0x78
	strh r0, [r1, #2]
	mov r4, sb
	strh r4, [r1, #4]
	adds r5, r7, #0
	adds r5, #0x40
	strb r5, [r1, #0xb]
	adds r0, r7, #1
	mov r8, r0
	adds r1, #0x22
	strb r0, [r1]
	adds r4, r7, #0
	adds r4, #0xb
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	movs r1, #3
	str r1, [sp]
	movs r1, #0xc8
	lsls r1, r1, #8
	ldr r2, _08070A58 @ =0x0000050E
	movs r3, #4
	bl init_battle_sprite_entry_08048818
	lsls r4, r4, #6
	add r4, sl
	movs r0, #0x70
	subs r0, r0, r6
	strh r0, [r4, #2]
	mov r2, sb
	strh r2, [r4, #4]
	strb r5, [r4, #0xb]
	adds r0, r7, #0
	adds r0, #0xc
	adds r4, #0x22
	strb r0, [r4]
	mov r7, r8
	cmp r7, #0xa
	ble _080708BA
	ldr r1, _08070A54 @ =0x03002C30
	ldr r4, _08070A5C @ =0x000002A2
	adds r2, r1, r4
	movs r0, #0xff
	strb r0, [r2]
	ldr r5, _08070A60 @ =0x00000562
	adds r2, r1, r5
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
	movs r7, #0
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r5, r1, r0
	movs r4, #0xb0
	lsls r4, r4, #0x15
_08070942:
	lsrs r0, r4, #0x18
	lsls r3, r7, #0x18
	lsrs r3, r3, #0x18
	movs r1, #1
	str r1, [sp]
	movs r1, #0xcc
	lsls r1, r1, #8
	movs r2, #0
	bl init_battle_sprite_entry_08048818
	movs r0, #0x40
	strh r0, [r5, #4]
	adds r5, #0x40
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r4, r4, r1
	adds r7, #1
	cmp r7, #3
	ble _08070942
	ldr r1, _08070A54 @ =0x03002C30
	ldr r2, _08070A64 @ =0x00000582
	adds r0, r1, r2
	movs r3, #0x10
	strh r3, [r0]
	ldr r4, _08070A68 @ =0x0000058B
	adds r0, r1, r4
	movs r2, #8
	strb r2, [r0]
	ldr r5, _08070A6C @ =0x000005C2
	adds r0, r1, r5
	movs r4, #0xd0
	strh r4, [r0]
	adds r5, #9
	adds r0, r1, r5
	strb r2, [r0]
	ldr r2, _08070A70 @ =0x00000602
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #0x40
	adds r2, r1, r5
	movs r0, #4
	strb r0, [r2]
	ldr r0, _08070A74 @ =0x00000604
	adds r2, r1, r0
	movs r0, #0x30
	strh r0, [r2]
	ldr r2, _08070A78 @ =0x00000642
	adds r0, r1, r2
	strh r4, [r0]
	ldr r4, _08070A7C @ =0x0000064B
	adds r2, r1, r4
	movs r0, #6
	strb r0, [r2]
	movs r7, #0
	adds r5, #0x77
	adds r4, r1, r5
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r6, r1, r0
	movs r5, #0xd0
	lsls r5, r5, #0x15
_080709BC:
	lsrs r0, r5, #0x18
	movs r1, #3
	str r1, [sp]
	ldr r1, _08070A80 @ =0x0000CC08
	ldr r2, _08070A84 @ =0x00000513
	movs r3, #0xe
	bl init_battle_sprite_entry_08048818
	ldrh r0, [r6, #2]
	strh r0, [r4]
	movs r0, #0x40
	strh r0, [r4, #2]
	adds r4, #0x40
	adds r6, #0x40
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r5, r5, r1
	adds r7, #1
	cmp r7, #3
	ble _080709BC
	ldr r0, _08070A54 @ =0x03002C30
	ldr r2, _08070A88 @ =0x00000704
	adds r0, r0, r2
	movs r1, #0x38
	strh r1, [r0]
	ldr r1, _08070A8C @ =0x03001800
	movs r0, #6
	strh r0, [r1, #4]
	ldr r1, _08070A90 @ =0x0300137C
	movs r0, #4
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08070A0C: .4byte 0x087C11C4
_08070A10: .4byte 0x06004000
_08070A14: .4byte 0x087C2598
_08070A18: .4byte 0x06008000
_08070A1C: .4byte 0x087C3928
_08070A20: .4byte 0x06006800
_08070A24: .4byte 0x087C3AF4
_08070A28: .4byte 0x06007000
_08070A2C: .4byte 0x087C3D40
_08070A30: .4byte 0x06007800
_08070A34: .4byte 0x087C40B0
_08070A38: .4byte 0x0600A800
_08070A3C: .4byte 0x087C4210
_08070A40: .4byte 0x0600B000
_08070A44: .4byte 0x087C4498
_08070A48: .4byte 0x0600B800
_08070A4C: .4byte 0x087B1CEC
_08070A50: .4byte 0x06010000
_08070A54: .4byte 0x03002C30
_08070A58: .4byte 0x0000050E
_08070A5C: .4byte 0x000002A2
_08070A60: .4byte 0x00000562
_08070A64: .4byte 0x00000582
_08070A68: .4byte 0x0000058B
_08070A6C: .4byte 0x000005C2
_08070A70: .4byte 0x00000602
_08070A74: .4byte 0x00000604
_08070A78: .4byte 0x00000642
_08070A7C: .4byte 0x0000064B
_08070A80: .4byte 0x0000CC08
_08070A84: .4byte 0x00000513
_08070A88: .4byte 0x00000704
_08070A8C: .4byte 0x03001800
_08070A90: .4byte 0x0300137C
	.syntax divided
