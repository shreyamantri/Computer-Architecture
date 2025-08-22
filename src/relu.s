.globl relu

.text
# ==============================================================================
# FUNCTION: Performs an inplace element-wise ReLU on an array of ints
# Arguments:
#   a0 (int*) is the pointer to the array
#   a1 (int)  is the # of elements in the array
# Returns:
#   None
# Exceptions:
#   - If the length of the array is less than 1,
#     this function terminates the program with error code 36
# ==============================================================================
relu:
    # Prologue
    
    # Need to decrease the stack pointer here before 
    
    # Do you put the edge cases in here? --> need to return the default value into a0
    # a0 points to the pointer
    # a1 points to the length of the array
    
    # If length of array is less than 1, run li a0 36 & j exit
    ebreak
    li t0 1 #storing a temporary value of 1 into t0 to check if a1 (length) is less than 1
    blt a1, t0 error
    
    li t1 0 #t1 points to the starting index
    li t2 0 #t2 points to 0 values that you should override --> you could just use x0
    
    # do i need to call loop_start?

loop_start:
    
    # now i want to actual start looping through a0
    # here i want to check conditions:
        # if the starting index is equal to length of the array --> exit
        # else --> store the current value into a register
        # check if that current value is negative and then set to 0 --> another function?
    
    bge t1 a1 loop_end
    lw t3 0(a0) # load the current word into the t3 register
    blt t3 x0 put # now check if that current word is negative --> set to 0
    #blt a0 x0 put

loop_continue:

    # here i want to increment the counter and then call loop_start
    # increment the counter that's looping through the array
    add t1 t1 t0
    addi a0 a0 4
    j loop_start

loop_end:


    # Epilogue
    # Need to increment the stack pointer here --> but i don't use s registers
    # Do I need to repoint where the a0 register here? bc the array isn't changing

    jr ra
    
put: # a method to assign the negative values to 0
    sw x0 0(a0)
    j loop_continue
 
error:
    li a0 36
    j exit
