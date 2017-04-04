.386
.MODEL FLAT, C

.DATA
k       dd ?
sum     dd ?
i       dd ?
factor2 dd ?

.CODE
properFactors PROC USES ebx ecx edx edi esi, n:dword, factors:ptr, NumFactors:ptr

; Move the factors list to ESI
MOV esi, factors
MOV [esi], 1

; Initialize Variables
MOV k,     2
MOV sum,   1
MOV i,     1

JMP while_1

while_1:
    ; (k * k <= n)
    MOV  ebx, k
	IMUL ebx, k
	CMP  ebx, n
	JLE  cwhile_1
	JMP  ewhile_1

cwhile_1:
    JMP if_1

if_1:
    ; (n % k == 0)
    CDQ
    MOV  eax, n
    IDIV k
    CMP  edx, 0
    JE   cif_1
	JMP  eif_1

cif_1:
    ; sum += k
    MOV eax, sum
	ADD eax, k
	MOV sum, eax

	; factors[i] = k
	MOV eax, i
	MOV [esi + eax * 4], k

	; i++
	INC eax
	MOV i, eax

	; int factor2 = n / k
	CDQ
	MOV eax, n
	IDIV k
	MOV factor2, eax

if_2:
    ; factor2 != k
    MOV eax, factor2
	CMP k, eax
	JE  eif_2
	JMP cif_2

cif_2:
    ; sum += factor2
    MOV eax, sum
	ADD eax, factor2
	MOV sum, eax

	; factors[i] = factor2
	MOV eax, i
	MOV [esi + eax * 4], factor2

	; i++
	INC eax
	MOV i, eax

eif_2:
    JMP eif_1

eif_1:
    ; k++
    MOV eax, k
	INC k
	MOV k, eax

	JMP while_1
    
ewhile_1:
    MOV [NumFactors], i

    ; return sum
    MOV eax, sum
    RET

properFactors ENDP

END
