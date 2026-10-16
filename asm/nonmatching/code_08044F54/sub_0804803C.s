	.syntax unified

	thumb_func_start sub_0804803C
	.global sub_0804803C
sub_0804803C: @ 0x0804803C
	movs r1, #0
	cmp r0, #0
	beq _08048048
	cmp r0, #1
	beq _08048064
	b _08048076
_08048048:
	ldr r1, _08048058 @ =0x083BEA90
	ldr r0, _0804805C @ =0x030057E0
	ldr r2, _08048060 @ =0x000007FE
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, #2
	b _08048072
	.align 2, 0
_08048058: .4byte 0x083BEA90
_0804805C: .4byte 0x030057E0
_08048060: .4byte 0x000007FE
_08048064:
	ldr r1, _0804807C @ =0x083BEA90
	ldr r0, _08048080 @ =0x030057E0
	ldr r2, _08048084 @ =0x000007FE
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, #3
_08048072:
	adds r0, r0, r1
	ldrb r1, [r0]
_08048076:
	adds r0, r1, #0
	bx lr
	.align 2, 0
_0804807C: .4byte 0x083BEA90
_08048080: .4byte 0x030057E0
_08048084: .4byte 0x000007FE
	.syntax divided
