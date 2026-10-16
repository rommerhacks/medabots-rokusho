	.include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_0807C740
	.global sub_0807C740
sub_0807C740: @ 0x0807C740
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0
	cmp r0, #4
	bne _0807C75C
	ldr r1, _0807C754 @ =0x03007018
	ldr r0, _0807C758 @ =0x083ABCA0
	str r0, [r1]
	b _0807C778
	.align 2, 0
_0807C754: .4byte 0x03007018
_0807C758: .4byte 0x083ABCA0
_0807C75C:
	cmp r0, #0x40
	bne _0807C770
	ldr r1, _0807C768 @ =0x03007018
	ldr r0, _0807C76C @ =0x083ABCAC
	str r0, [r1]
	b _0807C778
	.align 2, 0
_0807C768: .4byte 0x03007018
_0807C76C: .4byte 0x083ABCAC
_0807C770:
	ldr r1, _0807C77C @ =0x03007018
	ldr r0, _0807C780 @ =0x083ABCA0
	str r0, [r1]
	movs r2, #1
_0807C778:
	adds r0, r2, #0
	bx lr
	.align 2, 0
_0807C77C: .4byte 0x03007018
_0807C780: .4byte 0x083ABCA0
_0807C784:
	.byte 0x06, 0x49, 0x08, 0x88, 0x00, 0x28, 0x08, 0xD0, 0x08, 0x88, 0x01, 0x38
	.byte 0x08, 0x80, 0x00, 0x04, 0x00, 0x28, 0x02, 0xD1, 0x02, 0x49, 0x01, 0x20, 0x08, 0x70, 0x70, 0x47
	.byte 0xF6, 0x03, 0x00, 0x03, 0xF8, 0x03, 0x00, 0x03

	thumb_func_start sub_0807C7A8
	.global sub_0807C7A8
sub_0807C7A8: @ 0x0807C7A8
	adds r2, r1, #0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bhi _0807C7DC
	ldr r0, _0807C7CC @ =0x030003F4
	strb r1, [r0]
	ldr r1, _0807C7D0 @ =0x030003FC
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldr r3, _0807C7D4 @ =0x04000100
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0807C7D8 @ =0x0807C785
	str r0, [r2]
	movs r0, #0
	b _0807C7DE
	.align 2, 0
_0807C7CC: .4byte 0x030003F4
_0807C7D0: .4byte 0x030003FC
_0807C7D4: .4byte 0x04000100
_0807C7D8: .4byte 0x0807C785
_0807C7DC:
	movs r0, #1
_0807C7DE:
	bx lr

	thumb_func_start serial_init_transfer
