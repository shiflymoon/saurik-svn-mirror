info: SampleBot, John Doe, youremail@your-domain.com, 310 555-1212, UCLA

main:
        rand r0, 32
        mov [0], r0
	mov [1], r0
	mov [2], r0
	mov [3], r0
	mov [4], r0
	mov [5], r0
	mov [6], r0
	mov [7], r0
	mov [8], r0
	mov [9], r0
	mov [10], r0
	mov [11], r0
	mov [12], r0
	mov [13], r0
	mov [14], r0
	mov [15], r0
	mov [16], r0
	mov [17], r0
	mov [18], r0
	mov [19], r0
	mov [20], r0
	mov [21], r0
	mov [22], r0
	mov [23], r0
	mov [24], r0
	mov [25], r0
	mov [26], r0
	mov [27], r0
	mov [28], r0
	mov [29], r0
	mov [30], r0
	mov [31], r0
	mov [32], r0
	mov [33], r0
	mov [34], r0
	mov [35], r0
	mov [36], r0
	mov [37], r0
	mov [38], r0
	mov [39], r0
	mov [40], r0
	mov [41], r0
	mov [42], r0
	mov [43], r0
	mov [44], r0
	mov [45], r0
	mov [46], r0
	mov [47], r0
	mov [48], r0
	mov [49], r0
	mov [50], r0
	mov [51], r0
	mov [52], r0
	mov [53], r0
	mov [54], r0
	mov [55], r0
	mov [56], r0
	mov [57], r0
	mov [58], r0
	mov [59], r0
	mov [60], r0
	mov [61], r0
	mov [62], r0
	mov [63], r0
	mov [64], r0
	mov [65], r0
	mov [66], r0
	mov [67], r0
	mov [68], r0
	mov [69], r0
	mov [70], r0
	mov [71], r0
	mov [72], r0
	mov [73], r0
	mov [74], r0
	mov [75], r0
	mov [76], r0
	mov [77], r0
	mov [78], r0
	mov [79], r0
	mov [80], r0
	mov [81], r0
	mov [82], r0
	mov [83], r0
	mov [84], r0
	mov [85], r0
	mov [86], r0
	mov [87], r0
	mov [88], r0
	mov [89], r0
	mov [90], r0
	mov [91], r0
	mov [92], r0
	mov [93], r0
	mov [94], r0
	mov [95], r0
	mov [96], r0
	mov [97], r0
	mov [98], r0
	mov [99], r0
	mov [100], r0
	mov [101], r0
	mov [102], r0
	mov [103], r0
	mov [104], r0
check:
	mov r2, 0
loop:
	cmp [r2], r0
	je next
	mov r3, [r2]
	mov [r2], r0
next:
	add r2, 1
	cmp r2, 105
	je check
	jmp loop
