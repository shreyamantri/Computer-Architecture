.globl argmax

.text
# =================================================================
# FUNCTION: Given a int array, return the index of the largest
#   element. If there are multiple, return the one
#   with the smallest index.
# Arguments:
#   a0 (int*) is the pointer to the start of the array
#   a1 (int)  is the # of elements in the array
# Returns:
#   a0 (int)  is the first index of the largest element
# Exceptions:
#   - If the length of the array is less than 1,
#     this function terminates the program with error code 36
# =================================================================
argmax:
    # Prologue
    # Returns the index of the LARGEST element of the function
    # a0 - pointer to the start of the array
    # a1 - # elements in the array
    
    li t0 1 #storing a temporary value of 1 into t0 to check if a1 (length) is less than 1
    blt a1, t0 error
    
    li t1 0 #t1 points to the starting index
    # li t2 0 #t2 points to 0 values that you should override --> you could just use x0
    
    li t2 0 # this is my temporary max register
    li t3 0 # this is register with the index in my array
    
    #store a register equal to the max value 
    # one more register to point to the index


loop_start:
    bge t1 a1 loop_end
    lw t4 0(a0) #load the current value into t4
    bge t2 t4 loop_continue #branches if t4 is less than the value at the max register
    ## NOW THE MAX LOGIC
    mv t2 t4
    mv t3 t1
    # a0 at the end needs to point to the index?

loop_continue: # if my branch is true it's going to come here
    addi t1 t1 1
    addi a0 a0 4
    j loop_start

loop_end:
    # Epilogue
    
    #should i assign a0 to t3 before i exit?
    mv a0 t3
    jr ra
    
error:
    li a0 36
    j exit
