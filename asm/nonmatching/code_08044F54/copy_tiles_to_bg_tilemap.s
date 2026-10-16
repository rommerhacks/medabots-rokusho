	.syntax unified

	thumb_func_start copy_tiles_to_bg_tilemap
	.global copy_tiles_to_bg_tilemap
copy_tiles_to_bg_tilemap: @ 0x08048DD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	str r2, [sp, #0x14]
	mov sl, r3
	ldr r7, [sp, #0x70]
	ldr r1, [sp, #0x6c]
	adds r0, r2, r1
	movs r2, #0x20
	str r2, [sp, #0x18]
	cmp r0, #0x1f
	bgt _08048DFE
	ldr r3, [sp, #0x14]
	str r3, [sp, #0x18]
_08048DFE:
	movs r6, #0
	ldr r5, [sp, #0x18]
	cmp r6, r5
	blt _08048E08
	b _08048F28
_08048E08:
	mov r1, sl
	lsrs r0, r1, #0x1f
	add r0, sl
	asrs r0, r0, #1
	str r0, [sp, #0x1c]
	ldr r2, [sp, #0x6c]
	lsrs r0, r2, #0x1f
	adds r0, r2, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x20]
_08048E24:
	mov r3, sl
	adds r0, r3, r7
	movs r5, #0x20
	mov r8, r5
	cmp r0, #0x1f
	bgt _08048E32
	mov r8, sl
_08048E32:
	movs r4, #0
	adds r0, r6, #1
	str r0, [sp, #0x34]
	cmp r4, r8
	bge _08048EA0
	ldr r1, [sp, #0x74]
	lsls r1, r1, #0x10
	mov sb, r1
_08048E42:
	ldr r2, [sp, #0x6c]
	adds r0, r6, r2
	lsls r0, r0, #6
	ldr r3, [sp, #0x10]
	adds r0, r3, r0
	adds r1, r4, r7
	lsls r1, r1, #1
	adds r0, r0, r1
	lsrs r3, r6, #0x1f
	adds r3, r6, r3
	asrs r3, r3, #1
	ldr r5, [sp, #0x1c]
	adds r1, r5, #0
	muls r1, r3, r1
	lsrs r2, r4, #0x1f
	adds r2, r4, r2
	asrs r2, r2, #1
	ldr r5, [sp, #0xc]
	adds r1, r5, r1
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r3, r3, #1
	subs r3, r6, r3
	lsls r3, r3, #0x10
	lsls r2, r2, #1
	subs r2, r4, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	ldr r2, [sp, #0x20]
	str r2, [sp, #4]
	lsrs r2, r7, #0x1f
	adds r2, r7, r2
	asrs r2, r2, #1
	lsls r2, r2, #1
	subs r2, r7, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #8]
	mov r5, sb
	lsrs r2, r5, #0x10
	lsrs r3, r3, #0x10
	bl build_bg_tile_entry
	adds r4, #1
	cmp r4, r8
	blt _08048E42
_08048EA0:
	mov r0, sl
	cmp r0, #0x1f
	ble _08048F1E
	movs r4, #0
	movs r1, #0x20
	rsbs r1, r1, #0
	add r1, sl
	mov r8, r1
	cmp r4, r8
	bge _08048F1E
	ldr r2, [sp, #0x6c]
	adds r1, r6, r2
	lsls r1, r1, #6
	lsls r0, r7, #1
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	ldr r5, [sp, #0x10]
	adds r0, r0, r5
	adds r5, r0, r1
	lsrs r0, r6, #0x1f
	adds r0, r6, r0
	asrs r0, r0, #1
	mov sb, r0
	lsls r0, r0, #1
	subs r0, r6, r0
	lsls r6, r0, #0x10
_08048ED6:
	ldr r0, [sp, #0x1c]
	mov r1, sb
	muls r1, r0, r1
	lsrs r0, r4, #0x1f
	adds r0, r4, r0
	asrs r0, r0, #1
	ldr r2, [sp, #0xc]
	adds r1, r2, r1
	adds r1, r0, r1
	ldrb r1, [r1, #0x10]
	ldr r3, [sp, #0x74]
	lsls r2, r3, #0x10
	lsls r0, r0, #1
	subs r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	lsrs r0, r7, #0x1f
	adds r0, r7, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r5, #0
	lsrs r2, r2, #0x10
	lsrs r3, r6, #0x10
	bl build_bg_tile_entry
	adds r5, #2
	adds r4, #1
	cmp r4, r8
	blt _08048ED6
_08048F1E:
	ldr r6, [sp, #0x34]
	ldr r1, [sp, #0x18]
	cmp r6, r1
	bge _08048F28
	b _08048E24
_08048F28:
	ldr r2, [sp, #0x14]
	cmp r2, #0x1f
	bgt _08048F30
	b _08049082
_08048F30:
	movs r6, #0
	subs r2, #0x20
	str r2, [sp, #0x30]
	cmp r6, r2
	blt _08048F3C
	b _08049082
_08048F3C:
	mov r3, sl
	lsrs r0, r3, #0x1f
	add r0, sl
	asrs r0, r0, #1
	str r0, [sp, #0x24]
	lsls r0, r7, #1
	movs r5, #0x80
	lsls r5, r5, #5
	adds r1, r0, r5
	ldr r2, [sp, #0x10]
	adds r1, r1, r2
	str r1, [sp, #0x3c]
	ldr r3, [sp, #0x74]
	lsls r3, r3, #0x10
	str r3, [sp, #0x28]
	movs r5, #0xc0
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	str r0, [sp, #0x38]
_08048F64:
	movs r0, #0x20
	mov r8, r0
	mov r1, sl
	cmp r1, #0x1f
	bgt _08048F70
	mov r8, sl
_08048F70:
	movs r4, #0
	adds r2, r6, #1
	str r2, [sp, #0x34]
	cmp r4, r8
	bge _08048FF4
	ldr r3, [sp, #0x6c]
	adds r0, r6, r3
	lsls r0, r0, #6
	ldr r5, [sp, #0x3c]
	adds r0, r5, r0
	str r0, [sp, #0x40]
	lsrs r0, r6, #0x1f
	adds r0, r6, r0
	asrs r0, r0, #1
	mov sb, r0
	lsls r0, r0, #1
	subs r0, r6, r0
	lsls r0, r0, #0x10
	str r0, [sp, #0x2c]
_08048F96:
	mov r0, sb
	adds r0, #0x10
	ldr r2, [sp, #0x24]
	adds r1, r2, #0
	muls r1, r0, r1
	lsrs r0, r4, #0x1f
	adds r0, r4, r0
	asrs r0, r0, #1
	ldr r3, [sp, #0xc]
	adds r1, r3, r1
	adds r1, r1, r0
	ldrb r1, [r1]
	lsls r0, r0, #1
	subs r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r5, [sp, #0x6c]
	lsrs r0, r5, #0x1f
	adds r0, r5, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	lsrs r0, r7, #0x1f
	adds r0, r7, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldr r0, [sp, #0x40]
	ldr r3, [sp, #0x28]
	lsrs r2, r3, #0x10
	ldr r5, [sp, #0x2c]
	lsrs r3, r5, #0x10
	bl build_bg_tile_entry
	ldr r0, [sp, #0x40]
	adds r0, #2
	str r0, [sp, #0x40]
	adds r4, #1
	cmp r4, r8
	blt _08048F96
_08048FF4:
	mov r1, sl
	cmp r1, #0x1f
	ble _08049078
	movs r4, #0
	movs r2, #0x20
	rsbs r2, r2, #0
	add r2, sl
	mov r8, r2
	cmp r4, r8
	bge _08049078
	ldr r3, [sp, #0x6c]
	adds r0, r6, r3
	lsls r0, r0, #6
	ldr r1, [sp, #0x38]
	adds r5, r1, r0
	lsrs r0, r6, #0x1f
	adds r0, r6, r0
	asrs r0, r0, #1
	mov sb, r0
	lsls r0, r0, #1
	subs r0, r6, r0
	lsls r6, r0, #0x10
_08049020:
	mov r0, sb
	adds r0, #0x10
	ldr r2, [sp, #0x24]
	adds r1, r2, #0
	muls r1, r0, r1
	lsrs r0, r4, #0x1f
	adds r0, r4, r0
	asrs r0, r0, #1
	ldr r3, [sp, #0xc]
	adds r1, r3, r1
	adds r1, r0, r1
	ldrb r1, [r1, #0x10]
	lsls r0, r0, #1
	subs r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r2, [sp, #0x6c]
	lsrs r0, r2, #0x1f
	adds r0, r2, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	lsrs r0, r7, #0x1f
	adds r0, r7, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r5, #0
	ldr r3, [sp, #0x28]
	lsrs r2, r3, #0x10
	lsrs r3, r6, #0x10
	bl build_bg_tile_entry
	adds r5, #2
	adds r4, #1
	cmp r4, r8
	blt _08049020
_08049078:
	ldr r6, [sp, #0x34]
	ldr r5, [sp, #0x30]
	cmp r6, r5
	bge _08049082
	b _08048F64
_08049082:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08049094:
	.byte 0x10, 0xB5, 0x4B, 0x1C, 0x9B, 0x00, 0x09, 0x03, 0x89, 0x18, 0x1A, 0x1C
	.byte 0x0A, 0x43, 0x02, 0x80, 0x5A, 0x1C, 0x0A, 0x43, 0x42, 0x80, 0x04, 0x1C, 0x40, 0x34, 0x9A, 0x1C
	.byte 0x0A, 0x43, 0x22, 0x80, 0x42, 0x30, 0x03, 0x33, 0x0B, 0x43, 0x03, 0x80, 0x10, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00
	.syntax divided
