	.syntax unified

	thumb_func_start load_tilemap_rows_to_vram
load_tilemap_rows_to_vram: @ 0x08000F1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	.syntax divided
