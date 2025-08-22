.globl dot

.text
# =======================================================
# FUNCTION: Dot product of 2 int arrays
# Arguments:
#   a0 (int*) is the pointer to the start of arr0
#   a1 (int*) is the pointer to the start of arr1
#   a2 (int)  is the number of elements to use
#   a3 (int)  is the stride of arr0
#   a4 (int)  is the stride of arr1
# Returns:
#   a0 (int)  is the dot product of arr0 and arr1
# Exceptions:
#   - If the number of elements to use is less than 1,
#     this function terminates the program with error code 36
#   - If the stride of either array is less than 1,
#     this function terminates the program with error code 37
# =======================================================
dot:

    # Prologue
    # edge cases 
    
    #a0: address of start of first array
    #a1: address of start of second array
    #a2: num elements
    #a3: stride of first arr
    #a4: stride of second arr
    
    li t0 1 #storing a temporary value of 1 to check edge cases
    blt a2 t0 error_elements
    blt a3 t0 error_stride
    blt a4 t0 error_stride
    
    #addi sp sp -8 #move stack pointer by 8 bytes
    #sw s0 0(sp)
    #sw s1 0(sp)
    
    li t1 0 #storing the dot product
    li t2 0 #number of elements we've checked (num elements we check in both arrays is the same)
    
loop_start:

    beq t2 a2 loop_end # if number of elements is eqaul to total num of elements, branch to loop_end
    
    lw t3 0(a0) # load the value of first elem in arr0 into a0
    lw t4 0(a1) # load the value of first elem in arr1 into a1
    
    mul t5 t3 t4 # multiply the value in t3 with t4
    add t1 t1 t5 # add the value to the dot product register t1
    # mv t1 t6 # now t1 register contains the updated dot product
    
    slli t6 a3 2 # shift left by 2
    add a0 a0 t6
    
    slli t6 a4 2 # shift left by 2
    add a1 a1 t6
    
    addi t2 t2 1 # increment the number of elements 
    
    j loop_start
    
    # assign a temporary register to the start of the first value in both arrays --> value at a0 and a1
    # have another register point to the index and check that it's less than the stride of both arrays
    
    # compute this dot product as you increment the counters 
    # just loop until the number of elements is equal to 

loop_end:
    # Epilogue
    mv a0 t1
    jr ra
    
error_elements:
    li a0 36
    j exit

error_stride:
    li a0 37
    j exit

    
    
