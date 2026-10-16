	.syntax unified

	thumb_func_start sub_0804DBA4
	.global sub_0804DBA4
sub_0804DBA4: @ 0x0804DBA4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0804DBB8 @ =0x030057E0
	ldr r2, _0804DBBC @ =0x00000CA4
	adds r1, r1, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #1
	bx lr
	.align 2, 0
_0804DBB8: .4byte 0x030057E0
_0804DBBC: .4byte 0x00000CA4
	.syntax divided
