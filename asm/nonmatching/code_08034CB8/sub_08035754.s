	.syntax unified

	thumb_func_start sub_08035754
	.global sub_08035754
sub_08035754: @ 0x08035754
	adds r2, r0, #0
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, r1
	bge _08035762
	movs r0, #0
	b _08035766
_08035762:
	ldrh r0, [r2]
	subs r0, r0, r1
_08035766:
	strh r0, [r2]
	bx lr
	.align 2, 0
	.syntax divided