serial_init_transfer: @ 0x0807C7E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r2, _0807C84C @ =0x03000400
	ldr r1, _0807C850 @ =0x04000208
	mov sb, r1
	ldrh r1, [r1]
	strh r1, [r2]
	movs r6, #0
	mov r2, sb
	strh r6, [r2]
	ldr r3, _0807C854 @ =0x030003FC
	mov r8, r3
	ldr r5, [r3]
	strh r6, [r5, #2]
	ldr r3, _0807C858 @ =0x04000202
	ldr r4, _0807C85C @ =0x030003F4
	ldrb r1, [r4]
	movs r2, #8
	adds r7, r2, #0
	lsls r7, r1
	adds r1, r7, #0
	strh r1, [r3]
	subs r3, #2
	ldrb r1, [r4]
	lsls r2, r1
	ldrh r1, [r3]
	orrs r1, r2
	strh r1, [r3]
	ldr r1, _0807C860 @ =0x030003F8
	strb r6, [r1]
	ldr r2, _0807C864 @ =0x030003F6
	ldrh r1, [r0]
	strh r1, [r2]
	adds r0, #2
	ldrh r1, [r0]
	strh r1, [r5]
	adds r1, r5, #2
	mov r2, r8
	str r1, [r2]
	ldrh r0, [r0, #2]
	strh r0, [r5, #2]
	str r5, [r2]
	movs r0, #1
	mov r3, sb
	strh r0, [r3]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807C84C: .4byte 0x03000400
_0807C850: .4byte 0x04000208
_0807C854: .4byte 0x030003FC
_0807C858: .4byte 0x04000202
_0807C85C: .4byte 0x030003F4
_0807C860: .4byte 0x030003F8
_0807C864: .4byte 0x030003F6

	thumb_func_start sub_0807C868
sub_0807C868: @ 0x0807C868
	ldr r3, _0807C898 @ =0x04000208
	movs r1, #0
	strh r1, [r3]
	ldr r2, _0807C89C @ =0x030003FC
	ldr r0, [r2]
	strh r1, [r0]
	adds r0, #2
	str r0, [r2]
	strh r1, [r0]
	subs r0, #2
	str r0, [r2]
	ldr r2, _0807C8A0 @ =0x04000200
	ldr r0, _0807C8A4 @ =0x030003F4
	ldrb r0, [r0]
	movs r1, #8
	lsls r1, r0
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	ldr r0, _0807C8A8 @ =0x03000400
	ldrh r0, [r0]
	strh r0, [r3]
	bx lr
	.align 2, 0
_0807C898: .4byte 0x04000208
_0807C89C: .4byte 0x030003FC
_0807C8A0: .4byte 0x04000200
_0807C8A4: .4byte 0x030003F4
_0807C8A8: .4byte 0x03000400

	thumb_func_start eeprom_dma3_xfer
eeprom_dma3_xfer: @ 0x0807C8AC
	push {r4, r5, r6, lr}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r4, _0807C90C @ =0x04000208
	ldrh r3, [r4]
	adds r6, r3, #0
	movs r3, #0
	strh r3, [r4]
	ldr r5, _0807C910 @ =0x04000204
	ldrh r4, [r5]
	ldr r3, _0807C914 @ =0x0000F8FF
	ands r4, r3
	ldr r3, _0807C918 @ =0x03007018
	ldr r3, [r3]
	ldrh r3, [r3, #6]
	orrs r4, r3
	strh r4, [r5]
	ldr r3, _0807C91C @ =0x040000D4
	str r0, [r3]
	ldr r0, _0807C920 @ =0x040000D8
	str r1, [r0]
	ldr r1, _0807C924 @ =0x040000DC
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r2, r0
	str r2, [r1]
	adds r1, #2
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _0807C900
	ldr r2, _0807C928 @ =0x040000DE
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r0, #0
_0807C8F8:
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0807C8F8
_0807C900:
	ldr r0, _0807C90C @ =0x04000208
	strh r6, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807C90C: .4byte 0x04000208
_0807C910: .4byte 0x04000204
_0807C914: .4byte 0x0000F8FF
_0807C918: .4byte 0x03007018
_0807C91C: .4byte 0x040000D4
_0807C920: .4byte 0x040000D8
_0807C924: .4byte 0x040000DC
_0807C928: .4byte 0x040000DE

	thumb_func_start ReadEepromDword
	.global ReadEepromDword
ReadEepromDword: @ 0x0807C92C
	push {r4, r5, r6, lr}
	sub sp, #0x88
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _0807C944 @ =0x03007018
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	cmp r3, r0
	blo _0807C94C
	ldr r0, _0807C948 @ =0x000080FF
	b _0807C9CE
	.align 2, 0
_0807C944: .4byte 0x03007018
_0807C948: .4byte 0x000080FF
_0807C94C:
	ldr r0, _0807C9D8 @ =0x03007018
	adds r6, r0, #0
	ldr r0, [r0]
	ldrb r1, [r0, #8]
	lsls r0, r1, #1
	mov r4, sp
	adds r2, r0, r4
	adds r2, #2
	movs r4, #0
	cmp r4, r1
	bhs _0807C976
_0807C962:
	strh r3, [r2]
	subs r2, #2
	lsrs r3, r3, #1
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, [r6]
	ldrb r0, [r0, #8]
	cmp r4, r0
	blo _0807C962
_0807C976:
	movs r0, #1
	strh r0, [r2]
	subs r2, #2
	strh r0, [r2]
	movs r4, #0xd0
	lsls r4, r4, #0x14
	ldr r0, _0807C9D8 @ =0x03007018
	ldr r0, [r0]
	ldrb r2, [r0, #8]
	adds r2, #3
	mov r0, sp
	adds r1, r4, #0
	bl eeprom_dma3_xfer
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0x44
	bl eeprom_dma3_xfer
	add r2, sp, #8
	adds r5, #6
	movs r4, #0
	movs r6, #1
_0807C9A4:
	movs r1, #0
	movs r3, #0
_0807C9A8:
	lsls r1, r1, #0x11
	ldrh r0, [r2]
	ands r0, r6
	lsrs r1, r1, #0x10
	orrs r1, r0
	adds r2, #2
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xf
	bls _0807C9A8
	strh r1, [r5]
	subs r5, #2
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0807C9A4
	movs r0, #0
_0807C9CE:
	add sp, #0x88
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0807C9D8: .4byte 0x03007018

	thumb_func_start ProgramEepromDword
ProgramEepromDword: @ 0x0807C9DC
	push {r4, r5, lr}
	sub sp, #0xa4
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _0807C9F4 @ =0x03007018
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	cmp r4, r0
	blo _0807C9FC
	ldr r0, _0807C9F8 @ =0x000080FF
	b _0807CAA0
	.align 2, 0
_0807C9F4: .4byte 0x03007018
_0807C9F8: .4byte 0x000080FF
_0807C9FC:
	ldr r0, _0807CA3C @ =0x03007018
	ldr r0, [r0]
	ldrb r0, [r0, #8]
	lsls r0, r0, #1
	mov r1, sp
	adds r3, r0, r1
	adds r3, #0x84
	movs r0, #0
	strh r0, [r3]
	subs r3, #2
	movs r1, #0
_0807CA12:
	ldrh r2, [r5]
	adds r5, #2
	movs r0, #0
_0807CA18:
	strh r2, [r3]
	subs r3, #2
	lsrs r2, r2, #1
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0807CA18
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _0807CA12
	movs r1, #0
	ldr r0, _0807CA3C @ =0x03007018
	adds r2, r0, #0
	ldr r0, [r0]
	b _0807CA4E
	.align 2, 0
_0807CA3C: .4byte 0x03007018
_0807CA40:
	strh r4, [r3]
	subs r3, #2
	lsrs r4, r4, #1
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r0, [r2]
_0807CA4E:
	ldrb r0, [r0, #8]
	cmp r1, r0
	blo _0807CA40
	movs r0, #0
	strh r0, [r3]
	subs r3, #2
	movs r0, #1
	strh r0, [r3]
	movs r1, #0xd0
	lsls r1, r1, #0x14
	ldr r0, _0807CAA8 @ =0x03007018
	ldr r0, [r0]
	ldrb r2, [r0, #8]
	adds r2, #0x43
	mov r0, sp
	bl eeprom_dma3_xfer
	ldr r0, _0807CAAC @ =0x083ABCB8
	bl serial_init_transfer
	movs r4, #0
	movs r1, #0xd0
	lsls r1, r1, #0x14
	movs r3, #1
	ldr r2, _0807CAB0 @ =0x030003F8
_0807CA80:
	ldrh r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _0807CA9A
	ldrb r0, [r2]
	cmp r0, #0
	beq _0807CA80
	ldrh r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0807CA9A
	ldr r4, _0807CAB4 @ =0x0000C001
_0807CA9A:
	bl sub_0807C868
	adds r0, r4, #0
_0807CAA0:
	add sp, #0xa4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807CAA8: .4byte 0x03007018
_0807CAAC: .4byte 0x083ABCB8
_0807CAB0: .4byte 0x030003F8
_0807CAB4: .4byte 0x0000C001

	thumb_func_start VerifyEepromDword
VerifyEepromDword: @ 0x0807CAB8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r5, #0
	ldr r0, _0807CAD4 @ =0x03007018
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	cmp r1, r0
	blo _0807CADC
	ldr r0, _0807CAD8 @ =0x000080FF
	b _0807CB06
	.align 2, 0
_0807CAD4: .4byte 0x03007018
_0807CAD8: .4byte 0x000080FF
_0807CADC:
	adds r0, r1, #0
	mov r1, sp
	bl ReadEepromDword
	mov r2, sp
	movs r3, #0
	b _0807CAF4
_0807CAEA:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bhi _0807CB04
_0807CAF4:
	ldrh r1, [r4]
	ldrh r0, [r2]
	adds r2, #2
	adds r4, #2
	cmp r1, r0
	beq _0807CAEA
	movs r5, #0x80
	lsls r5, r5, #8
_0807CB04:
	adds r0, r5, #0
_0807CB06:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ProgramEepromDwordEx
	.global ProgramEepromDwordEx
ProgramEepromDwordEx: @ 0x0807CB10
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r6, #0
	b _0807CB22
_0807CB1C:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_0807CB22:
	cmp r6, #2
	bhi _0807CB46
	adds r0, r4, #0
	adds r1, r5, #0
	bl ProgramEepromDword
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _0807CB1C
	adds r0, r4, #0
	adds r1, r5, #0
	bl VerifyEepromDword
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _0807CB1C
_0807CB46:
	adds r0, r2, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
