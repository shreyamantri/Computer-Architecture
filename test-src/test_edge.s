.import ../src/utils.s
.import ../src/../coverage-src/zero_one_loss.s

.data
.align 4
m0: .word 
.align 4
m1: .word 

.globl main_test
.text
# main_test function for testing
main_test:

    # load address to array m0 into a0
    la a0 m0

    # load address to array m1 into a1
    la a1 m1

    # load 0 into a2
    li a2 0

    # call zero_one_loss function
    jal ra zero_one_loss
    # we expect zero_one_loss to exit early with code 36

    # exit normally
    li a0 0
    jal exit
