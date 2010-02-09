

; multipy
; using adds


ldaa	#0	
staa	VAL
ldaa	CAND
ldab	plier
dly #4

Loop:
	lsrb
	bcc	noadd
	adda	val
	staa	val
	noadd	ldaa	CAND
	lsla
	staa	CAND
	dbne	y,Loop
	
	

have
800
801
802
803

804
805
806
807

store in
810
811
812
813


ldd			$802
add		$806
std			$812

ldaa		$801
adca		$805

ldaa		$800
adca		$804
staa		$810



