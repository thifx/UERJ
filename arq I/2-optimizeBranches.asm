#/* trecho while */
#while (save[i] == k)
#	i += 1;

# s3: i
# s5: k
#s6: save
#s7: save.length

#Loop:  sll $t1, $s3, 2 
#	add $t1, $t1, $s6 
#	lw $t0, 0($t1) 
#	bne $t0, $s5, Exit 
#	addi $s3, $s3, 1 
#	j Loop 
#Exit:


loop: 
	# t0 = *(i*4 + &save[0])
	sll $t1, $s3, 2 
	add $t1, $t1, $s6
	lw $t0, 0($t1)
	
	beq $t0, $s5, loop
	addi $s3, $s3, 1
Exit: