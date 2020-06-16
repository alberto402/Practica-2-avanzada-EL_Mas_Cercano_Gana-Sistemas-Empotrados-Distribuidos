	.global start
    .extern Main
    .equ STACK, 0x0C7FF000

start: 
    LDR SP,=STACK
    MOV FP,#0
    
    MOV LR,PC
    LDR PC,=Main

End:
    B End

.end

