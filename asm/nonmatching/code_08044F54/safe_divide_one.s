	.syntax unified

	thumb_func_start safe_divide_one
safe_divide_one: @ 0x08048860
	push {r4, r5, lr}
	adds r5, r0, #0
	cmp r5, #0
	bne _0804886C
	movs r0, #1
	b _08048896
_0804886C:
	movs r4, #0
	b _08048872
_08048870:
	adds r4, #1
_08048872:
	cmp r4, #9
	bgt _08048894
	movs r1, #1
	cmp r4, #0
	ble _0804888A
	adds r2, r4, #0
_0804887E:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #1
	subs r2, #1
	cmp r2, #0
	bne _0804887E
_0804888A:
	adds r0, r5, #0
	bl sub_0807CBBC
	cmp r0, #0
	bne _08048870
_08048894:
	adds r0, r4, #0
_08048896:
	pop {r4, r5}
	pop {r1}
	bx r1
	.syntax divided
